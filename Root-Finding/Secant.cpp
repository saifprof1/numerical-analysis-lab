#include<iostream>
#include<cmath>
using namespace std;

double fun(double x){
    return x*x*x - x*x -2;
}

void Secant(double x0, double x1, double eph){

    double x2;
    while (true){
        x2 = x1 - ((fun(x1)*(x1-x0))/(fun(x1)- fun(x0)));

        if(fabs(fun(x2))<eph){
            break;
        }

        x0 = x1;
        x1 = x2;

    }

    cout<<"The result is: "<<x2<<endl;
      
}

int main(){
    double x0, x1, eph;
    cout<<"Enter the vlaue of x0, x1 and epsilon sequentially: ";
    cin>>x0>>x1>>eph;
    Secant(x0, x1, eph);

    return 0;
}