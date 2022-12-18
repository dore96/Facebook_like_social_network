#include "Facebook.h"

void newTerminate()
{
	cout << "There was a unexpected error , exiting the program.";
	exit(1);
}

int main() 
{
	set_terminate(newTerminate);
	Facebook myFacebook;
	myFacebook.runConsoleApp();
	return 0;
}