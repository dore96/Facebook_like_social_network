#include "Facebook.h"

Facebook::Facebook()
{
	numberOfUsers = numberOfFanpage = 0;
	physicalNumberOfUsers = physicalNumberOfFanpage = InitNumber;
	UsersPtrArr = new User * [physicalNumberOfUsers];
	FanpagePtrArr = new Fanpage * [physicalNumberOfFanpage];
}
void Facebook::PrintMenu()
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
	case 8:
		break;
	case 9:
		break;
	case 10:
		ShowAllUsersAndFanpages();
		break;
	case 11:
		break;
	case 12: Exit();
		break;
	default: cout << "Invalid choice" << endl;
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
		User* currentUser = FindUser(userName);
		if (currentUser != nullptr)
		{
			cout << "Enter Status: ";
			cin.getline(statusStr, STATUS_LEN - 1);
			Status* status = new Status(statusStr);
			currentUser->AddStatus(status);
		}
	}
	else                                       //double code - havent learnd inheritance
	{
		cout << "Enter page's name: ";
		char pageName[NAME_LEN];
		cin.getline(pageName, NAME_LEN - 1);
		Fanpage* currentPage = FindPage(pageName);
		CleanBuffer();
		if (currentPage != nullptr)
		{
			cout << "Enter Status: ";
			cin.getline(statusStr, STATUS_LEN - 1);
			Status* status = new Status(statusStr);
			currentPage->addStatus(status);
		}
	}

}
void Facebook::AddUser()      //check user exist ? 
{
	int day, month, year;
	char name[NAME_LEN];
	cout << "Please Enter the user's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	cout << "Please enter birthdate of the user (dd mm yy): ";
	cin >> day >> month >> year;
	if (numberOfUsers >= physicalNumberOfUsers)
	{
		makeDoubleSpace((void**)UsersPtrArr, sizeof(User*), physicalNumberOfUsers);
	}
	User* newUser = new User(name, year, month, day);
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
		currentPage->showAllStatus();
	}
	else
	{
		User* currentUser = FindUser(name);
		currentUser->ShowAllStatus();
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
		makeDoubleSpace((void**)FanpagePtrArr, sizeof(Fanpage*), physicalNumberOfFanpage);
	}
	Fanpage* newPage = new Fanpage(name);
	FanpagePtrArr[numberOfFanpage] = newPage;
	numberOfFanpage++;
}
void Facebook::ShowAllUsers()
{
	cout << "Users: " << endl;
	for (int i = 0; i < numberOfUsers; i++)
	{
		cout << i + 1 << "." << UsersPtrArr[i]->GetName() << endl;
	}
}
void Facebook::ShowAllFanpage()
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
	cin.getline(userName, NAME_LEN -1);
	user = FindUser(userName);
	if(user != nullptr)
		user->ShowFriendsStatus(10);
}
void Facebook::AddFriendship()   //to cancel the way of adding the same friend several times
{
	User* user1, *user2;
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to be friends:\n ";
	CleanBuffer();
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	user1 = FindUser(userName1);
	user2 = FindUser(userName2);
	if (user1 != nullptr && user2 != nullptr)
	{
		user1->AddFriend(user2);   //pointer dead at the end of func ? 
		user2->AddFriend(user1);
	}
}
void Facebook::CancelFriendship() 
{
	User* user1, * user2;
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to unfriend each other:\n ";
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	user1 = FindUser(userName1);
	user2 = FindUser(userName2);
	if (user1 != nullptr && user2 != nullptr)
	{
		user1->UnFriend(user2->GetName());   //is it the best way ? double searching.
		user2->UnFriend(user1->GetName());
	}
}
void Facebook::ShowAllUsersAndFanpages()
{
	ShowAllUsers();
	ShowAllFanpage();
}
User* Facebook::FindUser(const char* name)
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		if (!strcmp(name, UsersPtrArr[i]->GetName()))
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
void Facebook::Exit()
{
	cout << "Thank you for using FaceBook, goodbye !" << endl;
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