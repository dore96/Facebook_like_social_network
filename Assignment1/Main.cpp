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
		infile.close();
	}
	else
	{
		myFacebook = new Facebook(infile);
	}
	UserInteraction userInteraction(*myFacebook);
	userInteraction.runConsoleApp();
	delete myFacebook;
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}

