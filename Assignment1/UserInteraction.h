#ifndef __UserInteraction_H
#define __UserInteraction_H
#include "Fanpage.h"

#define NAME_LEN 50
#define STATUS_LEN 120

class Facebook;

class UserInteraction
{
public:
	UserInteraction(Facebook& facebook);
	void printMenu()							const;
	void chooseFromMenu(int choice);

	//show funcs
	void showFriendStatus();
	void showStatusOfEntity();
	void showAllFriendsOrFans();

	//action funcs
	void addTextStatus();
	void addUser();
	void addFanToPage();
	void addFanpage();
	void addFriendship();
	void removeFanFromPage();
	void cancelFriendship();

private:
	Facebook* facebook;
	UserInteraction(const UserInteraction& other);
};
#endif
