#ifndef __User_H
#define __User_H

#include "Status.h" 
class Fanpage;									  //avoiding the two way include problam. (user - fanpage , fanpage - user)

class User
{
public:
	User(const string& tryName, const Date &dateOfBirth); //constructor
	//getters
	const Date& getBirthDate()								 const;
	int getNumberOfStatus()		     						 const;
	int getNumberOfFriends()								 const;
	const string& getName()									 const;

	//printing funcs
	void printName()										 const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	 const;
	void showFriendsStatus(int numberOfPrintStatus = INT_MAX)const;
	void showPagesStatus(int numberOfPrintStatus = INT_MAX)	 const;
	void showAllFriends()									 const;
	void showAllLikedPages()								 const;

	//boolean funcs
	bool isFriendsWith(const User& isfriend)			 const;
	bool isFanOf(const Fanpage& page)                     const;

	//action funcs 
	void addFriend(User& addFriend);
	void addStatus(const string& status);		  //statusText is not able to change after creation - therefor const &
	void unFriend(User& friendToRemove);
	void likeAPage(Fanpage& page);
	void unlikeAPage(Fanpage& page);
	
	//Operators funcs
	const User& operator+=(User& addfriend);
	bool operator >(const User& other)						 const;
	bool operator >(const Fanpage& page)					 const;
	bool operator ==(const User& other)						 const;
	bool operator <(const User& other)						 const;
	bool operator <(const Fanpage& page)					 const;
	bool operator ==(const Fanpage& page)					 const;
private:
	const Date dateOfBirth;
	string name;
	vector<Status> statusVect;
	list<const User*> friendsList;
	list<const Fanpage*> pageList;

	void setName(const string& tryName)  noexcept(false);
};


#endif
