/*Tinashe Mukundi CHitamba
  The pixel implementation file contains the class implementation for the pixel class
  An object of type pixel contains an x coordinate, a y coordinate, and a boolean variable, checked,
  to which is true if the pixel has been checked in the floodfill algorithm, and false if it has not been checked
  */
#include "pixel.h"
#include <string>
#include <iostream>

using namespace CHTTIN007;

namespace CHTTIN007{
    //implementing constructors
    Pixel::Pixel(){
        checked = false;
    }
    Pixel::Pixel(int xCord,int yCord,unsigned char* val){
        x = xCord;
        y = yCord;
        value = val;
        checked = false;
    }
    Pixel::~Pixel(){}
    
    //Copy constructor
    Pixel::Pixel(const Pixel & rhs): x(rhs.x),y(rhs.y),value(rhs.value),checked(rhs.checked){}
    //Move construcot
    Pixel::Pixel(Pixel && rhs): x(rhs.x),y(rhs.y),value(rhs.value),checked(rhs.checked){
        delete &rhs;
    }
    //copy assignment operator
    Pixel & Pixel::operator=(const Pixel& rhs){
        x = rhs.x;
        y = rhs.x;
        value = rhs.value;
        checked = rhs.checked;
        return *this;
    }
    //move assignment operator
    Pixel & Pixel::operator=(Pixel && rhs){
        x = rhs.x;
        y = rhs.x;
        value = rhs.value;
        checked = rhs.checked;
        delete &rhs;
        return *this;
    }
    

} 
