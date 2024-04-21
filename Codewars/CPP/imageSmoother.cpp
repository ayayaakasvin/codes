#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

class Solution {
    private:
        std::vector <std::vector <int>> mixedPixel (std::vector <std::vector <int>>& img) {
            int sizeOfOuterVector = img.size(), sizeOfInnerVector = img[0].size();
            std::vector<std::vector<int>> pixelValues(sizeOfOuterVector, std::vector<int>(sizeOfInnerVector, 0));
            for (int i = 0; i < sizeOfOuterVector; i++) {
                for (int j = 0; j < sizeOfInnerVector; j++) {
                    std::vector <int> pixelSet;
                    
                    for (int relevantToI = -1; relevantToI <= 1; relevantToI++)
                    {
                        for (int relevantToJ = -1; relevantToJ <= 1; relevantToJ++)
                        {   
                            int IndexForI = i + relevantToI;
                            int IndexForJ = j + relevantToJ;

                            if ((IndexForI >= 0 && IndexForI < sizeOfOuterVector) && (IndexForJ >= 0 && IndexForJ < sizeOfInnerVector))
                            {
                                pixelSet.push_back(img[IndexForI][IndexForJ]);
                            }
                        }
                    }
                    
                    long long int sum = std::accumulate(pixelSet.begin(), pixelSet.end(), 0);
                    bool sizeOfPixelsVector = pixelSet.empty();
                    int averageOfPixels = sizeOfPixelsVector ? 0 : sum / pixelSet.size();
                    pixelValues[i][j] = averageOfPixels;
                }
            }

            return pixelValues;
        }

    public:
        std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
            std::vector<std::vector<int>> result = mixedPixel(img);

            return result;
        }
};

int main () {
    Solution Jokerge;

    std::vector <std::vector <int>> input = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
    std::vector <std::vector <int>> output =  Jokerge.imageSmoother(input);

    for (std::vector <std::vector <int>>::iterator i = output.begin(); i != output.end(); i++) {
        for (std::vector <int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            std::cout << *j << ' ';
        }

        std::cout << std::endl;
    }

    input = {{100,200,100}, {200,50,200}, {100,200,100}};
    output =  Jokerge.imageSmoother(input);

    for (std::vector <std::vector <int>>::iterator i = output.begin(); i != output.end(); i++) {
        for (std::vector <int>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            std::cout << *j << ' ';
        }

        std::cout << std::endl;
    }
}