#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    float x[10], y[10], d[10][10], a, sum, derivative, h, term;
    int i, j, k, n, sign;

    cout << "Enter number of table points: ";
    cin >> n;

    for (i = 1; i <= n; i++) {
        cout << "Enter x[" << i << "]: ";
        cin >> x[i];
        cout << "Enter y[" << i << "] = ";
        cin >> y[i];
    }
    
    h= x[2]-x[1];

    cout << "Enter tabulated point: ";
    cin >> a;

    if (a < x[1] && a > x[n]) {
        cout << "\nValue lies outside range\n";
        exit(1);
    }

    i = 1;
    while (a != x[i]) {
        i++;
    }

    k = i;
    for (j = 1; j <= (n - 1); j++) {
        for (i = 1; i <= (n - j); i++) 
	    {
            if (j == 1) {
                d[i][j] = (y[i + 1] - y[i]) ;
            } else {
                d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) ;
            }
        }
    }

    sum = 0.0;
    sign = 1;

    for (j = 1; j <= (n - k); j++) 
    {
        term = sign * d[k][j] / j;
        sum = sum + term;
        sign = -sign;
    }

    derivative = (1.0 / h) * sum;
   
    cout << setprecision(4) << "\nValue of the derivative = " << derivative << endl;

    return 0;
}























