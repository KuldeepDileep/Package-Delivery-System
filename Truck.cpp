#include "Truck.h"
#include <iostream>
using namespace std;
//Creates a dynamics array of boxes and then prints the dimensions randomly between 5 and 30.
Box* Truck::Load(int numBox)
{
    numberOfBoxes = numBox;
    box = new Box [numBox]; //dynamic array of box
    for (int m = 0; m < numBox; m++)
    {
        cout<<"Dimensions of Box "<<m+1<<endl;
        cout<<"Length: "<<box[m].get_length()<<endl;
        cout<<"Height: "<<box[m].get_height()<<endl;
        cout<<"Width: "<<box[m].get_width()<<endl;
    }
    return box;
}
//Unload prints the dimensions of Box and then deallocates memory
void Truck::Unload()
{
    int numBox = numberOfBoxes;
    for (int j = 0; j < numBox; j++)
    {
        cout<<"Dimensions of Box "<<j+1<<endl;
        cout<<"Length: "<<box[j].get_length()<<endl;
        cout<<"Height: "<<box[j].get_height()<<endl;
        cout<<"Width: "<<box[j].get_width()<<endl;
        //cout<<"Volume of Box "<<j+1<<box[j].Volume()<<endl;
    }
    delete [] box;  //deallocation of box dynamic array
    box = NULL;
}
//Cost function tells if the truck has enough to fill it's tank to max limit that is 50 liters
bool Truck::Cost(Truck &truck)
{
    if (truck.petrol < 50)    //If truck's fuel is less than 50 which means it needs to fill it's tank to 50 liters
    {
        int petrolNeeded = 50 - truck.petrol;   //Petrol needed to fill tank to 50 liters
        float moneyNeeded = petrolNeeded * 2.73;    //money needed for the petrol
        int petrolUsed = 60 / truck.get_fullMileage() + 60 / truck.get_emptyMileage();  //petrol used throughout the journey
        if (truck.money > moneyNeeded && petrolUsed <= 50)    //If petrol used throughout the journey is in the range of 50 liters
        {                                                  // and the truck has enough money to fill the tank with the required fuel
            truck.money = truck.money - moneyNeeded;    //money deducted
            truck.petrol += petrolNeeded;   //petrol added
        }
        else
        {
            return false;
        }
    }
    return true;
}
//Get function to access private attribute like driver
char* Truck::get_driver()
{
    return driver;
}
//Set function to set/assign value to a private attribute
void Truck::set_driver(char* n)
{
    for (int p = 0; p < 32; p++)    //Since driver is a dynamic array whereas, name read from the file is string/char
    {
        driver[p] = n[p];
    }
}
//Get function to access private attribute i.e. petrol
float Truck::get_petrol()
{
    return petrol;
}
//Set function to set/assign value to a private attribute
void Truck::set_petrol(float n)
{
    petrol = n;
}
//Get function to access private attribute i.e. money
float Truck::get_money()
{
    return money;
}
//Set function to set/assign value to a private attribute
void Truck::set_money(int n)
{
    money = n;
}
//Get function to access private attribute i.e. fullMileage
int Truck::get_fullMileage()
{
    return fullMileage;
}
//Set function to set/assign value to a private attribute
void Truck::set_fullMileage(int n)
{
    fullMileage = n;
}
//Get function to access private attribute i.e. emptyMileage
int Truck::get_emptyMileage()
{
    return emptyMileage;
}
//Set function to set/assign value to a private attribute
void Truck::set_emptyMileage(int n)
{
    emptyMileage = n;
}
