#include<iostream>
using namespace std;
// calculating u mentioned in the formula

float u_cal(float u, int n)
{
 float temp = u;
 for (int i = 1; i < n; i++)
 temp = temp * (u - i);
 return temp;
}
// calculating factorial of given number n
int fact(int n)
{
 int f = 1;
 for (int i = 2; i <= n; i++)
 f *= i;
 return f;
}

// Forward Table start
int main()
{
 float x[20], y[20][20];
 int i,j, n;
 /* Input Section */
 cout << "Enter number of data? " << endl;
 cin >> n;
 cout << "Enter data: " << endl;
 for(i = 0; i < n ; i++)
 {
 cout << "x[" << i << "] = ";
 cin >> x[i];
 cout << "y[" << i <<"] = ";
 cin >> y[i][0];
 }
 /* Generating Forward Difference Table */
 for(i = 1; i < n; i++)
 {
 for(j = 0; j < n-i; j++)
 {
 y[j][i] = y[j+1][i-1] - y[j][i-1];
 }
 }
 /* Displaying Forward Difference Table */
 cout << endl << "FORWARD DIFFERENCE TABLE" << endl;
 for(i = 0; i < n; i++)
 {
 cout << x[i];
 for(j = 0; j < n-i ; j++)
 {
 cout << "\t" << y[i][j];
 }
 cout << endl;
 }
 // Forward Table End.........

  // Value to interpolate at
 float value;
 cout << "Enter interpolation point" << endl;
 cin >> value;
 // initializing u and sum
 float sum = y[0][0];
 float u = (value - x[0]) / (x[1] - x[0]);
 for (int i = 1; i < n; i++) 
 {
 sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
 }
 cout << "\n Value at " << value << " is " << sum << endl;
 return 0;
}
