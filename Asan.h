#include <iostream>
#include<fstream>
#include<string>
#include"Umid.h"
// #include"Isfan.h"
using namespace std;

void AuthFlow();
void EmployerMenu(Employer &obj)
{
    int mchoice;
    bool check_point = true;
    while(check_point)
    {
    cout<<"\n\t\t\t----Employer Menu ----\n"; // selecting operation they going to do
    cout<<"1.Post a Job\n";
    cout<<"2.Edit Posted Job\n";
    cout<<"3.Delete a Job\n";
    cout<<"4.View posted jobs\n";
    cout<<"5.Edit profile\n";
    cout<<"6.Log out\n";
    cout<<"-----------------------------\n";
    cout<<"Enter your choice: ";

    cin>>mchoice;
    cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
    switch (mchoice)
    {
        case 1:
            cout<<"\t\tPost a Job\n";
            obj.add_to_post_IDs(Job::writeJobFile());
            break;
        case 2:
            cout<<"\t\tEdit Posted Job\n";
            Job::EditJobProfile();
            break;
        case 3: 
            cout<<"\t\tDelete a Job\n";
            Job::DeleteJob();
            break;
        case 4:
            cout<<"\t\tView posted jobs\n";
            obj.view_posted_jobs();
            break;
        case 5:
            cout<<"\t\tEdit\n";
            obj.edit_user();
            break;
        case 6:
            cout<<"\t\tLogging out...\n";
            check_point = false; // Just exit the loop without calling AuthFlow() here
            AuthFlow();
            break;
        default:
            cout<<"Invalid choice! Please try again."<<endl;
            break;
        }
    }
}

void JobseekerMenu(Employee &obj)
{
    int mchoice;
    bool check_point = true;
    while(check_point)
    {
    cout<<"\n\t\t\t----Jobseeker Menu ----\n"; // selecting operation they going to do
    cout<<"1.View All Available Jobs\n";
    cout<<"2.Search Jobs by Keyword\n";
    cout<<"3.Apply to a Job\n";
    cout<<"4.View Applied Jobs\n";
    cout<<"5.Edit Profile\n";
    cout<<"6. Logout\n";
    cout<<"-----------------------------\n";
    cout<<"Enter your choice: ";

    cin>>mchoice;
    cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
    switch (mchoice)
    {
        case 1:
            cout<<"\t\tView All Available Jobs\n";
            Job::readJobFile();
            break;
        case 2:
            cout<<"\t\tSearch Jobs by Keyword\n";
            Job::searchJobByKeyword();
            break;
        case 3: 
            cout<<"\t\tApply to a Job\n";
            Job::ApplicationSystem(obj);
            break;
        case 4:
            cout<<"\t\tView Applied Jobs\n";
            Job::ReadFromApplicationFile();
            break;
        case 5:
            cout<<"\t\tEdit Profile\n";
            obj.edit_user();
            break;
        case 6:
            cout<<"\t\tLogging out...\n";
            check_point = false;
            break;
        default:
            cout<<"Invalid choice! Please try again."<<endl;
            break;
        }
    }
}


