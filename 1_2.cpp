#include <iostream>
#include <string>

bool isPermutation(std::string wrd1, std::string wrd2)
{
    int ltr_cnt[26] = {0};
    for (char &c : wrd1)
    {
        ltr_cnt[std::tolower(c)-'a']++;
    }
    for (char &c : wrd2)
    {
        ltr_cnt[std::tolower(c)-'a']--;
    }
    for (int i : ltr_cnt)
    {
        if (i != 0)
        {    
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (isPermutation("yes","yes"))
    {
        std::cout << "yes" << std::endl;
    }
}
