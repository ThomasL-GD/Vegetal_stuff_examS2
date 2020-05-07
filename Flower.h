#ifndef GARDENER_H
#define GARDENER_H

class Flower : public Plant{
    private:

        int _eclosion;

    public:

        void dayPass();

        Flower(std::string name, std::string specie);  //Constructeur plein

};
#endif