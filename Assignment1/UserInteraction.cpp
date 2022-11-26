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
	cout << "10.Show all users and fanpages" << endl;
	cout << "11.Show all friends/fans of a User/Fanpage" << endl;
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
	char userName[NAME_LEN];
	cout << "Please enter the user name you would like to see his/her *all* friends 10 latest statuses:\n ";
	CleanBuffer();
	cin.getline(userName, NAME_LEN - 1);
	facebook->showFriendStatus(userName);
}
void UserInteraction::showStatusOfEntity()
{
	bool isPage;
	cout << "Press 0 to show status for a user or 1 for a fanpage: ";
	cin >> isPage;
	CleanBuffer();
	cout << "Enter your name: ";
	char name[NAME_LEN];
	cin.getline(name, NAME_LEN - 1);
	facebook->showStatusOfEntity(isPage, name);
}
void UserInteraction::showAllFriendsOrFans()
{
	bool isPage;
	cout << "Press 1 to see all fans of a page or 0 to see users friends ";
	cin >> isPage;
	CleanBuffer();
	cout << "Enter your name: ";
	char name[NAME_LEN];
	cin.getline(name, NAME_LEN - 1);
	facebook->showAllFriendsOrFans(isPage, name);
}

void UserInteraction::addTextStatus()
{
	bool isPage;
	char statusStr[STATUS_LEN];
	cout << "Press 1 to add status for a fanpage or 0 for a user: ";
	cin >> isPage;
	char name[NAME_LEN];
	cout << "Enter its name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	cout << "Enter Status: ";
	cin.getline(statusStr, STATUS_LEN - 1);
	facebook->addTextStatus(isPage, name, statusStr);  //adds a status to user/fanpage
}
void UserInteraction::addUser()      
{
	int day, month, year;
	char name[NAME_LEN];
	cout << "Please Enter the user's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	cout << "Please enter birthdate of the user (dd mm yy): ";
	cin >> day >> month >> year;
	facebook->addUser(name,day,month,year);  //addes new user to system
}
void UserInteraction::addFanToPage()
{
	char pageName[NAME_LEN];
	char fanName[NAME_LEN];
	cout << "To which page would you like to add a fan? ";
	CleanBuffer();
	cin.getline(pageName, NAME_LEN - 1);
	cout << "Which user would you like to add as a fan? ";
	CleanBuffer();
	cin.getline(fanName, NAME_LEN - 1);
	facebook->addFanToPage(pageName, fanName);  //addes user to panpage and vice versa.
}
void UserInteraction::addFanpage()
{
	char name[NAME_LEN];
	cout << "Please enter the page's name: ";
	CleanBuffer();
	cin.getline(name, NAME_LEN - 1);
	facebook->addFanpage(name);
}
void UserInteraction::addFriendship()
{
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to be friends:\n ";
	CleanBuffer();
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	facebook->addFriendship(userName1, userName2);
}
void UserInteraction::removeFanFromPage()
{
	char pageName[NAME_LEN];
	char fanName[NAME_LEN];
	cout << "From which page would you like to remove a fan? ";
	CleanBuffer();
	cin.getline(pageName, NAME_LEN - 1);
	cout << "Which user would you like to remove as a fan? ";
	cin.getline(fanName, NAME_LEN - 1);
	facebook->removeFanFromPage(pageName, fanName);  //removes fan from fanpage and vice versa.
}
void UserInteraction::cancelFriendship()
{
	char userName1[NAME_LEN], userName2[NAME_LEN];
	cout << "Please enter the two user names you would like to unfriend each other:\n ";
	CleanBuffer();
	cin.getline(userName1, NAME_LEN - 1);
	cin.getline(userName2, NAME_LEN - 1);
	facebook->cancelFriendship(userName1, userName2);  //cancel friendship to both users
}
