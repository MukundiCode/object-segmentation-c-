/* Tinashe Mukundi Chitamba
   Implementation file for the connectedComponent class
   */
   
#include "ConnectedComponent.h"
#include <vector>

using namespace CHTTIN007;

namespace CHTTIN007 {

    ConnectedComponent::ConnectedComponent(){};
    
    //To get the size of the component
    int ConnectedComponent::getSize(){
        return pixels.size();
    }

}