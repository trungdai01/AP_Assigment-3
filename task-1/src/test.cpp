// C Program to illustrate local auto variable in comparison
// of static variable.
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function
int fun()
{
    static int count = 0;
    count++;
    return count;
}

int fun1()
{
    static int count = 0;
    count++;
    return count;
}

// Driver Code
int main()
{
    // printf("%d ", fun());
    // printf("%d ", fun1());
    vector<string> vec = {"ab", "bc", "ca"};
    for (auto& e : vec)
    {
        e = "a";
    }
    for (auto e : vec)
    {
        cout << e << " ";
    }
    return 0;
}
