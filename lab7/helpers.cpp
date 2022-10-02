#include <string>
#include <vector>
#include <fstream>
#define EMPLOYEE_NAME_LENGTH 50
#define EMPLOYEE_STRING_DATA_LENGTH 70

using namespace std;

static class StringHelper
{
public:
    static vector<string> Split(string str)
    {
        vector<string> items;

        int i = 0;
        char word[EMPLOYEE_NAME_LENGTH];
        int j = 0;
        while (true)
        {
            if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n')
            {
                word[j] = '\0';
                if (j != 0)
                    items.push_back(word);
                j = 0;
                if (str[i] == '\0' || str[i] == '\n')
                    break;
                i++;
                continue;
            }
            word[j++] = str[i++];
        }

        return items;
    }

    static string Join(vector<string> items)
    {
        char str[255];
        int j = 0;
        for (auto item : items)
        {
            int i = 0;
            while (item[i] != '\0')
                str[j++] = item[i++];
            str[j++] = ' ';
        }
        str[--j] = '\0';
        return str;
    }

    static int ParseInt(string str)
    {
        int a = 0;
        int i = 0;
        while (str[i] != '\0')
            a = a * 10 + str[i++] - '0';
        return a;
    }

    static string ToString(int num)
    {
        char* str = new char[10];
        str += 10;
        *str-- = '\0';
        while (num != 0)
        {
            *str-- = num % 10 + '0';
            num /= 10;
        }

        return ++str;
    }

};

static class FileHelper
{

private:
    static bool SetCursorToPrevLine(ifstream* file)
    {
        if (file->tellg() == 0)
            return false;

        bool first = false;
        bool second = false;
        while (!(first && second))
        {
            file->seekg(-1, ios::cur);
            char ch = file->get();
            file->seekg(-1, ios::cur);
            if (ch == '\n' || file->tellg() == 0)
            {
                if (first) break;
                first = true;
            }
        }
        if (file->tellg() != 0)
            file->seekg(1, ios::cur);
        return true;
    }
public:
    static void GetLineByCharacters(char* buffer, int maxSize, ifstream* file)
    {
        while ((*buffer = file->get()) != EOF && *buffer != '\n' && *buffer != '\r' && maxSize--)
            buffer++;
        *buffer = '\0';

        file->get();
    }

    static void GetLine(char* buffer, int maxSize, ifstream* file)
    {
        file->getline(buffer, maxSize);

        if (*buffer == '\0')
            return;
        char* tmp = buffer;
        while (*tmp != '\r' && !file->eof())
            tmp++;
        *tmp = '\0';
    }

    static void GetLineFromTextFile(char* buffer, ifstream* file)
    {
        string name;
        int salary;
        int exp;
        *file >> name >> salary >> exp;

        if (name.size() == 0)
        {
            *buffer = '\0';
            return;
        }

        vector<string> data;
        data.push_back(name);
        data.push_back(StringHelper::ToString(salary));
        data.push_back(StringHelper::ToString(exp));
        strcpy(buffer, StringHelper::Join(data).c_str());
    }

    static void WriteLineByCharacters(char* buffer, ofstream* file)
    {
        char ch;
        while ((ch = *buffer++) != '\0')
            file->put(ch);
        WriteEndline(file);
    }

    static void WriteLine(const char* buffer, int size, ofstream* file)
    {
        file->write(buffer, size);
        WriteEndline(file);
    }

    static void WriteSpace(ofstream* file)
    {
        file->put(' ');
    }

    static void WriteEndline(ofstream* file)
    {
        file->put('\r');
        file->put('\n');
    }

    static void SetCursorToEnd(ifstream* file)
    {
        file->seekg(0, ios::end);
    }

    static void GetPrevLine(char* buffer, int maxSize, ifstream* file)
    {
        bool isEnd = !SetCursorToPrevLine(file);
        if (isEnd)
        {
            *buffer = '\0';
            return;
        }

        GetLine(buffer, maxSize, file);

        SetCursorToPrevLine(file);
    }

    static void GetPrevLineFromTextFile(char* buffer, ifstream* file)
    {
        bool isEnd = !SetCursorToPrevLine(file);
        if (isEnd)
        {
            *buffer = '\0';
            return;
        }

        string name;
        int salary;
        int exp;
        *file >> name >> salary >> exp;

        vector<string> data;
        data.push_back(name);
        data.push_back(StringHelper::ToString(salary));
        data.push_back(StringHelper::ToString(exp));

        strcpy(buffer, StringHelper::Join(data).c_str());

        // get \r\n
        file->get();
        file->get();

        SetCursorToPrevLine(file);
    }
};