//Bisection
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double func(double x)
{
    return x*exp(x)-3;
}
double bisection(double a, double b, double epsilon)
{
    double c;
    int i;
    while((b-a)>=epsilon)
    {
        c=(a+b)/2;
        i++;
        
        cout<<"Iteration:"<<i<<": ";
        cout<<"a= "<<a<<" b= "<<b<<" c= "<<c<<" function(c)= "<<func(c)<<endl;

        if(func(c)==0)
         break;
        else if(func(a)*func(c)<0)
        {
            b=c;
        }
        else
        {
            a=c;
        }
    }
    return c;
}
int main()
{
    double a=1;
    double b=2;
    double epsilon=0.001;
    double root = bisection(a,b,epsilon);
    cout<<"Root:"<<root<<endl;
    return 0;
}