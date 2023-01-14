#include "Facebook.h"

Facebook::Facebook()
{
	addUser("dor",25,07,1996);
	addUser("maor",29,04,1999);
	addUser("tovia",04,8,2022);
	addFanpage("MTA course recomendations");
	addFanpage("Pro yogurt");
	addFanpage("Merge Halicod & Meretz");
	addTextStatus(true, "MTA course recomendations", "c++ course is great");
	addTextStatus(true, "MTA course recomendations", "no time in this course");
	addTextStatus(true,"Merge Halicod & Meretz", "yammi");
	addTextStatus(true, "Merge Halicod & Meretz", "Henlo Wornld");
	addTextStatus(true, "Pro yogurt","29%");
	addTextStatus(true, "Pro yogurt", "Cheap Quality");
	addTextStatus(false,"dor", "Hi There");
	addTextStatus(false, "dor", "29%");
	addTextStatus(false,"tovia","barkbark");
	addTextStatus(false, "tovia", "whofwhof");
	addTextStatus(false,"maor","ok here");
	addTextStatus(false, "maor", "byebye");
	addFriendship("maor", "dor");
	addFriendship("dor", "tovia");
	addFriendship("tovia", "maor");
	addFanToPage("Merge Halicod & Meretz", "dor");
	addFanToPage("Pro yogurt", "tovia");
	addFanToPage("MTA course recomendations", "maor");
}
Facebook::Facebook(ifstream& in)
{
	in >> *this;

}
void Facebook::showAllUsers()										const
{
	list<User>::const_iterator itr = usersInSystem.begin();
	list<User>::const_iterator enditr = usersInSystem.end();
	cout << "Users: " << endl;
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << i + 1 << "." << (*itr).getName() << endl;
	}
}
void Facebook::showAllFanpage()										const
{
	list<Fanpage>::const_iterator itr = fanpagesInSystem.begin();
	list<Fanpage>::const_iterator enditr = fanpagesInSystem.end();
	cout << "Fanpages: " << endl;
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << i + 1 << "." << (*itr).getName() << endl;
	}
}
void Facebook::showAllUsersAndFanpages()							const
{
	showAllUsers();
	showAllFanpage();
}
void Facebook::showFeed(const string& userName)						const noexcept(false)
{
	const User* user = findUser(userName);
	if(user == nullptr)
	{
		throw notFoundException();
	}
	user->showFriendsStatus(10);
	user->showPagesStatus(10);
}
void Facebook::showStatusOfEntity(bool isPage, const string& name)  const noexcept(false)
{
	if (isPage)
	{
		const Fanpage* currentPage = findPage(name);
		if (currentPage == nullptr)
		{
			throw notFoundException();
		}
		currentPage->showStatuses(); //shows all satatuses of a fanpage
	}
	else
	{
		const User* currentUser = findUser(name);
		if (currentUser == nullptr)
		{
			throw notFoundException();
		}
		currentUser->showStatuses(); //shows all sattuses of a user
	}
}
void Facebook::showAllFriendsOrFans(bool isPage, const string& name)const noexcept(false)
{
	if (isPage)
	{
		showAllFans(name);
	}
	else
	{
		showAllLinks(name);
	}
}
void Facebook::showAllLinks(const string& userName)					const noexcept(false)
{
	const User* currentUser = findUser(userName);
	if (currentUser == nullptr)
	{
		throw notFoundException();
	}
	currentUser->showAllFriends();  //show all users friend listed.
	currentUser->showAllLikedPages();
}
void Facebook::showAllFans(const string& pageName)				    const noexcept(false)
{
	const Fanpage* currentPage = findPage(pageName);
	if (currentPage == nullptr)
	{
		throw notFoundException();
	}
	currentPage->showAllFans();  //show all fans of a page
}

