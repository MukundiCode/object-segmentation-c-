/* Tinashe Mukundi Chitamba
   Implementation file for the connectedComponent class
   */
   
#include "ConnectedComponent.h"
#include <vector>

using namespace CHTTIN007;

namespace CHTTIN007 {

    ConnectedComponent::ConnectedComponent(){
        boundaryCount = 0;
    };
    
    //destructor
    ConnectedComponent::~ConnectedComponent(){}
    
    //To get the size of the component
    int ConnectedComponent::getSize()const{
        return pixels.size();
    }
    
    int ConnectedComponent::getBoundary()const{
        return boundaryCount;
    }
    
    void ConnectedComponent::incrementBoundary(){
        boundaryCount++;
    }
    
    // == operator overload
    bool operator== (const ConnectedComponent &c1, const ConnectedComponent &c2){
        if( c1.getSize() != c2.getSize()){
            return false;
        }
        else {
            for(int i = 0;i<c1.getSize();++i){
                if (c1.pixels[i].value != c2.pixels[i].value){
                    return false;
                }
                else{
                    continue;
                }
            }
        return true;
        }
    }

}