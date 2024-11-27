#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector;

int min(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}



void _solve()
{
    int k;
    cin >> k;
    vector<int> piramids(0);
    int dno = 1, pir = 1, n = 1;
    int count = 0;
    do
    {
       piramids.push_back(pir);
       ++n;
       dno += n;
       pir += dno;
       count++;
    }while (piramids[piramids.size()-1] < k);
 
    // for (size_t i = 0; i < piramids.size(); i++)
    // {
    //     cout << piramids[i] << " ";
    // }
    // cout << endl;
    
    
    int len = piramids.size() + 1;
    int matrix[len][k+1];
    for (size_t i = 0; i < len; i++)
    {
        for (size_t g = 0; g < k+1; g++)
        {
             matrix[i][g] = 0;
        }
    }
 
    for (size_t i = 1; i < k+1; i++)
    {
        matrix[1][i] = i; 
    }
    
 
    for (int i = 2; i < len; i++)
    {
        for (int g = 1; g < k+1; g++)
        {
            if(g - piramids[i-1] >= 0)
            {
 
                matrix[i][g] = min(matrix[i][g-piramids[i-1]] + 1, matrix[i-1][g]);
            }
            else
                matrix[i][g] = matrix[i-1][g];
        }
    }
 
    int min = k;
    
    // for (size_t i = 0; i < k+1; i++)
    // {
    //     for (size_t g = 0; g < k+1; g++)
    //     {
    //         cout << matrix[i][g] << " ";
    //     }
    //     cout << endl;
    // }
 
    for (size_t i = 1; i < len; i++)
    {
        if(min > matrix[i][k])
            min = matrix[i][k];
    }
    
    
    
    
    cout << min << endl;
    
}
 
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
 
    // std::freopen("lepus.in", "r", stdin);
    // std::freopen("lepus.out", "w", stdout);
    int t;
    cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        _solve();
    }
    
    return 0;
}