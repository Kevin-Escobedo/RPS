#include "RPS.h"

int main(int argc, char** argv)
{
    RPS rps;

    int trials = 5;

    if(argc == 2)
    {
        trials = atoi(argv[1]);
    }

    rps.play(trials);

    return 0;
}