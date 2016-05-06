#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */

using namespace std;

class Move{
public:
    Move();
    ~Move();
    string User_Input(int WhoMove);
    int Num_Played(string USER);
    int Num;
    string IN;

};

#endif // MOVE_H_INCLUDED
