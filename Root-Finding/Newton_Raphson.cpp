#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double fun(double x){
    return x*x - 4*x +2;
}

double deb(double x){
    return 2*x -4;
}

void Newto_Rephson(double x, double ebh){
    double New_x;

    cout<<"I.No.\tx\tf(x)\tf'(x)\tNew_x"<<endl;

   for(int i=1;i<100;i++)
    {
        New_x = x - (fun(x)/deb(x));

        if(fabs(New_x-x)<ebh)
            break;
        
        cout<<fixed<<setprecision(2);
    
        cout<<i<<"\t"<<x<<"\t"<<fun(x)<<"\t"<<deb(x)<<"\t"<<New_x<<endl;

        x = New_x;
    }

    cout<<"The root is: "<<New_x;
}

int main(){
    double x, ebh;
    cout<<"Enter the initial guess and ephsilon: ";
    cin>>x>>ebh;
    Newto_Rephson(x,ebh);

}