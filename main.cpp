#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "Truck.h"
#include "Box.h"
using namespace std;

int LineCounter(char* fileName)
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen(fileName, "r");         //Opening file as read only

    if (filePointer == NULL)                    //If file is not found
    {
        perror ("Error opening file");          //Show Error
        return 0;
    }

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}
//To find the number of trucks/entries
int EntriesCounter(char* fileName)
{
    int numOfLines = LineCounter("Drivers.txt");
    int noOfTrucks = numOfLines / 5;                      //totalLines/5 gives the number of entries
    return noOfTrucks;
}
//Truck does the journey and petrol in the truck is updated
Truck* WriteFile(Truck truckObj, Truck* trucks, int numberOfEntries, int& numberOfBoxes, ofstream& myfile)
{
    cout<<endl<<"Loading of trucks!!!"<<endl<<endl;
    for (int n = 0; n < numberOfEntries; n++)
    {
        if (truckObj.Cost(trucks[n]) == true)   //If the truck has enough money to fill it's tank to 50 liters of petrol and mileage
        {
            cout << "Truck driver is: " << trucks[n].get_driver();
            numberOfBoxes = 12 + (rand() % (20 - 12 + 1));
            trucks[n].Load(numberOfBoxes);    //Loading random number of boxes
            float petrolNeededLoaded = 60 / (float)trucks[n].get_fullMileage();    //Petrol needed to travel 60km when loaded
            float petrolNeededEmpty = 60 / (float)trucks[n].get_emptyMileage();    //Petrol needed to travel 60km when unloaded
            float totalPetrolUsed = petrolNeededEmpty + petrolNeededLoaded;   //Total petrol required
            float remainingPetrol = trucks[n].get_petrol() - totalPetrolUsed; //required petrol deducted from the petrol of the truck
            trucks[n].set_petrol(remainingPetrol);  //petrol of the truck updated
            myfile<<"Truck driver is: "<<trucks[n].get_driver();    //Writing in the Trip.txt file
            myfile<<"Truck petrol is: "<<trucks[n].get_petrol()<<endl;
            myfile<<"Truck money is: "<<trucks[n].get_money()<<endl;
            myfile<<"Truck empty mileage is: "<<trucks[n].get_emptyMileage()<<endl;
            myfile<<"Truck full mileage is: "<<trucks[n].get_fullMileage()<<endl<<endl;
        }
        else    //When the cost returns false which means the truck doesnt has enough money to fill it's tank to 50 liters
        {
            cout<<endl<<"Truck which can't travel due to insufficient money: "<<trucks[n].get_driver()<<endl;
        }
    }
    return trucks;
}
//To read the file and set that line to a variable and loading of trucks
void ReadAndAssign(int numberOfEntries, Truck* trucks, FILE* filePointer, char* buff)
{
    for (int k = 0; k < numberOfEntries; k++)
        {
            fgets(buff, 32, (FILE*)filePointer); //Reading the name of the driver directly
            trucks[k].set_driver(buff);

            fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
            trucks[k].set_petrol(atoi(buff));          //Converting the string to integer and setting it to petrol of that truck

            fgets(buff, 32, (FILE*)filePointer);
            trucks[k].set_money(atoi(buff));          //Converting the string on 3rd line of the file to integer and setting it to money of that truck

            fgets(buff, 32, (FILE*)filePointer);
            trucks[k].set_emptyMileage(atoi(buff));  //string to int and setting it to emptyMileage

            fgets(buff, 32, (FILE*)filePointer);
            trucks[k].set_fullMileage(atoi(buff));  //string to int and setting it to fullMileage
    }
    return;
}
int main()
{
    srand(time(NULL));

    cout<<LineCounter("Drivers.txt")<<endl;     //Counts the number of lines in the input file

    FILE* filePointer;   //Declaring a file pointer
    ofstream myfile;    //To write in a file as output

    char buff[32];    //Declaring a character array to store a line
    int numberOfEntries;
    Truck* trucks;  //Trucks dynamic array
    Truck truckObj;
    int numberOfBoxes;

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    myfile.open("Trip.txt");    // Open/creates a new file to write

    if (filePointer == NULL)
    {
        perror ("Error opening file");  //Pops error when the program reads nothing in the file
        return 0;
    }
    else
    {
        numberOfEntries = EntriesCounter("Drivers.txt");    //Number of trucks
        cout<<"Number of trucks: "<<numberOfEntries<<endl;
        trucks = new Truck[numberOfEntries];
        ReadAndAssign(numberOfEntries, trucks, filePointer, buff);    //To read the file and set that line to a variable
        WriteFile(truckObj, trucks, numberOfEntries, numberOfBoxes, myfile);   //If Truck fulfills the conditions of journey then that truck is loaded and written in the output file
    }

    cout<<endl<<"Unloading of trucks!!!"<<endl<<endl;
    for (int n = 0; n < numberOfEntries; n++)
    {
        if(truckObj.Cost(trucks[n]) == true)
        {
            cout<<"Boxes in truck of "<<trucks[n].get_driver();
            trucks[n].Unload();  //To unload the trucks and deallocate box dynamic array
            cout<<endl;
        }
    }

    fclose(filePointer);    //Closes the input file
    myfile.close();         //Closes the output file

    delete [] trucks;   //Deallocation of truck's dynamics array
    trucks = NULL;
    return 0;
}

