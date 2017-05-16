#pragma once
#include <iostream>

using namespace std;

class Happiness
{
public:
    Happiness();
    Happiness(string forceDiseaseName, int forceR0, double forceDecline, double forceRecid);

    string getName() const;
    void setName(string userHappinessName);

    int getR0() const;
    void setR0(int userR0);

    double getDecline() const;
    void setDecline(double userDecline);

    double getRecid() const;
    void setRecid(double userRecid);

    friend ostream& operator<< (ostream& outs, const Happiness& src);

private:
    string name;
    int R0;
    double declineRate;
    double recidRate;
};
