#ifndef __Facebook_H
#define __Facebook_H
#include "User.h"
#define USER_NAME_LEN 50
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
	User* FindUser(char* name);
	~Facebook();
private:
	User** UsersPtrArr;
	//fanpage;
	int numberOfUsers, numberOfFanpage;
	int physicalNumberOfUsers, physicalNumberOfFanpage;
};

#endif
