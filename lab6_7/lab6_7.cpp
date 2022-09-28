#include <iostream>
#include <string>
#include <vector>


template<class T> 
class KeyValPair
{
    
public:
    std::string Key;
    T Value;

    KeyValPair()
    {

    }

    KeyValPair(std::string key, T value)
    {
        Value = value;
        Key = key;
    }
};

template<class T> 
T Find(std::string key, std::vector<class KeyValPair<T>> arr)
{
    for (KeyValPair<T> el : arr)
        if (!el.Key.compare(key))
            return el.Value;

}

int main()
{
    std::vector<KeyValPair<int>> arr;
    
    int count;
    std::cin >> count;

    for (int i = 0; i < count; i++)
    {
        std::string tmpKey;
        std::cin >> tmpKey;

        int value;
        std::cin >> value;

        KeyValPair<int> tmp(tmpKey, value);
        arr.push_back(tmp);
    }

    std::string key;
    std::cin >> key;

    std::cout << Find<int>(key, arr);
    return 0;
}