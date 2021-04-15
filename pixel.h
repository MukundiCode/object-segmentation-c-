/*Tinashe Mukundi Chitamba
  This is the header file for the pixel class
  */
#include <string>

namespace CHTTIN007 {
    
    class Pixel{
        public:
            int x;
            int y;
            int value;
            bool checked;
            
            //constructors
            Pixel();
            Pixel(int xCord, int yCord,int val);
    };



}