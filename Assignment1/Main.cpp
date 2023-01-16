#include "UserInteraction.h"

void newTerminate()
{
	cout << "There was a unexpected error , exiting the program.";
	exit(1);
}

int main() 
{
	set_terminate(newTerminate);
	ifstream infile("saveFacebook.txt");
	Facebook myFacebook(infile);
	//Facebook myFacebook;
	UserInteraction userInteraction(myFacebook);
	userInteraction.runConsoleApp();
	return 0;
}

