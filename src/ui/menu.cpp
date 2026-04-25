#include<iostream>
#include "menu.h"

int showMenu(){

    std::cout << "Welcome to Physics-Playground\n";
    std::cout << "---------------------\n";
    std::cout << "Choose an option to continue: \n";
    std::cout << "1 - Uniform Rectilinear Motion\n";
    std::cout << "2 - Uniform Accelerated Rectilinear Motion\n";
    std::cout << "3 - Projectile\n";
    std::cout << "4 - Pendulum\n";
    std::cout << "5 - Sprint\n";
    std::cout << "6 - Gravitation\n";
    std::cout << "7 - Collision\n";
    std::cout << "0 - Sair\n";

    int choice;

    while (true){
        std::cin >> choice;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(100000, '\n');

            std::cout << "Opcao invalida! Tente novamente.\n";

            continue;
        } else if(choice < 0 || choice > 7) {
            std::cout << "Opcao nao existe! Tente novamente.\n";
            continue;
        } else {
            break;
        }
    }

    return choice;
}