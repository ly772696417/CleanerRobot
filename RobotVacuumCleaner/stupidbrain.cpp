#include<iostream>
#include<cstdlib>
#include "stupidbrain.h"

enum{
    moveForward,
    turnLeft,
    turnRight
};

StupidBrain::StupidBrain()
{
}

int StupidBrain::think(){

    int instructionNum;
    dirtFlag = 0;

    if(this->aroundMessage[0] == '.'){
        dirtFlag = 1;
        return moveForward;
    }
    else if(this->aroundMessage[0] == ' '){
        instructionNum = rand()%3;
        switch(instructionNum){
        case 0:
            return moveForward;
            break;
        case 1:
            return turnLeft;
            break;
        case 2:
            return turnRight;
            break;
        }
    }
    else{
        instructionNum = rand()%2;
        switch(instructionNum){
        case 0:
            return turnLeft;
            break;
        case 1:
            return turnRight;
            break;
        }
    }
}
