#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 100;
 
void luDecomposition(int mat[][MAX], int n)
{
    int lower[n][n], upper[n][n];
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));
 
    // Descomposición de la matriz en Superior e Inferior
    // matriz triangular
    for (int i = 0; i < n; i++) 
    {
        // Triangular superior
        for (int k = i; k < n; k++)
        {
            // Sumacion de L(i, j) * U(j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);
 
            // Evaluar U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }
 
        // Triangular inferior
        for (int k = i; k < n; k++) 
        {
            if (i == k)
                lower[i][i] = 1; // Diagonal as 1
            else
            {
                // Sumacion de L(k, j) * U(j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);
 
                // Evaluating L(k, i)
                lower[k][i]
                    = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }
 
    // setw is for displaying nicely
    cout << setw(6) 
         << "      Triangular inferior"
         << setw(32)
         << "Triangular superior" << endl;
 
    // Displaying the result :
    for (int i = 0; i < n; i++) 
    {
        // Lower
        for (int j = 0; j < n; j++)
            cout << setw(6) << lower[i][j] << "\t";
        cout << "\t";
 
        // Upper
        for (int j = 0; j < n; j++)
            cout << setw(6) << upper[i][j] << "\t";
        cout << endl;
    }
}
 
// Driver code
int main()
{
    int mat[][MAX]
        = { { 2, -1, -2 }, { -4, 6, 3 }, { -4, -2, 8 } };
 
    luDecomposition(mat, 3);
    return 0;
}



