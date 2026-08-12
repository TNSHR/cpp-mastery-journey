#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
    Animal* animal;

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    return 0;
};