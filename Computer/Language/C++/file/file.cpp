#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream read_file;
    read_file.open("data.data", std::ios::binary);
    std::string line;
    std::getline(read_file, line);
    std::cout << "line1: " << line.c_str() << std::endl;

    std::getline(read_file, line);
    std::cout << "line2: " << line.c_str() << std::endl;  

    std::ifstream in("data/data.data");
	std::string filename;
	//std::string line;
 
	if(in) // 有该文件
	{
		while (std::getline (in, line)) // line中不包括每行的换行符
		{ 
			std::cout << line << std::endl;
		}
	}
	else // 没有该文件
	{
		std::cout <<"no such file" << std::endl;
	}

    return 0;
}
