#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "ERROR: too less/many arguments" << std::endl;
    else if (!argv[2][0])
        std::cout << "ERROR: the string that needs to be replaced can't be empty" << std::endl;
    else
    {
        size_t i;
        std::string temp(argv[1]), ins;
        std::ifstream ifs(temp);
        if (!ifs.is_open())
            std::cout << "Error opening input file. Maybe the file name isn't right ?" << std::endl;
        else
        {
            std::ofstream ofs(temp + ".replace");
            if (!ofs.is_open())
                std::cout << "Error opening output file" << std::endl;
            else
            {
                while (!ifs.eof())
                {
                    std::getline(ifs, temp);
                    ins += (temp + "\n");
                    if (ifs.fail())
                        std::cout << "Error reading from input stream" << std::endl;
                }
                ins.erase(ins.length() - 1, 1);
                temp = std::string(argv[2]);
                while ((i = ins.find(temp)) != std::string::npos)
                {
                    ins.erase(i, temp.length());
                    ins.insert(i, argv[3]);
                }
                ofs << ins;
            }
        }
    }
}