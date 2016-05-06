#include "Calculation.h"
#include <math.h>       /* ceil */

Calculation::Calculation(){

}


Calculation::~Calculation(){

}

int Calculation::Limit(vector <int> played){
   // int x=played.end();
    int g=0;
    int h=0;
    int x=0;
    int record=1000000;
    EuclideanAlgorithm testing;
        while (g<=played.size()-1){
            if (g==h){
                h++;
            }else{

            if (testing.GCD(played[g], played[h])==1){
            //cout << h << "  " << g << endl;
            x=played[g]*played[h]-played[g]-played[h];
            if (x<record){
                //cout << played[g] << "  " << played[h] << endl;
                record=x;
                }
            }
                h++;

            }
        if (h==played.size()){
            h=0;
            g++;
        }
    }

    return record;

}

vector <int> Calculation::Legal (vector <int> played, double limit){
    int p = 0;
    int q = 0;
    double a = 0;
    double b = 1;
    int counter = 1;
    bool LinCom=false;
    int Pmax=ceil(limit/played[a]);
    int Qmax=ceil(limit/played[b]);

    vector <int> legal;




        while (counter <= limit){
    while (a<played.size()){
            Pmax=ceil(limit/played[a]);
            Qmax=ceil(limit/played[b]);
            //cout << a << b << endl;
        while (p<=Pmax){
            if (p*played[a]+q*played[b]==counter){
                LinCom=true;
               // cout << p << "*" << played[a] << "+" << q << "*" << played[b] << " = " << counter << endl;
            }
            //cout << q << "  " << p << endl;

            //cout << counter << ":   " << p << "*" << played[a] << "+" << q << "*" << played[b] << endl;
        q++;
        if (q>Qmax){
            q=0;
            p++;
        }
    }
    //cout << a << "\t" << b << endl;
    b++;
    if (b==played.size()){
        //cout << b << endl;
        b=0;
        a++;
        p=0;
        q=0;
    }else{
        p=0;
        q=0;
    }
}

        if (LinCom==false){
        legal.push_back(counter);
}
        LinCom=false;
        counter++;
        p=0;
        q=0;
        a=0;
        b=1;
    }

        return legal;
}


bool Calculation::Game_Over(vector <int> legal, int WhoMove){
vector<int>::iterator it = legal.end()-1;
if (*it==1){
        if (WhoMove%2==0){
    cout << "PLAYER 2 LOSES" << endl;
        }else{
    cout << "PLAYER 1 LOSES" << endl;
        }
    return true;
}else{
    return false;
}

}

bool Calculation::MoveLegal(vector <int> legal, int input){
    bool input_in_legal = false;
   // cout << "We are inside the movelegal function with input " << input << ":  ";
        for (vector<int>::iterator it3 = legal.begin(); it3 != legal.end(); ++it3) {
        if (it3==legal.end()-1){
       // cout << ' ' << *it3 << "." << endl;
        }else{
       // cout << ' ' << *it3 << ", ";
        }
        if (*it3==input){
            input_in_legal=true;
        //    cout << *it3 << " is " << input << endl;
        }
    }

    if (input_in_legal == true){
        return true;
    }else{
        return false;
    }

}
