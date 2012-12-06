#include<iostream>
#include<cstdlib>
#include"room.h"

int main(){
    Room *myRoom;
    myRoom =new Room();
    myRoom->process();
    delete myRoom;
    return 0;
}
