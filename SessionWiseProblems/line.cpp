#include <iostream>
using namespace std;
int main(){
    int a1=2;
    int a2=3;
    int b1=3;
    int b2=2;
    int c1=-5;
    int c2=-5;
    int d=(a1*b2)-(a2*b1);
    if(d!=0){
        cout<<"intersecting"<<endl;
        int x=(b1*c2-b2*c1)/d;
        int y=((-a1*c2)+a2*c1)/d;
        cout<<x<<endl<<y;
    }
    else cout<<"parellel";
}