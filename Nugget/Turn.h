#ifndef TURN_H_INCLUDED
#define TURN_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;
class Turn{
public:
    Turn();
    ~Turn();
    vector <int> NumsLeft();
    string input ();
    string User;
    int num;

};

#endif // TURN_H_INCLUDED
