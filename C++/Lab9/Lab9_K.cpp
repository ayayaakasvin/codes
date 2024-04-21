#include <iostream>
#include <vector>
#include <algorithm>

long long int largest_rectangle (std::vector <long long int> widths_of_rectangle) {
    std::vector <long long int> rectangle_square;
    long long int width = widths_of_rectangle[0];
    long long int length = 0;

    for (long long int i = 0; i < widths_of_rectangle.size() - 1; i++)
    {
        if (widths_of_rectangle[i] == widths_of_rectangle[i + 1] or widths_of_rectangle[i] - widths_of_rectangle[i + 1] == -1)
        {
            length++;
        }
        else if (widths_of_rectangle[i] - widths_of_rectangle[i + 1] == 1)
        {
            width = widths_of_rectangle[i + 1];
            length++;
        }
        else
        {
            rectangle_square.push_back(length * width);
            width = widths_of_rectangle[i + 1];
            length = 1;
        }
    }

    return *(std::max_element(rectangle_square.begin(), rectangle_square.end()));
}

int main () {
    long l;
    std::cin >> l;
    std::vector <long long int> widths (l);
    for (long long int i = 0; i < l; i++)
    {
        std::cin >> widths[i];
    }
    
    std::cout << largest_rectangle(widths);
    
    return 0;
}