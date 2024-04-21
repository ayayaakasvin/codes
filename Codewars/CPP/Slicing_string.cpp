#include <string>
#include <iostream>

using namespace std; 

string sliceString (string str )
{
    return str.substr(1, str.length() - 2); 
}

int main () {
    std::cout << sliceString("Luna");

    return 0;
}