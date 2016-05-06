#include "EuclideanAlgorithm.h"

EuclideanAlgorithm::EuclideanAlgorithm(){

}


EuclideanAlgorithm::~EuclideanAlgorithm(){

}


int EuclideanAlgorithm::GCD(int m, int n){
 int temp = 0;
        if(m < n)
        {
                temp = m;
                m = n;
                n = temp;
        }
        while(n != 0)
        {
                temp = m % n;
                m = n;
                n = temp;
        }
        return m;

}
