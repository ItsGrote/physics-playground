#include "ui/menu.h"
#include "simulations/mru.h"
#include "simulations/mruv.h"
#include "simulations/projectile.h"
#include "simulations/pendulum.h"
#include "app/runner.h"

#include <iostream>

int main(){
    int choice = showMenu();
    float t;

    switch (choice)
    {
    case 1: {
        MRU sim;

        std::cout << "Insert the initial position of the particle\n";
        std::cout << "x0 = ";
        std::cin >> sim.x0;
        
        std::cout << "Insert the velocity of the particle\n";
        std::cout << "v = ";
        std::cin >> sim.v;

        runSimulation(sim, "MRU");

        break;
    }
    case 2: {
        MRUV sim;

        std::cout << "Insert the initial position of the particle\n";
        std::cout << "x0 = ";
        std::cin >> sim.x0;
        
        std::cout << "Insert the initial velocity of the particle\n";
        std::cout << "v = ";
        std::cin >> sim.v0;

        std::cout << "Insert the acceleration of the particle\n";
        std::cout << "a = ";
        std::cin >> sim.a;

        runSimulation(sim, "MRUV");

        break;
    }
    case 3: {
        Projectile sim;

        std::cout << "Insert the initial horizontal position of the projectile\n";
        std::cout << "x0 = ";
        std::cin >> sim.x0;

        std::cout << "Insert the initial vertical position of the projectile\n";
        std::cout << "y0 = ";
        std::cin >> sim.y0;
        
        std::cout << "Insert the initial velocity of the projectile\n";
        std::cout << "v = ";
        std::cin >> sim.v0;

        std::cout << "Insert the angle that de velocity makes with the horizontal\n";
        std::cout << "a = ";
        std::cin >> sim.angle;

        std::cout << "Insert the gravity\n";
        std::cout << "g = ";
        std::cin >> sim.g;

        runSimulation(sim, "PROJECTILE");
    }
    case 4: {
        Pendulum sim;

        std::cout << "Insert the mass of the pendulum\n";
        std::cout << "m = ";
        std::cin >> sim.m;

        std::cout << "Insert the lenth of the rope\n";
        std::cout << "l = ";
        std::cin >> sim.l;

        std::cout << "Insert the grvity\n";
        std::cout << "g = ";
        std::cin >> sim.g;

        sim.init(sim.m, sim.g, sim.l);
        
        runSimulation(sim, "PENDULUM");

        break;
    }
        
    default:
        break;
    }


    return 0;
}