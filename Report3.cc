//David Katz
//101157096
//Most Horses/Ponies (sub)
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "ReportGenerator.h"
using namespace std;

// round(x*10)/10
void Report3::compute()
{

    vector<string> regions = regionM.getKey();
    for (int i = 0; i < regions.size(); i++)
    {
        if (regions[i] == "Canada")
            regions.erase(regions.begin() + i);
    }
    for (int i = 0; i < regions.size(); i++)
    {

        vector<Record *> regionRecords = regionM[regions[i]];
        if (regions[i] == "CAN")
            continue;

        int count = 0;
        Record max(0, "", "", "", 0, 0);
        for (int j = 0; j < regionRecords.size(); j++)
        {

            Record rec = *(regionRecords[j]);

            if (rec.getAnimal() == "Horses-Ponies" && rec.getSubRegion() != "All" && rec.getyear() == 2016 && rec.getAnimalCount() > max.getAnimalCount())
            {
                max = rec;
            }
        }

        stringstream ss;
        if (max.getyear() == 0 && regions[i] != "CAN")
            ss <<setfill(' ') << setw(20)<< regions[i]<<setfill(' ') << setw(50)<< 0;
        else
            ss <<setfill(' ') << setw(20)<< max.getRegion() << setfill(' ') << setw(40)<< max.getSubRegion() <<  setfill(' ') << setw(10)<< to_string(max.getAnimalCount());
        results->add(max.getAnimalCount(), ss.str());
    }
        formatData();
}

void Report3::formatData()
{
    vector<int> year = yearM.getKey();
    stringstream ss;
    ss << "\t\t\tSUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl;
    ss << "\t\t\t----------------------------------------------------" << endl<< endl;
    ss << *(results);
    printReport(ss.str());
}

void Report3::printReport(string s)
{
    cout << s;
    ofstream myfile;
    myfile.open("subregional.txt");
    myfile << s;
    myfile.close();
}