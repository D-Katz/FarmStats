//David Katz
//101157096
#include "CompareBehaviour.h"
#include "Control.h"
#include "View.h"
#include "reportGenerator.h"
#include <string>
#include <iostream>
using namespace std;

//Calls report generator and implements the UI to show/create the different reports

Control::Control(){

  ReportGenerator* r1 = new Report1();  
  reports.push_back(r1);
  ReportGenerator* r2  = new Report2();
  reports.push_back(r2);
  ReportGenerator* r3 = new Report3(); 
  reports.push_back(r3);
}

Control::~Control(){
  for(int i = 0; i < reports.size(); i++){
    delete reports[i];
  }
}

void Control::launch(){

  reports.at(0)->load();

  int input;
  view->showMenu(input);
  while(input != 0)
  {
    if (input == 1)
    {
      reports.at(0)->compute();
      view->showMenu(input);
    }
    else if (input == 2)
    {
      reports.at(1)->compute();
      view->showMenu(input);
    }
    else if (input == 3)
    {
      reports.at(2)->compute();
      view->showMenu(input);
    }
    else
    {
      view->showMenu(input);
    }
  // clean the records?
  }
delete view;
}

