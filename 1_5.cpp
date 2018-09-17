#include <iostream>
#include <string>

using namespace std;

bool oneAway(std::string wrd1, std::string wrd2)
{
    std::string longer, shorter;
    if (wrd1.length() >= wrd2.length())
    {
        longer = wrd1;
        shorter = wrd2;
    }
    else
    {
        longer = wrd2;
        shorter = wrd1;
    }

    if (longer.length() - shorter.length() > 1)
    {
        return false;
    }

    int poss = 0;
    int posl = 0;
    
    bool diff = false;
    
    while (poss < shorter.length())
    {
        if (longer[posl] != shorter[poss])
        {
            if (diff)
            {
                return false;
            }
            diff = true;
            posl++;
            if (longer.length() == shorter.length())
            {
                poss++;
            }
        }
        else
        {
            posl++;
            poss++;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (oneAway("pale","bake"))
    {
        std::cout << "yes";
    }
}