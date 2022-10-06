#include <bits/stdc++.h>
using namespace std;
string matrix[105] = {};
int main()
{
    int n, line = -1, row = -1;
    int count = 0;
    while (1)
    {
        cin >> n;
        cin.get();
        if (n == 0)break;
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            count = 0;
            getline(cin, matrix[i]);
            if(!flag)continue;
            for (int j = 0; j <= 2 * n - 2; j++)
                if (matrix[i][j] == '1') count++;
            if (count % 2 == 1)
            {
                if (line == -1)
                    line = i;
                else
                {
                    cout << "Corrupt" << endl;
                    flag = false;
                }
            }
        }

        for (int j = 0; j <= 2 * n - 2 && flag; j++)
        {
            count = 0;
            for (int i = 1; i <= n; i++)
            {
                if (matrix[i][j] == '1')
                    count++;
            }
            if (count % 2 == 1)
            {
                if (row == -1)
                    row = j;
                else
                {
                    cout << "Corrupt" << endl;
                    flag = false;
                }
            }
        }
        if (flag)
        {

            if (line == -1 && row == -1)
                cout << "OK" << endl;
            else if (line != -1 && row != -1)
                printf("Change bit (%d,%d)\n", line, (row + 2) / 2);
            else
                cout << "Corrupt" << endl;
        }
        line = -1; row = -1;
    }
}