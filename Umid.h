#include <iostream>
#include <fstream>
#include <cstring>
#include "Employer.hpp"
// #include "Isfan.h"
using namespace std;

class Job
{
private:
    char job[30]; // private class members
    int hours_per_week;
    char salary[30];
    char location[30];
    char requirements[30];
    int ID;

protected:
    int applicants = 0; // array to store applicants
public:
    // incase jn for job name , h for hours per week , s for salary
    Job() : job("Unknown"), hours_per_week(0), salary("Unknown"), location("Unknown"), requirements("Unknown") {}
    Job(const char jn[], int h, const char s[], const char loc[], const char req[])
    {
        strcpy(job, jn);
        hours_per_week = h;
        strcpy(salary, s);
        strcpy(location, loc);
        strcpy(requirements, req);
    }

    void DisplayJobInfo()
    {
        cout << "\t\t\t Job information\n";
        cout << "\tJob: " << job << endl;
        cout << "\tHours per week: " << hours_per_week << endl;
        cout << "\tSalary: " << salary << endl;
        cout << "\tLocation: " << location << endl;
        cout << "\tRequirements: " << requirements << endl;
    }
    int getApplicants() const
    {
        return applicants;
    }
    const char *getJobName() const
    {
        return job;
    }

    int getHoursPerWeek() const
    {
        return hours_per_week;
    }

    const char *getSalary() const
    {
        return salary;
    }

    const char *getLocation() const
    {
        return location;
    }

    const char *getRequirements() const
    {
        return requirements;
    }
    void setApplicants()
    {
        applicants += 1;
    }

    void setJobname()
    {
        cout << "Enter Job name: ";
        cin.getline(job, 30);
    }
    void setHours()
    {
        cout << "Hours per week: ";
        cin >> hours_per_week;
        cin.ignore(); // using int before strings could cause some problem so we use cin.ignore for salary not to be empty line
    }
    void setSalary()
    {
        cout << "Salary: ";
        cin.getline(salary, 30);
    }
    void setLocation()
    {
        cout << "Location: ";
        cin.getline(location, 30);
    }
    void setRequirements()
    {
        cout << "Requirements: ";
        cin.getline(requirements, 30);
    }
    void setData() // function to set data
    {
        setJobname();
        setHours();
        setSalary();
        setLocation();
        setRequirements();
    }

