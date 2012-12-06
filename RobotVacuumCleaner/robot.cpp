#include<iostream>
#include"robot.h"
#include"brain.h"
#include"stupidbrain.h"
#include"smartbrain.h"

Robot::Robot(){
    brain = new StupidBrain;
}

void Robot::setBrain(int choice){
    if(choice == 0){
        brain = new StupidBrain;
    }
    else{
        brain = new SmartBrain;
    }
}

void Robot::act(){
    ifGoForwardFlag = 0;
    ifGoBackFlag = 0;
    switch(brain->think()){
    case 0:
        this->moveForward();
        ifGoForwardFlag = 1;
        break;
    case 1:
        this->turnLeft();
        break;
    case 2:
        this->turnRight();
        break;
    case 3:
        this->goBack();
        ifGoBackFlag = 1;
        break;
    }
}

void Robot::moveForward(){
    switch(getMark()){
    case 'v':
        setRow(getRow()+1);
        break;
    case '<':
        setCol(getCol()-1);
        break;
    case '^':
        setRow(getRow()-1);
        break;
    case '>':
        setCol(getCol()+1);
        break;
    }
}

void Robot::turnLeft(){
    switch(getMark()){
    case 'v':
        setMark('>');
        break;
    case '<':
        setMark('v');
        break;
    case '^':
        setMark('<');
        break;
    case '>':
        setMark('^');
        break;
    }
}

void Robot::turnRight(){
    switch(getMark()){
    case 'v':
        setMark('<');
        break;
    case '<':
        setMark('^');
        break;
    case '^':
        setMark('>');
        break;
    case '>':
        setMark('v');
        break;
    }
}

void Robot::goBack(){
    switch(getMark()){
    case 'v':
        setMark('^');
        break;
    case '<':
        setMark('>');
        break;
    case '^':
        setMark('v');
        break;
    case '>':
        setMark('<');
        break;
    }
}

char Robot::getMark(){
    return m_mark;
}

void Robot::setMark(char mark){
    m_mark = mark;
}

int Robot::getRow(){
    return m_row;
}

void Robot::setRow(int row){
    m_row = row;
}

int Robot::getCol(){
    return m_col;
}

void Robot::setCol(int col){
    m_col = col;
}

int Robot::getIfGoForwardFlag(){
    return ifGoForwardFlag;
}

int Robot::getIfGoBackFlag(){
    return ifGoBackFlag;
}
