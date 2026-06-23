#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string name = "Shrinath";

    cout << name << endl;

    vector<int> marks = {80,90,70,100};

    for(auto mark : marks)
    {
        cout << mark << endl;
    }

    return 0;
}