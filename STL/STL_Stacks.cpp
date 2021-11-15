#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<string> s;

    s.push("first");
    s.push("second");
    s.push("third");

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout<<"Size: "<<s.size()<<endl;
    cout<<"Empty? "<<s.empty()<<endl;
    return 0;
}