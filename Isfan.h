#pragma once
#include <iostream>
#include "file_utils.hpp"
#include "Employee.hpp"
#include "Employer.hpp"

void JobSeeker_Reg()
{   
    string name, email, p1, p2, skills, past_workplace;
    double experience;
    cout << "\n===============================\n"
            "\tJobSeeker Register"
            "\n===============================\n";
    cout << "Enter your full name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> email;
    while(true)
    {
    cout << "Create a password: ";
    cin >> p1;
    cout << "Confirm password: ";
    cin >> p2;
    if(p2 == p1)
    {
        break;
    }
    cout<<"Enter again your passwords are not similar\n";
}
    cout << "Enter your skills (comma separated): ";
    cin >> skills;
    cout << "Enter number of years you worked (only number): ";
    cin >> experience;
    Employee newEmployee(name, email, p2, skills, experience, past_workplace);
    FileUtils<Employee>::write_new_user(newEmployee);
    cout << "🎉Registration successful! You can now log in" << endl;
}
void Employer_Reg()
{
    string name, email, p1, p2, location, looking_for;
    cout << "\n===============================\n"
            "\tEmployer Register"
            "\n===============================\n";
    cout << "Enter your full name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> email;
    while(true)
    {
    cout << "Create a password: ";
    cin >> p1;
    cout << "Confirm password: ";
    cin >> p2;
    if(p2 == p1)
    {
        break;
    }
    cout<<"Enter again your passwords are not similar\n";
}
    cout << "Enter your company location: ";
    cin >> location;
    cout << "Who are you looking for? (write comma seperated if several): ";
    cin >> looking_for;
    
    Employer newEmployer(name, email, p2, location, looking_for);                
    FileUtils<Employer>::write_new_user(newEmployer);
    
    cout << "🎉Registration successful! You can now log in" << endl;
}

// string get_string_data()
// { // return basic credentials. Prefer json, but can't implement it in c++. Needs refinement
//     // string result = "name:" + u_name + ",email:" + u_email + ",skills:[" + u_skills + ",level:" + u_level + "],looking_for:" + em_looking_for;
//     string result = "{name:" + u_name + ",email:" + u_email + ",password:" + u_confirm_password + "}";
// }
void AuthFlow()
{
    int user_choice;
    cout << "\n==============================\n"
            "\tWelcome to JobSeek"
            "\n==============================\n"
            "1. Register\n"
            "2. Login\n"
            "3. Exit\n"
         << endl;
    cout << "Enter your choice: ";
    cin >> user_choice;
    if (user_choice == 1)
    {
        int op;
        cout << "\n=============================\n"
                "  Who are you registering as?\n"
                "=============================\n"
                "1. Job Seeker\n"
                "2. Employer\n"
                "-----------------------------\n"
                "Enter your choice (1 or 2): ";
        cin >> op;
        if (op == 1)
        {
            JobSeeker_Reg();
        }
        else if (op == 2)
        {
            Employer_Reg();
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    else if (user_choice == 2)
    {
    }
    else if (user_choice == 3)
    {
    }
}