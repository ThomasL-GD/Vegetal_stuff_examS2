#include <iostream>
#include <vector>
#include <string>

#include "Plant.cpp"
#include "Gardener.cpp"

using namespace std;

void choicePlant(Plant * plant, Gardener * Selene){

    int choice = 0;
    string sChoice = "";

    while(choice == 0){

        choice = 0;
        sChoice = "";
        string name = "";

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6){

            cout << endl << "Choose something to do with your plant named " << plant -> getName() << endl << "1) Observe it" << endl << "2) Cut it" << endl << "3) Water it" << endl << "4) Rename it" << endl << "5) Fertilize it (20 PO)" << endl << "6) Quit" << endl;

            cin >> choice;

        }

        //OBSERVE IT
        if(choice == 1){
            plant -> showStatus();
        }

        //CUT IT
        if(choice == 2){
            plant -> cut();
        }

        //WATER IT
        if(choice == 3){
            plant -> water();
        }

        //RENAME IT
        if(choice == 4){
            cout << "What will be it new name ?" << endl;
            cin >> name;
            plant -> setName(name);
        }

        //FERTILIZE IT
        if(choice == 5){
            bool buy = Selene -> buyFertilizer();
            if(buy == true){
                plant -> fertilize();
            }
            else if(buy == false){
                cout << "You don't have enough money to buy a fertilizer..." << endl;
            }
        }



        //Re-entering the while loop
        if(choice >= 1 && choice <= 5){
            cout << endl << "Do you want to do something else with " << plant -> getName() << " ? (type Yes or No)" << endl;
            cin >> sChoice;
            if(sChoice == "Yes"){
                choice = 0;
            }
            else{choice = 6;}
        }

    }

}

void whichPlant(Gardener * Selene){
    vector<Plant*> garden = Selene -> getGarden();
    int i =0;

    cout << "Which plant you want to take care of ?" << endl;
    for(i = 0; i< garden.size(); i++){
        cout << i+1 << ") " << garden[i] -> getName() << endl;
    }

    int choice = 0;
    cin >> choice;

    choicePlant(garden[i-1], Selene);
    
}

void buyPlant(Gardener * Selene){
    int money = Selene -> getMoney();

    if(money >= 50){
        money -= 50;
        string name ="";
        cout << "What will be the name of your new plant ?" << endl;
        Plant * newPlant = new Plant(name, "Grass");
        Selene -> addPlant(newPlant);
    }
    else {
        cout << "You don't have enough money to buy a plant..." << endl;
    }

}

int main(){

    Plant * Veggie = new Plant("Veggie", "Grass");
    Plant * Rotiflor = new Plant("Rotiflor", "Grass");


    vector<Plant*> garden;

    garden.push_back(Veggie);
    garden.push_back(Rotiflor);


    Gardener * Selene = new Gardener(150, garden);

    bool game = true;

    while(game == true){
        int choice = 0;
        while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
            cout << endl << "What do you want to do ?" << endl << "1) Take care of my plants" << endl << "2) Sell a plant" << endl << "3) Buy a plant" << endl << "4) Go to sleep" << endl << "5) Quit game T_T" << endl;
            cin >> choice;
        }

        if(choice == 1){
            whichPlant(Selene);
        }

        if(choice == 2){
            Selene -> sellPlant();
        }

        if(choice == 3){
            buyPlant(Selene);
        }

        if(choice == 4){
            Selene -> dayPass();
        }

        if(choice == 5){
            game = false;
        }

    }

}