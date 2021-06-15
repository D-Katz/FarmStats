//David Katz
//101157096
#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H
#include <string>
#include <iostream>
using namespace std;
//Compares two templates to return an ascending or descneding list

template <class T>
class CompareBehaviour
{
public:
    CompareBehaviour<T>(){};
    virtual bool compare(T, T) = 0;
};

template <class T>
class DescBehaviour : public CompareBehaviour<T>
{
public:
    virtual bool compare(T a, T b)
    {
        return (a > b);
    }
};

template <class T>
class AscBehaviour : public CompareBehaviour<T>
{
public:
    virtual bool compare(T a, T b)
    {
        return (a < b);
    }
};

#endif
