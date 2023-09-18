// N.R
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double func(double x)
{
    return pow(x,3)+cos(2)*3.14*x-exp(x);
}
double df(double x)
{
    return 3*pow(x,2)-sin(2)*0-exp(x);
}
double n_r(double x0)
{
    double x1=x0-func(x0)/df(x0);
    int i=1;
    while(abs(x1-x0)>0.0001)
    {
        if(df(x0)==0)
        {
            cout<<"NR failed!!";
            exit(0);
        }
        cout<<"Iteration "<<i++<<":"<<x1<<endl;
        x0=x1;
        x1=x0-func(x0)/df(x0);
    }
    return x1;
}
int main()
{
    double x0;
    cout<<"Enter x0:";
    cin>>x0;
    double root = n_r(x0);
    cout<<"Root:"<<root<<endl;
    return 0;
}