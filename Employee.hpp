#pragma once
#include <iostream>
#include "User.hpp"
#include <fstream>

using namespace std;

class Employee : public User
{
protected:
    char skills[31];
    char past_workplaces[31];
    double experience;
    bool is_hired = false;

public:
    Employee() {}
    Employee(string name, string email, string password, string skills, double experience, string past_workplaces)
        : User(name, email, password)
    {
        copyCharArr(skills, this->skills, 30);
        copyCharArr(past_workplaces, this->past_workplaces, 30);
        this->experience = experience;
    };
    void DisplayEmployeeInfo()
    {
        cout << "\t\t\t Employee information\n";
        cout << "\tName: " << getname() << endl;
        cout << "\tEmail: " << get_email() << endl;
        cout << "\tSkills: " << skills << endl;
        cout << "\tExperience: " << experience << endl;
        cout << "\tPast workplaces: " << past_workplaces << endl;
    }

    static void write_new_user(Employee &em)
    {
        Employee temp;
        int obj_size = sizeof(Employee);
        int ID = find_smallest_idle_id("Employee.dat", temp, obj_size);
        em.set_ID(ID);
        fstream datafile("Employee.dat", ios::binary | ios::in | ios::out);
        datafile.clear();
        if (!datafile.is_open())
        {
            datafile.close();
            datafile.open("Employee.dat", ios::binary | ios::out); // creates file if there is no
            datafile.close();
            datafile.open("Employee.dat", ios::binary | ios::in | ios::out); // reopens for IN | OUT
        }
        if (datafile.good())
        {
            datafile.seekp((ID - 1) * obj_size, ios::beg);
            datafile.write(reinterpret_cast<char *>(&em), obj_size);
        } 
        else {
            cerr << "Filesystem error.\n";
        }
        datafile.close();
    }
    static bool find_user(string email, string password)
    {
        Employee em;
        ifstream in("Employee.dat", ios::binary);
        if (in.is_open())
        {
            while(in.read((char *)&em, sizeof(Employee))) {
                if(em.get_email() == email) {
                    in.close();
                    return (em.get_password() == password);
                }
            }
        } 
        cout << "Failed to login. Check credentials or try again later.\n";
        in.close();
        return false;
    }

        static bool validate_credentials(int ID, string password)
    {
        ifstream in("Employee.dat", ios::binary);
        Employee tmp;
        int obj_size = sizeof(Employee);

        if (!in.is_open())
        {
            in.close();
            return false;
        }
        
        in.clear();
        in.seekg((ID - 1) * obj_size, ios::beg);
        in.read((char *)&tmp, obj_size);

        in.close();
        return (tmp.get_password() == password); // true -- login successful, false -- vice versa
    }
    
    void setHiringStatus(bool status)
    {
        is_hired = status;
    }
    string getname() const{
        return name;
    }
};

Employee get_employee(int ID)
{
    ifstream in("Employee.dat", ios::binary);
    Employee tmp;
    int obj_size = sizeof(Employee);

    if (!in.is_open())
    {
        in.close();
    }
    
    in.clear();
    in.seekg((ID - 1) * obj_size, ios::beg);
    in.read((char *)&tmp, obj_size);

    if (in.fail())
    {
        cout << "Error: ID not found.\n";
        return tmp;
    }
    in.close();
    return tmp;
}
