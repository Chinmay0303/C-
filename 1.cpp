#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

    // Stage 1: Basic Organism Simulation (Using basic arrays, if-else, loops)
    // Problem
    // Start by simulating a population of organisms where each organism has a single genetic trait (like speed). 
    // The environment will have a "difficulty" (a threshold number), and if an organism’s trait is above the 
    // threshold, it survives. Otherwise, it doesn't.

    // Challenge for Stage 1:
    // Genetic Diversity: Modify the project to simulate multiple traits (like speed, strength, etc.). 
    // Each organism will now have a pair of traits.
    // Calculate fitness of the organisms and select the best-fit ones.
    
    //Optional:
    // Calculate the average speed,strength and fitness of 1) All organisms, 2) Survivors, and 3) Organisms which couldn't survive.
    // Add exception handling to ensure the program handles incorrect inputs gracefully.
    // Enhance user experience and output formatting.


int main() {

    // Input: Number of organisms in the population (each organism will have two genetic traits).
    // In biological terms, this represents the population size for one generation.
    int num;
    cout << "Enter the no. of Organisms: ";
    cin >> num;
    cout << "Total Organisms in Generation 1: " << num << endl;

    // Array to store organism IDs (representing individuals in the population).
    int orgs[num];
    for (int i = 0; i < num; i++) {
        orgs[i] = i + 1;  // Each organism is given an ID starting from 1.
    }

    // Arrays to store genetic traits: speed and strength
    // which affect their chances of survival (natural selection).
    float speed[num];
    float strength[num];

    cout << "Current Traits of the organisms: Speed and Strength" << endl << endl;
    cout << "Press Enter to Generate Random Traits...";
    cin.ignore();
    cin.get();

    // Use the current time as a seed to generate random numbers for traits.
    srand(time(0));

    // Generating random traits for each organism:
    int sp, st;
    for (int i = 0; i < num; i++) {
        sp = rand() % 100 + 1;  
        speed[i] = sp / 10.0;    //trait magnitude.
    }
    for (int i = 0; i < num; i++) {
        st = rand() % 100 + 1;  
        strength[i] = float(st) / 10;
    }
    cout << endl;

    // Output all the organisms with their speed and strength values.
    cout << "Org \tspeed \tstrength:" << endl;
    for (int i = 0; i < num; i++) {
        cout << orgs[i] << " \t" << speed[i] << " \t" << strength[i];
        cout << endl;
    }
    cout << endl;

    // Fitness Calculation: A measure of an organism's ability to survive and reproduce in the environment.
    // Here, fitness is calculated as a weighted sum of speed and strength.
    float thresh;

    cout << "Press Enter to Generate the Function for Fitness...";
    cin.get();
    cout << endl;

    // Fitness function: Combining traits with different weights (0.3 for speed and 0.7 for strength).
    // This reflects how in nature, certain traits might have more influence on survival than others, 
    // depending on environmental conditions.
    cout << "Fitness = 0.3(speed) + 0.7(strength)" << endl;
    cout << endl;


    cout << "Press Enter to Select Fitness Criteria...";
    cin.get();
    cout << endl;

    //The threshold represents the minimum fitness level required
    // for an organism to survive in the current environment.

    cout << "Enter Threshold Fitness (out of 10): ";
    cin >> thresh;
    cout << "Only those organisms having fitness more than or equal to " << thresh << " will survive, the rest will die" << endl;
    cout << endl;

    // Now, we calculate the fitness of each organism and determine which survive.
    cout << "Press Enter to Select the Best-Fit Organisms...";
    cin.ignore();
    cin.get();
    cout << endl;

    int survCount = 0;  

    float fitness[num];  // Array to store fitness values of each organism.

    for (int i = 0; i < num; i++) {
        fitness[i] = 0.3 * speed[i] + 0.7 * strength[i];
    }

    // Count how many organisms survive based on the fitness threshold.
    // Organisms with higher fitness are more likely to survive and reproduce, 
    // passing on their advantageous traits to the next generation (natural selection).
    for (int i = 0; i < num; i++) {
        if (fitness[i] >= thresh) {
            survCount++;
        }
    }

    cout << "Survival Count: " << survCount << " Out of " << num << endl;
    cout << endl;

    if (survCount > 0) {
        cout << "The survivors are: " << endl;
        cout << "Org \tspeed \tstrength \tfitness:" << endl;
        for (int i = 0; i < num; i++) {
            if (fitness[i] >= thresh) {
                cout << orgs[i] << " \t" << speed[i] << " \t" << strength[i] << " \t\t" << fitness[i];
                cout << endl;
            }
        }
        cout << endl;
        cout << endl;
    }

    // These organisms were not well-adapted to the environment.
    // They do not survive to pass on their traits, and this reflects the principle of "survival of the fittest."
    if (survCount <num) {
        cout << "Those who couldn't survive are: " << endl;
        cout << "Org \tspeed \tstrength \tfitness:" << endl;
        for (int i = 0; i < num; i++) {
            if (fitness[i] < thresh) {
                cout << orgs[i] << " \t" << speed[i] << " \t" << strength[i] << " \t\t" << fitness[i];
                cout << endl;
            }
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}