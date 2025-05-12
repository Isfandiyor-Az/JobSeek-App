#pragma once
#include <iostream>
#include "Employee.hpp"
#include "Employer.hpp"

void JobSeeker_Reg(bool &success);

void Employer_Reg(bool &success);

void forgot_ID(bool &success);

void Login_flow(bool &success);

void AuthFlow()
{
    cout << "\n===============================\n"
	     "\nEmployer Register"
	     "\n===============================\n";
	bool success = false;
	while (!success) {
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
		cin.ignore();
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
			cin.ignore();
			if (op == 1)
			{
				JobSeeker_Reg(success);
				if(success) {
					cout << "Authentication Successful!\n";
				};
			}
			else if (op == 2)
			{
				Employer_Reg(success);
				if(success) {
					cout << "Authentication Successful!\n";
				};
			}
			else
			{
				cout << "Wrong Choice" << endl;
			}
		}
		else if (user_choice == 2)
		{
            Login_flow(success);
		}
		else if (user_choice == 3)
		{
		}
	}
}

void JobSeeker_Reg(bool &success)
{
	string name, email, p1, p2, skills, past_workplaces;
	double experience;
	cout << "Enter your full name: ";
	cin >> name;
	cout << "Enter your email: ";
	cin >> email;
	while(p1 != "q" && p2 != "Q") {
	    cout << "Create a password: ";
		cin >> p1;
		cout << "Confirm password: ";
		cin >> p2;
		if(p1 == p2) break;
		cout << "Passwords are not Equal! (enter 'q' to quit)\n";
	}

	cout << "Enter your skills (comma separated): ";
	cin >> skills;
	cout << "Enter your past workplaces (comma separated): ";
	cin >> past_workplaces;
	cout << "Enter number of years you worked (only number): ";
	cin >> experience;
	Employee newEmployee(name, email, p2, skills, experience, past_workplaces);
	Employee::write_new_user(newEmployee);
	cout << "Registration successful!\nYour ID is " << newEmployee.get_ID()
	     << ". Please REMEMBER IT, as you will use it for login!" << endl;
	success = true;
}

void Employer_Reg(bool & success)
{
	string name, email, p1, p2, location;
	cout << "Enter your full name: ";
	cin >> name;
	cout << "Enter your email: ";
	cin >> email;
	while(p1 != "q" && p2 != "Q") {
	    cout << "Create a password: ";
		cin >> p1;
		cout << "Confirm password: ";
		cin >> p2;
		if(p1 == p2) break;
		cout << "Passwords are not Equal! (enter 'q' to quit)\n";
	}

	cout << "Enter the location of your company: ";
	cin >> location;
	Employer newEmployer(name, email, p2, location);
	Employer::write_new_user(newEmployer);
	cout << "Registration successful!\nYour ID is " << newEmployer.get_ID()
	     << ". Please REMEMBER IT, as you will use it for login!" << endl;
	     success = true;
}

void forgot_ID(bool &success, char &opcode) {
	string email, password;
	cout << "Enter Your email: ";
	cin >> email;
	cout << "Enter Your password: ";
	cin >> password;

	if(opcode == '1')
		success = Employee::find_user(email, password);
	else if (opcode == '2')
		success =  Employer::find_user(email, password);
	else
		cout << "Improper input.\n";
}

void Login_flow(bool &success) {
	string ID_str;
	string password;
	char opcode;

	cout << "Please choose 1 or 2:\n"
	     << "\t1. Login as a Job Seeker.\n"
	     << "\t2. Login as an Employer.\n"
	     << "Your choice: ";
	cin >> opcode;
	cin.ignore();
	cout << "Enter Your ID. (Enter EMPTY LINE if you forgot your ID): ";
	getline(cin, ID_str);
	if (ID_str.empty()) {
		forgot_ID(success, opcode);
		if(success) {
			cout << "Authentication Successful!\n";
		};
		return;
	}
	cout << "Enter Your password: ";
	cin >> password;

	int ID = stoi(ID_str); // stoi converts string to int
	if(opcode == '1')
		success = Employee::validate_credentials(ID, password);
	else if (opcode == '2')
		success =  Employer::validate_credentials(ID, password);
	else
		cout << "Improper input.\n";

	if ( success ) {
		cout << "Authentication Successful!\n";
	} else {
		cout << "Failed authentication!\n";
	}
}