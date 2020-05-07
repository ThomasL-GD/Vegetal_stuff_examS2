#include <iostream>
#include <vector>
#include <string>

#include "Plant.cpp"

using namespace std;

void choicePlant(Plant * plant){

    int choice = 0;
    string sChoice = "";

    while(choice == 0){

        choice = 0;
        sChoice = "";
        string name = "";

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){

            cout << endl << "Choose something to do with your plant named " << plant -> getName() << endl << "1) Observe it" << endl << "2) Cut it" << endl << "3) Water it" << endl << "4) Rename it" << endl << "5) Fertilize it (50 PO)" << endl << "6) Quit" << endl;

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
            plant -> fertilize();
            //money loss
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

int main(){

    Plant * Veggie = new Plant("Veggie", "Grass");

    Veggie -> showStatus();

    choicePlant(Veggie);

    Veggie -> dayPass();

    Veggie -> showStatus();

}