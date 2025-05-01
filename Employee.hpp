#pragma once
#include <iostream>
#include "User.hpp"
using namespace std;

class Employee : public User
{
protected:
    string skills, past_workplaces;
    double experience;

public:
    Employee(string name, string email, string password, string skills, double experience, string past_workplaces) : 
        User(name, email, password), 
        skills(skills), 
        experience(experience), 
        past_workplaces(past_workplaces) {};
    string get_string_data()
    { // return basic credentials. Prefer json, but can't implement it in c++. Needs refinement
        string result = string("{name:") + name + ",email:" + email + ",password:" + password + ",skills:" + skills + ",experience:" + to_string(experience) + ",past_workplaces:" + past_workplaces + "}";
        return result;
    }
};