    static Job R_searchJobByKeyword(char search_name[30])
    {
        ifstream fin("job.dat", ios::binary);
        Job job_obj;
        bool find = false;

        // Check if file opened successfully
        if (!fin)
        {
            cout << "Error: Could not open job file.\n";
            return Job(); // Return default job if file can't be opened
        }

        while (fin.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)))
        {
            if (strcmp(search_name, job_obj.getJobName()) == 0)
            {
                find = true;
                fin.close();
                return job_obj;
            }
        }

        fin.close();

        if (!find)
        {
            cout << "Job is not found\n";
        }

        return Job(); // Return default job if not found
    }

    static void searchJobByKeyword()
    {
        char search_name[30];
        cout << "Which job you want to search: ";
        cin.getline(search_name, 30);

        ifstream fin("job.dat", ios::binary);
        Job job_obj;
        bool find = false;

        while (fin.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)))
        {
            if (strcmp(search_name, job_obj.getJobName()) == 0)
            {
                job_obj.DisplayJobInfo();
                find = true;
                // 123
            }
        }

        if (!find)
        {
            cout << "Job is not found\n";
        }

        fin.close();
    }

    static void EditJobProfile()
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

        while (fin.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)))
        {
            if (strcmp(search_name, job_obj.getJobName()) == 0)
            {
                job_obj.DisplayJobInfo();
                find = true;
                break;
                // 123
            }
            pos += sizeof(job_obj); // move the file pointer to the next record
        }

        if (!find)
        {
            cout << "Job is not found\n";
        }
        else
        {

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
        fin.seekp(pos);                                                 // set the position of the file pointer to the beginning of the file
        fin.write(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)); // write the updated record to the file2
        fin.close();
    }

    static void DeleteJob()
    {
        char search_name[30];
        cout << "Enter the job name you want to delete: ";
        cin.getline(search_name, 30);

        ifstream fin("job.dat", ios::binary); // Open the original file for reading
        if (!fin)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        ofstream fout("temp.dat", ios::binary); // Create a temporary file for writing
        Job job_obj;
        bool found = false;

        // Read all jobs and write them to the temporary file, skipping the job to be deleted
        while (fin.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)))
        {
            if (strcmp(search_name, job_obj.getJobName()) != 0)
            {
                // Write all jobs except the one to be deleted
                fout.write(reinterpret_cast<const char *>(&job_obj), sizeof(job_obj));
            }
            else
            {
                found = true; // Job was found and will be deleted
            }
        }

        fin.close();
        fout.close();
        remove("job.dat");
        rename("temp.dat", "job.dat");
    }

    static void ApplicationSystem(Employee &employee_obj) // function to apply for a job
    {
        // basically i need user inforamation what i mean is how they will user our application
        // file for job applicatioon data
        fstream app_file("application.dat", ios::binary | ios::in | ios::out);

        static int number_of_applicants = 0; // it going to help when we have to read from file it will be used as a pointer
        char search_name[30];
        cout << "Which job you want to search: ";
        cin.getline(search_name, 30);

        ifstream job_file("job.dat", ios::binary);
        Job job_obj;
        bool find = false;
        while (job_file.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)))
        {
            if (strcmp(search_name, job_obj.getJobName()) == 0)
            {
                find = true;
                job_obj.DisplayJobInfo();
                cout << "Do you want to apply for this job? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    job_obj.setApplicants();
                    cout << "You have successfully applied for this job.\n";
                    cout << "Total applicants: " << job_obj.getApplicants() << endl;
                    // write to application file
                    app_file.clear();
                    app_file.write(reinterpret_cast<char *>(&search_name), sizeof(search_name));
                    // there must be a writing information regarding user
                    int temp_id = employee_obj.get_ID();
                    app_file.write(reinterpret_cast<char *>(&temp_id), sizeof(temp_id));
                }
                else
                {
                    cout << "You have not applied for this job.\n";
                    return;
                }
            }
        }

        if (!find)
        {
            cout << "Job is not found\n";
        }
        app_file.close();
        job_file.close();
    }

    static void ReadFromApplicationFile()
    {
        ifstream app_file("application.dat", ios::binary);
        if (!app_file)
        {
            cerr << "Error opening application file.\n";
            return;
        }
        char job_name[30];
        int employee_id;

        while (app_file.read(reinterpret_cast<char *>(&job_name), sizeof(job_name)))
        {
            if (app_file.read(reinterpret_cast<char *>(&employee_id), sizeof(employee_id)))
            {
                Job A = Job::R_searchJobByKeyword(job_name);
                A.DisplayJobInfo();
                Employee employee_obj = get_employee(employee_id);

                employee_obj.display();
                // You can add more information about the application here if needed
            }
            else
            {
                cerr << "Corrupted application entry found.\n";
                break;
            }
        }

        app_file.close();
    }

    static int writeJobFile() // function to write job information to a file
    {
        fstream fout("job.dat", ios::binary | ios::in | ios::out | ios::app);
        if (!fout) {
            cerr << "Error opening file for writing.\n";
            return -1;
        }
        fout.clear();
        Job job_obj;
        job_obj.setData();

        fout.seekp(0, ios::end);
        std::streampos pos = fout.tellp();
        job_obj.ID = static_cast<int>(pos / sizeof(Job));

        fout.write(reinterpret_cast<char *>(&job_obj), sizeof(job_obj));
        fout.close();
        return job_obj.ID;
    }

    static void readJobFile() // function to read job information from a file
    {
        fstream fin("job.dat", ios::binary | ios::in);
        Job job_obj;
        fin.clear();
        fin.seekg(0, ios::beg); // set the position of the file pointer to the beginning of the file
        while (fin.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj)))
        {
            job_obj.DisplayJobInfo();
        }
        fin.close();
    }
    static void readJobFile(int ID) // overloaded function to get specific job info
    {
        ifstream fin("job.dat", ios::binary);
        if (!fin) {
            cerr << "Error: Could not open job file.\n";
            return;
        }

        Job job_obj;
        fin.clear();
        
        int position = ID * sizeof(Job);
        fin.seekg(position, ios::beg);
        
        if (fin.fail()) {
            cerr << "Can't find job with this ID: " << ID << ".\n";
            fin.close();
            return;
        }
        
        if (!fin.read(reinterpret_cast<char *>(&job_obj), sizeof(job_obj))) {
            cerr << "Can't read job with ID " << ID << ".\n";
            fin.close();
            return;
        }
        
        job_obj.DisplayJobInfo();
        fin.close();
    }
};

void Employer::view_posted_jobs()
{
    if(number_of_posts <= 0) {
        cout << "You haven't posted any jobs yet.\n";
        return;
    }
    for (int i = 0; i < number_of_posts; i++)
    {
        cout << "-- Job number " << i << "--\n";
        Job::readJobFile(posted_jobs[i]);
    }
}

// Job R_searchJobByKeyword(char search_name[30])
// {
//     ifstream fin("job.dat", ios::binary);
//     Job job_obj;
//     bool find = false;

//     while (fin.read(reinterpret_cast<char*>(&job_obj), sizeof(job_obj)))
//     {
//         if (strcmp(search_name, job_obj.getJobName()) == 0)
//         {

//             return job_obj;
//             find = true;
//         }
//     }

//     if (!find)
//     {
//         cout << "Job is not found\n";
//     }

//     fin.close();

// }
