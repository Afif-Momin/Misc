// Absolute & Relative error
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double actualPi;
    cout<<"Enter actual value:";
    cin>>actualPi;

    double approaxPi;
    cout<<"Enter approax value:";
    cin>>approaxPi;
    
    cout<<"Absolute Error:-"<<endl;

    double absolutePi=abs(actualPi-approaxPi);
    cout<<"Absolute Error:"<<absolutePi<<endl;

    cout<<"Relative Error:-"<<endl;
    double relativePi=(actualPi-approaxPi)/actualPi;
    cout<<"Relative Error:"<<relativePi;

    return 0;
}