/*Tinashe Mukundi Chitamba
  Implementation file for the PGMimageprocessor class */

#include "PGMimageProcessor.h"
#include <iostream>
#include <vector>

using namespace CHTTIN007;
namespace CHTTIN007 {
    
    PGMimageProcessor::PGMimageProcessor(){}
    PGMimageProcessor::PGMimageProcessor(int r,int c){
        rows = r;
        columns = c;
    }
    
    //Implementing floodfill
    void PGMimageProcessor:: floodfill(int x,int y,ConnectedComponent* c){
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
            (c)->pixels.push_back(imagePixels[x][y]);
            floodfill(x,y+1,c);
            floodfill(x,y-1,c);
            floodfill(x+1,y,c);
            floodfill(x-1,y,c);
            return;
        }
        
    }
    
    /* Extracts the components from the pgm file, and filters by min size */
    int PGMimageProcessor::extractComponents(int threshold, int minValidSize){
        for (int x = 0;x<columns;++x){
            for(int y = 0;y<rows;++y){
                if (*imagePixels[x][y].value > threshold && imagePixels[x][y].checked == false){
                    ConnectedComponent c;
                    floodfill(x,y,&c);
                    if (c.getSize() >= minValidSize){
                        components.push_back(c);
                        std::cout<<"Component created and added to the vector with size: "<<c.getSize()<<std::endl;
                    }
                }
                else if(*imagePixels[x][y].value <= threshold && imagePixels[x][y].checked == false){
                    *imagePixels[x][y].value = 0;
                    imagePixels[x][y].checked = !imagePixels[x][y].checked ;
                }
            }
        }
        return components.size();
    }
    
    /* Get the number of components in the vector */
    int PGMimageProcessor::getComponentCount(){
        return components.size();
    }



}