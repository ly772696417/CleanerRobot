#include<iostream>
#include<cstdlib>
#include "smartbrain.h"

SmartBrain::SmartBrain()
{
    backStatus = false;
    turnedAround = false;
    pathRecord = new std::vector<int>;
}

int SmartBrain::think(){
    dirtFlag = 0;
    if(this->aroundMessage[0] == '.'){
        actSignal = 0;
        dirtFlag = 1;
        if(this->backStatus == true){
            switch(pathRecord->back()){
            case 1:
                pathRecord->pop_back();
                pathRecord->push_back(2);
                break;
            case 2:
                pathRecord->pop_back();
                pathRecord->push_back(1);
            }
            backStatus = false;
        }
        pathRecord->push_back(actSignal);
        turnedAround = false;
    }
    else if(this->aroundMessage[1] == '.'){
        actSignal = 1;
        if(backStatus == true){
            pathRecord->push_back(2);
            backStatus = false;
        }
        else
            pathRecord->push_back(actSignal);
        turnedAround = false;
    }
    else if(this->aroundMessage[2] == '.'){
        actSignal = 2;
        if(backStatus == true){
            pathRecord->push_back(1);
            backStatus = false;
        }
        else{
            pathRecord->push_back(actSignal);
        }
        turnedAround = false;
    }
    else{
        if(!turnedAround){
            actSignal = 3;
            turnedAround = true;
            backStatus = true;
            return actSignal;
        }
        lastAction = pathRecord->back();
        pathRecord->pop_back();
        switch(lastAction){
        case 0:
            actSignal = 0;
            break;
        case 1:
            actSignal = 2;
            break;
        case 2:
            actSignal = 1;
            break;
        }
    }
    return actSignal;
}
