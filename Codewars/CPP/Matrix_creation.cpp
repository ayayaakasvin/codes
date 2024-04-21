#include <vector>

std::vector <std::vector<int>> getMatrix(const int n) {
    std:: vector <std:: vector <int>> result(n);
    for (int i = 0; i < n; i++)
    {
        std:: vector <int> temp_vector(n);
        for (int j = 0; j < n; j++)
        {
            i == j ? temp_vector[j] = 1 : true;
        }
        result[i] = temp_vector;
    }
    
    return result;
}