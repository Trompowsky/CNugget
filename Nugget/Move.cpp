#include "Move.h"

Move::Move(){
string input = IN;
}

Move::~Move(){

}

string Move::User_Input(int WhoMove){
    if (WhoMove%2!=0){
        cout << "Player 1:    ";
    }else{
        cout << "Player 2:    ";
    }

cin >> IN;
return IN;
}

int Move::Num_Played(string USER){
Num = atoi(USER.c_str());
return Num;
}
