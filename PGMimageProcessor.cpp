/*Tinashe Mukundi Chitamba
  Implementation file for the PGMimageprocessor class */

#include "PGMimageProcessor.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

using namespace CHTTIN007;
namespace CHTTIN007 {
    
    PGMimageProcessor::PGMimageProcessor(){}
    PGMimageProcessor::PGMimageProcessor(int r,int c,int t){
        rows = r;
        columns = c;
        threshold = t;
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
            c->pixels.push_back(imagePixels[x][y]);
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
                        c.id = components.size();
                        c.pixelCount = c.getSize();
                        components.push_back(c);
                        std::cout<<"Component created with size "<<components.back().getSize()<<" and ID "<<c.id<<" and added to components vector."<<std::endl;
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
    int PGMimageProcessor::getComponentCount()const{
        return components.size();
    }
    
    /* create a new PGM file which contains all current components
    (255=component pixel, 0 otherwise) and write this to outFileName as a
    valid PGM. the return value indicates success of operation
    */
    bool PGMimageProcessor::writeComponents(const std::string & outFileName){
        std::string name = outFileName;
        std::ofstream MyFile(name);
        MyFile << "P5" << std::endl;
        MyFile << rows<< " "<< columns << std::endl;
        MyFile << "255" << std::endl;
        for (int x=0;x<columns;++x){
            for(int y=0;y<rows;++y){
                unsigned char binary = *imagePixels[x][y].value;
                MyFile << binary ;
            }
        }
        std::cout << name << " Created" << std::endl;
        return true;
    }
    
    /* iterate - with an iterator - though your container of connected
    components and filter out (remove) all the components which do not
    obey the size criteria pass as arguments. The number remaining
    after this operation should be returned.
    */
    int PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){
        for(std::vector<ConnectedComponent>::iterator i= components.begin();i != components.end(); ++i ){
            if ((*i).getSize() < minSize || (*i).getSize() > maxSize){
                components.erase(i--);
            }
        }
        return components.size();
    }
    
    // return number of pixels in largest component
    int PGMimageProcessor::getLargestSize(void) const{
        int largest = 0;
        for(std::vector<ConnectedComponent>::const_iterator i= components.begin();i != components.end(); ++i ){
            if ((*i).getSize() > largest){
                largest = (*i).getSize();
            }
        }
        return largest;
    }
    
    // return number of pixels in smallest component
    int PGMimageProcessor::getSmallestSize(void) const{
        int smallest = components.back().getSize();
        for(std::vector<ConnectedComponent>::const_iterator i= components.begin();i != components.end(); ++i ){
            if ((*i).getSize() < smallest){
                smallest = (*i).getSize();
            }
        }
        return smallest;
    
    }
    
    /* print the data for a component to std::cout
    see ConnectedComponent class;
    print out to std::cout: component ID, number of pixels
    */
    void PGMimageProcessor::printComponentData(const ConnectedComponent & theComponent) const{
        int counter = 0;
        for(std::vector<ConnectedComponent>::const_iterator i= components.begin();i != components.end(); ++i ){
            if ((*i) == theComponent){
                std::cout<<counter<<","<<(*i).getSize()<<std::endl;
            }
            counter++;
        }
    
    }





}