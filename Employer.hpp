#pragma once
#include <iostream>
#include <fstream>
#include "User.hpp"
// #include "Umid.h"
using namespace std;

class Employer : public User
{
protected:
    char location[30];
    unsigned int posted_jobs[20]; // posted job IDs
    unsigned short number_of_posts = 0;
    // char looking_for[30]; will be implemented along application system

public:
    Employer() {}
    Employer(string name, string email, string password, string location) : User(name, email, password)
    {
        copyCharArr(location, this->location, 30);
    };

    void display()
    {
        cout << "\t\t\t Employer information\n";
        cout << "\tName: " << get_name() << endl;
        cout << "\tEmail: " << get_email() << endl;
        cout << "\tLocation: " << location << endl;
    }

    string get_location()
    {
        return string(location);
    }

    void set_location(string location)
    {
        copyCharArr(location, this->location, 30);
    }

    unsigned int *get_post_IDs()
    {
        return this->posted_jobs;
    }

    void add_to_post_IDs(int id)
    {
        posted_jobs[number_of_posts] = id;
        number_of_posts++;
        update_user();
    }

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
        else
        {
            cerr << "Filesystem error.\n";
        }
        datafile.close();
    }

    static bool find_user(string email, string password, Employer &res_obj)
    {
        Employer em;
        ifstream in("Employer.dat", ios::binary);
        if (in.is_open())
        {
            while (in.read((char *)&em, sizeof(Employer)))
            {
                if (em.get_email() == email)
                {
                    in.close();
                    return (em.get_password() == password);
                }
            }
        }
        cout << "Failed to login. Check credentials or try again later.\n";
        in.close();
        res_obj = em;
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

    virtual void edit_user()
    {
        char opcode;
        display();
        cout << "What do you want to edit?" << endl
             << "1. Name\n2. Email\n3. Location\nYour choice: ";
        cin >> opcode;
        cin.ignore();
        cout << "Enter a new value: ";
        switch (opcode)
        {
        case '1':
        {
            string new_val;
            cin >> new_val;
            cin.ignore();
            set_name(new_val);
            break;
        }
        case '2':
        {
            string new_val;
            cin >> new_val;
            cin.ignore();
            set_email(new_val);
            break;
        }
        case '3':
        {
            string new_val;
            cin >> new_val;
            cin.ignore();
            set_location(new_val);
            break;
        }
        default:
            cout << "Improper input. Try again.\n";
            break;
        }
        update_user();
    }

    void update_user()
    {
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
            datafile.seekp((ID - 1) * sizeof(Employer), ios::beg);
            datafile.write(reinterpret_cast<char *>(this), sizeof(Employer));
        }
        else
        {
            cerr << "Filesystem error.\n";
        }
        datafile.close();
    }
    void view_posted_jobs();
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