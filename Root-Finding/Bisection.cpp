#include<iostream>
#include<cmath>
using namespace std;

double function(double x){
    return x*x*x -x*x -2;
   
}

double bisection(double a, double b, double ebh){
    if(function(a)*function(b) > 0){
        cout<<"Wrong initialization."<<endl;
    }
    double c;
    while(true){
        c = (a+b)/2;
        if(function(c)==0)break;
        if(fabs(function(c)) < ebh)break;
        if(function(a)*function(c)<0){
            b=c;
        }
        else a=c;
    }
    cout<<"result is: "<<c<<endl;
}

int main(){
    double a,b;
    double ebh;
    cout<<"Enter the value of a, b and ebhselon siquentially: ";
    cin>>a>>b>>ebh;
    bisection(a,b,ebh);
}