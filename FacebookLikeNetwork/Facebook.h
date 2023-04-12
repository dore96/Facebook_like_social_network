#ifndef __Facebook_H
#define __Facebook_H
#include "Fanpage.h"

class Facebook
{
public:
	Facebook();
	//showing funcs
	void showAllUsers()										  const;
	void showAllFanpage()									  const;
	void showAllUsersAndFanpages()							  const;
	void showFeed(const string& userName)					  const noexcept(false);
	void showStatusOfEntity(bool isPage, const string& name)  const noexcept(false);
	void showAllLinks(const string& name)					  const noexcept(false);
	void showAllFans(const string& pageName)   				  const noexcept(false);
	void showAllFriendsOrFans(bool isPage,const string& name) const noexcept(false);

	//action funcs
	User* findUser(const string& name);
	const User* findUser(const string& name)				  const;
	Fanpage* findPage(const string& name);
	const Fanpage* findPage(const string& name)				  const;

	void addUser(const string& userName, int day, int month, int year)			noexcept(false);
	void addFanpage(const string& pageName)										noexcept(false);
	void addFanToPage(const string& pageName, const string& userName)			noexcept(false);
	void addFriendship(const string& userName1, const string& userName2)		noexcept(false);
	void addTextStatus(bool isPage, const string& name,const string& textStatus)noexcept(false);
	void cancelFriendship(const string& userName1, const string& userName2)		noexcept(false);
	void removeFanFromPage(const string& pageName, const string& userName)		noexcept(false);
	
private:
	list<User> usersInSystem;
	list<Fanpage> fanpagesInSystem;
};

#endif
