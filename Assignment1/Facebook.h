#ifndef __Facebook_H
#define __Facebook_H
#include "UserInteraction.h"

#define NAME_LEN 50
#define STATUS_LEN 120

class Facebook
{
public:
	Facebook();
	void printMenu()							const;
	void chooseFromMenu(int choice);

	//showing funcs
	void showAllUsers()							const;
	void showAllFanpage()						const;
	void showAllUsersAndFanpages()				const;
	void showFriendStatus();
	void showStatusOfEntity();
	void showAllFriendsOrFans();

	//action funcs
	User* findUser(const char* name);
	Fanpage* findPage(const char* name);
	void addUser();
	void addFanpage();
	void addFanToPage();
	void addFriendship();
	void addTextStatus();
	void cancelFriendship();
	void removeFanFromPage();
	void Exit()									const;

	//admin funcs
	void addFanpage(const char* name);												  //overload only for init perpuses adding 3 fanpage.
	void addUser(char* name, int day, int month, int year);							  //overload only for init perpuses adding 3 users.
	void addFriendship(const char* name1, const char* name2);						  //overload only for init perpuses adding friendship.
	void addTextStatus(bool isPage, const char* statusStr, const char* userName);     //overload only for init perpuses adding statuses.
	void addFanToPage(const char* userName, const char* pageName);					  //overload only for init perpuses adding relasions.

	~Facebook();
private:
	User** UsersPtrArr;
	Fanpage** FanpagePtrArr;
	int numberOfUsers, numberOfFanpage;
	int physicalNumberOfUsers, physicalNumberOfFanpage;

	void makeDoubleUserssSpace();
	void makeDoublePageSpace();
	Facebook(const Facebook& other);
};

#endif