User* Facebook::findUser(const string& name)                        
{
	list<User>::iterator itr = usersInSystem.begin();
	list<User>::iterator end = usersInSystem.end();
	for (int i = 0;itr != end; ++itr, i++)
	{
		if (!name.compare((*itr).getName()))
		{//compare users by name (uniq)
			return &*itr;
		}
	}
	return nullptr;
}
const User* Facebook::findUser(const string& name)					const
{
	list<User>::const_iterator itr = usersInSystem.begin();
	list<User>::const_iterator end = usersInSystem.end();
	for (int i = 0; itr != end; ++itr, i++)
	{
		if (!name.compare((*itr).getName()))
		{//compare users by name (uniq)
			return &*itr;
		}
	}
	return nullptr;
}
Fanpage* Facebook::findPage(const string& name)                   
{
	list<Fanpage>::iterator itr = fanpagesInSystem.begin();
	list<Fanpage>::iterator end = fanpagesInSystem.end();
	for (; itr != end; ++itr)
	{
		if (!name.compare((*itr).getName()))
		{//compare users by name (uniq)
			return &(*itr);
		}
	}
	return nullptr;
}
const Fanpage* Facebook::findPage(const string& name)               const
{
	list<Fanpage>::const_iterator itr = fanpagesInSystem.begin();
	list<Fanpage>::const_iterator end = fanpagesInSystem.end();
	for (; itr != end; ++itr)
	{
		if (!name.compare((*itr).getName()))
		{//compare users by name (uniq)
			return &(*itr);
		}
	}
	return nullptr;
}

void Facebook::addTextStatus(bool isPage, const string& name, const string& textStatus) noexcept(false)
{
	if (!isPage)
	{
		User* user = findUser(name);
		if (user == nullptr)
		{
			throw notFoundException();
		}
		allStatuses.push_back(new Status(textStatus));
		user->addStatus(allStatuses.back());
	}
	else
	{
		Fanpage* fanpage = findPage(name);
		if (fanpage == nullptr)
		{
			throw notFoundException();
		}
		allStatuses.push_back(new Status(textStatus));
		fanpage->addStatus(allStatuses.back());
	}
}
void Facebook::addMediaStatus(bool isPage, const string& name, const string& textStatus, string& url, int type) noexcept(false)
{
	if (!isPage)
	{
		User* user = findUser(name);
		if (user == nullptr)
		{
			throw notFoundException();
		}
		if(type == video)
		{
			allStatuses.push_back(new VideoStatus(url, textStatus));
			user->addStatus(allStatuses.back());
		}
		else
		{
			allStatuses.push_back(new PictureStatus(url, textStatus));
			user->addStatus(allStatuses.back());
		}
	}
	else
	{
		Fanpage* fanpage = findPage(name);
		if (fanpage == nullptr)
		{
			throw notFoundException();
		}
		if (type == video)
		{
			allStatuses.push_back(new VideoStatus(url, textStatus));
			fanpage->addStatus(allStatuses.back());
		}
		else
		{
			allStatuses.push_back(new PictureStatus(url, textStatus));
			fanpage->addStatus(allStatuses.back());
		}
	}
}
void Facebook::addUser(const string& userName, int day, int month, int year) noexcept(false)
{
	User* user = findUser(userName);
	if (user != nullptr)
	{
		throw duplicateUserException();
	}
	Date userDate(day, month, year);					      //creates a date.
	usersInSystem.push_back(User(userName, userDate));   //creats a user with given date (now) - and use of default move ctor.
}
void Facebook::addFanToPage(const string& pageName, const string& userName) noexcept(false)
{
	Fanpage* page = findPage(pageName);
	User* user = findUser(userName);
	if (page == nullptr)
	{
		throw notFoundException();
	}
	if (user == nullptr)
	{
		throw notFoundException();
	}
	if (user->isFanOf(pageName))
	{
		throw duplicateConnactionException();
	}
	page->addFan(*user);
}
void Facebook::addFanpage(const string& pageName) noexcept(false)
{
	Fanpage* page = findPage(pageName);
	if (page != nullptr)
	{
		throw duplicateFanpageException();
	}
	fanpagesInSystem.push_back(Fanpage(pageName));  //creats a fan page with given name - and use of default move ctor.
}
void Facebook::addFriendship(const string& userName1, const string& userName2) noexcept(false)
{
	User* user1 = findUser(userName1);
	User* user2 = findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		throw notFoundException();
	}
	if (user1->isFriendsWith(*user2))
	{
		throw duplicateConnactionException();
	}
	if (user1 ==user2)
	{
		throw invalid_argument("User can not add itself as a friend");
	}
	user1->addFriend(*user2);
}
void Facebook::removeFanFromPage(const string& pageName, const string& userName) noexcept(false)
{
	Fanpage* page = findPage(pageName);
	User* user = findUser(userName);
	if (page == nullptr)
	{
		throw notFoundException();
	}
	if (user == nullptr)
	{
		throw notFoundException();
	}
	if (!user->isFanOf(*page))
	{
		throw invalid_argument("The fan called " + userName +" is not a fan of "
			+ pageName + "therefor can not be erased from fans");
	}
	page->removeFan(*user);
}
void Facebook::cancelFriendship(const string& userName1, const string& userName2) noexcept(false)
{
	User* user1 = findUser(userName1);
	User* user2 = findUser(userName2);
	if (user1==nullptr || user2 == nullptr)
	{
		throw notFoundException();
	}
	if (!user1->isFriendsWith(*user2))
	{
		throw invalid_argument("No friendship exist between " + userName1+ 
			" and " + userName2);
	}
	user1->unFriend(*user2);
}

