#ifndef PUZZLE_H_INCLUDED
#define PUZZLE_H_INCLUDED
#include "header.h"
#include "family.h"
#include "wgc.h"
template <typename T>
T gensuccesssors(T puzzle)
{
    if(puzzle=="puzzle1")
    {
        frog_puzzle();
    }
    else if(puzzle=="puzzle2")
    {
        puzzle2();
    }
    else if(puzzle=="puzzle3")
    {
        puzzle3();
    }
}


#endif // PUZZLE_H_INCLUDED
