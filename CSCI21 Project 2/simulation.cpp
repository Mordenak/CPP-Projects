#include "simulation.h"


// SIMULATION CLASS

Simulation::Simulation()
{
    recidActive = false;
}

void Simulation::infectCity(City& cityObject)
{
    int temp = 0;
    temp = cityObject.getInfPop() * cityObject.getDiseaseR0();
    if (temp >= cityObject.getSusPop()) // in case the number generated is larger than the actual suspetible population
    {
        cityObject.setInfPop(cityObject.getInfPop() + cityObject.getSusPop());
        cityObject.setSusPop(0);
        cityObject.setAlive(false);
    }
    else
    {
        cityObject.setSusPop(cityObject.getSusPop() - temp);
        cityObject.setInfPop(cityObject.getInfPop() + temp);
    }
}

void Simulation::healCity(City& cityObject)
{
    int temp = 0;
    if (cityObject.getSusPop() != 0)
    {
        temp = cityObject.getInfPop() * cityObject.getDiseaseDecline();
        cityObject.setRecPop(cityObject.getRecPop() + temp);
        cityObject.setInfPop(cityObject.getInfPop() - temp);
    }
}

void Simulation::recidCity(City& cityObject)
{
    int temp = 0;
    temp = cityObject.getRecPop() * cityObject.getDiseaseRecid();
    cityObject.setSusPop(cityObject.getSusPop() + temp);
    cityObject.setRecPop(cityObject.getRecPop() - temp);
}

bool Simulation::checkPop(City& cityObject)
{
    if (cityObject.getSusPop() <= 0)
        return false;
    else
        return true;
}

int Simulation::setSim()
{
    int userDays = 0;
    bool acceptableInput = false;
    cout << "Allow recidivism? (Y)es (N)o: ";
    char userChoice = ' ';
    while (acceptableInput == false)
    {
        cin >> userChoice;
        if (userChoice == 'Y' || userChoice == 'y')
        {
            setRecid(true);
            acceptableInput = true;
        }
        else if (userChoice == 'N' ||  userChoice == 'n')
        {
            setRecid(false);
            acceptableInput = true;
        }
        else
        {
            cout << "Incorrect input, please enter (Y)es or (N)o: ";
        }
    }
    acceptableInput = false;  //reset variable for use in next loop

    cout << "How many days would you like to run this simulation for?";
    while (acceptableInput == false)
    {
        cin >> userDays;
        if (!isdigit(userDays))
        {
            if (userDays >= 7 && userDays <= 30)
            {
                cout << "You've chosen to the run the simulation for " << userDays << " days.  Computing...\n\n";
                return userDays;
            }
            else
                cout << "Incorrect input, please enter a number between 7 and 30: ";
        }
        else
        {
            cout << "Incorrect input, please enter a number between 7 and 30: ";
        }
    }
    return 0;
}

void Simulation::runSim(City& cityObject)
{
    healCity(cityObject);
    if (recidActive == true)
        recidCity(cityObject);
    infectCity(cityObject);
}

void Simulation::displayCity(const City& cityObject)
{
    cout << cityObject;
}

void Simulation::displayDisease(Happiness& diseaseObject)
{
    cout << diseaseObject;
}

bool Simulation::getRecid()
{
    return recidActive;
}

void Simulation::setRecid(bool userRecid)
{
    recidActive = userRecid;
}
