#pragma once
#include "happiness.h"
#include "city.h"

class Simulation
{
public:
    Simulation();

    bool getRecid();
    void setRecid(bool userRecid);

    void displayCity(const City& cityObject);
    void displayDisease(Happiness& diseaseObject);

    void infectCity(City& cityObject);
    void healCity(City& cityObject);
    void recidCity(City& cityObject);
    bool checkPop(City& cityObject);

    int setSim();
    void runSim(City& cityObject);

private:
    bool recidActive;
};
