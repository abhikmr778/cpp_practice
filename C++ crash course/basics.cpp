#include <iostream>
#include <iomanip>
using namespace std;

// int main(){
    // typedef int item;
    // item number = 0;
    // number++;
    // cout<<number;
//     return 0;
// }

int main(){
    int a;
    long b;
    char c;
    float d;
    double e;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<fixed<<setprecision(3)<<d<<endl;
    cout<<fixed<<setprecision(9)<<e<<endl;
    return 0;
}