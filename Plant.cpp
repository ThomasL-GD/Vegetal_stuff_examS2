#ifndef PLANT_CPP
#define PLANT_CPP
#include "Plant.h"


int Plant::getInt(){
    return _int;
}

void setString(std::string string){
    _name = string;
}


Plant::Plant () : _int(0), _name("rien") {}; //Constructeur vide
Plant::Plant (int qqch, std::string name) : _int(qqch), _name(name) {}; //Constructeur plein

#endif