#include <iostream>
#include <string>

bool isPermutation(std::string wrd)
{
    int ltr_cnt[26] = {0};
    for (char & c : wrd)
    {
        if (c != ' ')
        {
            ltr_cnt[std::toupper(c)-'A']++;
        }
    }
    bool found_odd = false;
    for (int cnt : ltr_cnt)
    {
        if (cnt % 2 != 0)
        {
            if (found_odd)
            {
                return false;
            }
            else
            {
                found_odd = true;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (isPermutation("tact coa"))
    {
        std::cout << "yes" << std::endl;
    }
    return 0;
}