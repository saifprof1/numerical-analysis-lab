#include <iostream>
#include <cmath>
using namespace std;

double fun(double x){
    return x*x*x -x*x -2;
}

void False_Position(double a, double b, double eph){
    if (fun(a)*fun(b) > 0){
         cout<<"Invalid initialization."<<endl;
         return;
    }

    double c;
    while (true)
    {
        c = a - ((fun(a)*(b-a))/(fun(b)-fun(a)));
        if (fabs(fun(c))< eph) break;
        if(fun(a)*fun(c)<0){
            b = c;
        }
        else a = c;
    }

    cout<< "The result is "<< c<<endl;
    

}

int main(){
    cout<<"Enter the value of a, b and ephsion sequentially: ";
    double a, b, eph;
    cin>> a>> b>> eph;
    False_Position(a,b,eph);

    return 0;

}