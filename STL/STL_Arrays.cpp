//arrays are static

#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int, 4> a = {1,2,3,4};
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<a.at(1)<<endl;
    cout<<a.empty()<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    return 0;
}