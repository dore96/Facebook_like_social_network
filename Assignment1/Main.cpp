#include "Facebook.h"
#define EXIT 12 
//create another class for user interaction
void InitFacebook(Facebook& myFacebook); //initiating the facebook with initals entities as asked.
int main()
{
	Facebook myFacebook;
	int choice;
	InitFacebook(myFacebook);//initiating the facebook with initals entities as asked.
	do
	{
		myFacebook.printMenu();
		cin >> choice;
		myFacebook.chooseFromMenu(choice);
	} while (choice != EXIT);
	return 0;
}

void InitFacebook(Facebook& myFacebook) //initiating the facebook with the needed arguments..
{
	char dor[4] = { "dor"};
	char maor[5] = { "maor" };
	char tovia[6] = { "tovia" };
	myFacebook.addUser(dor, 25, 07, 1996);
	myFacebook.addUser(maor, 29, 04, 1999);
	myFacebook.addUser(tovia, 04, 8, 2022);
	myFacebook.addFanpage("MTA course recomendations");
	myFacebook.addFanpage("Pro yogurt");
	myFacebook.addFanpage("Merge Halicod & Meretz");
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
	myFacebook.addFriendship("dor", "maor");
	myFacebook.addFriendship("dor", "tovia");
	myFacebook.addFriendship("tovia", "maor");
	myFacebook.addFanToPage("maor", "Merge Halicod & Meretz");
	myFacebook.addFanToPage("tovia", "Pro yogurt");
	myFacebook.addFanToPage("dor", "MTA course recomendations");

}