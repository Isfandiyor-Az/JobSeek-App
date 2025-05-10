// Asan's page to write some code

// --- Employer Menu ---
// 1. Post a Job
// 2. Edit Posted Job
// 3. Delete a Job
// 4. View Applicants for a Job
// 5. Logout
// Enter your choice:
// 🔄 If user chooses Logout (from anywhere):

// You have been logged out successfully.
// Returning to Main Menu...
// → Back to:

// markdown

// ==============================
//         Welcome to JobSeek
// ==============================
// Select your language:
// 1. English
// 2. Uzbek
// 3. Russian
// Enter your choice:

#include <iostream>
#include<fstream>
#include<string>
#include"Umid.h"
using namespace std;

void EmployerMenu()
{
    int mchoice;
    bool check_point = true;
    while(check_point)
    {
    cout<<"\t\t\t----Employer Menu ----\n"; // selecting operation they going to do
    cout<<"1.Post a Job\n";
    cout<<"2.Edit Posted Job\n";
    cout<<"3.Delete a Job\n";
    cout<<"4.View Applicants for a Job\n";
    cout<<"5.Log out\n";
    cout<<"-----------------------------\n";
    cout<<"Enter your choice: ";

    cin>>mchoice;
    cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
    switch (mchoice)
    {
        case 1:
            cout<<"\t\tPost a Job\n";
            writeJobFile();
            break;
        case 2:
            cout<<"\t\tEdit Posted Job\n";
            EditJobProfile();
            break;
        case 3: 
            cout<<"\t\tDelete a Job\n";
            DeleteJob();
            break;
        case 4:
            cout<<"\t\tView Applicants for a Job\n";
            break;
        case 5:
            cout<<"\t\tLog out\n";
            AuthFlow();
            check_point = false;
            break;
        default:
            cout<<"Invalid choice! Please try again."<<endl;
            break;
        }
    }
}


