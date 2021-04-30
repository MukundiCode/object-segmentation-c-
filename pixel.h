/*Tinashe Mukundi Chitamba
  This is the header file for the pixel class
  */
#ifndef _Pixel_h
#define _Pixel_h
#include <string>

namespace CHTTIN007 {
    
    class Pixel{
        public:
            int x;
            int y;
            unsigned char* value;
            bool checked;
            
            //constructors
            Pixel();
            Pixel(int xCord, int yCord,unsigned char* val);
            
            //destructor 
            ~Pixel();
            //copy constructor
            Pixel(const Pixel & rhs);
            //move constructor
            Pixel(Pixel && rhs);
            //copy assignment operator
            Pixel & operator=(const Pixel& rhs);
            //move assignment operator
            Pixel & operator=(Pixel && rhs);
    };

}
#endif