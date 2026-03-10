#include<iostream>
using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    void getPerson()
    {
        cout<<"Enter ID: ";
        cin>>id;

        cout<<"Enter Name: ";
        cin>>name;
    }

    void showPerson()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
    }
};

class Employee : virtual public Person
{
protected:
    float salary;

public:
    void getEmployee()
    {
        cout<<"Enter Salary: ";
        cin>>salary;
    }

    void showEmployee()
    {
        cout<<"Salary: "<<salary<<endl;
    }
};

class Manager : virtual public Person
{
protected:
    int teamSize;

public:
    void getManager()
    {
        cout<<"Enter Team Size: ";
        cin>>teamSize;
    }

    void showManager()
    {
        cout<<"Team Size: "<<teamSize<<endl;
    }
};

class TeamLead : public Employee, public Manager
{
    int experience;

public:

    void getTeamLead()
    {
        getPerson();   // only one Person now
        getEmployee();
        getManager();

        cout<<"Enter Experience: ";
        cin>>experience;
    }

    void showTeamLead()
    {
        showPerson();
        showEmployee();
        showManager();

        cout<<"Experience: "<<experience<<endl;
    }
};

int main()
{
    TeamLead t;

    cout<<"Enter Team Lead Details\n";
    t.getTeamLead();

    cout<<"\nTeam Lead Information\n";
    t.showTeamLead();

    return 0;
}