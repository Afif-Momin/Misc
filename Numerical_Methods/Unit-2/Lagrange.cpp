// lagrange method
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    float x[100],y[100],xp,yp=0,p;
    int i,j,n;
    cout<<"Enter no of data:";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Enter x["<<i<<"] =";
        cin>>x[i];
        cout<<"Enter y["<<i<<"] =";
        cin>>y[i];
    }

    cout<<"Enter interpolation point:";
    cin>>xp;

    for(i=0;i<n;i++)
    {
        p=1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                p=p*(xp-x[i])/(x[i]-x[j]);
            }
            
        }
        yp= yp + p*y[i];
    }
    cout<<"Value of y at "<<xp<<" is "<<yp<<endl;
    return 0;
}