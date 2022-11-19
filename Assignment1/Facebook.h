#ifndef __Facebook_H
#define __Facebook_H
#include "User.h"
//include fanpage

class Facebook
{
public:
	Facebook();
	void PrintMenu();
	void ChooseFromMenu(int choice);
	void AddUser();
	void AddFanpage();
	void ShowAllUsers();
	void ShowAllFanpage();
	void ShowAllUsersAndFanpages();
	void Exit();
	~Facebook();
private:
	User** UsersPtrArr;
	//fanpage;
	int numberOfUsers, numberOfFanpage;
	int phisNumberOfUsers, phisNumberOfFanpage;
};

#endif
