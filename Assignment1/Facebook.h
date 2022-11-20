#ifndef __Facebook_H
#define __Facebook_H
#include "Fanpage.h"
#define NAME_LEN 50
#define STATUS_LEN 120

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
	void addTextStatus();
	void Facebook::ShowStatusOfEntity();
	User* FindUser(const char* name);
	Fanpage* FindPage(const char* name);
	~Facebook();
private:
	User** UsersPtrArr;
	Fanpage** FanpagePtrArr;
	int numberOfUsers, numberOfFanpage;
	int physicalNumberOfUsers, physicalNumberOfFanpage;
};

#endif
