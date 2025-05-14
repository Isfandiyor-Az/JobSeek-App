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
    void display()
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
        else
        {
            cerr << "Filesystem error.\n";
        }
        datafile.close();
    }
    static bool find_user(string email, string password, Employee &res_obj)
    {
        Employee em;
        ifstream in("Employee.dat", ios::binary);
        if (in.is_open())
        {
            while (in.read((char *)&em, sizeof(Employee)))
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
    string getname() const
    {
        return name;
    }

    string get_skills()
    {
        return string(this->skills);
    }

    string get_past_workplaces()
    {
        return string(this->past_workplaces);
    }

    double get_experience() const
    {
        return experience;
    }

    bool get_hiring_status() const
    {
        return is_hired;
    }

    void set_skills(string skills)
    {
        copyCharArr(skills, this->skills, 30);
    }

    void set_past_workplaces(string past_workplaces)
    {
        copyCharArr(past_workplaces, this->past_workplaces, 30);
    }

    void set_experience(double experience)
    {
        this->experience = experience;
    }

    void set_hiring_status(bool status)
    {
        is_hired = status;
    }

    virtual void edit_user()
    {
        char opcode;
        display();
        cout << "What do you want to edit?" << endl
             << "1. Name\n2. Email\n3. Skills"
             << "\n4. Past workplaces.\n5. Experience\n6. Hired status.\nYour choice: ";
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
            set_skills(new_val);
            break;
        }
        case '4':
        {
            string new_val;
            cin >> new_val;
            cin.ignore();
            set_past_workplaces(new_val);
            break;
        }
        case '5':
        {
            double new_exp;
            cin >> new_exp;
            cin.ignore();
            set_experience(new_exp);
            break;
        }
        case '6':
        {
            cout << "('1' for hired; '0' for unhired) ";
            string inp;
            cin >> inp;
            cin.ignore();
            set_hiring_status(inp == "1" ? true : false);
            break;
        }
        default:
            cout << "Improper input. Try again.\n";
            break;
        }

        try
        {
            update_user();
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }
        
    }

    void update_user()
    {
        fstream datafile("Employee.dat", ios::binary | ios::in | ios::out);
        datafile.clear();
        cout << datafile.good()<< endl;
        if (!datafile.is_open())
        {
            datafile.close();
            datafile.open("Employee.dat", ios::binary | ios::out); // creates file if there is no
            datafile.close();
            datafile.open("Employee.dat", ios::binary | ios::in | ios::out); // reopens for IN | OUT
        }
        if (datafile.good())
        {
            datafile.seekp((ID - 1) * sizeof(Employee), ios::beg);
            datafile.write(reinterpret_cast<char *>(this), sizeof(Employee));
        }
        else
        {
            cerr << "Filesystem error.\n";
        }
        datafile.close();
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
