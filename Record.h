//David Katz
//101157096
#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <iostream>
using namespace std;

//Sets the variables and function names for Record

class Record
{
public:
    Record(int, string, string, string, int, int);
    ~Record();
    int getyear();
    string getRegion();
    string getSubRegion();
    string getAnimal();
    int getFarmCount();
    int getAnimalCount();
    void print();

private:
    int year;
    string region;
    string subRegion;
    string animal;
    int farmCount;
    int animalCount;
};

#endif
