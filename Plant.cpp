#ifndef PLANT_CPP
#define PLANT_CPP
#include "Plant.h"


std::string Plant::getName(){
    return _name;
}

std::string Plant::getSpecie(){
    return _specie;
}

int Plant::getHealth(){
    return _health;
}

int Plant::getMaturity(){
    return _maturity;
}

void Plant::setName(std::string name){
    _name = name;
}

void Plant::showStatus(){
    std::cout << std::endl << "-> " << _name << " ( " << _specie << " )" << std::endl << "- Health : " << _health << "/5" << std::endl 
    << "- Maturity : " << _maturity << std::endl << "- Density : " << _density << std::endl << "- Hydratation : " << _hydratation << std::endl;
}

void Plant::cut(){
    _density -= 2;
    std::cout << "You cut " << _name << std::endl;
}

void Plant::water(){
    _hydratation += 2;
    std::cout << "You watered " << _name << std::endl;
}

void Plant::fertilize(){
    if(_fertilizer == false){
        _fertilizer = true;
        std::cout << "You put fertilizer on " << _name << std::endl;
    }
    else if (_fertilizer == true){
        std::cout << _name << " already have fertilizer on it" << std::endl;
    }
}


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


    _fertilizer = false;
    _density += 3;
    _hydratation -= 3;
}


Plant::Plant () : _maturity(0), _health(5), _density(1), _hydratation(1), _fertilizer(false), _name("Vegetal"), _specie("Unknow") {}; //Constructeur vide
Plant::Plant (std::string name, std::string specie) : _maturity(0), _health(5), _density(1), _hydratation(1), _fertilizer(false), _name(name), _specie(specie) {}; //Constructeur plein

#endif