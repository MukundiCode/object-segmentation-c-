/* Tinashe Mukundi Chitamba
   Implementation file for the connectedComponent class
   */
   
#include "ConnectedComponent.h"
#include <vector>

using namespace CHTTIN007;

namespace CHTTIN007 {

    ConnectedComponent::ConnectedComponent(){};
    //destructor
    
    ConnectedComponent::~ConnectedComponent(){}
    //copy constructor
    ConnectedComponent::ConnectedComponent(const ConnectedComponent& rhs){
        for(int i = 0;i<pixels.size();i++){
            pixels[i] = rhs.pixels[i];
        }
    }
    //move constructor
    ConnectedComponent::ConnectedComponent(ConnectedComponent && rhs){
        for(int i = 0;i<pixels.size();i++){
            pixels[i] = rhs.pixels[i];
        }
        for(int i = 0;i<pixels.size();i++){
           // delete &rhs.pixels[i];
        }
    }
    //copy assignment
   ConnectedComponent & ConnectedComponent::operator=(const ConnectedComponent& rhs){
       for(int i = 0;i<pixels.size();i++){
            pixels[i] = rhs.pixels[i];
        }
        return *this;
   }
   //move assignment
   ConnectedComponent & ConnectedComponent::operator=(ConnectedComponent &&rhs){
       for(int i = 0;i<pixels.size();i++){
            pixels[i] = rhs.pixels[i];
        }
        for(int i = 0;i<pixels.size();i++){
           // delete &rhs.pixels[i];
        }
        return *this;
   }
    
    //To get the size of the component
    int ConnectedComponent::getSize()const{
        return pixels.size();
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