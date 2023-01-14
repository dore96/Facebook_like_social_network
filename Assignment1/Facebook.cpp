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

Facebook::~Facebook()
{
	vector<const Status*>::const_iterator itr = allStatuses.begin();
	vector<const Status*>::const_iterator end = allStatuses.end();
	for (; itr != end; ++itr)
	{
		delete (*itr);
	}
}