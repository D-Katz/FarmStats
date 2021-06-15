//David Katz
//101157096
//Distribution of all the animals  (Nat)
#include <string>
#include <iostream>
using namespace std;
#include "ReportGenerator.h"
#include "Record.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iomanip>

void Report1::compute()
{

    Map<string> animals;
    vector<string> animalKeys = animalM.getKey();
    vector<int> counts;
    vector<int> strYears = yearM.getKey();

    for (int i = 0; i < yearM.getSize(); i++)
    {
        vector<Record *> year = yearM[strYears[i]];
        vector<Record> recYear;
        int count = 0;

        for (int i = 0; i < year.size(); i++)
        {
            Record *rec = year[i];
            if (rec->getRegion() == "CAN" && rec->getSubRegion() == "All")
            {
                count += rec->getAnimalCount();
                animals.add(rec->getAnimal(), rec);
            }
        }
        counts.push_back(count);
    }
    for (int i = 0; i < animals.getSize(); i++)
    {
        stringstream ss;
        Record *first = animals[animalKeys[i]][0];
        Record *second = animals[animalKeys[i]][1];
        float one, two;

        if (first == NULL)
        {
            first = new Record(2011, "CAN", "ALL", animalKeys[i], 0, 0);
            one = (float)first->getAnimalCount() / counts[0];
            delete first;
        }
        else
            one = (float)first->getAnimalCount() / counts[0];

        if (second == NULL)
        {

            second = new Record(2016, "CAN", "ALL", animalKeys[i], 0, 0);
            two = (float)second->getAnimalCount() / counts[1];
            delete second;
        }
        else
            two = (float)second->getAnimalCount() / counts[1];

        ss << setfill(' ')<<setw(30)<<animalKeys[i] << setfill(' ')<<setw(8) << setprecision(3) << roundf(one * 100) <<  setfill(' ')<<setw(10) << setprecision(3) << roundf(two * 100) << " " << setfill(' ')<<setw(7)<< setprecision(2) << roundf((two - one) * 100);
        results->add((two - one) * 100, ss.str());
    }
    formatData();
}

void Report1::formatData()
{
    vector<int> year = yearM.getKey();
    stringstream ss;
    ss << "\t\t\tPERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl;
    ss << "\t\t\t--------------------------------------" << endl<< setfill(' ') << setw(38) << endl;;
    for (int i = 0; i < year.size(); i++)
    {
        ss << year[i]<< setfill(' ') << setw(10);
    }
    ss << "Change" << endl<<endl;
    ss << *(results);
    printReport(ss.str());
}

void Report1::printReport(string s)
{
    cout << s;
    ofstream myfile;
    myfile.open("national.txt");
    myfile << s;
    myfile.close();
}
// round(x*10)/10