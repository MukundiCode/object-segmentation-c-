/*This is the header file for the PGMImageprocessor class, that stores the data for 
  the pgm files, and the methods used to extract pgm data as well as apply connected 
  component analysis on it
  */

#include <vector>
//#include "pixel.h"
#include "ConnectedComponent.h"

namespace CHTTIN007 {
    class PGMimageProcessor{
        public:
            std::vector<std::vector<Pixel> > imagePixels;
            int threshold = -61;
            std::vector<ConnectedComponent> components;
            
            //constructors
            PGMimageProcessor(void);
            
            /*The floodfill method rakes in an x and y value then recursively check if neighbors are connected*/
            void floodfill(int x, int y,ConnectedComponent c);
    };



}