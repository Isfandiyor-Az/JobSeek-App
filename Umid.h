// Umid's page to write some code

// Welcome, [username]!
// Please select your role:
// 1. Job Seeker
// 2. Employer
// 3. Logout
// Enter your choice:
// 👤 Job Seeker Menu:
// markdown
// --- Job Seeker Menu ---
// 1. View All Available Jobs
// 2. Search Jobs by Keyword
// 3. Apply to a Job
// 4. View Applied Jobs
// 5. Edit Profile
// 6. Logout
// Enter your choice:
// 🏢 Employer Menu:
// markdown
#include<iostream>
#include<string>
using namespace std;

class Job
{
    public:
            string job;  // public class members
            int hours_per_week;
            string salary;
            string location;
            string requirements;
            // incase jn for job name , h for hours per week , s for salary
            Job(string jn,int h,string s,string loc,string req) : job(jn) , hours_per_week(h) , salary(s),location(loc),requirements(req) {}
            void DisplayJobInfo()
            {
                cout<<"\t\t\t Job information\n";
                cout<<"\tJob: "<<job<<endl;
                cout<<"\tsalary: "<<salary<<endl;
                cout<<"\t Location: "<<location<<endl;
                cout<<"\t Requirements: "<<requirements<<endl;
            }
};

template<typename T>
int WelcomePAge(T &user)  // welcome page for: clarifying who is user
{
    cout<<"Welcome,"<<user.name<<"!"<<endl;
    cout<<"\t\tSelect your role:\n";
    cout<<"1.Job seeker\n";
    cout<<"2.Employer\n";
    cout<<"3.Logout\n";
    int choice ;
    cout<<"Enter your choice: ";
    cin>> choice;
    return choice;
}

void  JobseekerMenu()
{
    int mchoice;
    cout<<"\t\t\t----Jobseeker Menu ----\n"; // selecting operation they going to do
    cout<<"1.View all available jobs\n";
    cout<<"2.Search job by keyword\n"; // not logical to have search and apply to a job
    cout<<"3.Apply to a job\n";
    cout<<"4.View applied jobs\n";
    cout<<"5.Edit profile\n";
    cout<<"6.Log out\n";
    cout<<"Enter your choice: ";
    cin>>mchoice;
    switch (mchoice)
    {
    case 1:
        cout<<"View all available jobs\n";
        break;
    case 2:
        cout<<"Search job by keyword\n";
        break;
    case 3:
        cout<<"Apply to a job\n";
        break;
    case 4: 
        cout<<"View applied jobs\n";
        break;
    case 5:
        
        cout<<"Edit profile\n";
        break;
    case 6:
        cout<<"Log out\n";
        break;
    default:
}}
