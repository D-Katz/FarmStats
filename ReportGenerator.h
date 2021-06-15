//David Katz
//101157096
#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Record.h"
#include "ReportData.h"
#include "Map.h"
#include "CompareBehaviour.h"

//Polymorphic class which sends functions to sub-classes that make specified reports
class ReportGenerator
{
public:
    ReportGenerator(){};
    ~ReportGenerator(){};
    static void load();
    virtual void compute();
    static void clean();

protected:
    static Map<string> regionM;
    static Map<string> animalM;
    static Map<int> yearM;
    static vector<Record *> recs;
};

//National Records for all animals
class Report1 : public ReportGenerator
{
public:
    Report1() : ReportGenerator()
    {
        ascending = new AscBehaviour<float>();
        results = new ReportData<float>(ascending);
    };
    ~Report1()
    {
        delete ascending;
        delete results;
    };
    void compute();
    void formatData();
    void printReport(string s);

protected:
    ReportData<float> *results;
    AscBehaviour<float> *ascending;
};

//Regional Records for % change between 2011 and 2016
class Report2 : public ReportGenerator
{
public:
    Report2() : ReportGenerator()
    {
        descending = new DescBehaviour<float>();
        results = new ReportData<float>(descending);
    };
    ~Report2()
    {
        delete descending;
        delete results;
    };
    void compute();
    void formatData();
    void printReport(string s);

protected:
    ReportData<float> *results;
    DescBehaviour<float> *descending;
};

//SubRegional Records for most Horses/ponies per region
class Report3 : public ReportGenerator
{
public:
    Report3() : ReportGenerator()
    {
        descending = new DescBehaviour<float>();
        results = new ReportData<float>(descending);
    };
    ~Report3()
    {
        delete descending;
        delete results;
    };
    void compute();
    void formatData();
    void printReport(string s);

protected:
    ReportData<float> *results;
    DescBehaviour<float> *descending;
};

#endif
