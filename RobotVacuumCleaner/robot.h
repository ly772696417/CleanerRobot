#ifndef ROBOT_H
#define ROBOT_H

#include"brain.h"

class Robot
{
public:
    Brain *brain;

    Robot();   
    void setBrain(int choice);

    void act();

    void moveForward();
    void turnLeft();
    void turnRight();
    void goBack();

    char getMark();
    void setMark(char mark);

    int getRow();
    void setRow(int row);

    int getCol();
    void setCol(int col);

    int getIfGoForwardFlag();
    int getIfGoBackFlag();

protected:
    char m_mark;
    int m_row,m_col;
    int ifGoForwardFlag,ifGoBackFlag;

};

#endif // ROBOT_H
