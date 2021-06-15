//David Katz
//101157096
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Record.h"

//Template class which arranges data in key/value relationships

template <class T>
class Map
{

    //need to change these up
public:
    Map();
    ~Map(){};
    void add(T, Record *);
    void add(T, int);
    int getSize();
    int get(T);
    vector<T> &getKey();
    vector<Record *> &operator[](T);

private:
    vector<T> keys;
    vector<vector<Record *>> vals;
    vector<int> val;
};

template <class T>
Map<T>::Map() {}

template <class T>
Map<T>::~Map();

template <class T>
void Map<T>::add(T k, Record *recorder)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (keys[i] == k)
        {
            vals[i].push_back(recorder);
            return;
        }
    }
    vector<Record *> x;
    x.push_back(recorder);
    vals.push_back(x);
    keys.push_back(k);
}

template <class T>
void Map<T>::add(T k, int i)
{
    keys.push_back(k);
    val.push_back(i);
}

template <class T>
int Map<T>::getSize()
{
    return keys.size();
}

template <class T>
vector<T> &Map<T>::getKey()
{
    return keys;
}

template <class T>
vector<Record *> &Map<T>::operator[](T k)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (keys[i] = k)
        {
            return vals[i];
        }
    }
}

template <class T>
int Map<T>::get(T k)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (k == keys[i])
        {
            return value[i];
        }
    }
    return 0;
}
