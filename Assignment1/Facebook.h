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
	void showAllUsers()										  const;
	void showAllFanpage()									  const;
	void showAllUsersAndFanpages()							  const;
	void showFeed(const string& userName)				      const;
	void showStatusOfEntity(bool isPage, const char* name)    const;
	void showAllLinks(const string& name)					  const;
	void showAllFans(const string& pageName)   				  const;
	void showAllFriendsOrFans(bool isPage,const string& name) const;

	//action funcs
	User* findUser(const string& name)						  const;
	Fanpage& findPage(const string& name);
	void Exit()												  const;
	void addUser(string& userName, int day, int month, int year);
	void addFanpage(const string& pageName);
	void addFanToPage(const string& pageName, const string& userName);
	void addFriendship(const string& userName1, const string& userName2);
	void addTextStatus(bool isPage, const string& name,const string& textStatus);
	void cancelFriendship(const string& userName1, const string& userName2);
	void removeFanFromPage(const string& pageName, const string& userName);

	~Facebook();
	
private:
	vector<User> usersVect;
	vector<Fanpage> fanpageVect;
	UserInteraction userInterface;
};

#endif
