#include <iostream>
#include <ctime>
using namespace std;

float f1(float);
float f2(float);
int choice(int, int);

float a = 0.2;
float b = 2;


int main(){ 
    cout << f2(3.0) << endl;
    //printf("%f\n", f2(3.0));
    cout << choice(10,40);
    return 0;
}

int choice(int p1, int p2){
    
    int s = p1 + p2;
    srand(time(NULL));
    int random = rand() % s + 1;
    cout << random << endl;

    if (random <= p1){
        return 1;
    }
    else{
        return 2;
    }
    
    

}

float f1(float x){
    return x + a;
}

float f2(float x){
    return x/b + 0.5 * (1 - (1/b));
}