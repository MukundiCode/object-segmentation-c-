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
            //destructor
            ~ConnectedComponent();
            //copy constructor
            ConnectedComponent(const ConnectedComponent& rhs);
            //move constructor
            ConnectedComponent(ConnectedComponent && rhs);
            //copy assignment 
            ConnectedComponent & operator=(const ConnectedComponent& rhs);
            ConnectedComponent & operator=(ConnectedComponent && rhs);
            
            int getSize()const;
            
    
    };
    bool operator== (const ConnectedComponent &c1, const ConnectedComponent &c2);





}