#pragma once
#include <iostream>
#include <fstream>
#include "User.h"
#include "Employee.h"
using namespace std;

class Employer : public User
{
protected:
    char location[30];
    // char looking_for[30]; will be implemented along application system
    
    public:
    Employer() {}
    Employer(string name, string email, string password, string location) : User(name, email, password) {
        copyCharArr(location, this->location, 30);
    };

    static void write_new_user(Employer &em)
    {
        Employer temp;
        int obj_size = sizeof(Employer);
        int ID = find_smallest_idle_id("Employer.dat", temp, obj_size);
        em.set_ID(ID);
        fstream datafile("Employer.dat", ios::binary | ios::in | ios::out);
        datafile.clear();
        
        if (!datafile.is_open())
        {
            datafile.close();
            datafile.open("Employer.dat", ios::binary | ios::out); // creates file if there is no
            datafile.close();
            datafile.open("Employer.dat", ios::binary | ios::in | ios::out); // reopens for IN | OUT
            
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
        Employer em;
        ifstream in("Employer.dat", ios::binary);
        if (in.is_open())
        {
            while(in.read((char *)&em, sizeof(Employer))) {
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
        ifstream in("Employer.dat", ios::binary);
        Employer tmp;
        int obj_size = sizeof(Employer);

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
}; 

Employer get_employer(int ID)
{
    ifstream in("Employer.dat", ios::binary);
    Employer tmp;
    int obj_size = sizeof(Employee);
    bool check = false;

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
        in.close();
        return tmp;
    }
    in.close();
    return tmp;
    
}