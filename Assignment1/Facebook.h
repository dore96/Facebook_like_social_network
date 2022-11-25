#ifndef __Facebook_H
#define __Facebook_H
#include "UserInteraction.h"

class Facebook
{
public:
	Facebook();

	//showing funcs
	void showAllUsers()								const;
	void showAllFanpage()							const;
	void showAllUsersAndFanpages()					const;
	void showFriendStatus(const User& user)			const;
	void showStatusOfEntity(const User& user)		const;
	void showStatusOfEntity(const Fanpage& fanpage)	const;
	void showAllFriends(const User& user)			const;
	void showAllFans(const Fanpage& fanpage)		const;

	//action funcs
	User* findUser(const char* name);
	Fanpage* findPage(const char* name);
	void addUser(User& user);
	void addFanpage(Fanpage& fanpage);
	void addFanToPage(Fanpage& fanpage, User& user);
	void addFriendship(User& user1, User& user2);
	void addTextStatus(User& user, const Status& status);
	void addTextStatus(Fanpage& fanpage, const Status& status);
	void cancelFriendship(User& user1, User& user2);
	void removeFanFromPage(Fanpage& fanpage, User& user);
	void Exit()										const;

	~Facebook();
	UserInteraction userInterface;   
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
