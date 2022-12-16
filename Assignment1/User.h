#ifndef __User_H
#define __User_H

#include "Status.h" 
class Fanpage;									  //avoiding the two way include problam. (user - fanpage , fanpage - user)
const int InitNumber = 10;						  //initiation number for the size of arrays of users,statuses and fanpages

class User
{
public:
	User(char* tryName, const Date &dateOfBirth); //constructor 
	//getters
	const Date& getBirthDate()								 const;
	int getNumberOfStatus()		     						 const;
	int getNumberOfFriends()								 const;
	const char* getName()									 const;

	//printing funcs
	void printName()										 const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	 const;
	void showFriendsStatus(int numberOfPrintStatus = INT_MAX)const;
	void showPagesStatus(int numberOfPrintStatus = INT_MAX)	 const;
	void showAllFriends()									 const;
	void showAllLikedPages()								 const;

	//boolean funcs
	bool isFriendsWith(const char* friendName)				 const;
	bool isFanOf(const char* pageName)                       const;

	//action funcs 
	void addFriend(User& addFriend);
	void addStatus(const Status& status);		  //statusText is not able to change after creation - therefor const &
	void unFriend(User& friendToRemove);
	void likeAPage(Fanpage& page);
	void unlikeAPage(Fanpage& page);
	
	//Operators funcs
	const User& operator+=(User& addfriend);
	bool operator >(const User& other)						 const;
	bool operator <(const User& other)						 const;
	const Status& getStatuse(int index) 					 const; //checking perpuse
	~User();														
private:
	int numberOfFriends, numberOfStatus,numberOfLikedPages;
	int physicalNumberOfFriends, physicalNumberOfStatus,physicalNumberOfLikedPages;
	const Date dateOfBirth;
	char* name;
	const Status** statusPtrArr;
	const User** friendsPtrArr;
	const Fanpage** fanpagePtrArr;

	bool setName(char* tryName);                               
	void makeDoubleFriendsSpace();
	void makeDoubleStatusSpace();
	void makeDoublePageSpace();
	User(const User&);												 //disable the possibility of user copy.
};


#endif