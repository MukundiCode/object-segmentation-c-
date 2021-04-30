#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "PGMimageProcessor.h"

using namespace CHTTIN007;
int main(int argc, char* argv[]) {


    std::string filename;
    //declaring defaults
    int minSize = 3;
    int threshold = 128;
    if (argc > 1){
        filename = argv[1];
        minSize = atoi(argv[3]);
        int maxSize = atoi(argv[4]);
        threshold = atoi(argv[6]);
        std::string outFile = argv[9];

        std::string line;
        std::ifstream image(filename,std::ios::binary);
        
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
                std::cout <<"PGM Header info: "<< line << std::endl;
                }
                
            if (line == "255"){
                std::istringstream iss(prevLine);
                iss >> rows;
                iss >> columns;
                read = !read;  
                }
            if (read == false){
                prevLine = line;
                }   
        }
        
        PGMimageProcessor imageProcessor(rows,columns,threshold);
        //Loop to create vector of pixel objects
        int pos = 0;
        for (int x=0;x<columns;++x){
            std::vector<Pixel> pixelrow;
            for(int y=0;y<rows;++y){
                Pixel p(x,y,&all[pos]);
                pixelrow.push_back(p);
                pos++;
            }
            imageProcessor.imagePixels.push_back(pixelrow);
        }
        
        
        int noOfComps = imageProcessor.extractComponents(threshold,minSize);
        std::cout<< "Number of components: "<< imageProcessor.getComponentCount() << std::endl;
        std::cout<< "Largest component is: "<< imageProcessor.getLargestSize() << std::endl;
        std::cout<< "Smallest component is: "<< imageProcessor.getSmallestSize() << std::endl;
        std::cout<< "Number of components after filter: "<<imageProcessor.filterComponentsBySize(minSize,maxSize)<<std::endl;
        //printing vector
        imageProcessor.writeComponents(outFile);
        
    }
    
    
    //if no commandline args
    else {
        std::cout << "Please add valid commandline arguments" << std::endl;
    }
    

}

