#include "Facebook.h"

Facebook::Facebook()
{
	numberOfUsers = numberOfFanpage = 0;
	physicalNumberOfUsers = physicalNumberOfFanpage = InitNumber;
	UsersPtrArr = new User * [physicalNumberOfUsers];
	FanpagePtrArr = new Fanpage * [physicalNumberOfFanpage];
}
void Facebook::PrintMenu() const
{
	cout << "Choose an action number from the above menu:" << endl;
	cout << "1.Add user" << endl;
	cout << "2.Add fanpage" << endl;
	cout << "3.Add status to a user or fanpage" << endl;
	cout << "4.Show all status of a user or fanpage" << endl;
	cout << "5.Show a user feed (10 most recent friend/fanpage status)" << endl;
	cout << "6.Add a friendship" << endl;
	cout << "7.Cancel a friendship" << endl;
	cout << "8.Add a fan to a fanpage" << endl;
	cout << "9.Delete a fan from fanpage" << endl;
	cout << "10.Show all users and fanpage" << endl;
	cout << "11.Show all frieds/fans of a User/Fanpage" << endl;
	cout << "12.Exit" << endl;
}
void  Facebook::ChooseFromMenu(int choice)
{
	switch (choice)
	{
	case 1: AddUser();
		break;
	case 2: AddFanpage();
		break;
	case 3:addTextStatus();
		break;
	case 4:ShowStatusOfEntity();
		break;
	case 5:ShowFriendStatus();
		break;
	case 6:AddFriendship();
		break;
	case 7:CancelFriendship();
		break;
	case 8:addFanToPage();
		break;
	case 9:removeFanFromPage();
		break;
	case 10:ShowAllUsersAndFanpages();
		break;
	case 11: showAllFriendsOrFans();
		break;
	case 12: Exit();
		break;
	default: cout << "Invalid choice, choose again" << endl;
		break;
	}
}
void Facebook::addTextStatus()
{
	bool isPage;
	char statusStr[STATUS_LEN];
	cout << "Press 1 to add status for a fanpage or 0 for a user: ";
	cin >> isPage;
	if (!isPage)
	{
		cout << "Enter user's name: ";
		char userName[NAME_LEN];
		CleanBuffer();
		cin.getline(userName, NAME_LEN - 1);
		User* currentUser = findUser(userName);
		if (currentUser == nullptr)
		{
			cout << "No user called " << userName << " was found, returning to menu." << endl;
			return;
		}
		cout << "Enter Status: ";
		cin.getline(statusStr, STATUS_LEN - 1);
		Status* status = new Status(statusStr);
		currentUser->addStatus(*status);
	}
	else                                       //double code - havent learnd inheritance
	{
		cout << "Enter page's name: ";
		char pageName[NAME_LEN];
		cin.getline(pageName, NAME_LEN - 1);
		Fanpage* currentPage = FindPage(pageName);
		if (currentPage == nullptr)
		{
			cout << "No page called " << pageName << " was found, returning to menu" << endl;
		}
		CleanBuffer();
		cout << "Enter Status: ";
		cin.getline(statusStr, STATUS_LEN - 1);
		Status* status = new Status(statusStr);
		currentPage->addStatus(*status);
	}
}
void Facebook::addTextStatus(bool isPage, const char* statusStr, const char* userOrPageName)
{//overload only for init perpuses adding statuses.
	if (!isPage)
	{
		User* currentUser = findUser(userOrPageName);
		if (currentUser == nullptr)
		{
			cout << "No user called " << userOrPageName << " was found, returning to menu." << endl;
			return;
		}
		Status* status = new Status(statusStr);
		currentUser->addStatus(*status);
	}
	else
	{
		Fanpage* currentPage = FindPage(userOrPageName);
		if (currentPage == nullptr)
		{
			cout << "No page called " << userOrPageName << " was found, returning to menu" << endl;
		}
		Status* status = new Status(statusStr);
		currentPage->addStatus(*status);
	}
}
void Facebook::AddUser()      //check user exist ? 
{
	int day, month, year;
	char name[NAME_LEN];
	cout << "Please Enter the user's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	if (findUser(name) != nullptr)
	{
		cout << "This user already exists, returning to menu" << endl;
		return;
	}
	cout << "Please enter birthdate of the user (dd mm yy): ";
	cin >> day >> month >> year;
	if (numberOfUsers >= physicalNumberOfUsers)
	{
		makeDoubleUserssSpace();
	}
	Date* userDate = new Date(year, month, day);
	User* newUser = new User(name, *userDate);
	UsersPtrArr[numberOfUsers] = newUser;
	numberOfUsers++;
}
void Facebook::AddUser(char* name, int day, int month, int year) //overload only for init perpuses adding 3 users.
{
	if (numberOfUsers >= physicalNumberOfUsers)
	{
		makeDoubleUserssSpace();
	}
	if (findUser(name) != nullptr)
	{
		cout << "This user already exists, returning to menu" << endl;
		return;
	}
	Date* userDate = new Date(year, month, day);
	User* newUser = new User(name, *userDate);
	UsersPtrArr[numberOfUsers] = newUser;
	numberOfUsers++;
}
void Facebook::ShowStatusOfEntity()
{
	bool isPage;
	cout << "Press 1 to show status for a fanpage or 0 for a user: ";
	cin >> isPage;
	CleanBuffer();
	cout << "Enter your name: ";
	char name[NAME_LEN];
	cin.getline(name, NAME_LEN - 1);
	if (isPage)
	{
		Fanpage* currentPage = FindPage(name);
		if (currentPage == nullptr)
		{
			cout << "This page does not exist, returning to menu" << endl;
		}
		else
		{
			currentPage->showStatuses();
		}
	}
	else
	{
		User* currentUser = findUser(name);
		if (currentUser == nullptr)
		{
			cout << "This user does not exist, returning to menu" << endl;
		}
		else
		{
			currentUser->showStatuses();
		}
	}
}
void Facebook::AddFanpage()
{
	char name[NAME_LEN];
	cout << "Please enter the page's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	if (numberOfFanpage >= physicalNumberOfFanpage)
	{
		makeDoublePageSpace();
	}
	if (FindPage(name) != nullptr)
	{
		cout << "This page already exists, returning to menu" << endl;
	}
	Fanpage* newPage = new Fanpage(name);
	FanpagePtrArr[numberOfFanpage] = newPage;
	numberOfFanpage++;
}
void Facebook::AddFanpage(const char* name)                            //overload only for init perpuses adding 3 fanpage.
{
	if (numberOfFanpage >= physicalNumberOfFanpage)
	{
		makeDoublePageSpace();
	}
	if (FindPage(name) != nullptr)
	{
		cout << "This page already exists, returning to menu" << endl;
	}
	Fanpage* newPage = new Fanpage(name);
	FanpagePtrArr[numberOfFanpage] = newPage;
	numberOfFanpage++;
}
void Facebook::ShowAllUsers() const
{
	cout << "Users: " << endl;
	for (int i = 0; i < numberOfUsers; i++)
	{
		cout << i + 1 << "." << UsersPtrArr[i]->getName() << endl;
	}
}
void Facebook::ShowAllFanpage() const
{
	cout << "FanPages: " << endl;
	for (int i = 0; i < numberOfFanpage; i++)
	{
		cout << i + 1 << ".";
		FanpagePtrArr[i]->printName();
	}

}
void Facebook::ShowFriendStatus()
{
	User* user;
	char userName[NAME_LEN];
	cout << "Please enter the user name you would like to see his/her *all* friends 10 latest statuses:\n ";
	CleanBuffer();
	cin.getline(userName, NAME_LEN - 1);
	user = findUser(userName);
	if (user == nullptr)
	{
		cout << "User doesnt exist, returning to menu" << endl;
	}
	user->showStatuses(10);
}
void Facebook::AddFriendship()   //to cancel the way of adding the same friend several times
{
	User* user1, * user2;
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to be friends:\n ";
	CleanBuffer();
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	user1 = findUser(userName1);
	user2 = findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "at least one of the users does not exits, returning to menu." << endl;
	}
	else if (!user1->isFriendsWith(userName2))
	{
		cout << "Users are not friend." << endl;
	}
	else
	{
		user1->addFriend(*user2);
	}
}
void Facebook::AddFriendship(const char* name1, const char* name2)
{//overload only for init perpuses adding friendship.
	User* user1, * user2;
	user1 = findUser(name1);
	user2 = findUser(name2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "at least one of the users does not exits, returning to menu." << endl;
	}
	else if (!user1->isFriendsWith(name2))
	{
		cout << "Users are not friend." << endl;
	}
	else
	{
		user1->addFriend(*user2);
	}
}
void Facebook::CancelFriendship()
{
	User* user1, * user2;
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to unfriend each other:\n ";
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	user1 = findUser(userName1);
	user2 = findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "At least one of the users does not exist, returning to menu" << endl;
	}
	else if (!user1->isFriendsWith(userName2))
	{
		cout << "Users are not friend, returning to menu" << endl;
	}
	else
	{
		user1->unFriend(*user2);
	}
}
void Facebook::ShowAllUsersAndFanpages() const
{
	ShowAllUsers();
	ShowAllFanpage();
}
User* Facebook::findUser(const char* name)
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		if (!strcmp(name, UsersPtrArr[i]->getName()))
		{
			return UsersPtrArr[i];
		}
	}
	cout << "User not found, nullptr returned" << endl;
	return nullptr;
}
Fanpage* Facebook::FindPage(const char* name)
{
	for (int i = 0; i < numberOfFanpage; i++)
	{
		if (!strcmp(name, FanpagePtrArr[i]->getName()))
		{
			return FanpagePtrArr[i];
		}
	}
	cout << "Page not found, nullptr returned" << endl;
	return nullptr;
}
void Facebook::Exit() const
{
	cout << "Thank you for using FaceBook, goodbye !" << endl;
}
void Facebook::showAllFriendsOrFans()
{
	bool isPage;
	cout << "Press 1 to add status for a fanpage or 0 for a user: ";
	cin >> isPage;
	CleanBuffer();
	cout << "Enter your name: ";
	char name[NAME_LEN];
	cin.getline(name, NAME_LEN - 1);
	if (isPage)
	{
		Fanpage* currentPage = FindPage(name);
		if (currentPage == nullptr)
		{
			cout << "No page called " << name << " was found, returning to menu." << endl;
			return;
		}
		currentPage->showAllFans();
	}
	else
	{
		User* currentUser = findUser(name);
		if (currentUser == nullptr)
		{
			cout << "No user called " << name << " was found, returning to menu." << endl;
			return;
		}
		currentUser->showAllFriends();
	}
}
void Facebook::addFanToPage()
{
	char pageName[NAME_LEN];
	char fanName[NAME_LEN];
	cout << "To which page would you like to add a fan? ";
	CleanBuffer();
	cin.getline(pageName, NAME_LEN - 1);
	Fanpage* page = FindPage(pageName);
	if (page == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	cout << "Which user would you like to add as a fan? ";
	CleanBuffer();
	cin.getline(fanName, NAME_LEN - 1);
	User* user = findUser(fanName);
	if (user == nullptr)
	{
		cout << "No user called " << fanName << " was found, returning to menu." << endl;
		return;
	}
	page->addFan(*user);
}
void Facebook::addFanToPage(const char* userName, const char* pageName)
{//overload only for adding inital entities.
	Fanpage* page = FindPage(pageName);
	page->addFan(*findUser(userName));
}
void Facebook::removeFanFromPage()
{
	char pageName[NAME_LEN];
	char fanName[NAME_LEN];
	cout << "From which page would you like to remove a fan? ";
	CleanBuffer();
	cin.getline(pageName, NAME_LEN - 1);
	Fanpage* page = FindPage(pageName);
	if (page == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	cout << "Which user would you like to remove as a fan? ";
	CleanBuffer();
	cin.getline(fanName, NAME_LEN - 1);
	User* user = findUser(fanName);
	if (user == nullptr)
	{
		cout << "No fan called " << fanName << " was found, returning to menu." << endl;
		return;
	}
	page->removeFan(*user);
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