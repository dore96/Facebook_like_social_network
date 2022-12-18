#ifndef __UserInteraction_H
#define __UserInteraction_H
#include "Fanpage.h"

class Facebook;

class UserInteraction
{
public:
	UserInteraction(Facebook& facebook);
	void printMenu()							const;
	void chooseFromMenu(int choice) noexcept(false);

	//show funcs
	void showFeed()                             const;
	void showStatusOfEntity()                   const;
	void showAllFriendsOrFans()                 const;

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
};
#endif
