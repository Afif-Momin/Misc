#include<iostream>
using namespace std;
float u_cal(float u, int n)
{
    float temp=u;
    for(int i=1;i<n;i++)
    {
        temp = temp*(u+i);
    }
    return temp;
}
int fact(int n)
{
    int f=1;
    for(int i=2;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}

int main()
{
    float x[20];
    float y[20][20];
    int i,j,n;
    cout<<"Enter total no of data:";
    cin>>n;
    cout<<endl<<"Enter data:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter x["<<i<<"] =";
        cin>>x[i];
        cout<<"Enter y["<<i<<"] =";
        cin>>y[i][0];
    }

    //Generate
    for(i=1;i<n;i++)
    {
        for(j=n-1;j>i-1;j--)
        {
            y[j][i] = y[j][i-1] - y[j-1][i-1];
        }
    }

    cout<<endl<<"Displaying Backward Interpolation:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<x[i];
        for(j=0;j<=i;j++)
        {
            cout<<"\t"<<y[i][j];
        }
        cout<<endl;
    }
    float val;
    cout<<"Enter interpolation point:";
    cin>>val;
    float sum = y[n-1][0];
    float u = (val-x[n-1])/(x[1]-x[0]);
    for(int i=1;i<n;i++)
    {
        sum = sum + (u_cal(u,i)*y[n-1][i])/(fact(i));
    }
    cout<<"Interpolation point at "<<val<<" is "<<sum<<endl;;
    return 0;
}