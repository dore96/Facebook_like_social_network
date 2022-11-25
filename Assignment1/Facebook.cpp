#include "Facebook.h"

Facebook::Facebook() : userInterface(*this)
{
	numberOfUsers = numberOfFanpage = 0;
	physicalNumberOfUsers = physicalNumberOfFanpage = InitNumber;
	UsersPtrArr = new User * [physicalNumberOfUsers];
	FanpagePtrArr = new Fanpage * [physicalNumberOfFanpage];

	Date* dorBday = new Date(25, 07, 1996);
	Date* toviaBday = new Date(04, 8, 2022);
	Date* maorBday = new Date(29, 04, 1999);
	User* dor = new User((char*)"dor", *dorBday);
	User* maor = new User((char*)"maor", *maorBday);
	User* tovia = new User((char*)"tovia", *toviaBday);
	Fanpage* mta = new Fanpage("MTA course recomendations");
	Fanpage* Pro = new Fanpage("Pro yogurt");
	Fanpage* Merge = new Fanpage("Merge Halicod & Meretz");
	Status* a = new Status("c++ course is great");
	Status* b = new Status("OOP is cool");
	Status* c = new Status("no time in this course");
	Status* d = new Status("yammi");
	Status* e = new Status("a lot of protein");
	Status* f = new Status("new flavor");

	addUser(*dor);
	addUser(*maor);
	addUser(*tovia);
	addFanpage(*mta);
	addFanpage(*Pro);
	addFanpage(*Merge);
	addTextStatus(*mta, *a);
	addTextStatus(*mta, *b);
	addTextStatus(*Merge, *c);
	addTextStatus(*Merge, *d);
	addTextStatus(*Pro, *e);
	addTextStatus(*Pro, *f);
	addTextStatus(*dor, *a);
	addTextStatus(*dor, *b);
	addTextStatus(*tovia, *c);
	addTextStatus(*tovia, *d);
	addTextStatus(*maor, *e);
	addTextStatus(*maor, *f);
	addFriendship(*maor, *dor);
	addFriendship(*dor, *tovia);
	addFriendship(*tovia, *maor);
	addFanToPage(*Merge, *maor);
	addFanToPage(*Pro, *tovia);
	addFanToPage(*mta, *dor);
}

void Facebook::showAllUsers()									const
{
	cout << "Users: " << endl;
	for (int i = 0; i < numberOfUsers; i++)
	{
		cout << i + 1 << "." << UsersPtrArr[i]->getName() << endl;
	}
}
void Facebook::showAllFanpage()									const
{
	cout << "FanPages: " << endl;
	for (int i = 0; i < numberOfFanpage; i++)
	{
		cout << i + 1 << ".";
		FanpagePtrArr[i]->printName();
	}

}
void Facebook::showAllUsersAndFanpages()						const
{
	showAllUsers();
	showAllFanpage();
}
void Facebook::showFriendStatus(const User& user)				const
{
	user.showStatuses(10);
}
void Facebook::showStatusOfEntity(const User& user)				const
{
	user.showStatuses();
}
void Facebook::showStatusOfEntity(const Fanpage& fanpage)		const
{
	fanpage.showStatuses();
}
void Facebook::showAllFriends(const User& user)					const
{
	user.showAllFriends();
}
void Facebook::showAllFans(const Fanpage& fanpage)				const
{
	fanpage.showAllFans();
}

User* Facebook::findUser(const char* name)
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		if (!strcmp(name, UsersPtrArr[i]->getName()))
		{
			return UsersPtrArr[i];
		}
	}
	return nullptr;
}
Fanpage* Facebook::findPage(const char* name)
{
	for (int i = 0; i < numberOfFanpage; i++)
	{
		if (!strcmp(name, FanpagePtrArr[i]->getName()))
		{
			return FanpagePtrArr[i];
		}
	}
	return nullptr;
}
void Facebook::Exit() const
{
	cout << "Thank you for using FaceBook, goodbye !" << endl;
}

void Facebook::addTextStatus(User& user, const Status& status)
{
	user.addStatus(status);
}
void Facebook::addTextStatus(Fanpage& fanpage, const Status& status)
{
	fanpage.addStatus(status);
}
void Facebook::addUser(User& user)
{
	if (numberOfUsers >= physicalNumberOfUsers)
	{
		makeDoubleUserssSpace();
	}
	UsersPtrArr[numberOfUsers] = &user;
	numberOfUsers++;
}
void Facebook::addFanToPage(Fanpage& fanpage, User& user)
{
	if (user.isFanOf(fanpage.getName()))
	{
		cout << "User is already a fan of this page." << endl;
	}
	fanpage.addFan(user);
}
void Facebook::addFanpage(Fanpage& fanpage)
{
	if (numberOfFanpage >= physicalNumberOfFanpage)
	{
		makeDoublePageSpace();
	}
	FanpagePtrArr[numberOfFanpage] = &fanpage;
	numberOfFanpage++;
}
void Facebook::addFriendship(User& user1, User& user2)
{
	if (user1.isFriendsWith(user2.getName()))
	{
		cout << "Users are already friend." << endl;
	}
	else
	{
		user1.addFriend(user2);
	}
}
void Facebook::removeFanFromPage(Fanpage& fanpage, User& user)
{
	if (!user.isFanOf(fanpage.getName()))
	{
		cout << "No fan called " << user.getName() << " was found, returning to menu." << endl;
		return;
	}
	fanpage.removeFan(user);
}
void Facebook::cancelFriendship(User& user1, User& user2)
{
	if (!user1.isFriendsWith(user2.getName()))
	{
		cout << "No friendship exist between " << user2.getName() <<
			" and " << user1.getName() << " returning to menu." << endl;
		return;
	}
	user1.unFriend(user2);
}

void Facebook::makeDoubleUserssSpace()
{
	physicalNumberOfUsers *= 2;
	User** newFriendsPtrArr = new User * [physicalNumberOfUsers];
	for (int i = 0; i < numberOfUsers; i++)
	{
		newFriendsPtrArr[i] = UsersPtrArr[i];
	}
	delete[]UsersPtrArr;
	UsersPtrArr = newFriendsPtrArr;
}
void Facebook::makeDoublePageSpace()
{
	physicalNumberOfFanpage *= 2;
	Fanpage** newFanpagePtrArr = new Fanpage * [physicalNumberOfFanpage];
	for (int i = 0; i < numberOfFanpage; i++)
	{
		newFanpagePtrArr[i] = FanpagePtrArr[i];
	}
	delete[] FanpagePtrArr;
	FanpagePtrArr = newFanpagePtrArr;
}
Facebook::~Facebook()
{
	for (int i = 0; i < numberOfUsers; i++)
	{
		delete UsersPtrArr[i];
	}
	for (int j = 0; j < numberOfFanpage; j++)
	{
		delete FanpagePtrArr[j];
	}
	delete[]UsersPtrArr;
	delete[]FanpagePtrArr;
}