// number 9
#include <iostream>
#include <string>
#include <vector>
#include "helpers.cpp"
#define FILE_NAME "company.txt"

using namespace std;

class Employee
{
private:
    unsigned int salary;
public:
    string name;
    unsigned int experience;

    Employee(string _name, unsigned int _salary, unsigned short _experience)
    {
        name = *(new string(_name));
        salary = _salary;
        experience = _experience;
    }

    string ToString()
    {
        vector<string> data;
        data.push_back(name);
        data.push_back(StringHelper::ToString(salary));
        data.push_back(StringHelper::ToString(experience));

        return StringHelper::Join(data);
    }

    bool operator ==(const Employee& item)
    {
        return name == item.name;
    }

    friend class Company;
};

class Company
{
private:
    vector<Employee> staff;

    void GetReportFromTextFile(string fileName)
    {
        staff.clear();
        ifstream f(fileName);

        while (true)
        {
            string name;
            unsigned int salary;
            unsigned short experience;
            f >> name >> salary >> experience;

            if (name.size() == 0)
                break;

            Employee emp = Employee(name, salary, experience);
            staff.push_back(emp);
        }

        f.close();
    }

    void MakeReportToTextFile(string fileName)
    {
        ofstream f(fileName);

        for (auto item : staff)
        {
            string row = item.ToString();
            f << row << endl;
        }

        f.close();
    }

public:

    Company()
    {
        
    }

    void GetReport(string fileName, bool isBinary = false)
    {
        if (!isBinary)
        {
            GetReportFromTextFile(fileName);
            return;
        }

        staff.clear();
        ifstream f(fileName, ios_base::binary);

        char employeeDataString[EMPLOYEE_STRING_DATA_LENGTH];
        while (true) 
        {
            FileHelper::GetLine(employeeDataString, EMPLOYEE_STRING_DATA_LENGTH, &f);
            vector<string> data = StringHelper::Split(employeeDataString);
            if (data.size() == 0) break;

            string name = string(data[0]);
            unsigned int salary = StringHelper::ParseInt(data[1]);
            unsigned short experience = StringHelper::ParseInt(data[2]);

            Employee emp = Employee(name, salary, experience);
            staff.push_back(emp);
        }

        f.close();
    }

    void MakeReport(string fileName, bool isBinary = false)
    {
        if (!isBinary)
        {
            MakeReportToTextFile(fileName);
            return;
        }
        ofstream f(fileName, ios_base::binary);

        for (auto item : staff)
        {
            string row = item.ToString();
            FileHelper::WriteLine(row.c_str(), row.size(), &f);
        }

        f.close();
    }

    void AddEmployee(Employee empl)
    {
        staff.push_back(empl);
    }

    string FindByName(string name, string fileName, bool isBinary = false)
    {
        GetReport(fileName, isBinary);
        if (staff.size() == 0)
            return "";
        
        for (auto item : staff)
        {
            if (!item.name.compare(name))
                return item.ToString();
        }
        return "";
    }

    string DeleteEmployeeByName(string name, string fileName, bool isBinary = false)
    {
        GetReport(fileName, isBinary);
        string deleted;
        for (auto item : staff)
        {
            if (!item.name.compare(name))
            {
                deleted = item.ToString();
                staff.erase(std::find(staff.begin(), staff.end(), item));
            }   
        }
        MakeReport(fileName, isBinary);
        return deleted;
    }

    void PrintReverseData(string fileName, bool isBinary = false)
    {
        ifstream f(fileName, ios_base::binary);
        FileHelper::SetCursorToEnd(&f);

        while (true)
        {
            char employeeDataString[EMPLOYEE_STRING_DATA_LENGTH];
            if (isBinary)
                FileHelper::GetPrevLine(employeeDataString, EMPLOYEE_STRING_DATA_LENGTH, &f);
            else
                FileHelper::GetPrevLineFromTextFile(employeeDataString, &f);

            if (employeeDataString[0] == '\0')
                return;
            cout << employeeDataString << endl;
        }

        f.close();
    }

    void PrintData(string fileName, bool isBinary = false)
    {

        ifstream f(fileName, ios_base::binary);

        while (true)
        {
            char employeeDataString[EMPLOYEE_STRING_DATA_LENGTH];
            if (isBinary)
                FileHelper::GetLine(employeeDataString, EMPLOYEE_STRING_DATA_LENGTH, &f);
            else
                FileHelper::GetLineFromTextFile(employeeDataString, &f);
            if (employeeDataString[0] == '\0')
                return;
            cout << employeeDataString << endl;
        }

        f.close();
    }
};

int main()
{
    Company company = Company();
    
    cout << "Is file binary? (1/0):";
    bool isBinary;
    cin >> isBinary;
   
    int count;
    cout << "Input count of employers:";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        string name;
        unsigned int salary;
        unsigned int experience;
        cin >> name >> salary >> experience;

        Employee tmp = Employee(name, salary, experience);
        company.AddEmployee(tmp);
    }

    company.MakeReport(FILE_NAME, isBinary);
    
    cout << "Data from file" << endl;
    company.PrintData(FILE_NAME, isBinary);
    cout << endl << "Data from file (reverse)" << endl;
    company.PrintReverseData(FILE_NAME, isBinary);

    string name;
    cout << "Input employee name for deleting:";
    cin >> name;
    cout << company.DeleteEmployeeByName(name, FILE_NAME, isBinary) << endl;

    cout << "Input employee name for find:";
    cin >> name;
    cout << company.FindByName(name, FILE_NAME, isBinary) << endl;

    return 0;
}