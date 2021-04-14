#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main(void) {

        std::string line;
        std::ifstream image("chess.pgm",std::ios::binary);
    
        int thresh = -96;
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
        
        //getting min for ches.pgm
        //printing vector
        std::string name = "test.pgm";
        std::ofstream MyFile(name);
        MyFile << "P5" << std::endl;
        MyFile << rows<< " "<< columns << std::endl;
        MyFile << "255" << std::endl;
        for (int x = 0;x < all.size(); x++){
            if (all[x] <= thresh){
                all[x] = -255;
            }
            else{
                all[x] = 255;
            }
            unsigned char character_binary = all[x];
            MyFile << character_binary ;
        }
        std::cout << name << " Created" << std::endl;

}