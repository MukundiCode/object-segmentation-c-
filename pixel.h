/*Tinashe Mukundi Chitamba
  This is the header file for the pixel class
  */
#include <string>


namespace CHTTIN007 {
    
    class Pixel{
        public:
            int x;
            int y;
            int* value;
            bool checked;
            
            //constructors
            Pixel();
            Pixel(int xCord, int yCord,int* val);
            
            /*
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
            */
    };



}