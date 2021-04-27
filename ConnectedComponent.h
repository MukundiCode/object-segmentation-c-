/* Tinashe Mukundi Chitamba
   This is the header file for the connected component class
   */
#ifndef _CnnectedComponent_h
#define _ConnectedComponent_h
#include <vector>
#include "pixel.h"
namespace CHTTIN007 {

    class ConnectedComponent {
        public:
            int id;
            int pixelCount;
            std::vector<Pixel> pixels;
            
            //constructor
            ConnectedComponent();
            //destructor
            ~ConnectedComponent();
            //copy constructor
            ConnectedComponent(const ConnectedComponent& rhs) = default;
            //move constructor
            ConnectedComponent(ConnectedComponent && rhs) = default;
            //copy assignment 
            ConnectedComponent & operator=(const ConnectedComponent& rhs) = default;
            ConnectedComponent & operator=(ConnectedComponent && rhs) = default;
            
            int getSize()const;
            
    
    };
    bool operator== (const ConnectedComponent &c1, const ConnectedComponent &c2);

}
#endif