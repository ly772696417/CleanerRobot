#ifndef SMARTBRAIN_H
#define SMARTBRAIN_H
#include<vector>
#include"brain.h"

class SmartBrain : public Brain
{
public:
    SmartBrain();

    int think();
protected:
    int actSignal,lastAction;
    std::vector<int>* pathRecord;
    bool backStatus,turnedAround;
};

#endif // SMARTBRAIN_H
