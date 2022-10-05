// number 12
#include <bits/stdc++.h>
using namespace std;


vector<string> GetLines(ifstream* file)
{
    vector<string> words;
    while (!file->eof())
    {
        string tmp;
        getline(*file, tmp);
        words.push_back(tmp);
    }
    return words;
}

vector<string> GetWords(string line)
{
    vector<string> words;

    stringstream sstream(line);
    string word;
    while (std::getline(sstream, word, ' ')) {
        words.push_back(word);
    }
    return words;
}

map<char, vector<string>> Sort(vector<string> words)
{
    map<char, vector<string>> table;

    for (auto word : words)
    {
        set<char> letters;
        for (auto ch : word)
            letters.insert(ch);
        
        for (char c : letters)
        {
            auto item = table.find(c);
            if (item != table.end())
            {
                (*item).second.push_back(word);
                continue;
            }

            pair<char, vector<string>> tmp;
            tmp.first = c;
            tmp.second.push_back(word);

            table.insert(tmp);
        }  
    }
    return table;
}

set<string> Find(map<char, vector<string>> table, string chars)
{
    set<string> intersection;
    set<string> s1;
    set<string> s2;

    for (char c : chars)
    {
        auto item = table.find(c);
        if (item == table.end())
            break;
        if (s1.empty())
        {
            for (auto i : (*item).second)
                s1.insert(i);
            intersection = s1;
            continue;
        }

        s2.clear();
        for (string s : (*item).second) s2.insert(s);
        
        intersection.clear();
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(intersection, intersection.begin()));

        s1 = intersection;
    }

    return intersection;
}

int main()
{
    vector<string> lines;
    try
    {
        ifstream in("in.txt");
        if (in.is_open())
            cout << "file in.txt is opened" << endl;
        else
            throw "File opening error";

        lines = GetLines(&in);
        in.close();
        cout << "file in.txt is closed" << endl;
    }
    catch (const char* msg) {
        cout << string(msg) << endl;
        terminate();
    }

    for (auto line : lines)
    {
        std::string chars;
        cout << "Input chars:";
        std::cin >> chars;

        vector<string> words = GetWords(line);
        map<char, vector<string>> table = Sort(words);

        set<string> ws = Find(table, chars);

        for (auto i : ws)
            cout << i << endl;

        try
        {
            ofstream out("out.txt", std::ios_base::app);
            if (out.is_open())
                cout << "file out.txt is opened" << endl;
            else
                throw "File opening error";
            out << ws.size() << endl;
            out.close();
            cout << "file out.txt is closed" << endl;
        }
        catch (const char* msg)
        {
            cout << string(msg) << endl;
            terminate();
        }
    }

    return 0;
}