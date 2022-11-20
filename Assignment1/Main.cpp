#include "Facebook.h"
#define EXIT 12 

//ptr arr const question.
int main()
{
	Facebook myFacebook;
	int choice;
	do
	{
		myFacebook.PrintMenu();
		cin >> choice;
		myFacebook.ChooseFromMenu(choice);
	} while (choice != EXIT);
	return 0;
}

