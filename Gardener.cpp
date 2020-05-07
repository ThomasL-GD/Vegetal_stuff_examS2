#ifndef GARDENER_CPP
#define GARDENER_CPP
#include "Gardener.h"

int Gardener::getMoney(){
    return _money;
}

std::vector<Plant*> Gardener::getGarden(){
    return _garden;
}

bool Gardener::buyFertilizer(){
    if(_money >= 20){
        _money -= 20;
        return true;
    }
    else{
        return false;
    }
}

void Gardener::addPlant(Plant * plant){
    _garden.push_back(plant);
}

void Gardener::sellPlant(){

    int i = 0;
    std::cout << "Which plant do you want to sell ?" << std::endl;
    for(i = 0; i< _garden.size(); i++){
        std::cout << i+1 << ") " << _garden[i] -> getName() << std::endl;
    }

    std::cin >> i;

    if(_garden[i] -> getMaturity() >= 40){
        std::cout << "You sold " << _garden[i] -> getName() << std::endl;

        if(_garden[i] -> getSpecie() == "Flower"){
            if(_garden[i] -> getMaturity() >= 40 && _garden[i] -> getMaturity() < 45){
                _money += 200;
            }
            else if(_garden[i] -> getMaturity() >= 45){
                _money += 20;
            }
        }
        else if(_garden[i] -> getSpecie() == "Carnivore"){
            _money += 150;
        }
        _garden.erase(_garden.begin()+i);
    }
    else{
        std::cout << _garden[i] -> getName() << "is not mature enough to be sell" << std::endl;
    }


}

void Gardener::dayPass(){
    for(int i=0; i< _garden.size(); i++){
        _garden[i] -> dayPass();
        if (_garden[i] -> getHealth() <= 0){
            std::cout << _garden[i] -> getName() << " is dead..." << std::endl;
            _garden.erase(_garden.begin()+i);
        }
    }
}


Gardener::Gardener (int money, std::vector<Plant*> garden) : _money(money), _garden(garden) {}; //Constructeur plein

#endif