#include "Animal.h"

void Animal::sound()
{
    cout << "Animal makes a sound. " << endl;
};

Animal::~Animal()
{
    cout << "Animal Destructor" << endl;
};