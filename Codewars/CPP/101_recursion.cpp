#include <iostream>

std::pair<int, int> solve (int a, int b){
    if (a == b or a == 0 or b == 0) 
    {
        return {a, b};
    } 
    else if (a >= 2 * b) 
    {
        a = a - 2 * b;
        return solve(a, b);
    } 
    else if (b >= 2 * a) 
    {
        b = b - 2 * a;
        return solve(a, b);
    }
    
    return {a, b};
}

int main () {
    std::pair<int, int> result = solve(22, 5);
    std::cout << result.first << ' ' << result.second;
    return 0;
}


// std::pair<int, int> solve(int a, int b) {
//     if (a == b) {
//         return {a, b};
//     } else if (a >= 2 * b) {
//         a = a - 2 * b;
//         return solve(a, b);
//     } else if (b >= 2 * a) {
//         b = b - 2 * a;
//         return solve(a, b);
//     }

//     // Add a return statement for the case when neither condition is met
//     return {a, b};
// }

// int main() {
//     std::pair<int, int> result = solve(22, 5);
//     std::cout << result.first << ' ' << result.second;
//     return 0;
// }
