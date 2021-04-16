#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "PGMimageProcessor.h"

using namespace CHTTIN007;
int main(void) {

        std::string line;
        std::ifstream image("chess.pgm",std::ios::binary);
    
        int thresh = -96;
        int counter = 0;
        bool read = false;
        std::string prevLine = "";
        int rows = 0;
        int columns = 0;
        PGMimageProcessor imageProcessor;
        
        //extracting the file contents and loading them into a 1D vector
        std::vector<int> all ;
        while (std::getline(image, line)) {
            counter++;
            if (read == true) {
                //unsigned char n = '\n';
                //int a = n;
                //all.push_back(a);
                for (char c : line){
                    int y = c;
                    all.push_back(c);
                    }
                }
            else{
                std::cout << line << std::endl;
                }
                
            if (line == "255"){
                std::istringstream iss(prevLine);
                iss >> rows;
                iss >> columns;
                //std::cout << "Rows "<< rows<< " and Columns " << columns << std::endl;
                read = !read;  
                }
            if (read == false){
                prevLine = line;
                }   
        }
        
        int pos = 0;
        for (int x=0;x<columns;++x){
            std::vector<Pixel> pixelrow;
            for(int y=0;y<rows;++y){
                int value = all[pos]; 
                Pixel p(x,y,value);
                pixelrow.push_back(p);
                pos++;
            }
            imageProcessor.imagePixels.push_back(pixelrow);
        }
        
        //trying the floodfill method
        for (int x = 0;x<columns;++x){
            for(int y = 0;y<rows;++y){
                imageProcessor.floodfill(x,y);
            }
        }
        
        std::cout<< "Size of row is: "<<imageProcessor.imagePixels[0].size()<<" and must be "<< rows << std::endl;
        std::cout<< "Size of column is: "<<imageProcessor.imagePixels.size() << std::endl;
        //getting min for ches.pgm
        //printing vector
        std::string name = "test.pgm";
        std::ofstream MyFile(name);
        MyFile << "P5" << std::endl;
        MyFile << rows<< " "<< columns << std::endl;
        MyFile << "255" << std::endl;
        for (int x=0;x<columns;++x){
            for(int y=0;y<rows;++y){
            /*
                if (imageProcessor.imagePixels[x][y].value <= thresh){
                    imageProcessor.imagePixels[x][y].value = 0;
                }
                else{
                    imageProcessor.imagePixels[x][y].value = 255;
                } */
                unsigned char binary = imageProcessor.imagePixels[x][y].value;
                MyFile << binary ;
            }
        }
        std::cout << name << " Created" << std::endl;

}
