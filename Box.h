#pragma once

class Box
{
    private:
        int length;
        int width;
        int height;
    public:
        Box();  //Constructor
        //Operations
        int Volume();
        int get_length();
        int get_height();
        int get_width();
};

