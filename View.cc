//David Katz
//101157096
#include <string>
#include <iostream>
using namespace std;
#include "View.h"

//Runs the User interface and sends off input to Control.cc class

void View::showMenu(int& input)
{
  cout << "What would you like to do:"<< endl;
  cout << "(1) Percentage distribution of farms, by province (2016)" << endl;
  cout << "(2) Percentage change of animals, by province (2011-2016)" << endl;
  cout << "(3) Sub-region with highest number of horses, by province (2016)" << endl;
  cout << "(0) Exit" <<endl;
  cout << "Enter your selection: ";
  
  cin >> input;
  while (input!=0 && (input > 4||input < 1)) 
  {
    cout << "Enter selection:";
    cin >> input;
  }
  return;
}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}



