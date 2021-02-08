#include "Box.h"
#include <iostream>
using namespace std;
//Randomly generates length, width, height between 5 to 30 inches
Box::Box()
{
    length  = rand() % (30 - 5 + 1) + 5;
    height  = rand() % (30 - 5 + 1) + 5;
    width  = rand() % (30 - 5 + 1) + 5;
}
//Gives the volume
int Box::Volume()
{
    int vol = length * height * width;
    return vol;
}
//Get function to access private variable of Box class
int Box::get_length()
{
    return length;
}
//Get function to access private variable of Box class
int Box::get_width()
{
    return width;
}
//Get function to access private variable of Box class
int Box::get_height()
{
    return height;
}
