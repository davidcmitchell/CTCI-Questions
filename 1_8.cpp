#include <iostream>
#include <vector>

void zeroRow(int row, std::vector<std::vector<int>> & mat)
{
    for (int i = 0; i < mat[row].size(); i++)
    {
        if (mat[row][i] != -1)
        {
            mat[row][i] = 0;
        }
    }
}

void zeroCol(int col, std::vector<std::vector<int>> & mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][col] != -1)
        {
            mat[i][col] = 0;
        }
    }
}

void zero(std::vector<std::vector<int>> & mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == -1)
            {
                zeroRow(i, mat);
                zeroCol(j, mat);
            }
        }
    }

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = 0;
            }
        }
    }
}



int main(int argc, char * argv[])
{
    std::vector<std::vector<int>> mat(3, std::vector<int>(3,0));
    int cnt = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            mat[i][j] = cnt;
            cnt++;
        }
    }
    zero(mat);
}