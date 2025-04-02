#include <iostream>
using namespace std;

class Employee
{
public:
    int empid, empage, attendance;
    string empname, department;
    float salary, bonus;
    float HRA, DA, TA, PF, PT, Net_Salary;

    void calculate()
    {
        HRA = salary * 0.02;
        DA = salary * 0.01;
        TA = salary * 0.05;
        PF = salary * 0.12;
        PT = 200;
        Net_Salary = salary + HRA + DA + TA - (PF + PT);
    }

    void getSalary()
    {
        calculate();
        cout << "HRA: " << HRA << endl;
        cout << "DA: " << DA << endl;
        cout << "TA: " << TA << endl;
        cout << "PF: " << PF << endl;
        cout << "PT: " << PT << endl;
        cout << "Net salary: " << Net_Salary << endl;
    }

    void addEmployee()
    {
        cout << "Enter employee id: ";
        cin >> empid;

        cout << "Enter employee name: ";
        cin >> empname;

        cout << "Enter employee age: ";
        cin >> empage;

        cout << "Enter employee department: ";
        cin >> department;

        cout << "Enter employee salary: ";
        cin >> salary;

        cout << "Enter employee attendance: ";
        cin >> attendance;

        cout << "Employee added successfully!!" << endl;
    }

    void MarkAttendance()
    {
        int id;
        cout << "Enter employee id: ";
        cin >> id;

        if (id == empid)
        {
            cout << "Enter employee attendance: ";
            cin >> attendance;

            cout << "Attendance marked successfully!!" << endl;
        }
        else
        {
            cout << "Employee id not found!" << endl;
        }
    }

    void calculateSalary()
    {
        int id;
        cout << "Enter employee id: ";
        cin >> id;

        if (id == empid)
        {
            cout << "Employee id: " << empid << endl;
            getSalary();
        }
        else
        {
            cout << "Employee id not found!!" << endl;
        }
    }

    void applyIncrement()
    {
        int id;
        float increment;
        cout << "Enter employee id: ";
        cin >> id;

        if (id == empid)
        {
            cout << "Enter increment amount: ";
            cin >> increment;

            salary += increment;

            cout << "Salary increment successfully!!" << endl;
        }
        else
        {
            cout << "Employee id not found!!" << endl;
        }
    }

    void grantBonus()
    {
        int id;
        cout << "Enter employee id: ";
        cin >> id;
        if (id == empid)
        {
            cout << "Enter bonus amount: ";
            cin >> bonus;

            salary += bonus;
            cout << "Bonus granted successfully!!" << endl;
        }
        else
        {
            cout << "Employee id not found!!" << endl;
        }
    }

    void displayEmployee()
    {
        cout << "Employee id: " << empid << endl;
        cout << "Employee name: " << empname << endl;
        cout << "Employee age: " << empage << endl;
        cout << "Employee department: " << department << endl;
        cout << "Employee salary: " << salary << endl;
        cout << "Employee attendance: " << attendance << endl;
        cout << "Employee bonus:" << bonus << endl;
    }
};

int main()
{

    int choice;
    Employee emp;
    do
    {
        cout << endl
             << "Employee Management System" << endl;
        cout << endl
             << "Press 1 for Add employee" << endl;
        cout << "Press 2 for Mark attendance" << endl;
        cout << "Press 3 for Calculate salary" << endl;
        cout << "Press 4 for Apply increment" << endl;
        cout << "Press 5 for Grant bonus" << endl;
        cout << "Press 6 for Display employee" << endl;
        cout << "Press 7 for exit!!" << endl;

        cout << endl
             << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            emp.addEmployee();
            break;

        case 2:
            emp.MarkAttendance();
            break;

        case 3:
            emp.calculateSalary();
            break;
        case 4:
            emp.applyIncrement();
            break;
        case 5:
            emp.grantBonus();
            break;

        case 6:
            emp.displayEmployee();
            break;
        case 7:
            cout << "Exiting..!!" << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}
