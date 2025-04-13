#include <iostream>
using namespace std;

class User{
    protected:
    string u_name,u_email,u_create_password,u_confirm_password,u_skills,u_level;
    string em_name,em_email,em_create_password,em_confirm_password,em_com_location;
    public:
    void Display(){
    int user_choice;
    cout<<"\n==============================\n"
          "\tWelcome to JobSeek"
          "\n==============================\n"
          "1. Register\n"
          "2. Login\n"
          "3. Exit\n"<<endl;
    cout<<"Enter your choice: ";
    cin>>user_choice;
    if (user_choice == 1){
        int op;
        cout<<"\n=============================\n"
              "  Who are you registering as?\n"
              "=============================\n"
              "1. Job Seeker\n"
              "2. Employer\n"
              "-----------------------------\n"
              "Enter your choice (1 or 2): ";
        cin>>op;
        if (op==1){JobSeeker_Reg();}
        else if (op==2){Employer_Reg();}
        else {cout<<"Wrong Choice"<<endl;}
        
    }
    else if (user_choice == 2){}
    else if (user_choice == 3){}  
    }
    void JobSeeker_Reg(){
        cout<<"\n===============================\n"
              "\tJobSeeker Register"
              "\n===============================\n";
        cout<<"Enter your full name: ";
        cin>>u_name;
        cout<<"Enter your email: ";
        cin>>u_email;
        cout<<"Create a password: ";
        cin>>u_create_password;
        cout<<"Confirm password: ";
        cin>>u_confirm_password;
        cout<<"Enter your skills (comma separated): ";
        cin>>u_skills;
        cout<<"Enter your experience level (e.g., Beginner, Intermediate, Expert): ";
        cin>>u_level;
        cout<<"🎉Registration successful! You can now log in"<<endl;
    }
    void Employer_Reg(){
        cout<<"\n===============================\n"
              "\tEmployer Register"
              "\n===============================\n";
        cout<<"Enter your full name: ";
        cin>>em_name;
        cout<<"Enter your email: ";
        cin>>em_email;
        cout<<"Create a password: ";
        cin>>em_create_password;
        cout<<"Confirm password: ";
        cin>>em_confirm_password;
        cout<<"Enter your company location: ";
        cin>>em_com_location;
        cout<<"🎉Registration successful! You can now log in"<<endl;
    }
};