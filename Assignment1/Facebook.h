#ifndef __Facebook_H
#define __Facebook_H
#include "UserInteraction.h"
#define EXIT 12 

class Facebook
{
public:
	Facebook();
	void runConsoleApp();
	//showing funcs
	void showAllUsers()										const;
	void showAllFanpage()									const;
	void showAllUsersAndFanpages()							const;
	void showFeed(const char* userName)				const;
	void showStatusOfEntity(bool isPage, const char* name)  const;
	void showAllLinks(const char* name)					const;
	void showAllFans(const char* pageName)   				const;
	void showAllFriendsOrFans(bool isPage,const char* name) const;

	//action funcs
	User* findUser(const char* name)						const;
	Fanpage* findPage(const char* name)						const;
	void Exit()												const;
	void addUser(char* userName, int day, int month, int year);
	void addFanpage(const char* pageName);
	void addFanToPage(const char* pageName, const char* userName);
	void addFriendship(const char* userName1, const char* userName2);
	void addTextStatus(bool isPage, const char* name,const char* textStatus);
	void cancelFriendship(const char* userName1, const char* userName2);
	void removeFanFromPage(const char* pageName, const char* userName);

	~Facebook();
	
private:
	User** UsersPtrArr;
	Fanpage** FanpagePtrArr;
	UserInteraction userInterface;
	int numberOfUsers, numberOfFanpage;
	int physicalNumberOfUsers, physicalNumberOfFanpage;

	void makeDoubleUserssSpace();
	void makeDoublePageSpace();
	Facebook(const Facebook& other);
};

#endif
