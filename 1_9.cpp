#include <iostream>
#include <string>

bool rotate(std::string wrd1, std::string wrd2)
{
    if (wrd1.length() != wrd2.length())
    {
        return false;
    }

    int lng = wrd1.length();

    for (int i = 0; i < lng; i++)
    {
        int pos1 = 0;
        int pos2 = i;
        while (pos2 < i + lng)
        {
            if (wrd1[pos1] != wrd2[pos2 % lng])
            {
                break;
            }
            pos1++;
            pos2++;
            if (pos2 == i + lng)
            {
                return true;
            }
        }

    }
}

int main(int argc, char* argv[])
{
    rotate("waterbottle","erbottlewat");
    return 0;
}