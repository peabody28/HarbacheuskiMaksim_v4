// number 8
#include<iostream>
#include<vector>
#include<iterator>

#define QUEUE_EMTPY_EXCEPTION "Queue is empty"
#define QUEUE_FULL_EXCEPTION "Queue is full"

using namespace std;

template<class T>
class Queue
{
private:
    inline static T _arr[10] = {0,0,0,0,0,0,0,0,0,0};
    T* begin;
    T* end;
public:

    Queue()
    {
        begin = _arr;
        end = _arr;
    }

    T Pop() {
        if (IsEmpty())
            throw "Queue is empty";
        return *begin++;
    }

    void Push(T val) {
        if (end - begin >= 10)
            throw "Queue is full";

        *end++ = val;
    }

    bool IsEmpty()
    {
        return begin == end;
    }
};

void my_terminate() {
    printf("Shutdown after 3...2...1...\n");
    abort();
}

void my_unexpected() {
    printf("I dont smart, i dont know\n");
    abort();
}

int main()
{
    set_terminate(my_terminate);
    set_unexpected(my_unexpected);

    Queue<int> q;

    try
    {
        while (true)
        {
            switch (getchar())
            {
                case 'd':
                    q.Pop();
                    break;
                case 'a':
                    int tmp;
                    cin >> tmp;
                    q.Push(tmp);
                    break;
                case 'e':
                    if(q.IsEmpty())
                        cout << "is empty" << endl;
                    else
                        cout << "not empty" << endl;
                    break;
                case '\n':
                    break;
                default:
                    cout << "you can write 'a', 'd' or 'e' character" << endl;
                    break;
            }
        }
    }
    catch(const char* msg)
    {
        if (!strcmp(msg, QUEUE_EMTPY_EXCEPTION))
            cout << "Already empty" << endl;
        else if (!strcmp(msg, QUEUE_FULL_EXCEPTION))
            cout << "Already full" << endl;
        else
            unexpected();

        return 0;
    }

    return 0;
}