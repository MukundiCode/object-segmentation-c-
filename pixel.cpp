/*Tinashe Mukundi CHitamba
  The pixel implementation file contains the class implementation for the pixel class
  An object of type pixel contains an x coordinate, a y coordinate, and a boolean variable, checked,
  to which is true if the pixel has been checked in the floodfill algorithm, and false if it has not been checked
  */

#include "pixel.h"
#include <string>

using namespace CHTTIN007;

namespace CHTTIN007{
    //implementing constructors
    Pixel::Pixel(){}
    Pixel::Pixel(int xCord,int yCord,int val){
        x = xCord;
        y = yCord;
        value = val;
        checked = false;
    }

} 