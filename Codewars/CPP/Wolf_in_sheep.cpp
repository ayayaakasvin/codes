#include <vector>
#include <string>
#include <algorithm>

std::string warn_the_sheep(const std::vector<std::string>& queue)
{
    if (std::distance(queue.begin(), std::find(queue.begin(), queue.end(), "wolf")) == queue.size() - 1)
    {
        return "Pls go away and stop eating my sheep";
    }
    else
    {
        return "Oi! Sheep number " + std::to_string(queue.size() - (std::distance(queue.begin(), std::find(queue.begin(), queue.end(), "wolf"))) - 1) + "! You are about to be eaten by a wolf!";
    }

    return "";
}