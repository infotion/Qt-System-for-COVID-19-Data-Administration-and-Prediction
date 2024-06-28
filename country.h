#ifndef COUNTRY_H
#define COUNTRY_H

#include<QComboBox>
#include<QDebug>
#include<QString>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<QFile>
#include<QDir>
#include<QCoreApplication>
using namespace std;

const int MAXN=200;

class Country
{
private:
    vector<string> item;
    int data_month[10];

protected:
    static string find_windowspath();

public:
    Country();
    ~Country();

    void read(int);
    void read(QString);
    int calc_month(int,int);

    QString Item(int,int);
    static int to_number(string);

    static QString NAME[30];
    static map<QString,int> cindex;
    static int COLUMN;
    static int ROW;
    static string PATH;
};

#endif // COUNTRY_H
