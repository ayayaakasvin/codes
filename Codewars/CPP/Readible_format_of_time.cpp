#include <iostream>
#include <limits.h>
#include <string>
#include <vector>


std::string format_duration(int seconds) {
    if (seconds == 0)
    {
        return "now";
    }

    std::vector <std::string> time_parts;
    int year;
    bool year_available = ((seconds / 31536000) > 0) ? 1 : 0;
    if (year_available)
    {
        year = (seconds / 31536000);
    }
    
    int day;
    bool day_available = ((seconds % 31536000) / 86400 > 0) ? 1 : 0;
    if (day_available)
    {
        day = (seconds % 31536000) / 86400;
    }
    
    int hour;
    bool hour_available = ((seconds % 86400) / 3600 > 0) ? 1 : 0;
    if (hour_available)
    {
        hour = (seconds % 86400) / 3600;
    }
    
    int minute;
    bool minute_available = ((seconds % 3600) / 60) > 0 ? 1 : 0;
    if (minute_available)
    {
        minute = (seconds % 3600) / 60;
    }
    
    int second;
    bool seconds_available = (seconds % 60) > 0 ? 1 : 0;  
    if (seconds_available)
    {
        second = (seconds % 60);
    }
    
    if (year_available)
    {
        time_parts.push_back(std::to_string(year) + ((year > 1) ? " years" : " year"));
    }
    if (day_available)
    {
        time_parts.push_back(std::to_string(day) + ((day > 1) ? " days" : " day"));
    }
    if (hour_available)
    {
        time_parts.push_back(std::to_string(hour) + ((hour > 1) ? " hours" : " hour"));
    }
    if (minute_available)
    {
        time_parts.push_back(std::to_string(minute) + ((minute > 1) ? " minutes" : " minute"));
    }
    if (seconds_available)
    {
        time_parts.push_back(std::to_string(second) + ((second > 1) ? " seconds" : " second"));
    }

    std::string result;

    for (int i = 0; i < time_parts.size(); i++)
    {
        result += time_parts[i];
        if (i < time_parts.size() - 2)
        {
            result += ", ";
        }
        else if (i == time_parts.size() - 2)
        {
            result += " and ";
        }
    }
    
    if (result.substr(result.length() - 2, result.length() - 1) == ", ")
    {
        result.pop_back();
        result.pop_back();
    }
    
    return result;
}

int main () {
    std::cout << format_duration(3600) << std::endl;
    std::cout << format_duration(61) << std::endl;
    std::cout << format_duration(63) << std::endl;
    std::cout << format_duration(59) << std::endl;
    std::cout << format_duration(3599) << std::endl;
    std::cout << format_duration(0) << std::endl;
    std::cout << format_duration(3666) << std::endl;
    std::cout << format_duration(INT_MAX) << std::endl;
    std::cout << format_duration(31536060) << std::endl;
}