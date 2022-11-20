#include "Facebook.h"

Facebook::Facebook()
{
	numberOfUsers = numberOfFanpage = 0;
	physicalNumberOfUsers = physicalNumberOfFanpage = InitNumber;
	UsersPtrArr = new User*[physicalNumberOfUsers];
	//fanpage;
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
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
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
void Facebook::AddUser()
{//לבדוק אם המשתמש כבר קיים ואז לא להוסיף?
	int day, month, year;
	char name[USER_NAME_LEN];
	cout << "Please Enter the users name: ";
	cin.getline(name, USER_NAME_LEN - 1);
	CleanBuffer();
	cout << "Please enter birthdate of the user (dd/mm/yy): ";
	cin >> day >> month >> year;
	if (numberOfUsers >= physicalNumberOfUsers)
	{
		makeDoubleSpace(UsersPtrArr, sizeof(User*), numberOfUsers);
	}
	User* newUser = new User(name,year,month,day);
	UsersPtrArr[numberOfUsers] = newUser;
	numberOfUsers++;
}
void Facebook::AddFanpage()
{

}
void Facebook::ShowAllUsers()
{
	cout << "Users: " << endl;
	for ( int i = 0; i < numberOfUsers; i++)
	{
		cout << i + 1 << "." << UsersPtrArr[i]->GetName() << endl;
	}
}
void Facebook::ShowAllFanpage()
{
	cout << "FanPages: " << endl;
}
void Facebook::ShowAllUsersAndFanpages()
{
	ShowAllUsers();
	ShowAllFanpage();
}
User* FindUser(char* name)
{
	
}
void Facebook::Exit()
{
	cout << "Thank you for using FaceBook" << endl;
	exit(1);
}
Facebook::~Facebook()
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		delete UsersPtrArr[i];
	}
	delete []UsersPtrArr;
}