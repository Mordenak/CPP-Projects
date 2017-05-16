#pragma once
#include "happiness.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class City
{
public:
    City();
    City(string forceCityName, Happiness& cityDisease);
    City(string forceCityName, int forcePopulation, int forceInfPop, int forceRecPop, Happiness& cityDisease, bool forceAlive);

    string getName();
    void setName(string userCityName);

    string getDiseaseName();

    Happiness getDisease();
    void setDisease(Happiness userDisease);

    int getPopulation();
    void setPopulation(int userPopulation);

    int getSusPop();
    void setSusPop(int userSusPop);

    int getInfPop();
    void setInfPop(int userInfPop);

    int getRecPop();
    void setRecPop(int userRecPop);

    bool getAlive();
    void setAlive(bool userSetAlive);

    int getDiseaseR0();
    double getDiseaseDecline();
    double getDiseaseRecid();

    friend ostream& operator<< (ostream& outs, const City& cityObject);

private:
    string name;
    int population;
    int susPopulation;
    int infPopulation;
    int recPopulation;
    Happiness diseaseObject;
    bool isAlive;
};
