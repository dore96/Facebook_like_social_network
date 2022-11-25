#include "Facebook.h"
#define EXIT 12 

int main()
{
	Facebook myFacebook;
	int choice;
	do
	{
		myFacebook.userInterface.printMenu();
		cin >> choice;
		myFacebook.userInterface.chooseFromMenu(choice);
	} while (choice != EXIT);
	return 0;
}