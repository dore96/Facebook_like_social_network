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
{//prints all users
	list<User>::const_iterator itr = usersInSystem.begin();
	list<User>::const_iterator enditr = usersInSystem.end();
	cout << "Users: " << endl;
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << i + 1 << "." << (*itr).getName() << endl;
	}
}
void Facebook::showAllFanpage()										const
{//prints all fanpages
	list<Fanpage>::const_iterator itr = fanpagesInSystem.begin();
	list<Fanpage>::const_iterator enditr = fanpagesInSystem.end();
	cout << "Fanpages: " << endl;
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << i + 1 << "." << (*itr).getName() << endl;
	}
}
void Facebook::showAllUsersAndFanpages()							const
{//shows all entities
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
{//finds user in system
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
{//finds user in system
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
{//finds page in system
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
{//finds page in system
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
{//adds text status to an entity
	if (!isPage)
	{
		User* user = findUser(name);
		if (user == nullptr)
		{
			throw notFoundException();
		}
		user->addStatus(new Status(textStatus));
	}
	else
	{
		Fanpage* fanpage = findPage(name);
		if (fanpage == nullptr)
		{
			throw notFoundException();
		}
		fanpage->addStatus(new Status(textStatus));
	}
}
void Facebook::addMediaStatus(bool isPage, const string& name, const string& textStatus, string& url, int type) noexcept(false)
{//ads video or image status to entity
	if (!isPage)
	{
		User* user = findUser(name);
		if (user == nullptr)
		{
			throw notFoundException();
		}
		if(type == video)
		{
			user->addStatus(new VideoStatus(url, textStatus));
		}
		else
		{
			user->addStatus(new PictureStatus(url, textStatus));
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
			fanpage->addStatus(new VideoStatus(url, textStatus));
		}
		else
		{
			fanpage->addStatus(new PictureStatus(url, textStatus));
		}
	}
}
void Facebook::addUser(const string& userName, int day, int month, int year) noexcept(false)
{//ads user to system
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
{//adds fanpage to system
	Fanpage* page = findPage(pageName);
	if (page != nullptr)
	{
		throw duplicateFanpageException();
	}
	fanpagesInSystem.push_back(Fanpage(pageName));  //creats a fan page with given name - and use of default move ctor.
}
void Facebook::addFriendship(const string& userName1, const string& userName2) noexcept(false)
{//connects between 2 users
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
{//cancel link between 2 users
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

istream& operator>>(istream& in, Facebook& facebook)//read to system from file
{
	int numberofUsers , numberOfFanpages;
	string name, ignore;
	Date* date;
	User* user;
	Fanpage* fanpage;

	in >> numberofUsers >> numberOfFanpages;
	for (int i = 0; i < numberofUsers; i++)//read userss
	{
		getline(in, name);
		getline(in, name);
		date = new Date(in);
		user = new User(in, name, *date);
		facebook.usersInSystem.push_back(*user);
	}
	for (int i = 0; i < numberOfFanpages; i++)//read fanpages
	{
		getline(in, name);
		getline(in, name);
		fanpage = new Fanpage(in, name);
		facebook.fanpagesInSystem.push_back(*fanpage);
	}

	list<User>::iterator itr = facebook.usersInSystem.begin();
	list<User>::iterator enditr = facebook.usersInSystem.end();
	int numOfFriends, numOfPages;
	for (; itr != enditr; ++itr)//read all links that exist in the system
	{
		in >> numOfFriends >> numOfPages;
		in.ignore();
		for (int i = 0; i < numOfFriends; i++)
		{
			getline(in, name);
			user = facebook.findUser(name);
			(*itr).addFriend(*user);
		}
		for (int i = 0; i < numOfPages; i++)
		{
			getline(in, name);
			fanpage = facebook.findPage(name);
			(*itr).likeAPage(*fanpage);
		}
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

	for(;itr != enditr; ++itr)//print all users
	{
		os << (*itr);
	}
	for (; itr2 != enditr2; ++itr2)//print all pages in system
	{
		os << (*itr2);
	}

	for (itr = facebook.usersInSystem.begin(); itr != enditr; ++itr)//prints all links of entites
	{
		os << (*itr).getNumberOfFriends() << endl;
		os << (*itr).getNumberOfFanpaegs() << endl;
		(*itr).showAllFriends(os);
		(*itr).showAllLikedPages(os);
	}
	return os;
}
Facebook::~Facebook()//dtor
{
	ofstream outfile("compSaveFacebook.txt", ios::trunc);
	outfile << *this << endl;
}