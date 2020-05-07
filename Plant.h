#ifndef PLANT_H
#define PLANT_H

class Plant{
    private:

        int _int;
        std::string _name;

    public:

        int getInt();

        void setString(std::string string);

        Plant(); //Constructeur vide
        Plant(int qqch, std::string name);  //Constructeur plein

};
#endif