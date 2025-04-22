#pragma once
#include <iostream>
using namespace std;

class User
{
protected:
    string name, email, password;
    // string u_name, u_email, u_create_password, u_confirm_password, u_skills, u_level;
    // string em_com_location, em_looking_for;
    virtual string get_string_data()
    { // return basic credentials. Prefer json, but can't implement it in c++. Needs refinement
        // string result = "name:" + u_name + ",email:" + u_email + ",skills:[" + u_skills + ",level:" + u_level + "],looking_for:" + em_looking_for;
        string result = string("{type:employee,") + "name:" + name + ",email:" + email + ",password:" + password + "}";
        return result;
    }

public:
    User(string name, string email, string password): name(name), email(email), password(password) {};
};