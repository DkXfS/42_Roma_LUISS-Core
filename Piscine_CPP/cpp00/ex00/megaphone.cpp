#include <iostream>

int main(int argc, char** argv)
{
    int i=1, j;

    if(argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        while(i < argc)
        {
            j=0;
            while (argv[i][j])
            {
                if(argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    argv[i][j] -= 32;
                j++;
            }
            std::cout << argv[i];
            i++;
        }
    std::cout << std::endl;
}