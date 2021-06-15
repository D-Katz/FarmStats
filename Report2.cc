//David Katz
//101157096
//Animal change (reg)
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "ReportGenerator.h"
using namespace std;
//move shit from h to cc files


// round(x*10)/10
void Report2::compute()
{

    Map<string> regions;
    vector<string> regionKeys = regionM.getKey();

    vector<string> animalKeys = animalM.getKey();
    Map<string> counts;
    int globalCount = 0;
    vector<Record*> clean;

    for (int i = 0; i < animalM.getSize(); i++)
    {

        vector<Record *> animals = animalM[animalKeys[i]];
        int count = 0;
        bool found = false;
        for (int i = 0; i < animals.size(); i++)
        {
            Record *rec = animals[i];
            if (rec->getRegion() != "CAN" && rec->getSubRegion() == "All" && rec->getyear() == 2016)
            {
                found = true;
                count += rec->getFarmCount();
                globalCount += rec->getFarmCount();
                regions.add(rec->getRegion(), rec);
            }
        }
        if (found == false)
        {
            for (int k = 0; k < regionKeys.size(); k++)
            {
                if (regionKeys[k] != "CAN"){
                    Record* rec = new Record(2016, regionKeys[k], " ", animalKeys[i], 0, 0);
                    regions.add(regionKeys[k], rec);
                    clean.push_back(rec);
                }
            }
        }
        counts.add(animalKeys[i], count);
    }
    regionKeys = regions.getKey();

    for (int i = 0; i < regions.getSize(); i++)
    {

        vector<Record *> regionVec = regions[regionKeys[i]];
        stringstream ss;
        ss << regionKeys[i];
        int count = 0;

        for (int i = 0; i < regionVec.size(); i++)
        {
            Record *rec = regionVec[i];
            count += rec->getFarmCount();

            if (counts.get(rec->getAnimal()) == 0)
            {
                ss << setw(17) << setprecision(3) << 0;
                cout << rec->getAnimal() << endl;
            }
            else
                ss << setfill(' ') << setw(17) << setprecision(3) << roundf((float)rec->getFarmCount() / counts.get(rec->getAnimal()) * 100);
        }
        ss << setfill(' ') << setw(17) << setprecision(3) << roundf((float)count * 100 / globalCount);
        results->add((float)count * 100 / globalCount, ss.str());
    }
    string s;
    formatData();
    for (int k = 0; k < clean.size(); k++)
        delete clean[k];
}

void Report2::formatData()
{
    vector<string> strings = animalM.getKey();
    stringstream ss;
    ss << "\t\t\t\t\tPERCENTAGE OF FARMS BY REGION IN 2016" << endl;
    ss << "\t\t\t\t\t--------------------------------------" << endl
       << "  ";
    for (int i = 0; i < strings.size(); i++)
    {
        ss << right << setfill(' ') << setw(17) << strings[i];
    }
    ss << right << setfill(' ') << setw(17) << "Totals" << endl;
    ss << *(results);
    printReport(ss.str());
}

void Report2::printReport(string s)
{
    cout << s;
    ofstream myfile;
    myfile.open("regional.txt");
    myfile << s;
    myfile.close();
}
