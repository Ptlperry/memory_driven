#include <iostream>
#include <vector>

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
        cout << "HRA:" << HRA << endl;
        cout << "DA:" << DA << endl;
        cout << "TA:" << TA << endl;
        cout << "PF:" << PF << endl;
        cout << "PT:" << PT << endl;
        cout << "Net salary:" << Net_Salary << endl;
    }

 
    vector<Employee> EmployeeList;

    void addEmployee()
    {

        Employee n_employee;
        cout << "Enter employee ID: ";
        cin >> n_employee.empid;

        cout << "Enter employee name: ";
        cin >>n_employee.empname;

        cout << "Enter employee age: ";
        cin >>n_employee.empage;

        cout << "Enter employee department: ";
        cin >> n_employee.department;

        cout << "Enter employee salary: ";
        cin >>n_employee.salary;

        EmployeeList.push_back(n_employee);
        cout << "Employee added successfully!" << endl;
    }

    void MarkAttendance()
    {
        int id;
        cout << "Enter employee ID: ";
        cin >> id;

        for (int i = 0; i < EmployeeList.size(); i++)
        {
            if (EmployeeList[i].empid == id)
            {
                cout << "Enter employee attendance: ";
                cin >> EmployeeList[i].attendance;
                cout << "Attendance marked successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void calculateSalary()
    {
        int id;
        cout << "Enter employee ID: ";
        cin >> id;

        for (int i = 0; i < EmployeeList.size(); i++)
        {
            if (EmployeeList[i].empid == id)
            {
                EmployeeList[i].getSalary();
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void applyIncrement(float percentage)
    {

        cout << "Enter employee id:" ;
        cin >> empid;

        cout << "Enter employee salary:";
        cin >> salary;

        cout << "Enter employee bonus:";
        cin >> bonus;

        cout << "Enter increment precentage:";
        cin >> percentage;

        float increment = (percentage / 100) * salary;

        float TotalSalary = salary + bonus + increment;
        cout << "Total salary is:" << TotalSalary << endl;

        cout << "Increment applied!!" << endl;
    }

    void grantBonus()
    {
        int id;
        cout << "Enter employee ID: ";
        cin >> id;

        for (int i = 0; i < EmployeeList.size(); i++)
        {
            if (EmployeeList[i].empid == id)
            {
                cout << "Enter bonus amount: ";
                cin >> EmployeeList[i].bonus;
                cout << "Bonus granted successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void displayEmployee()
    {
        if (EmployeeList.empty())
        {
            cout << "No employees found!" << endl;
            return;
        }

        for (int i = 0; i < EmployeeList.size(); i++)
        {
            cout << "Employee ID: " << EmployeeList[i].empid << endl;
            cout << "Name: " << EmployeeList[i].empname << endl;
            cout << "Age: " << EmployeeList[i].empage << endl;
            cout << "Department: " << EmployeeList[i].department << endl;
            cout << "Salary: " << EmployeeList[i].salary << endl;
            cout << "Bonus: " << EmployeeList[i].bonus << endl;
            cout << "Attendance: " << EmployeeList[i].attendance << endl;
        
        }
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
            emp.applyIncrement(0);
            break;

        case 5:
            emp.grantBonus();
            break;

        case 6:
            emp.displayEmployee();
            break;
        case 7:
            cout << "Exiting...";
            break;
        }
    } while (choice != 7);

    return 0;
}

