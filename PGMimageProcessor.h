/*This is the header file for the PGMImageprocessor class, that stores the data for 
  the pgm files, and the methods used to extract pgm data as well as apply connected 
  component analysis on it
  */
#ifndef _PGMimageProcessor_h
#define _PGMimageProcessor_h
#include <vector>
//#include "pixel.h"
#include "ConnectedComponent.h"

namespace CHTTIN007 {
    class PGMimageProcessor{
        private:
            std::vector<std::vector<Pixel> > imagePixels;
        public:
            int rows;
            int columns;
            int threshold = -61;
            //constructors
            PGMimageProcessor(void);
            PGMimageProcessor(int r,int c,int t);
            //destructor
            ~PGMimageProcessor() = default;
            //copy constructor
            PGMimageProcessor(const PGMimageProcessor& rhs) = default;
            //move constructor
            PGMimageProcessor(PGMimageProcessor && rhs) = default;
            //copy assignment 
            PGMimageProcessor & operator=(const PGMimageProcessor& rhs) = default;
            PGMimageProcessor & operator=(PGMimageProcessor && rhs) = default;
            
            std::vector<std::vector<Pixel> >* getImagePixels();
            /*The floodfill method rakes in an x and y value then recursively check if neighbors are connected*/
            void floodfill(int x, int y,ConnectedComponent* c);
            int extractComponents(int threshold, int minValidSize);
            int getComponentCount()const;
            bool writeComponents(const std::string & outFileName);
            int filterComponentsBySize(int minSize,int maxSize);
            int getLargestSize(void)const;
            int getSmallestSize(void) const;
            void printComponentData(const ConnectedComponent & theComponent) const;
        private:
            std::vector<ConnectedComponent> components;
    
    };



}
#endif