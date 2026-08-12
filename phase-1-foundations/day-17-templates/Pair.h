#ifndef PAIR_H
#define PAIR_H

#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Pair
{
private:

    T1 first;

    T2 second;

public:

    Pair(T1 a, T2 b);

    void display();
};

template<typename T1, typename T2>
Pair<T1,T2>::Pair(T1 a, T2 b)
{
    first = a;
    second = b;
}

template<typename T1, typename T2>
void Pair<T1,T2>::display()
{
    cout<<"First : "<<first<<endl;

    cout<<"Second : "<<second<<endl;
}

#endif