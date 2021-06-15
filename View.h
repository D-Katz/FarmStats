//David Katz
//101157096
#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <iostream>
using namespace std;

//Runs the UI which gives options for different reports
class View
{
public:
  void showMenu(int &);
  void readInt(int &);
  void readStr(string &);
  void printStr(string);
};

#endif
