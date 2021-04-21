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
        int counter = 0;
        bool read = false;
        std::string prevLine = "";
        int rows = 0;
        int columns = 0;
        
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
        
        PGMimageProcessor imageProcessor(rows,columns);
        //Loop to create vector of pixel objects
        int pos = 0;
        for (int x=0;x<columns;++x){
            std::vector<Pixel> pixelrow;
            for(int y=0;y<rows;++y){
                //int value = all[pos]; 
                Pixel p(x,y,&all[pos]);
                pixelrow.push_back(p);
                pos++;
            }
            imageProcessor.imagePixels.push_back(pixelrow);
        }
        
        int noOfComps = imageProcessor.extractComponents(-61,0);
        std::cout<< "Number of components: "<< imageProcessor.getComponentCount() << std::endl;
        std::cout<< "Number of components after filer: "<<imageProcessor.filterComponentsBySize(4500,7000)<<std::endl;
        //printing vector
        imageProcessor.writeComponents("test.pgm");

}
