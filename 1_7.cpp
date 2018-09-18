#include <iostream>
#include <vector>

std::string rotate(std::vector<std::vector<int>> & img)
{
    int n = img.size();
    for (int i = 0; i < n/2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int tmp = img[i][j];
            img[i][j] = img[j][n-i-1];
            img[j][n-i-1] = img[n-i-1][n-j-1];
            img[n-i-1][n-j-1] = img[n-j-1][i];
            img[n-j-1][i] = tmp;
        }
    }
}

int main(int argc, char * argv[])
{
    std::vector<std::vector<int>> img(3, std::vector<int>(3,0));
    int cnt = 1;
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[i].size(); j++)
        {
            img[i][j] = cnt;
            cnt++;
        }
    }
    rotate(img);
}