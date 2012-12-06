#include<iostream>
#include<cstdlib>

#include "room.h"
#include"robot.h"


Room::Room()
{
    int x,y;
    robot = new Robot;

    std::cout<<"Which robot to run? 0 (stupid) or 1 (clever)?";
    std::cin>>m_choice;
    robot->setBrain(m_choice);

    std::cout<<"How many pieces of furniture?";
    std::cin>>m_furnitureNum;

    std::cout<<"How many walls?";
    std::cin>>m_wallsNum;

    std::cout<<"How many small items?";
    std::cin>>m_smallItemsNum;

    std::cout<<"Random number seed?";
    std::cin>>m_randomNum;
    srand(m_randomNum);

    std::cout<<std::endl;
    std::cout<<"Initial room:";
    std::cout<<std::endl<<std::endl;

    for(x = 0;x<20;x++){
        m_nodes[x][0] = m_nodes[x][59] = '#';
    }

    for(y = 0;y<60;y++){
        m_nodes[0][y] = m_nodes[19][y] = '#';
    }

    for(x = 1;x<19;x++){
        for(y = 1;y<59;y++){
            m_nodes[x][y] = '.';
        }
    }

    initializeFurniture();
    initializeWall();
    initializeSmallItem();
    initializeRobot();

    printfRoom();
}

Room::~Room(){
    //nothing to do
}

//initialize furniture
void Room::initializeFurniture(){
    int i,x,y;

    for(i = 0;i<m_furnitureNum;i++){
        int edgeXNum = 2+rand()%9;
        int edgeYNum = 2+rand()%9;
        int randX = 1+rand()%18;
        int randY = 1+rand()%58;

        if((edgeXNum+randX<=18)&&(edgeYNum+randY<=58)){
            for(x = 0;x<edgeXNum;x++){
                for(y = 0;y<edgeYNum;y++){
                    m_nodes[randX+x][randY+y] = '#';
                }
            }
        }
        else if((edgeXNum+randX>18)&&(edgeYNum+randY<=58)){
            for(x = 0;x+randX<18;x++){
                for(y = 0;y<edgeYNum;y++){
                    m_nodes[randX+x][randY+y] = '#';
                }
            }
        }
        else if((edgeXNum+randX<=18)&&(edgeYNum+randY>58)){
            for(x = 0;x<edgeXNum;x++){
                for(y = 0;y+randY<58;y++){
                    m_nodes[randX+x][randY+y] = '#';
                }
            }
        }
        else{
            for(x = 0;x+randX<18;x++){
                for(y = 0;y+randY<58;y++){
                    m_nodes[randX+x][randY+y] = '#';
                }
            }
        }
    }
}

//initialize wall
void Room::initializeWall(){
    int i,x,y;
    for(i = 0;i<m_wallsNum;i++){
        int direction = 1+rand()%2;// 1 stand for horizontal,2 stand for vertical
        int edgeNum = 1+rand()%16;
        int randX = 1+rand()%18;
        int randY = 1+rand()%58;

        if(direction == 1){
            if(randX+edgeNum<=18){
                for(x = 0;x<edgeNum;x++){
                    m_nodes[randX+x][randY] = '#';
                }
            }
            else{
                for(x = 0;x+randX<18;x++){
                    m_nodes[randX+x][randY] = '#';
                }
            }
        }
        else{
            if(randY+edgeNum<=58){
                for(y = 0;y<edgeNum;y++){
                    m_nodes[randX][randY+y] = '#';
                }
            }
            else{
                for(y = 0;y+randY<18;y++){
                    m_nodes[randX][randY+y] = '#';
                }
            }
        }
      }
}

//initialize small item
void Room::initializeSmallItem(){
    int x;
    for(x = 0;x<m_smallItemsNum;x++){
        int randX = 1+rand()%18;
        int randY = 1+rand()%58;

        m_nodes[randX][randY] = '#';
    }
}

