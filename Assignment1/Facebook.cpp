#include "Facebook.h"

Facebook::Facebook() : userInterface(*this)
{
	numberOfUsers = numberOfFanpage = 0;
	physicalNumberOfUsers = physicalNumberOfFanpage = InitNumber;
	UsersPtrArr = new User * [physicalNumberOfUsers];
	FanpagePtrArr = new Fanpage * [physicalNumberOfFanpage];

	addUser((char*)"dor",25,07,1996);
	addUser((char*)"maor",29,04,1999);
	addUser((char*)"tovia",04,8,2022);
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

	bool ans = (*(UsersPtrArr[0])).getStatuse(0) != (*(UsersPtrArr[0])).getStatuse(0);  // == 0r != statuses ( delete get status later)
	cout << ans;
	*(UsersPtrArr[0]) += *(UsersPtrArr[1]);				// += user check to users
	*(UsersPtrArr[0]) += *(UsersPtrArr[2]);  
	ans = *(UsersPtrArr[2]) < *(UsersPtrArr[0]);	// < or > user check to users
	cout << ans;
	*(FanpagePtrArr[0]) += *(UsersPtrArr[1]);			// += user check to fanpage
	*(FanpagePtrArr[0]) += *(UsersPtrArr[2]);
	*(FanpagePtrArr[1]) += *(UsersPtrArr[2]);
	ans = *(FanpagePtrArr[2]) < *(FanpagePtrArr[0]);	// < or > user check to users
	cout << ans;

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
		userInterface.printMenu();
		cin >> choice;
		userInterface.chooseFromMenu(choice);
	} while (choice != EXIT);

}

void Facebook::showAllUsers()									const
{
	cout << "Users: " << endl;
	for (int i = 0; i < numberOfUsers; i++)
	{
		cout << i + 1 << "." << UsersPtrArr[i]->getName() << endl;
	}
}
void Facebook::showAllFanpage()									const
{
	cout << "Fanpages: " << endl;
	for (int i = 0; i < numberOfFanpage; i++)
	{
		cout << i + 1 << "." << FanpagePtrArr[i]->getName() << endl;
	}
}
void Facebook::showAllUsersAndFanpages()						const
{
	showAllUsers();
	showAllFanpage();
}
void Facebook::showFeed(const char* userName)		    const
{
	User* user;
	user = findUser(userName);
	if (user == nullptr)
	{
		cout << "User doesnt exist, returning to menu" << endl;
		return;
	}
	user->showFriendsStatus(10);
	user->showPagesStatus(10);
}
void Facebook::showStatusOfEntity(bool isPage, const char* name) const
{
	if (isPage)
	{
		Fanpage* currentPage = findPage(name);
		if (currentPage == nullptr)
		{
			cout << "This page does not exist, returning to menu" << endl;
			return;
		}
		currentPage->showStatuses(); //shows all sattuses of a fanpage
	}
	else
	{
		User* currentUser = findUser(name);
		if (currentUser == nullptr)
		{
			cout << "This user does not exist, returning to menu" << endl;
			return;
		}
		currentUser->showStatuses(); //shows all sattuses of a user
	}
}
void Facebook::showAllFriendsOrFans(bool isPage, const char* name)const
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
void Facebook::showAllLinks(const char* userName)					const
{
	User* currentUser = findUser(userName);
	if (currentUser == nullptr)
	{
		cout << "No user called " << userName << " was found, returning to menu." << endl;
		return;
	}
	currentUser->showAllFriends();  //show all users friend listed.
	currentUser->showAllLikedPages();
}
void Facebook::showAllFans(const char* pageName)				    const
{
	Fanpage* currentPage = findPage(pageName);
	if (currentPage == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	currentPage->showAllFans();  //show all fans of a page
}

User* Facebook::findUser(const char* name)                      const
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		if (!strcmp(name, UsersPtrArr[i]->getName()))
		{//compare users by name (uniq)
			return UsersPtrArr[i];
		}
	}
	return nullptr;
}
Fanpage* Facebook::findPage(const char* name)                   const
{
	for (int i = 0; i < numberOfFanpage; i++)
	{
		if (!strcmp(name, FanpagePtrArr[i]->getName()))
		{//compare fanpages by name (uniq)
			return FanpagePtrArr[i];
		}
	}
	return nullptr;
}
void Facebook::Exit()                                           const
{
	cout << "Thank you for using FaceBook, goodbye !" << endl;
}

