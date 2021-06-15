//David Katz
//101157096
#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "ReportGenerator.h"

//Sets the variables and function names for Control

class Control
{
public:
    Control();
    ~Control();
    void launch();

private:
    vector<ReportGenerator *> reports;
    View *view;
};

#endif
