#include <iostream>

std::string compress(std::string wrd)
{
    std::string compress = "";
    int pos = 0;
    while (pos < wrd.length())
    {
        int cnt = 0;
        char c = wrd[pos];
        while (wrd[pos] == c)
        {
            pos++;
            cnt++;
        }
        compress.push_back(c);
        compress.push_back('0' + cnt);
    }
    if (compress.length() < wrd.length())
        return compress;
    else
        return wrd;
}

int main(int argc, char * argv[])
{
    std::cout << compress("abcd") << std::endl;
}