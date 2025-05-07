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
#include<fstream>
#include<cstring>
using namespace std;
class Job
{
    public:
            char job[30];  // public class members
            int hours_per_week;
            char salary[30];
            char location[30];
            char requirements[30];
            // incase jn for job name , h for hours per week , s for salary
            Job(): job("Unknown") , hours_per_week(0), salary("Unknown"), location("Unknown"),requirements("Unknown") {}
            Job(const char jn[], int h, const char s[], const char loc[], const char req[]) {
                strcpy(job, jn);
                hours_per_week = h;
                strcpy(salary, s);
                strcpy(location, loc);
                strcpy(requirements, req);
            }
            void DisplayJobInfo()
            {
                cout<<"\t\t\t Job information\n";
                cout<<"\tJob: "<<job<<endl;
                cout<<"\tsalary: "<<salary<<endl;
                cout<<"\t Location: "<<location<<endl;
                cout<<"\t Requirements: "<<requirements<<endl;
            }
            void setData()
            {
                cout<<"Enter Job name: ";
                cin.getline(job,30);
                cout<<"Hours per week: ";
                cin>>hours_per_week;
                cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
                cout<<"Salary: ";
                cin.getline(salary,30);
                cout<<"Location: ";
                cin.getline(location,30);
                cout<<"Requirements: ";
                cin.getline(requirements,30);

            }
};

void writeJobeFile() // function to write job information to a file
{
    ofstream fout("job.dat",ios::binary);

    Job job_obj;
    job_obj.setData();
    fout.write((char*)&job_obj,sizeof(job_obj));
    fout.close();
}

void readJobFile() // function to read job information from a file
{
    ifstream fin("job.dat",ios::binary);
    Job job_obj;
    while(fin.read((char*)&job_obj,sizeof(job_obj)))
    {
    job_obj.DisplayJobInfo();
    }
    fin.close();
}

void searchJobByKeyword()
{
    char search_name[30];
    cout<<"Which job you want to search: ";
    cin.getline(search_name,30);
    
    ifstream fin("job.dat",ios::binary);
    Job job_obj;
    bool find=false;
    
    while(fin.read((char*)&job_obj,sizeof(job_obj)))
    {
        if(strcmp(search_name,job_obj.job)==1)
        {
            job_obj.DisplayJobInfo();
            find = true;
            //123
        }
    }
    
    if(!find)
    {
        cout<<"Job is not found\n";
    }

    fin.close();

}


/*template<typename T>
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
} */


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
        readJobFile();
        break;
    case 2:
        cout<<"Search job by keyword\n";
        searchJobByKeyword();
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
        AuthFlow();
        break;
    default:
        break;
}
}
