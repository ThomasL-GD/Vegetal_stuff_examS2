#ifndef FLOWER_CPP
#define FLOWER_CPP
#include "Flower.h"


void Plant::dayPass(){

    if(_density <= 0){
        _health -= 1;
        std::cout << _name << " was cut too much" << std::endl;
    }
    else if(_density >= 5){
        _health -= 1;
        std::cout << _name << " was not cut enough" << std::endl;
    }

    if(_hydratation <= 0){
        _health -= 1;
        std::cout << _name << " was too thirsty" << std::endl;
    }
    else if(_hydratation >= 5){
        _health -= 1;
        std::cout << _name << " was too watered" << std::endl;
    }


    if(_fertilizer == true){
        _maturity += _health*2;
        //Fertilizer authorize regeneration
        if(_health < 5){
            _health += 1;
        }
    }
    else if(_fertilizer == false){
        _maturity += _health;
    }

    if(_maturity >= 40 && _maturity < 45){
        _eclosion = 1;
    }
    esle if(_maturity >= 45){
        _eclosion = 2;
    }


    _fertilizer = false;
    _density += 3;
    _hydratation -= 3;
}


Plant::Plant (std::string name, std::string specie) : Plant(name, specie), _eclosion(0) {}; //Constructeur plein

#endif