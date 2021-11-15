#include<iostream>
#include<sstream>
using namespace std;


int main()  {
    string A;
    cin>>A;
    // YOUR CODE GOES HERE
    stringstream ss(A);
    // int a;
    // char ch;
    // while(ss>>a){
    //     cout<<a<<endl;
    //     ss>>ch;
    //     // ss>>a;
    // }
    while(ss.good()){
        string substr;
        getline(ss,substr,',');
        cout<<substr<<endl;
    }
    return 0;
}