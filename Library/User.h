#ifndef _USER_H_
#define _USER_H_
#include<string>
using namespace std;

class User {
public:
	string id;
	string name;
	string  password;
	bool priv;
	int booknum;
};
class UserQuery {
public:
	string id;
	string name;
	string  password;
	std::vector<User> Users;
};

class Manager {
public:
	string id;
	string name;
	string password;
};
#endif // !_USER_H_
