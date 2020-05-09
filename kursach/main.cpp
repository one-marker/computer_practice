#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#define K 100
#define H 1000
#define N 5
#define SIZE 100000
using namespace std;



float f1(float);
float f2(float);
int choice(int, int);
float xi(float);
void printArray(float*, int);

float a = 0.2;
float b = 2;

float M(float* array, int index) {
    float m = 0;

    for (size_t i = index; i < index + K; i++)
    {
        m += array[index];
    }

    return m/K;
}
float D(float* array, int index, float M) {
    float d = 0;

    for (size_t i = index; i < index + K; i++)
    {
        d += (array[index] - M) * (array[index] - M);
    }

    return d / K;
}

float Min(float* array, int index) {
    float min = 0;

    for (size_t i = index; i < index + K; i++)
        if (array[i] < min)
            min = array[i];

    return min;
}

float Max(float* array, int index) {
    float max = 0;

    for (size_t i = index; i < index + K; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}

struct Result {
    float max = 0;
    float min = 0;
    float M = 0;
    float D = 0;
};

int main() {
    Result* results = new Result[N];
    //ПОСЛЕДОВАТЕЛЬНОСТЬ СЛУЧАНЫХ ВЕЛИЧИН 
    //sequence of random variables SORV
    float* sorv = new float[SIZE];
    float tmp = xi(0);
    sorv[0] = tmp;

    for (size_t i = 1; i < SIZE; i++)
        sorv[i] = xi(sorv[i - 1]);

    //printArray(sorv, SIZE);

     
    int n = 0;
    int i = 0;
   
    while (n != N && i < SIZE)
    {
        if (i % H == 0)
        {
            cout << n << endl;
            cout << i << " mod 1000" << endl;
            cout << "M = " << M(sorv, i) << endl;
            cout << "D = " << D(sorv, i, M(sorv, i)) << endl;


            ///Место для функций 1. 3.
           
            results[n].M = M(sorv, i); //Среднее
            results[n].D = D(sorv, i, M(sorv, i));  //Дисперсию найти

            results[n].max = Max(sorv, i); //Max найти
            results[n].min = Min(sorv, i);  //Min найти

            //пердавать в функцию указатель на массив и индекс с которого начинать производичть вычисления;
            //при прохождении массива Ваш цикл должен начинать с i, а заканчиваться на i+K;



            i += K;
            n++;
          
        }
        i++;
    }


    cout << results[0].M << endl;

    cout << "\nRESULTS:" << endl;
    cout << "------------------" << endl;

    for (size_t i = 0; i < N; i++)
    {    
        cout << "n = " << i+1 << endl;
        cout << "Max: " << results[i].max << endl;
        cout << "Min: " << results[i].min << endl;
        cout << "M: " << results[i].M << endl;
        cout << "D: " << results[i].D << endl;
        cout << "------------------" << endl;
        
    }


    return 0;




}

void printArray(float* array, int len) {
    cout << "Array: " << endl;
    for (size_t i = 0; i < len; i++)
        cout << array[i] << endl;


}

float xi(float old) {

    float xi;

    switch (choice(10, 40)) {
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

int choice(int p1, int p2) {

    int s = p1 + p2;

    int random = rand() % s + 1;
    //cout << random << endl;

    if (random <= p1)
        return 1;
    else
        return 2;
}

float f1(float x) {
    //cout << "function 1" << endl;
    return x + a;
}

float f2(float x) {
    //cout << "function 2" << endl;
    return x / b + 0.5 * (1 - (1 / b));
}