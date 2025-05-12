#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void copyCharArr(string s, char *res, int size)
{
    int s_length = s.length();
	for (int i = 0; i < size && i < s_length; i++)
	{
		*(res + i) = s[i];
	}
	res[s_length < size ? s_length : size] = '\0';
}
template <class T>
int find_smallest_idle_id(string filename, T &temp, int object_size)
{
	fstream in(filename, ios::binary | ios::in);
	int position;

    int i = 0;
    if(in.is_open()) {
	    for(; in.read(reinterpret_cast<char *>(&temp), object_size); i++) {} // iterates until no object is found
    }
	in.close();
	return i + 1;
}

class User
{
protected:
	int ID;
	char name[31];
	char email[31];
	char password[31];

public:
	User()
	{
		ID = 0;
	}
	User(string name, string email, string password)
	{
		set_name(name);
		set_password(password);
		set_email(email);
	}

	int get_ID()
	{
		return this->ID;
	}
	
	string get_name() {
	    string name_str(this->name);
	    return name_str;
	}

	string get_password()
	{
	    string pass_str (this->password);
	   // cout << password << endl;
		return pass_str;
	}

	string get_email() {
	    string email_str(this->email);
	    return email_str;
	}

	void set_ID(int ID) {
	    this->ID = ID;
	};
	
	void set_name(string name) {
	    copyCharArr(name, this->name, 30);
	}

	void set_password(string password) {
	    copyCharArr(password, this->password, 30);
	}

	void set_email(string email) {
	    copyCharArr(email, this->email, 30);
	}

    static bool validate_credentials(int, string );
    
	bool validate_login();
};
