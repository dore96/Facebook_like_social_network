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
	Facebook* myFacebook;
	if(infile.fail())
	{
		myFacebook = new Facebook();
		
	}
	else
	{
		myFacebook = new Facebook(infile);
		infile.close();
	}
	UserInteraction userInteraction(*myFacebook);
	userInteraction.runConsoleApp();
	delete myFacebook;
	return 0;
}

