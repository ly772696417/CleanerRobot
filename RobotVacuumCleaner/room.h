#ifndef ROOM_H
#define ROOM_H

#include"robot.h"

class Room
{
public:
    Room();
    ~Room();

    void process();
    void tell();

    void printfRoom();

    void initializeFurniture();
    void initializeWall();
    void initializeSmallItem();
    void initializeRobot();

    void countInitDirtNum();
    int getDirtNum();
    void setDirtNum(int dirtNum);

protected:
    char m_nodes[20][60];
    int m_choice,m_furnitureNum,m_wallsNum,m_smallItemsNum,m_randomNum,m_dirtNum;
    Robot *robot;
};

#endif // ROOM_H
