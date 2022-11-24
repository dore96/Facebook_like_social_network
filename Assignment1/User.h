#ifndef __User_H
#define __User_H

#include "Status.h" 
class Fanpage;														 //avoiding the two way include problam. (user - fanpage , fanpage - user)
const int InitNumber = 10;

class User
{
public:
	User(char* tryName, const Date &dateOfBirth);							//constructor 
	const Date& getBirthDate()								const;
	int getNumberOfStatus()		     						const;
	int getNumberOfFriends()								const;
	const char* getName()									const;

	void printName()										const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	const;
	void showFriendsStatus(int numberOfPrintStatus)			const;
	void showAllFriends()									const;

	bool isFriendsWith(const char* friendName)				const;
	bool isFanOf(const char* pageName)                      const;

	void addFriend(User& addFriend);								 //recive by refrence
	void addStatus(const Status& status);
	void unFriend(User& friendToRemove);
	void likeAPage(Fanpage& page);
	void unlikeAPage(Fanpage& page);
	
	~User();														//Destructor
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