void Facebook::addTextStatus(bool isPage, const char* name, const char* textStatus)
{
	if (!isPage)
	{
		User* currentUser = findUser(name);
		if (currentUser == nullptr)
		{
			cout << "No user called " << name << " was found, returning to menu." << endl;
			return;
		}
		Status* status = new Status(textStatus); //creates a new status by input and adds it to user.
		currentUser->addStatus(*status);
	}
	else
	{
		Fanpage* currentPage = findPage(name);
		if (currentPage == nullptr)
		{
			cout << "No page called " << name << " was found, returning to menu" << endl;
			return;
		}
		Status* status = new Status(textStatus); //creates a new status by input and adds it to fanpage.
		currentPage->addStatus(*status);
	}
}
void Facebook::addUser(char* userName, int day, int month, int year)
{
	if (findUser(userName) != nullptr)
	{
		cout << "This user already exists, returning to menu" << endl;
		return;
	}
	Date userDate(day, month, year);  //creates a date.
	User* user = new User(userName, userDate);   //creats a user with given date (now)
	if (numberOfUsers >= physicalNumberOfUsers)
	{
		makeDoubleUserssSpace();
	}
	UsersPtrArr[numberOfUsers] = user;
	numberOfUsers++;
}
void Facebook::addFanToPage(const char* pageName, const char* userName)
{
	Fanpage* page = findPage(pageName);
	if (page == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	User* user = findUser(userName);
	if (user == nullptr)
	{
		cout << "No user called " << userName << " was found, returning to menu." << endl;
		return;
	}
	if (user->isFanOf(pageName))
	{
		cout << "User is already a fan of this page." << endl;
		return;
	}
	page->addFan(*user);
}
void Facebook::addFanpage(const char* pageName)
{
	if (findPage(pageName) != nullptr)
	{
		cout << "This page already exists, returning to menu" << endl;
	}
	Fanpage* newPage = new Fanpage(pageName);
	if (numberOfFanpage >= physicalNumberOfFanpage)
	{
		makeDoublePageSpace();
	}
	FanpagePtrArr[numberOfFanpage] = newPage;
	numberOfFanpage++;
}
void Facebook::addFriendship(const char* userName1, const char* userName2)
{
	User* user1 = findUser(userName1);
	User* user2 = findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "at least one of the users does not exits, returning to menu." << endl;
		return;
	}
	if (user1->isFriendsWith(user2->getName()))
	{
		cout << "Users are already friends." << endl;
	}
	else
	{
		user1->addFriend(*user2);
	}
}
void Facebook::removeFanFromPage(const char* pageName, const char* userName)
{
	Fanpage* page = findPage(pageName);
	if (page == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	User* user = findUser(userName);
	if (user == nullptr)
	{
		cout << "No user called " << userName << " was found, returning to menu." << endl;
		return;
	}
	if (!user->isFanOf(page->getName()))
	{
		cout << "No fan called " << user->getName() << " was found, returning to menu." << endl;
		return;
	}
	page->removeFan(*user);
}
void Facebook::cancelFriendship(const char* userName1, const char* userName2)
{
	User* user1 = findUser(userName1);
	User* user2 = findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "At least one of the users does not exist, returning to menu" << endl;
		return;
	}
	if (!user1->isFriendsWith(user2->getName()))
	{
		cout << "No friendship exist between " << user2->getName() <<
			" and " << user1->getName() << " returning to menu." << endl;
		return;
	}
	user1->unFriend(*user2);
}

void Facebook::makeDoubleUserssSpace()
{
	physicalNumberOfUsers *= 2;
	User** newFriendsPtrArr = new User * [physicalNumberOfUsers];
	for (int i = 0; i < numberOfUsers; i++)
	{
		newFriendsPtrArr[i] = UsersPtrArr[i];
	}
	delete[]UsersPtrArr;
	UsersPtrArr = newFriendsPtrArr;
}
void Facebook::makeDoublePageSpace()
{
	physicalNumberOfFanpage *= 2;
	Fanpage** newFanpagePtrArr = new Fanpage * [physicalNumberOfFanpage];
	for (int i = 0; i < numberOfFanpage; i++)
	{
		newFanpagePtrArr[i] = FanpagePtrArr[i];
	}
	delete[] FanpagePtrArr;
	FanpagePtrArr = newFanpagePtrArr;
}
Facebook::~Facebook()
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		delete UsersPtrArr[i];
	}
	for (int j = 0; j < numberOfFanpage; j++)
	{
		delete FanpagePtrArr[j];
	}
	delete[]UsersPtrArr;
	delete[]FanpagePtrArr;
}