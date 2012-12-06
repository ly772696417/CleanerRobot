#include<iostream>
#include "brain.h"

Brain::Brain(){

}

int Brain::think(){
    return 0;
}

int Brain::getDirtFlag(){
    return dirtFlag;
}

void Brain::getAroundMessage(char *message,int random){
    aroundMessage = message;
    m_random = random;
}

