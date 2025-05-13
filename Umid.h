// Umid's page to write some code
// 👤 Job Seeker Menu:
// markdown
// --- Job Seeker Menu ---
// 1. View All Available Jobs
// 2. Search Jobs by Keyword
// 3. Apply to a Job
// 4. View Applied Jobs
// 5. Edit Profile
// 6. Logout

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
    protected:
        int applicants = 0;// array to store applicants
    public:

            // incase jn for job name , h for hours per week , s for salary
            Job(): job("Unknown") , hours_per_week(0), salary("Unknown"), location("Unknown"),requirements("Unknown") {}
            Job(const char jn[], int h, const char s[], const char loc[], const char req[]) {
                strcpy_s(job, jn);
                hours_per_week = h;
                strcpy_s(salary, s);
                strcpy_s(location, loc);
                strcpy_s(requirements, req);
            }
            void DisplayJobInfo()
            {
                cout<<"\t\t\t Job information\n";
                cout<<"\tJob: "<<job<<endl;
                cout<<"\tHours per week: "<<hours_per_week<<endl;
                cout<<"\tSalary: "<<salary<<endl;
                cout<<"\tLocation: "<<location<<endl;
                cout<<"\tRequirements: "<<requirements<<endl;
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

void ApplicationSystem()
{
    // basically i need user inforamation what i mean is how they will user our application
    fstream fin("application.dat",ios::binary|ios::in|ios::out);
    if(!fin)
    {
        cout<<"Error opening file!"<<endl;
        return;
    }

}
void writeJobFile() // function to write job information to a file
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

void EditJobProfile()
{
    char search_name[30];
    cout << "Which job you want to search: ";
    cin.getline(search_name, 30);

    fstream fin("job.dat", ios::binary | ios::in | ios::out);
    if (!fin)
    {
        cerr << "Cannot open file for editing \n";
        return;
    }
    int pos = 0; // useful for editing it will be used as a pointer
    Job job_obj;
    bool find = false;

    while (fin.read(reinterpret_cast<char*>(&job_obj), sizeof(job_obj)))
    {
        if (strcmp(search_name, job_obj.getJobName()) == 0)
        {
            job_obj.DisplayJobInfo();
            find = true;
            break;
            //123
        }
        pos += sizeof(job_obj); // move the file pointer to the next record
    }

    if (!find)
    {
        cout << "Job is not found\n";
    }
    else {

        cout << "What do you want to edit?\n";
        cout << "1.Job name\n";
        cout << "2.Hours per week\n";
        cout << "3.Salary\n";
        cout << "4.Location\n";
        cout << "5.Requirements\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter new job name: ";
            job_obj.setJobname();
            break;
        case 2:
            cout << "\t\tEnter new hours per week \n ";
            job_obj.setHours();
            break;
        case 3:
            cout << "\t\tEnter new salary \n";
            job_obj.setSalary();
            break;
        case 4:
            cout << "\t\tEnter new location \n";
            job_obj.setLocation();
            break;
        case 5:
            cout << "\t\tEnter new requirements \n";
            job_obj.setRequirements();
            break;
        default:
            cout << "\tInvalid choice\n";
            break;
        }

    }
    fin.seekp(pos); // set the position of the file pointer to the beginning of the file
    fin.write(reinterpret_cast<char*>(&job_obj), sizeof(job_obj)); // write the updated record to the file2
    fin.close();

}


void DeleteJob()
{
    char search_name[30];
    cout << "Enter the job name you want to delete: ";
    cin.getline(search_name, 30);

    ifstream fin("job.dat", ios::binary);  // Open the original file for reading
    if (!fin) {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream fout("temp.dat", ios::binary);  // Create a temporary file for writing
    Job job_obj;
    bool found = false;

    // Read all jobs and write them to the temporary file, skipping the job to be deleted
    while (fin.read(reinterpret_cast<char*>(&job_obj), sizeof(job_obj))) {
        if (strcmp(search_name, job_obj.getJobName()) != 0) {
            // Write all jobs except the one to be deleted
            fout.write(reinterpret_cast<const char*>(&job_obj), sizeof(job_obj));
        }
        else {
            found = true;  // Job was found and will be deleted
        }
    }

    fin.close();
    fout.close();
    remove("job.dat");
    rename("temp.dat", "job.dat");
}
