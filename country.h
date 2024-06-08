#ifndef COUNTRY_H
#define COUNTRY_H

#include<QComboBox>
#include<QDebug>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
using namespace std;

const int MAXN=200;

class Country
{
private:
    vector<string> item;
    int data_month[10];

protected:
    const string PATH="D:\\1111111111111111111\\CSU\\0000\\system\\System\\data\\";
    int to_number(string);

public:
    Country();

    void read(int);
    void read(QString);
    int calc_month(int,int);

    QString Item(int,int);

    static QString NAME[30];
    static map<QString,int> cindex;
    static int COLUMN;
    static int ROW;
};

#endif // COUNTRY_H
