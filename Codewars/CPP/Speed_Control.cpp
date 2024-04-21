#include <vector>
#include <cmath>

class GpsSpeed
{
public:
    static int gps(int s, std::vector<double>& x) {
        if (x.size() <= 1)
        {
            return 0;
        }
        std::vector <double> speed_array;
        for (std::size_t i = 1; i < x.size(); i ++)
        {
            speed_array.push_back((3600 * (x[i] - x[i - 1])) / s);
        }
        double answer = *std::max_element(speed_array.begin(), speed_array.end());
        return static_cast<int>(std::floor(answer));
    }
};