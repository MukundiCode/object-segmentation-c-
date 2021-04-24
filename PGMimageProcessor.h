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
            int rows;
            int columns;
            std::vector<std::vector<Pixel> > imagePixels;
            int threshold = -61;
            std::vector<ConnectedComponent> components;
            
            //constructors
            PGMimageProcessor(void);
            PGMimageProcessor(int r,int c);
            //destructor
            ~PGMimageProcessor() = default;
            //copy constructor
            PGMimageProcessor(const PGMimageProcessor& rhs) = default;
            //move constructor
            PGMimageProcessor(PGMimageProcessor && rhs) = default;
            //copy assignment 
            PGMimageProcessor & operator=(const PGMimageProcessor& rhs) = default;
            PGMimageProcessor & operator=(PGMimageProcessor && rhs) = default;
            
            
            /*The floodfill method rakes in an x and y value then recursively check if neighbors are connected*/
            void floodfill(int x, int y,ConnectedComponent* c);
            int extractComponents(int threshold, int minValidSize);
            int getComponentCount()const;
            bool writeComponents(const std::string & outFileName);
            int filterComponentsBySize(int minSize,int maxSize);
            int getLargestSize(void)const;
            int getSmallestSize(void) const;
            void printComponentData(const ConnectedComponent & theComponent) const;
    };



}