#include "city.h"

// CITY CLASS

City::City()
{
    name = "Boston";
    population = (rand() % 4 + 1) * 1000000; //  4000000 - 1000000
    population += (rand() % 999 + 1) * 1000; //     999000 - 1000
    population += (rand() % 999 + 1);        //           999 - 1
    population++; // add 1 to get up to 5 mill
    infPopulation = rand() % 10 + 1;
    susPopulation = population - infPopulation;
    recPopulation = 0;
    isAlive = true;
}

City::City(string forceCityName, Happiness& cityDisease)
{
    name = forceCityName;
    population = (rand() % 4 + 1) * 1000000; //  4000000 - 1000000
    population += (rand() % 999 + 1) * 1000; //     999000 - 1000
    population += (rand() % 999 + 1);        //           999 - 1
    population++; // add 1 to get up to 5 mill
    infPopulation = rand() % 10 + 1;
    susPopulation = population - infPopulation;
    recPopulation = 0;
    diseaseObject = cityDisease;
    isAlive = true;
}

City::City(string forceCityName, int forcePopulation, int forceInfPop, int forceRecPop, Happiness& cityDisease, bool forceAlive)
{
    name = forceCityName;
    population = forcePopulation;
    susPopulation = forcePopulation - forceInfPop;
    infPopulation = forceInfPop;
    recPopulation = forceRecPop;
    diseaseObject = cityDisease;
    isAlive = forceAlive;
}

ostream& operator<< (ostream& outs, const City& cityObject)
{
    outs << "\t+--------------------------CITY------------------------------+\n"
         << "\t    Name: " << cityObject.name << ", Population: " << cityObject.population << "\n"
         << "\t    Disease: " << cityObject.diseaseObject.getName() << ", Infected: " << cityObject.infPopulation << "\n"
         << "\t    Suspectible Population: " << cityObject.susPopulation << "\n"
         << "\t    Recovered Population: " << cityObject.recPopulation << "\n"
         << "\t+------------------------------------------------------------+\n";
	return outs;
}

string City::getName()
{
    return name;
}

void City::setName(string userCityName)
{
    name = userCityName;
}

string City::getDiseaseName()
{
    return diseaseObject.getName();
}

void City::setDisease(Happiness userDisease)
{
    diseaseObject = userDisease;
}

Happiness City::getDisease()
{
    return diseaseObject;
}

int City::getPopulation()
{
    return population;
}

void City::setPopulation(int userPopulation)
{
    population = userPopulation;
}

int City::getSusPop()
{
    return susPopulation;
}

void City::setSusPop(int userSusPop)
{
    susPopulation = userSusPop;
}

int City::getInfPop()
{
    return infPopulation;
}

void City::setInfPop(int userInfPop)
{
    infPopulation = userInfPop;
}

int City::getRecPop()
{
    return recPopulation;
}

void City::setRecPop(int userRecPop)
{
    recPopulation = userRecPop;
}

bool City::getAlive()
{
    return isAlive;
}

void City::setAlive(bool userSetAlive)
{
    isAlive = userSetAlive;
}

int City::getDiseaseR0()
{
    return diseaseObject.getR0();
}

double City::getDiseaseDecline()
{
    return diseaseObject.getDecline();
}

double City::getDiseaseRecid()
{
    return diseaseObject.getRecid();
}
