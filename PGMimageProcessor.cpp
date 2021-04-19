/*Tinashe Mukundi Chitamba
  Implementation file for the PGMimageprocessor class */

#include "PGMimageProcessor.h"
#include <iostream>

using namespace CHTTIN007;
namespace CHTTIN007 {
    
    PGMimageProcessor::PGMimageProcessor(){}
    
    
    //Implementing floodfill
    void PGMimageProcessor:: floodfill(int x,int y,ConnectedComponent c){
        if (x >= imagePixels.size() || y >= imagePixels[0].size() || x < 0 || y < 0){
            return;
        }
        else if(imagePixels[x][y].checked == true){
            return;
        }
        else if(*imagePixels[x][y].value <= threshold){
            *imagePixels[x][y].value = 0;
            imagePixels[x][y].checked = !imagePixels[x][y].checked;
            return;
        }
        else{
            *imagePixels[x][y].value = 255;
            imagePixels[x][y].checked = !imagePixels[x][y].checked;
            c.pixels.push_back(imagePixels[x][y]);
            floodfill(x,y+1,c);
            floodfill(x,y-1,c);
            floodfill(x+1,y,c);
            floodfill(x-1,y,c);
            return;
        }
        
    }



}