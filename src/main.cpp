#include "ui/menu.h"
#include "simulations/mru.h"
#include "simulations/mruv.h"
#include "simulations/projectile.h"
#include "simulations/pendulum.h"
#include "simulations/spring.h"
#include "simulations/gravitation.h"
#include "simulations/collision.h"
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

        break;
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
    case 5: {
        Spring sim;

        std::cout << "Insert the mass of the particle\n";
        std::cout << "m = ";
        std::cin >> sim.m;

        std::cout << "Insert the spring constant\n";
        std::cout << "k = ";
        std::cin >> sim.k;

        sim.init(sim.m, sim.k);

        runSimulation(sim, "SPRING");

        break;
    }
    case 6: {
        Simulation sim;
        float m, M, r, v;

        std::cout << "Insert the mass of the sun\n";
        std::cout << "M = ";
        std::cin >> M;

        std::cout << "Insert the mass of the planet\n";
        std::cout << "m = ";
        std::cin >> m;

        std::cout << "Insert the inicial velocity\n";
        std::cout << "v0 = ";
        std::cin >> v;

        std::cout << "Insert the distance between the sun and the planet\n";
        std::cout << "r = ";
        std::cin >> r;

        sim.init(M, m, v, r);

        runSimulation(sim, "GRAVITATION");

        break;
    }
    case 7: {
        SimulationCol sim;
        float m1, m2, v1, v2, e;

        std::cout << "Insert the mass of the first particle\n";
        std::cout << "m1 = ";
        std::cin >> m1;

        std::cout << "Insert the mass of the second particle\n";
        std::cout << "m2= ";
        std::cin >> m2;

        std::cout << "Insert the inicial velocity of the first particle\n";
        std::cout << "v1 = ";
        std::cin >> v1;

        std::cout << "Insert the velocity of the second particle\n";
        std::cout << "v2 = ";
        std::cin >> v2;

        std::cout << "Insert the coefficient of restituition\n";
        std::cout << "e = ";
        std::cin >> e;

        sim.init(m1, m2, v1, v2, e);

        runSimulation(sim, "COLLISION");

        break;
    }
    case 0:{
        std::cout << "end\n";
        break;
    }   
    default:
        break;
    }


    return 0;
}