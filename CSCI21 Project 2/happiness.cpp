#include "happiness.h"
#include <cstdlib>

// HAPPINESS CLASS

Happiness::Happiness()
{
    name = "Crappy";
    R0 = rand() % 10 + 1;;
    declineRate = .10;
    recidRate = .05;
}

Happiness::Happiness(string forceDiseaseName, int forceR0, double forceDecline, double forceRecid)
{
    name = forceDiseaseName;
    R0 = forceR0;
    declineRate = forceDecline;
    recidRate = forceRecid;
}

ostream& operator<< (ostream& outs, const Happiness& src)
{
    outs << "\t+-------------------------DISEASE----------------------------+\n"
         << "\t    Name: " << src.name << ", R0 Rate: " << src.R0 << "\n"
         << "\t    Decline Rate: " << src.declineRate << ", Recidivism Rate: " << src.recidRate << "\n"
         << "\t+------------------------------------------------------------+\n";
	return outs;
}

string Happiness::getName() const
{
    return name;
}

void Happiness::setName(string userHappinessName)
{
    name = userHappinessName;
}

int Happiness::getR0() const
{
    return R0;
}

void Happiness::setR0(int userR0)
{
    R0 = userR0;
}

double Happiness::getDecline() const
{
    return declineRate;
}

void Happiness::setDecline(double userDecline)
{
    declineRate = userDecline;
}

double Happiness::getRecid() const
{
    return recidRate;
}

void Happiness::setRecid(double userRecid)
{
    recidRate = userRecid;
}
