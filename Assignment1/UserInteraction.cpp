#include "UserInteraction.h"
#include "Facebook.h"

UserInteraction::UserInteraction(Facebook& inputfacebook)
{
	facebook = &inputfacebook;
}
void UserInteraction::printMenu()								const
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
void UserInteraction::chooseFromMenu(int choice)
{
	switch (choice)
	{
	case 1: addUser();
		break;
	case 2: addFanpage();
		break;
	case 3:addTextStatus();
		break;
	case 4:showStatusOfEntity();
		break;
	case 5:showFriendStatus();
		break;
	case 6:addFriendship();
		break;
	case 7:cancelFriendship();
		break;
	case 8:addFanToPage();
		break;
	case 9:removeFanFromPage();
		break;
	case 10:facebook->showAllUsersAndFanpages();
		break;
	case 11: showAllFriendsOrFans();
		break;
	case 12: facebook->Exit();
		break;
	default: cout << "Invalid choice, choose again" << endl;
		break;
	}
}

void UserInteraction::showFriendStatus()
{
	User* user;
	char userName[NAME_LEN];
	cout << "Please enter the user name you would like to see his/her *all* friends 10 latest statuses:\n ";
	CleanBuffer();
	cin.getline(userName, NAME_LEN - 1);
	user = facebook->findUser(userName);
	if (user == nullptr)
	{
		cout << "User doesnt exist, returning to menu" << endl;
		return;
	}
	facebook->showFriendStatus(*user);
}
void UserInteraction::showStatusOfEntity()
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
		Fanpage* currentPage = facebook->findPage(name);
		if (currentPage == nullptr)
		{
			cout << "This page does not exist, returning to menu" << endl;
		}
		else
		{
			facebook->showStatusOfEntity(*currentPage);
		}
	}
	else
	{
		User* currentUser = facebook->findUser(name);
		if (currentUser == nullptr)
		{
			cout << "This user does not exist, returning to menu" << endl;
		}
		else
		{
			facebook->showStatusOfEntity(*currentUser);

		}
	}
}
void UserInteraction::showAllFriendsOrFans()
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
		Fanpage* currentPage = facebook->findPage(name);
		if (currentPage == nullptr)
		{
			cout << "No page called " << name << " was found, returning to menu." << endl;
			return;
		}
		facebook->showAllFans(*currentPage);
	}
	else
	{
		User* currentUser = facebook->findUser(name);
		if (currentUser == nullptr)
		{
			cout << "No user called " << name << " was found, returning to menu." << endl;
			return;
		}
		facebook->showAllFriends(*currentUser);
	}
}

void UserInteraction::addTextStatus()
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
		User* currentUser = facebook->findUser(userName);
		if (currentUser == nullptr)
		{
			cout << "No user called " << userName << " was found, returning to menu." << endl;
			return;
		}
		cout << "Enter Status: ";
		cin.getline(statusStr, STATUS_LEN - 1);
		Status* status = new Status(statusStr);
		facebook->addTextStatus(*currentUser, *status);
	}
	else                                    
	{
		cout << "Enter page's name: ";
		char pageName[NAME_LEN];
		cin.getline(pageName, NAME_LEN - 1);
		Fanpage* currentPage = facebook->findPage(pageName);
		if (currentPage == nullptr)
		{
			cout << "No page called " << pageName << " was found, returning to menu" << endl;
			return;
		}
		CleanBuffer();
		cout << "Enter Status: ";
		cin.getline(statusStr, STATUS_LEN - 1);
		Status* status = new Status(statusStr);
		facebook->addTextStatus(*currentPage,*status);
	}
}
void UserInteraction::addUser()      
{
	int day, month, year;
	char name[NAME_LEN];
	cout << "Please Enter the user's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	if (facebook->findUser(name) != nullptr)
	{
		cout << "This user already exists, returning to menu" << endl;
		return;
	}
	cout << "Please enter birthdate of the user (dd mm yy): ";
	cin >> day >> month >> year;
	Date* userDate = new Date(year, month, day);
	User* newUser = new User(name, *userDate);
	facebook->addUser(*newUser);
}
void UserInteraction::addFanToPage()
{
	char pageName[NAME_LEN];
	char fanName[NAME_LEN];
	cout << "To which page would you like to add a fan? ";
	CleanBuffer();
	cin.getline(pageName, NAME_LEN - 1);
	Fanpage* page = facebook->findPage(pageName);
	if (page == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	cout << "Which user would you like to add as a fan? ";
	CleanBuffer();
	cin.getline(fanName, NAME_LEN - 1);
	User* user = facebook->findUser(fanName);
	if (user == nullptr)
	{
		cout << "No user called " << fanName << " was found, returning to menu." << endl;
		return;
	}
	facebook->addFanToPage(*page, *user);
}
void UserInteraction::addFanpage()
{
	char name[NAME_LEN];
	cout << "Please enter the page's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	if (facebook->findPage(name) != nullptr)
	{
		cout << "This page already exists, returning to menu" << endl;
	}

	Fanpage* newPage = new Fanpage(name);
	facebook->addFanpage(*newPage);
}
void UserInteraction::addFriendship()   //to cancel the way of adding the same friend several times
{
	User* user1, * user2;
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to be friends:\n ";
	CleanBuffer();
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	user1 = facebook->findUser(userName1);
	user2 = facebook->findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "at least one of the users does not exits, returning to menu." << endl;
		return;
	}
	facebook->addFriendship(*user1, *user2);
}
void UserInteraction::removeFanFromPage()
{
	char pageName[NAME_LEN];
	char fanName[NAME_LEN];
	cout << "From which page would you like to remove a fan? ";
	CleanBuffer();
	cin.getline(pageName, NAME_LEN - 1);
	Fanpage* page = facebook->findPage(pageName);
	if (page == nullptr)
	{
		cout << "No page called " << pageName << " was found, returning to menu." << endl;
		return;
	}
	cout << "Which user would you like to remove as a fan? ";
	cin.getline(fanName, NAME_LEN - 1);
	User* user = facebook->findUser(fanName);
	if (user == nullptr)
	{
		cout << "No user called " << fanName << " was found, returning to menu." << endl;
		return;
	}
	facebook->removeFanFromPage(*page,*user);
}
void UserInteraction::cancelFriendship()
{
	User* user1, * user2;
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to unfriend each other:\n ";
	CleanBuffer();
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	user1 = facebook->findUser(userName1);
	user2 = facebook->findUser(userName2);
	if (user1 == nullptr || user2 == nullptr)
	{
		cout << "At least one of the users does not exist, returning to menu" << endl;
		return;
	}
	facebook->cancelFriendship(*user1, *user2);
}
