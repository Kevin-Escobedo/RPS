#ifndef RPS_H
#define RPS_H
#include <iostream>
#include <string>
#include <time.h>

class RPS
{
private:
    int result; //-1 is loss, 0 is draw, 1 is win
    std::string lastPlayerMove;

public:
    RPS();
    RPS(const RPS& rps);
    RPS& operator =(const RPS& rps);
    ~RPS();
    std::string getUserInput();
    void play(const int trials);
    void showResult();

private:
    std::string makeMove();

};


#endif /* RPS_H */