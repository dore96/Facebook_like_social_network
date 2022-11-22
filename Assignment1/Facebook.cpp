#include "Facebook.h"

Facebook::Facebook()
{
	numberOfUsers = numberOfFanpage = 0;
	phisNumberOfUsers = phisNumberOfFanpage = InitNumber;
	UsersPtrArr = new User*[phisNumberOfUsers];
	//fanpage;
}
int Facebook::ChooseFromMenu()
{
	int choice;
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
	cin >> choice;
	return choice;
}
void Facebook::AddUser()
{

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
void Facebook::AddUser()
{//לבדוק אם המשתמש כבר קיים ואז לא להוסיף?
	int day, month, year;
	char name[NAME_LEN];
	cout << "Please Enter the user's name: ";
	cin.getline(name, NAME_LEN - 1);
	CleanBuffer();
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
void Facebook::AddFanpage()
{

}
void Facebook::ShowAllUsers()
{
	for ( int i = 0; i < numberOfUsers; i++)
	{
		cout << i + 1 << "." << UsersPtrArr[i]->GetName() << endl;
	}
}
void Facebook::ShowAllFanpage()
{

}
void Facebook::ShowAllUsersAndFanpages()
{
	ShowAllUsers();
	ShowAllFanpage();
}
void Facebook::Exit()
{
	
}
Facebook::~Facebook()
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		delete UsersPtrArr[i];
	}
	delete []UsersPtrArr;
}