istream& operator>>(istream& in, Facebook& facebook)
{
	int numberofUsers , numberOfFanpages, nameLen;
	in >> numberofUsers >> numberOfFanpages;
	char* name;
	for (int i = 0; i < numberofUsers; i++)
	{
		int year, month, day;
		in >> nameLen;
		name = new char[nameLen];
		in >> name;
		name[nameLen] = '\0';
		in >> day >> month >> year;
		facebook.addUser(name, day, month, year);
		delete[]name;
	}
	for (int i = 0; i < numberOfFanpages; i++)
	{
		in >> nameLen;
		name = new char[nameLen];
		in >> name;
		name[nameLen] = '\0';
		facebook.addFanpage(name);
		delete[]name;
	}
	list<User>::iterator itr = facebook.usersInSystem.begin();
	list<User>::iterator enditr = facebook.usersInSystem.end();
	list<Fanpage>::iterator itr2 = facebook.fanpagesInSystem.begin();
	list<Fanpage>::iterator enditr2 = facebook.fanpagesInSystem.end();

	for (; itr != enditr; ++itr)
	{
		in >> (*itr);
	}
	for (; itr2 != enditr2; ++itr2)
	{
		in >> (*itr2);
	}
	return in;
}
ostream& operator<<(ostream& os, const Facebook& facebook)
{
	os << facebook.usersInSystem.size() << endl;
	os << facebook.fanpagesInSystem.size() << endl;

	list<User>::const_iterator itr = facebook.usersInSystem.begin();
	list<User>::const_iterator enditr = facebook.usersInSystem.end();
	list<Fanpage>::const_iterator itr2 = facebook.fanpagesInSystem.begin();
	list<Fanpage>::const_iterator enditr2 = facebook.fanpagesInSystem.end();

	os << endl << endl<< "names of fanpage and users: "  << endl;		/////////////////
	for (; itr != enditr; ++itr)
	{
		os << (*itr).getName().size() << endl;
		os << (*itr).getName() << endl;
		os << (*itr).getBirthDate().getDay() << endl;
		os << (*itr).getBirthDate().getMonth() << endl;
		os << (*itr).getBirthDate().getYear() << endl;
	}
	for (; itr2 != enditr2; ++itr2)
	{
		os << (*itr2).getName() << endl;
	}


	os<< endl << endl << "users :" << endl ;			/////////////////
	for(itr = facebook.usersInSystem.begin();itr != enditr; ++itr)
	{
		os << (*itr) << endl << endl << endl;
	}
	os << endl << endl << "fanpages :" << endl;           /////////////////
	for (itr2 = facebook.fanpagesInSystem.begin(); itr2 != enditr2; ++itr2)
	{
		os << (*itr2) << endl << endl << endl;
	}
	return os;
}
Facebook::~Facebook()
{
	ofstream outfile("saveFacebook.txt", ios::trunc);
	outfile << *this << endl;

	vector<const Status*>::const_iterator itr = allStatuses.begin();
	vector<const Status*>::const_iterator end = allStatuses.end();
	for (; itr != end; ++itr)
	{
		delete (*itr);
	}
}