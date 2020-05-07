#ifndef PLANT_H
#define PLANT_H

class Plant{
    protected:

        int _maturity;
        int _health;
        int _density;
        int _hydratation;
        bool _fertilizer;
        std::string _name;
        std::string _specie;

    public:

        std::string getName();
        int getHealth();
        int getMaturity();

        void setName(std::string name);

        void showStatus();
        void cut();
        void water();
        void fertilize();

        void dayPass();


        Plant(); //Constructeur vide
        Plant(std::string name, std::string specie);  //Constructeur plein

};
#endif