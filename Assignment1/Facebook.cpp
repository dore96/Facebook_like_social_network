#include "Facebook.h"

Facebook::Facebook() : userInterface(*this)
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

void Facebook::runConsoleApp()									
{
	int choice;
	do
	{
		try
		{
			userInterface.printMenu();
			cin >> choice;
			userInterface.chooseFromMenu(choice);
		}
		catch (invalid_argument& e)
		{
			cout << "Invalid argumant:" << e.what() << endl;
		}
		catch (out_of_range& e)
		{
			cout << "Out of range:" << e.what() << endl;
		}
		catch (...)
		{
			cout << "There was a unexpected error, please try again." << endl;
		}

	} while (choice != EXIT);

}

void Facebook::showAllUsers()										const
{
	vector<User>::const_iterator itr = usersVect.begin();
	vector<User>::const_iterator enditr = usersVect.end();
	cout << "Users: " << endl;
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << i + 1 << "." << (*itr).getName() << endl;
	}
}
void Facebook::showAllFanpage()										const
{
	vector<Fanpage>::const_iterator itr = fanpageVect.begin();
	vector<Fanpage>::const_iterator enditr = fanpageVect.end();
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
		throw invalid_argument("No user with that name");
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
			throw invalid_argument("No fan page with that name");
		}
		currentPage->showStatuses(); //shows all sattuses of a fanpage
	}
	else
	{
		const User* currentUser = findUser(name);
		if (currentUser == nullptr)
		{
			throw invalid_argument("No user with that name");
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
		throw invalid_argument("No user with that name");
	}
	currentUser->showAllFriends();  //show all users friend listed.
	currentUser->showAllLikedPages();
}
void Facebook::showAllFans(const string& pageName)				    const noexcept(false)
{
	const Fanpage* currentPage = findPage(pageName);
	if (currentPage == nullptr)
	{
		throw invalid_argument("No fan page with that name");
	}
	currentPage->showAllFans();  //show all fans of a page
}

User* Facebook::findUser(const string& name)                        
{
	vector<User>::iterator itr = usersVect.begin();
	vector<User>::iterator end = usersVect.end();
	for (int i = 0;itr < end; ++itr, i++)
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
	vector<User>::const_iterator itr = usersVect.begin();
	vector<User>::const_iterator end = usersVect.end();
	for (int i = 0; itr < end; ++itr, i++)
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
	vector<Fanpage>::iterator itr = fanpageVect.begin();
	vector<Fanpage>::iterator end = fanpageVect.end();
	for (; itr < end; ++itr)
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
	vector<Fanpage>::const_iterator itr = fanpageVect.begin();
	vector<Fanpage>::const_iterator end = fanpageVect.end();
	for (; itr < end; ++itr)
	{
		if (!name.compare((*itr).getName()))
		{//compare users by name (uniq)
			return &(*itr);
		}
	}
	return nullptr;
}
void Facebook::Exit()											    const
{
	cout << "Thank you for using FaceBook, goodbye !" << endl;
}

void Facebook::addTextStatus(bool isPage, const string& name, const string& textStatus) noexcept(false)
{
	Status* status = new Status(textStatus);
	if (!isPage)
	{
		User* user = findUser(name);
		if (user == nullptr)
		{
			delete status;
			throw invalid_argument("No user with that name");
		}
		user->addStatus(*status);  //creates a new status by input and adds it to user.
	}
	else
	{
		Fanpage* fanpage = findPage(name);
		if (fanpage == nullptr)
		{
			delete status;
			throw invalid_argument("No user with that name");
		}
		fanpage->addStatus(*status); //creates a new status by input and adds it to fanpage.
	}
}
void Facebook::addUser(const string& userName, int day, int month, int year) noexcept(false)
{
	User* user = findUser(userName);
	if (user != nullptr)
	{
		throw invalid_argument("This user already exists, returning to menu");
	}
	Date userDate(day, month, year);					  //creates a date.
	usersVect.push_back(User(userName, userDate));   //creats a user with given date (now) - and use of default move ctor.
}
void Facebook::addFanToPage(const string& pageName, const string& userName) noexcept(false)
{
	Fanpage* page = findPage(pageName);
	User* user = findUser(userName);
	if (page == nullptr)
	{
		throw invalid_argument("No page called" + pageName + " was found");
	}
	if (user == nullptr)
	{
		throw invalid_argument("No user called" + userName + " was found");
	}
	if (user->isFanOf(pageName))
	{
		throw invalid_argument("User is already a fan of this page.");
	}
	page->addFan(*user);
}
void Facebook::addFanpage(const string& pageName) noexcept(false)
{
	Fanpage* page = findPage(pageName);
	if (page != nullptr)
	{
		throw invalid_argument("This page already exists");
	}
	fanpageVect.push_back(Fanpage(pageName));  //creats a fan page with given name - and use of default move ctor.
}
void Facebook::addFriendship(const string& userName1, const string& userName2) noexcept(false)
{
	//try catch
	User* user1 = findUser(userName1);
	User* user2 = findUser(userName2);
	if (user1->isFriendsWith(*user2))
	{
		throw invalid_argument("Users are already friends.");
	}
	user1->addFriend(*user2);
}
void Facebook::removeFanFromPage(const string& pageName, const string& userName) noexcept(false)
{
	Fanpage* page = findPage(pageName);
	User* user = findUser(userName);
	if (page == nullptr)
	{
		throw invalid_argument("No page called " + pageName + " was found");
	}
	if (user == nullptr)
	{
		throw invalid_argument("No user called " + userName + " was found");
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
	//try catch
	User* user1 = findUser(userName1);
	User* user2 = findUser(userName2);
	if (user1==nullptr || user2 == nullptr)
	{
		throw invalid_argument("At least one of the users does not exist");
	}
	if (!user1->isFriendsWith(*user2))
	{
		throw invalid_argument("No friendship exist between " + userName1+ 
			" and " + userName2);
	}
	user1->unFriend(*user2);
}