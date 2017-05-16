/*
 * Infectious Disease Simulator
 * This program takes in user input to decide options and for how long to run the simulation of 3 diseases in 3 different cities.
 * After it takes in user input, the program computes the results of the simulation and displays it to the screen.  The program
 * will run between 7 and 30 days, or will exit early if all cities have been completely infected.
 *
 * Nicholas J. Solwick
 * Date created: 2/14/2012
 * Last date modified: 3/1/2012
 *
 * SOURCES USED
 * http://plus.maths.org/content/mathematics-diseases
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "city.h"
#include "happiness.h"
#include "simulation.h"

using namespace std;

const int NUM_CITIES = 3;
const int NUM_DISEASES = 3;

int main(int argc, char** argv)
{
    srand(time(0));

    int trash = rand() % 10;  // random number hack to prevent first number not being truly "random"

    Simulation mainSim;
    Happiness diseases[NUM_DISEASES];
    diseases[0] = Happiness("Warm Fuzzies", (rand() % 2 + 1), .10, .025);
    diseases[1] = Happiness("Smile", (rand() % 3 + 2), .25, .05);
    diseases[2] = Happiness("Laughter", (rand() % 6 + 5), .50, .10);
    City cities[NUM_CITIES];
    cities[0] = City("Philadelphia", diseases[0]);
    cities[1] = City("Boston", diseases[1]);
    cities[2] = City("San Francisco", diseases[2]);

    int numOfDays = 0;

    int daysToRun = mainSim.setSim();

    while (daysToRun > numOfDays)
    {
        int citiesInfected = 0;
        for (int i = 0;i < NUM_CITIES;i++)
        {
            if (mainSim.checkPop(cities[i]) != false)
                mainSim.runSim(cities[i]);
            else
                citiesInfected++;
        }
        if (citiesInfected == 3)
        {
            cout << "All cities infected by day " << numOfDays << ", exiting simulation.\n";
            break;
        }
        numOfDays++;
    }

    for (int i = 0;i < NUM_CITIES;i++)
        mainSim.displayCity(cities[i]);

    cin.ignore(256,'\n');
    string trashString;
    cout << "Hit ENTER to continue.";
    getline(cin, trashString);

    for (int i = 0;i < NUM_CITIES;i++)
        mainSim.displayDisease(diseases[i]);

    trashString = "";
    cout << "Hit ENTER to exit.";
    getline(cin, trashString);

    return 0;
}
