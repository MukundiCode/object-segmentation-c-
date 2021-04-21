/* Tinashe Mukundi Chitamba
   This is the header file for the connected component class
   */
#include <vector>
#include "pixel.h"
namespace CHTTIN007 {

    class ConnectedComponent {
        public:
            std::vector<Pixel> pixels;
            
            //constructor
            ConnectedComponent();
            int getSize()const;
            
    
    };
    bool operator== (const ConnectedComponent &c1, const ConnectedComponent &c2);





}