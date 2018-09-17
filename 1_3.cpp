#include <iostream>
#include <string>

void replace(std::string wrd)
{

    std::string wrd_rp;
    std::string rep = "\%20";
    for (int i = 0; i < wrd.length(); i++)
    {
        if (wrd[i] != ' ')
        {
            wrd_rp.append(1, wrd[i]);
        }
        else
        {
            wrd_rp.append(rep);
        }
    }
    std::cout << wrd_rp << std::endl;
}

int main(int argc, char* argv[])
{
    replace("hello there cowboy");
}