#pragma once
#include "Box.h"

class Truck
{
    private:
        //private data and functions
        char driver[32];
        float petrol;
        float money;
        int fullMileage;
        int emptyMileage;
        int numberOfBoxes;
    public:
        Box* box;
        Box* Load(int numBox);
        void Unload();
        bool Cost(Truck &truck);
        char* get_driver();
        void set_driver(char* n);
        float get_petrol();
        void set_petrol(float n);
        float get_money();
        void set_money(int n);
        int get_fullMileage();
        void set_fullMileage(int n);
        int get_emptyMileage();
        void set_emptyMileage(int n);
};

