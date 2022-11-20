#ifndef __Facebook_H
#define __Facebook_H
#include "Fanpage.h"
#define NAME_LEN 50
#define STATUS_LEN 120

class Facebook
{
public:
	Facebook();
	void PrintMenu()      const;
	void ChooseFromMenu(int choice);
	void AddUser();
	void AddFanpage();
	void ShowAllUsers()   const;
	void ShowAllFanpage() const;
	void ShowAllUsersAndFanpages()  const;
	void Exit()  const;
	void addTextStatus();
	void ShowStatusOfEntity();
	User* FindUser(const char* name);
	Fanpage* FindPage(const char* name);
	void showAllFriendsOrFans();
	void addFanToPage();
	void removeFanFromPage();
	~Facebook();
private:
	User** UsersPtrArr;
	Fanpage** FanpagePtrArr;
	int numberOfUsers, numberOfFanpage;
	int physicalNumberOfUsers, physicalNumberOfFanpage;
};

#endif
