#include <filesystem>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		std::filesystem::path some_file = std::filesystem::path("C:/Study/test") / (std::to_string(i) + ".py");

		if (!std::filesystem::exists(some_file))
		{
			printf("Path doesn't exist\n");
			std::ofstream user_info_txt_file(some_file);
			if (user_info_txt_file.is_open())
			{
				user_info_txt_file << "def ";
				user_info_txt_file.close();
				printf("Data has been wriiten: %i \n", i);
			}
			else
			{
				std::cerr << "Unable to open the file\n\n"
						  << std::endl;
			}
		}
		else
		{
			std::cerr << "File already exists\n\n"
					  << std::endl;
		}
	}

	return 0;
}