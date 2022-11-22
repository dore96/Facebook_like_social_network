#include "Facebook.h"
#define EXIT 12 

void InitFacebook(Facebook& myFacebook); //initiating the facebook with initals entities as asked.
int main()
{
	Facebook myFacebook;
	int choice;
	InitFacebook(myFacebook);//initiating the facebook with initals entities as asked.
	do
	{
		myFacebook.PrintMenu();
		cin >> choice;
		myFacebook.ChooseFromMenu(choice);
	} while (choice != EXIT);
	return 0;
}

void InitFacebook(Facebook& myFacebook) //initiating the facebook with the needed arguments..
{
	myFacebook.AddUser("dor", 25, 07, 1996);
	myFacebook.AddUser("maor", 29, 04, 1999);
	myFacebook.AddUser("tovia", 04, 8, 2022);
	myFacebook.AddFanpage("MTA course recomendations");
	myFacebook.AddFanpage("Pro yogurt");
	myFacebook.AddFanpage("Merge Halicod & Meretz");
	myFacebook.addTextStatus(true, "c++ course is great", "MTA course recomendations");
	myFacebook.addTextStatus(true, "c++ course is ok", "MTA course recomendations");
	myFacebook.addTextStatus(true, "OOP is cool", "MTA course recomendations");
	myFacebook.addTextStatus(true, "yammi", "Pro yogurt");
	myFacebook.addTextStatus(true, "a lot of protein", "Pro yogurt");
	myFacebook.addTextStatus(true, "new flavor", "Pro yogurt");
	myFacebook.addTextStatus(true, "bibi loves zehava", "Merge Halicod & Meretz");
	myFacebook.addTextStatus(true, "bibi and tibi", "Merge Halicod & Meretz");
	myFacebook.addTextStatus(true, "where is gantz?", "Merge Halicod & Meretz");
	myFacebook.addTextStatus(false, "im tiered", "dor");
	myFacebook.addTextStatus(false, "lets go out", "dor");
	myFacebook.addTextStatus(false, "at the gym", "dor");
	myFacebook.addTextStatus(false, "done my homework", "maor");
	myFacebook.addTextStatus(false, "eating lunch", "maor");
	myFacebook.addTextStatus(false, "need to pee", "maor");
	myFacebook.addTextStatus(false, "bark", "tovia");
	myFacebook.addTextStatus(false, "bark bark", "tovia");
	myFacebook.addTextStatus(false, "whof", "tovia");
	myFacebook.AddFriendship("dor", "maor");
	myFacebook.AddFriendship("dor", "tovia");
	myFacebook.AddFriendship("tovia", "maor");
	myFacebook.addFanToPage("maor", "Merge Halicod & Meretz");
	myFacebook.addFanToPage("tovia", "Pro yogurt");
	myFacebook.addFanToPage("dor", "MTA course recomendations");

}