//initialize the robot
void Room::initializeRobot(){

    int markNum,randX,randY;
    markNum = 1+rand()%4;

    switch(markNum){
    case 1:
        robot->setMark('v');
        break;
    case 2:
        robot->setMark('<');
        break;
    case 3:
        robot->setMark('^');
        break;
    case 4:
        robot->setMark('>');
        break;
    }

    do{
        randX = 1+rand()%18;
        randY = 1+rand()%58;
    }while(m_nodes[randX][randY]=='#');
    m_nodes[randX][randY] = robot->getMark();
    robot->setRow(randX);
    robot->setCol(randY);
}

void Room::printfRoom(){
    int x,y;

    for(x = 0;x<20;x++){
        for(y = 0;y<60;y++){
            std::cout<<m_nodes[x][y];
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
}

void Room::countInitDirtNum(){
    int x,y;
    m_dirtNum = 0;
    for(x = 0;x<20;x++){
        for(y = 0;y<60;y++){
            if(m_nodes[x][y]=='.'){
                m_dirtNum++;
            }
        }
    }
}

int Room::getDirtNum(){
    return m_dirtNum;
}

void Room::setDirtNum(int dirtNum){
    m_dirtNum = dirtNum;
}

void Room::tell(){
    char message[3];
    switch(robot->getMark()){
    case 'v':
        message[0] = m_nodes[robot->getRow()+1][robot->getCol()];
        message[1] = m_nodes[robot->getRow()][robot->getCol()+1];
        message[2] = m_nodes[robot->getRow()][robot->getCol()-1];
        break;

    case '<':
        message[0] = m_nodes[robot->getRow()][robot->getCol()-1];
        message[1] = m_nodes[robot->getRow()+1][robot->getCol()];
        message[2] = m_nodes[robot->getRow()-1][robot->getCol()];
        break;

    case '^':
        message[0] = m_nodes[robot->getRow()-1][robot->getCol()];
        message[1] = m_nodes[robot->getRow()][robot->getCol()-1];
        message[2] = m_nodes[robot->getRow()][robot->getCol()+1];
        break;

    case '>':
        message[0] = m_nodes[robot->getRow()][robot->getCol()+1];
        message[1] = m_nodes[robot->getRow()-1][robot->getCol()];
        message[2] = m_nodes[robot->getRow()+1][robot->getCol()];
        break;
    }
    robot->brain->getAroundMessage(message,m_randomNum);
}


void Room::process(){
    do{

        srand(m_randomNum);

        int x,y;

        for(x = 0;x<20;x++){
            m_nodes[x][0] = m_nodes[x][59] = '#';
        }

        for(y = 0;y<60;y++){
            m_nodes[0][y] = m_nodes[19][y] = '#';
        }

        for(x = 1;x<19;x++){
            for(y = 1;y<59;y++){
                m_nodes[x][y] = '.';
            }
        }

        initializeFurniture();
        initializeWall();
        initializeSmallItem();
        initializeRobot();


        int giveSimulationSteps,step = 0;
        std::cout<<"How many simulation steps to run?";
        std::cin>>giveSimulationSteps;
        std::cout<<std::endl;

        this->countInitDirtNum();

        for(int i = 0;i<giveSimulationSteps;i++){
            this->tell();
            robot->act();
            if(robot->brain->getDirtFlag()){
                m_dirtNum--;
            }
            m_nodes[robot->getRow()][robot->getCol()] = robot->getMark();
            if(robot->getIfGoForwardFlag()){
                switch(robot->getMark()){
                case 'v':
                    m_nodes[robot->getRow()-1][robot->getCol()] = ' ';
                    break;
                case '<':
                    m_nodes[robot->getRow()][robot->getCol()+1] = ' ';
                    break;
                case '^':
                    m_nodes[robot->getRow()+1][robot->getCol()] = ' ';
                    break;
                case '>':
                    m_nodes[robot->getRow()][robot->getCol()-1] = ' ';
                    break;
                }
            }
            if(robot->getIfGoBackFlag() == 1){
                step++;
            }

            step++;
            if(m_dirtNum==0){
                std::cout<<"Floor completely clean at step "<<step<<std::endl<<std::endl;
                break;
            }
        }

        printfRoom();
    }while(m_dirtNum>0);

    std::cout<<"Simulation complete"<<std::endl;

}




