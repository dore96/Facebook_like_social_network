#include "UserInteraction.h"
#include "Facebook.h"

UserInteraction::UserInteraction(Facebook& inputfacebook)
{
	facebook = &inputfacebook;
}
void UserInteraction::runConsoleApp()
{
	int choice;
	do
	{
		try
		{
			printMenu();
			cin >> choice;
			chooseFromMenu(choice);
		}
		catch (invalid_argument& e)
		{
			cout << "Invalid argument:" << e.what() << endl;
		}
		catch (out_of_range& e)
		{
			cout << "Out of range:" << e.what() << endl;
		}
		catch (generalFacebookException& e)
		{//all the inherit exceptions will search for their virtual override "what" func
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "There was a unexpected error, please try again." << endl;
		}

	} while (choice != EXIT);

}
void UserInteraction::printMenu()								const
{
	cout << "Choose an action number from the above menu:" << endl;
	cout << "1.Add user" << endl;
	cout << "2.Add fanpage" << endl;
	cout << "3.Add a status to a user or fanpage" << endl;
	cout << "4.Show all statuses of a user or fanpage" << endl;
	cout << "5.Show a user feed (10 most recent friend/fanpage statuses)" << endl;
	cout << "6.Add a friendship" << endl;
	cout << "7.Cancel a friendship" << endl;
	cout << "8.Add a fan to a fanpage" << endl;
	cout << "9.Delete a fan from fanpage" << endl;
	cout << "10.Show all users and fanpages" << endl;
	cout << "11.Show all friends/fans of a User/Fanpage" << endl;
	cout << "12.Exit" << endl;
}
void UserInteraction::chooseFromMenu(int choice) noexcept(false)
{
	switch (choice)
	{
	case 1: addUser();
		break;
	case 2: addFanpage();
		break;
	case 3:addStatus();
		break;
	case 4:showStatusOfEntity();
		break;
	case 5:showFeed();
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
	case 12: Exit();
		break;
	default: throw out_of_range(" choice needs to bo between 1 - 12");
	}
}

void UserInteraction::showFeed()                   const
{
	string userName;
	cout << "Please enter the user name you would like to see his/her *all* friends 10 latest statuses:\n ";
	CleanBuffer();
	getline(cin, userName);
	facebook->showFeed(userName);
}
void UserInteraction::showStatusOfEntity()         const
{
	bool isPage;
	string name;
	cout << "Press 0 to show statuses of a user or 1 for a fanpage: ";
	cin >> isPage;
	CleanBuffer();
	cout << "Enter your name: ";
	getline(cin, name);
	facebook->showStatusOfEntity(isPage, name);
}
void UserInteraction::showAllFriendsOrFans()       const
{
	bool isPage;
	cout << "Press 1 to see all fans of a page or 0 to see users friends and liked pages ";
	cin >> isPage;
	CleanBuffer();
	cout << "Enter your name: ";
	string name;
	getline(cin, name);
	facebook->showAllFriendsOrFans(isPage, name);
}

void UserInteraction::addStatus()
{
	bool isPage;
	int statusType;
	string statusStr, name, statusUrl;
	cout << "Press 1 to add status for a fanpage or 0 for a user: ";
	cin >> isPage;
	cout << "Press 0 to add text status, 1 for image status, 2 for video status:";
	cin >> statusType;
	cout << "Enter its name: ";
	CleanBuffer();
	getline(cin, name);
	cout << "Enter Status text: ";
	getline(cin , statusStr);
	switch(statusType)
	{
	case text:
		facebook->addTextStatus(isPage, name, statusStr);  //adds a statusText to user/fanpage
		break;
	case image:
	case video:
		cout << "Enter Media url: ";
		getline(cin, statusUrl);
		facebook->addMediaStatus(isPage, name, statusStr, statusUrl, statusType);
		break;
	default:
		throw invalid_argument("invalid status type");
	}
}
void UserInteraction::addUser()      
{
	int day, month, year;
	string name;
	cout << "Please Enter the user's name: ";
	CleanBuffer();
	getline(cin, name);
	cout << "Please enter birthdate of the user (dd mm yy): ";
 	cin >> day >> month >> year;
	facebook->addUser(name,day,month,year);  //addes new user to system
}
void UserInteraction::addFanToPage()
{
	string pageName,fanName;
	cout << "To which page would you like to add a fan? ";
	CleanBuffer();
	getline(cin, pageName);
	cout << "Which user would you like to add as a fan? ";
	getline(cin, fanName);
	facebook->addFanToPage(pageName, fanName);  //addes user to panpage and vice versa.
}
void UserInteraction::addFanpage()
{
	string name;
	cout << "Please enter the page's name: ";
	CleanBuffer();
	getline(cin, name);
	facebook->addFanpage(name);
}
void UserInteraction::addFriendship()
{
	string userName1, userName2;
	CleanBuffer();
	cout << "Please enter the first user name: ";
	getline(cin, userName1);
	cout << "Please enter the second user name: ";
	getline(cin, userName2);
	facebook->addFriendship(userName1, userName2);
}
void UserInteraction::removeFanFromPage()
{
	string pageName, fanName;
	cout << "From which page would you like to remove a fan? ";
	CleanBuffer();
	getline(cin, pageName);
	cout << "Which user would you like to remove as a fan? ";
	getline(cin, fanName);
	facebook->removeFanFromPage(pageName, fanName);  //removes fan from fanpage and vice versa.
}
void UserInteraction::cancelFriendship()
{
	string userName1, userName2;
	CleanBuffer();
	cout << "Please enter the first user name: ";
	getline(cin, userName1);
	cout << "Please enter the second user name: ";
	getline(cin, userName2);
	facebook->cancelFriendship(userName1, userName2);  //cancel friendship to both users
}
void UserInteraction::Exit()						const
{
	cout << "Thank you for using FaceBook, goodbye !" << endl;
}
