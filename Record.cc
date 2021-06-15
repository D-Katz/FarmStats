//David Katz
//101157096
#include "Record.h"
#include <string>
#include <iostream>
using namespace std;

//Class called upon when dealing with an entry in the farms.dat file

Record::Record(int yer, string reg, string sub, string aType, int farm, int anim){
    year = yer;
    region = reg;
    subRegion = sub;
    animal = aType;
    farmCount = farm;
    animalCount = anim;
}

int Record::getyear(){
    return year;
}
string Record::getRegion(){
    return region;
}
string Record::getSubRegion(){
    return subRegion;
}
string Record::getAnimal(){
    return animal;
}
int Record::getFarmCount(){
    return farmCount;
}
int Record::getAnimalCount(){
    return animalCount;
}

void Record::print(){
    cout<<right<<year<<" "<<region<<" "<<subRegion<<" "<<animal<<" "<<farmCount<<" "<<animalCount<<" "<<endl;
}
