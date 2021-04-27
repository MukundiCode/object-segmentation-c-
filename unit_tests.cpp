#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PGMimageProcessor.h"

using namespace CHTTIN007;

TEST_CASE("PGMimageProcessor Methods"){
    //Creating the pgmprocessor object to test
    int minSize = 3;
    int maxSize = 7000;
    int threshold = -61;
    std::string outFile = "testOutputFile.pgm";
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
            for (char c : line){
                int y = c;
                all.push_back(c);
            }
        }
        /*else{
            std::cout <<"PGM Header info: "<< line << std::endl;
        } */     
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
            //int value = all[pos]; 
            Pixel p(x,y,&all[pos]);
            pixelrow.push_back(p);
            pos++;
        }
        imageProcessor.imagePixels.push_back(pixelrow);
    }
    SECTION("Constructor"){
        REQUIRE(imageProcessor.rows == rows);
    }
    
    SECTION("Constructor"){
        REQUIRE(imageProcessor.rows == rows);
    }
    
    SECTION( "Move Assignment Operator" ) {
        PGMimageProcessor p = PGMimageProcessor(3,4,-10);
        p = std::move(imageProcessor);
        REQUIRE(p.rows == imageProcessor.rows);
    }
    
    SECTION( "Copy Assignment Operator" ) {
        PGMimageProcessor p = PGMimageProcessor(3,4,-10);
        p = imageProcessor;
        REQUIRE(p.rows == imageProcessor.rows);
    }
    
        
    SECTION("Component Methods"){
        REQUIRE(imageProcessor.extractComponents(threshold,0) == 6);
        REQUIRE(imageProcessor.getComponentCount() == 6);
        REQUIRE(imageProcessor.filterComponentsBySize(minSize,maxSize) == 3);
        REQUIRE(imageProcessor.getLargestSize() == 6458);
        REQUIRE(imageProcessor.getSmallestSize() == 4275);
        REQUIRE(imageProcessor.writeComponents(outFile) == true);
    }
    
    SECTION( "Move Constructor" ) {
        PGMimageProcessor p = std::move(imageProcessor);
        REQUIRE(p.rows == imageProcessor.rows);
    }
}
#endif