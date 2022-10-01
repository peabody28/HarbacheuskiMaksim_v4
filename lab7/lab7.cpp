// number 9
#include <iostream>
#include <string>
#include <fstream>
#define COMPANY_NAME_LENGTH 50

using  namespace std;

class Company
{
private:
    char name[COMPANY_NAME_LENGTH];
    unsigned short staffCount;
    int capital;

public:

    Company()
    {
        staffCount = -1;
    }


    string Name()
    {
        return name;
    }

    unsigned short StaffCount()
    {
        return staffCount;
    }

    // characters
    void BuildFromBinaryFile(ifstream* file)
    {
        char* tmpName = name;
        while ((*tmpName = file->get()) != EOF && *tmpName != '\n' && *tmpName != '\r')
            tmpName++;

        *tmpName = '\0';

        if (file->eof())
            return;
        file->get();
        file->get();

        char* tmpStaffCount = new char[9];
        while ((*tmpStaffCount = file->get()) != EOF && *tmpStaffCount != ' ');

        file->get();
        file->get();

        char* tmpCapital = new char[9];
        while ((*tmpCapital = file->get()) != EOF && *tmpCapital != ' ');

    }
};

int main()
{
    ifstream companyFile("company.txt", ios_base::binary);
    if (!companyFile.is_open())
        return 1;

    Company* company = new Company();
    company->BuildFromBinaryFile(&companyFile);
}