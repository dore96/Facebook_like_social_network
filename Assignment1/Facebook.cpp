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