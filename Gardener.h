#ifndef GARDENER_H
#define GARDENER_H

class Gardener{
    private:

        int _money;
        std::vector<Plant*> _garden;

    public:

        int getMoney();
        std::vector<Plant*> getGarden();

        bool buyFertilizer();
        void addPlant(Plant * plant);

        void sellPlant();

        void dayPass();

        Gardener(int money, std::vector<Plant*> garden);  //Constructeur plein

};
#endif