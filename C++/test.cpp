// #include <string>
// #include <iostream>
// #include <filesystem>
// #include <stdio.h>
// #include <fstream>

// int main () {

//     for (int i = 1; i <= 8; i++)
//     {

//         std::filesystem::path path_of_file_will_be = std::filesystem::path("C:/Study/repos/python/TSIS_6/Files_and_Directories_manipulation") / ("Ex"+ std::to_string(i) + ".py");
        
//         if (!std::filesystem::exists(path_of_file_will_be))
//         {
//             std::ofstream user_info_txt_file(path_of_file_will_be);
            
//             if (user_info_txt_file.is_open())
//             {       
//                 user_info_txt_file << "def" << std::endl;
//                 std::cout << "Ex" + std::to_string(i) + " was created" << std::endl;
//             }
//         }
//         else
//         {
//             printf("File already exists!\n");
//         }
//     }

//     return 0;
// }
#include <vector>
#include <iostream>

int main () {
    std::vector <int> array;

    for (int i = 0; i < 1000000; i++)
    {
        array.push_back(i);
        std::cout << i << std::endl;
    }

    return 0;
}