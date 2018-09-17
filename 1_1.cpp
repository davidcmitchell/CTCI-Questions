#include <iostream>
#include <string>

void mergeSort(std::string & wrd)
{
    if (wrd.length() <= 1)
    {
        return;
    }
    int mid = wrd.length()/2;
    std::string left = wrd.substr(0,mid);
    std::string right = wrd.substr(mid,wrd.length()-mid);
    mergeSort(left);
    mergeSort(right);
    int pos0 = 0, pos1 = 0, pos2 = 0;
    while (pos0 < wrd.length())
    {
        if (pos1 < left.length() && pos2 < right.length())
        {
            if (std::toupper(left[pos1]) < std::toupper(right[pos2]))
            {
                wrd[pos0] = left[pos1];
                pos1++;
            }
            else
            {
                wrd[pos0] = right[pos2];
                pos2++;
            }
        }
        else if (pos1 < left.length())
        {
            wrd[pos0] = left[pos1];
            pos1++;
        }
        else
        {
            wrd[pos0] = right[pos2];
            pos2++;
        }
        pos0++;
    }
}

bool isUnique(std::string & wrd)
{
    mergeSort(wrd);
    if (wrd.length() <= 1)
    {
        return true;
    }
    for (int i = 1; i < wrd.length(); i++)
    {
        if (std::toupper(wrd[i]) == std::toupper(wrd[i-1]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char * argv[])
{
    std::string wrd = "heey";
    if (isUnique(wrd))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}