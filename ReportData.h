//David Katz
//101157096
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "CompareBehaviour.h"
#include "Record.h"

//gotta change the fuck outa this one
template <class T>
class ReportData
{
    template <class A>
    friend ostream &operator<<(ostream &out, const ReportData<A> &r);

    template <class B>
    class ReportRow
    {
    public:
        ReportRow<B>(B k, string s)
        {
            key = k;
            reportRow = s;
        }
        B key;
        string reportRow;
    };

public:
    ReportData(CompareBehaviour<T> *c)
    {
        comparison = c;
    }
    ~ReportData() {}
    //idk if this works
    void add(T key, string row)
    {
        ReportRow<T> repRow(key, row);
        typename vector<Row<T>>::iterator p;
        for (p = reportRows.begin(); p < reportRows.end(); ++p)
        {
            if (comparison->compare(key, p->key))
            {
                reportRows.insert(p, repRow);
                return;
            }
        }
        reportRows.insert(p, repRow);
    }

private:
    vector<ReportRow<T>> reportRows;
    CompareBehaviour<T> *comparison;
};

template <typename T>
ostream &operator<<(ostream &out, const ReportData<T> &r)
{
    for (int i = 0; i < r.reportRows.size(); i++)
    {
        out << r.reportRows[i].reportRow << endl;
    }
    return out;
}
