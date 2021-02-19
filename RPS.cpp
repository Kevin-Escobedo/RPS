#include "RPS.h"

RPS::RPS()
:result(0), lastPlayerMove()
{
    srand(time(nullptr));
}

RPS::RPS(const RPS& rps)
:result(rps.result), lastPlayerMove(rps.lastPlayerMove)
{
    srand(time(nullptr));
}

RPS& RPS::operator =(const RPS& rps)
{
    result = rps.result;
    lastPlayerMove = rps.lastPlayerMove;

    return *this;
}

RPS::~RPS()
{

}

std::string RPS::getUserInput()
{
    std::string playerMove;

    while(true)
    {
        std::cout<<"Enter Move: ";
        std::getline(std::cin, playerMove);

        if(playerMove == "Rock" || playerMove == "Paper" || playerMove == "Scissors")
        {
            break;
        }
    }

    return playerMove;
}

void RPS::play(const int trials)
{
    for(int i = 0; i < trials; i++)
    {
        std::string cpuMove = makeMove();
        std::string humanMove = getUserInput();

        lastPlayerMove = humanMove;

        if(cpuMove == humanMove)
        {
            result = 0;
        }

        //TODO: Optimize
        if(cpuMove == "Rock")
        {
            if(humanMove == "Paper")
            {
                result = -1;
            }

            if(humanMove == "Scissors")
            {
                result = 1;
            }
        }

        if(cpuMove == "Paper")
        {
            if(humanMove == "Rock")
            {
                result = 1;
            }

            if(humanMove == "Scissors")
            {
                result = -1;
            }
        }

        if(cpuMove == "Scissors")
        {
            if(humanMove == "Rock")
            {
                result = -1;
            }

            if(humanMove == "Paper")
            {
                result = 1;
            }
        }

        showResult();
    }
}

void RPS::showResult()
{
    switch(result)
    {
        case -1:
            std::cout<<"Player Win!"<<std::endl;
            break;
        case 0:
            std::cout<<"Draw!"<<std::endl;
            break;
        case 1:
            std::cout<<"Computer Win!"<<std::endl;
            break;
        default:
            std::cout<<"ERROR"<<std::endl;
    }
}

std::string RPS::makeMove()
{
    const int move = rand() % 3;
    switch(result)
    {
        case -1: //Play what wasn't played
            if(lastPlayerMove == "Rock")
            {
                return "Paper";
            }

            if(lastPlayerMove == "Paper")
            {
                return "Scissors";
            }

            if(lastPlayerMove == "Scissors")
            {
                return "Rock";
            }

            break;

        case 0: //Random move
            switch(move)
            {
                case 0:
                    return "Rock";
                case 1:
                    return "Paper";
                case 2:
                    return "Scissors";
                default:
                    return "ERROR";
            }
            break;

        case 1: //Play what they played
            return lastPlayerMove;

        default:
            return "ERROR";
    }

    return "ERROR";
}