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
	void AddUser(const char* name, int day, int month, int year); //overload only for init perpuses adding 3 users.
	void AddFanpage();
	void AddFanpage(const char* name);                            //overload only for init perpuses adding 3 fanpage.
	void ShowAllUsers()   const;
	void ShowAllFanpage() const;
	void ShowAllUsersAndFanpages()  const;
	void Exit()  const;
	void ShowFriendStatus();
	void AddFriendship();
	void AddFriendship(const char* name1, const char* name2);    //overload only for init perpuses adding friendship.
	void CancelFriendship();
	void addTextStatus();
	void addTextStatus(bool isPage, const char* statusStr, const char* userName);     //overload only for init perpuses adding statuses.
	void ShowStatusOfEntity();
	User* FindUser(const char* name);
	Fanpage* FindPage(const char* name);
	void showAllFriendsOrFans();
	void addFanToPage();
	void addFanToPage(const char* userName, const char* pageName);//overload only for init perpuses adding relasions.
	void removeFanFromPage();
	~Facebook();
private:
	Facebook(const Facebook& other);
	User** UsersPtrArr;
	Fanpage** FanpagePtrArr;
	int numberOfUsers, numberOfFanpage;
	int physicalNumberOfUsers, physicalNumberOfFanpage;
};

#endif
