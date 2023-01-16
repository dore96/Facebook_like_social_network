#ifndef __User_H
#define __User_H

#include "Entity.h" 
class Fanpage;									  //avoiding the two way include problam. (user - fanpage , fanpage - user)

class User : public Entity
{
public:
	User(const string& tryName, const Date &dateOfBirth); //constructor
	User(istream& in);
	//getters
	const Date& getBirthDate()								 const;
	int getNumberOfFriends()								 const;
	int getNumberOfFanpaegs()								 const;

	//printing funcs
	void showFriendsStatus(int numberOfPrintStatus = INT_MAX)const;
	void showPagesStatus(int numberOfPrintStatus = INT_MAX)	 const;
	void showAllFriends()									 const;
	void showAllFriends(ostream& os)						 const;
	void showAllLikedPages()								 const;
	void showAllLikedPages(ostream& os)						 const;

	//boolean funcs
	bool isFriendsWith(const User& isfriend)				const;
	bool isFanOf(const Fanpage& page)						const;

	//action funcs 
	void addFriend(User& addFriend);
	void unFriend(User& friendToRemove);
	void likeAPage(Fanpage& page);
	void unlikeAPage(Fanpage& page);

	virtual void toOs(ostream& os)const override;
	//Operators funcs
	const User& operator+=(User& addfriend);
	bool operator >(const User& other)						 const;
	bool operator >(const Fanpage& page)					 const;
	bool operator ==(const User& other)						 const;
	bool operator <(const User& other)						 const;
	bool operator <(const Fanpage& page)					 const;
	bool operator ==(const Fanpage& page)					 const;
private:
	Date dateOfBirth;
	list<const User*> friendsList;
	list<const Fanpage*> pageList;
};


#endif