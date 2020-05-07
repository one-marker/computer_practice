#include <iostream>
using namespace std;

float f1(float);
float f2(float);

float a = 0.2;
float b = 2;


int main(){ 
    cout << f2(3.0) << endl;
    //printf("%f\n", f2(3.0));
    return 0;
}

float f1(float x){
    return x + a;
}

float f2(float x){
    return x/b + 0.5 * (1 - (1/b));
}