#ifndef TYPE_INFERENCE_DEMO_H
#define TYPE_INFERENCE_DEMO_H

#include <iostream>
#include <string>
#include <vector>

class TypeInferenceDemo
{
public:

    static void basicAuto();

    static void autoWithContainers();

    static void referenceDeduction();

    static void constDeduction();

    static void demonstrateDecltype();
};

#endif