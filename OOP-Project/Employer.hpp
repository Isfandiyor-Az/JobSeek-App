#pragma once
#include <iostream>
#include "User.hpp"
using namespace std;

class Employer : public User
{
protected:
    string location, looking_for;

    // string u_name, u_email, u_create_password, u_confirm_password, u_skills, u_level;
    // string em_com_location, em_looking_for;
    
    public:
    Employer(string name, string email, string password, string location, string looking_for) : User(name, email, password), location(location), looking_for(looking_for) {};
    string get_string_data()
    { // return basic credentials. Prefer json, but can't implement it in c++. Needs refinement
        // string result = "name:" + u_name + ",email:" + u_email + ",skills:[" + u_skills + ",level:" + u_level + "],looking_for:" + em_looking_for;
        string result = "{name:" + name + ",email:" + email + ",password:" + password + ",location:" + location + ",looking_for:" + looking_for + "}";
        return result;
    }
    
};