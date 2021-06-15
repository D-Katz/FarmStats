//David Katz
//101157096
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Control.h"
#include "ReportGenerator.h"
#include "View.h"

void ReportGenerator::load()
{
    ifstream infile("farms.dat", ios::in);
    int yr,farmCount,animalCount;
    string reg, sub, anim;
    while (infile >> yr >> reg >> sub >> anim >> farmCount >> animalCount)
    {
        Record *r = new Record(yr, reg, sub, anim, farmCount, animalCount);
        regionM.add(reg, r);
        animalM.add(anim, r);
        yearM.add(yr, r);
        recs.push_back(r);
    }
}

void ReportGenerator::clean()
{
    for(int i=0;i<recs.size();i++)
    {
        delete recs[i];
    }
}
