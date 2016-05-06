#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <vector>
#include <math.h>       /* ceil */
#include "Move.h"
#include "Calculation.h"
#include "EuclideanAlgorithm.h"


using namespace std;




int main()
{
    bool Exit = false;

while (Exit == false){

    Move a;
    Move b;

    string User1;
    int num1;
    string User2;
    int num2;
    int counter=1;
    bool LinCom=false;
    vector <int> Played;
    int WhoMove=1;
    int Lim;
    EuclideanAlgorithm tester;

    User1 = a.User_Input(WhoMove);
    num1 = a.Num_Played(User1);
    Played.push_back(num1);


    WhoMove++;

    User2 = b.User_Input(WhoMove);
    num2 = b.Num_Played(User2);
    Played.push_back(num2);

    WhoMove++;

    Calculation calc1;

    if (tester.GCD(num1, num2) == 1){
        Lim=calc1.Limit(Played);

    }else{
        cout << "Why would you start off the game with two numbers that are not relatively \ncoprime?  I'll set the limit to 300 just to be nice ;)" << endl;
        Lim=300;
        Played.push_back(200);

    }

    cout << "All numbers greater than " << Lim << " have been eliminated." << endl << endl;

    vector <int> Legal = calc1.Legal(Played, Lim);
    cout << "Remaining numbers:  ";
    for (vector<int>::iterator it = Legal.begin(); it != Legal.end(); ++it) {
        if (it==Legal.end()-1){
            cout << ' ' << *it << "." << endl;
        }else{
        cout << ' ' << *it << ", ";
        }
    }


    /*cout << "THIS IS A TEST" << endl;

    vector <int> F;
    F.push_back(15);
    F.push_back(11);
    F.push_back(8);

    vector <int> E = calc.Legal(F, 80);
    cout << "Remaining numbers:  ";
    for (vector<int>::iterator it3 = E.begin(); it3 != E.end(); ++it3) {
        if (it3==E.end()-1){
            cout << ' ' << *it3 << "." << " Size of "<< E.size() << endl;
        }else{
        cout << ' ' << *it3 << ", ";
        }
    }*/
        cout << "Played Numbers:\t";
        for (vector<int>::iterator it3 = Played.begin(); it3 != Played.end(); ++it3) {
        if (it3==Played.end()-1){
            cout << ' ' << *it3 << "." << endl;
        }else{
        cout << ' ' << *it3 << ", ";
        }
    }

    cout << endl;


        if (calc1.Game_Over(Legal, WhoMove)==true){
        cout << "Play again? (Y or N)" << endl;
        string Playing1;
        cin >> Playing1;
        if (Playing1 == "N"){
            Exit = true;
        }
    }

vector <int> TLegal = Legal;

    Calculation calc;


while (calc.Game_Over(TLegal, WhoMove)==false){

    User1 = a.User_Input(WhoMove);
    num1 = a.Num_Played(User1);




    if (calc.MoveLegal(TLegal, num1)==true){

    Played.push_back(num1);
    double Lim=calc.Limit(Played);

    cout << "All numbers greater than " << Lim << " have been eliminated." << endl;
    cout << endl;

    TLegal = calc.Legal(Played, Lim);
    cout << "Remaining numbers:  ";

    for (vector<int>::iterator it = TLegal.begin(); it != TLegal.end(); ++it) {
        if (it==TLegal.end()-1){
            cout << ' ' << *it << "." << endl;
        }else{
        cout << ' ' << *it << ", ";
        }
    }

        cout << "Played Numbers:\t";

        for (vector<int>::iterator it3 = Played.begin(); it3 != Played.end(); ++it3) {
        if (it3==Played.end()-1){
            cout << ' ' << *it3 << "." << endl;
        }else{
        cout << ' ' << *it3 << ", ";
        }
    }


    WhoMove++;
    if (calc.Game_Over(TLegal, WhoMove)==true){
        cout << "Play again? (Y or N)" << endl;
        string Playing;
        cin >> Playing;
        if (Playing == "N"){
            Exit = true;
        }
    }
   // }else{
     //   cout << "Illegal move:  Try again " << endl;
    //}


}else{
    cout << "ERROR:  Number not on list of remaining numbers.  Try again." << endl;
}

    cout << endl;

    }
}
}

