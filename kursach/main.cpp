#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>    
using namespace std;

const int n = 5;
const int h = 1000;
const int k = 100;
const int len = n*h*k;

float f1(float);
float f2(float);
int choice(int, int);
float xi(float);
void printArray(float *,int);

float a = 0.2;
float b = 2;


int main(){ 
    
    //ПОСЛЕДОВАТЕЛЬНОСТЬ СЛУЧАНЫХ ВЕЛИЧИН
    float *array = new float[len];
    float tmp = xi(0);
    array[0] = tmp;

    for (size_t i = 1; i < len; i++)
        array[i] = xi(array[i-1]);
    
    printArray(array, len);
    
    return 0;
}

void printArray(float *array, int len){
    cout << "Array: " << endl;
    for (size_t i = 0; i < len; i++)
        cout << array[i] << endl;
    
    
}

float xi(float old){

    float xi;
    
    switch (choice(10,40)){
        case 1:
            xi = f1(old);
            break;
        case 2:
            xi = f2(old);
            break;
        default:
            break;
    }

    return xi;
}

int choice(int p1, int p2){
    
    int s = p1 + p2;
   
    int random = rand() % s + 1;
    //cout << random << endl;

    if (random <= p1)
        return 1;
    else
        return 2;
    
    
    

}

float f1(float x){
    //cout << "function 1" << endl;
    return x + a;
}

float f2(float x){
    //cout << "function 2" << endl;
    return x/b + 0.5 * (1 - (1/b));
}