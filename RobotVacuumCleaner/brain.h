#ifndef BRAIN_H
#define BRAIN_H


class Brain
{
public:
    Brain();

    void getAroundMessage(char* message,int random);

    virtual int think();

    int getDirtFlag();
protected:
    char* aroundMessage;
    int m_random;
    int dirtFlag;
};

#endif // BRAIN_H
