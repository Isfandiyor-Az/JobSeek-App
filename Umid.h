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
    private:
        char job[30];  // private class members
        int hours_per_week;
        char salary[30];
        char location[30];
        char requirements[30];
    public:

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
                cout<<"\tHours per week: "<<hours_per_week<<endl;
                cout<<"\tsalary: "<<salary<<endl;
                cout<<"\t Location: "<<location<<endl;
                cout<<"\t Requirements: "<<requirements<<endl;
            }

            const char* getJobName() const {
                return job;
            }
        
            int getHoursPerWeek() const {
                return hours_per_week;
            }
        
            const char* getSalary() const {
                return salary;
            }
        
            const char* getLocation() const {
                return location;
            }
        
            const char* getRequirements() const {
                return requirements;
            }


            void setJobname()
            {
                cout<<"Enter Job name: ";
                cin.getline(job,30);
            }
            void setHours()
            {
                cout<<"Hours per week: ";
                cin>>hours_per_week;
                cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
            }
            void setSalary()
            {
                cout<<"Salary: ";
                cin.getline(salary,30);
            }
            void setLocation()
            { 
                cout<<"Location: ";
                cin.getline(location,30);
            } 
            void setRequirements()
            {
                cout<<"Requirements: ";
                cin.getline(requirements,30);
            }
            void setData() // function to set data
            {
                setJobname();
                setHours();
                setSalary();
                setLocation();
                setRequirements();
            }
};

void writeJobeFile() // function to write job information to a file
{
    fstream fout("job.dat",ios::binary|ios::app|ios::in);

    Job job_obj;
    job_obj.setData();
    fout.write(reinterpret_cast<char*>(&job_obj),sizeof(job_obj));
    fout.close();
}

void readJobFile() // function to read job information from a file
{
    fstream fin("job.dat",ios::binary|ios::in|ios::out);
    Job job_obj;
    fin.clear();
    fin.seekg(0,ios::beg); // set the position of the file pointer to the beginning of the file
    while(fin.read(reinterpret_cast<char*>(&job_obj),sizeof(job_obj)))
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
    
    while(fin.read(reinterpret_cast<char*>(&job_obj),sizeof(job_obj)))
    {
        if(strcmp(search_name,job_obj.getJobName())==0)
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

void EditProfile()
{
    char search_name[30];
    cout<<"Which job you want to search: ";
    cin.getline(search_name,30);
    
    ifstream fin("job.dat",ios::binary);
    Job job_obj;
    bool find=false;
    
    while(fin.read(reinterpret_cast<char*>(&job_obj),sizeof(job_obj)))
    {
        if(strcmp(search_name,job_obj.getJobName())==1)
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
    else{
        cout<<"What do you want to edit?\n";
        cout<<"1.Job name\n";
        cout<<"2.Hours per week\n";
        cout<<"3.Salary\n";
        cout<<"4.Location\n";
        cout<<"5.Requirements\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout<<"Enter new job name: ";
            job_obj.setJobname();
            break;
        case 2:
            cout<<"Enter new hours per week: ";
            job_obj.setHours();
            break;
        case 3:
            cout<<"Enter new salary: ";
            job_obj.setSalary();
            break;
        case 4:
            cout<<"Enter new location: ";
            job_obj.setLocation();
            break;
        case 5:
            cout<<"Enter new requirements: ";
            job_obj.setRequirements();
            break;
        default:
            cout<<"Invalid choice\n";
            break;
        }
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
    bool check_point = true;
    while(check_point)
    {
    cout<<"\t\t\t----Jobseeker Menu ----\n"; // selecting operation they going to do
    cout<<"1.View all available jobs\n";
    cout<<"2.Search job by keyword\n"; // not logical to have search and apply to a job
    cout<<"3.Apply to a job\n";
    cout<<"4.View applied jobs\n";
    cout<<"5.Edit profile\n";
    cout<<"6.Log out\n";
    cout<<"7.Add new Job\n";
    cout<<"Enter your choice: ";
    cin>>mchoice;
    cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
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
        EditProfile();
        break;
    case 6:
        cout<<"Log out\n";
        AuthFlow();
        check_point = false;
    case 7:
        cout<<"Add new job\n";
        writeJobeFile();
        break;
    default:
        break;
}
    }
}
