#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> q;

    q.push("1stperson");
    q.push("2ndperson");
    q.push("3rdperson");

    cout<<"Size: "<<q.size()<<endl;
    cout<<"First in line: "<<q.front()<<endl;
    q.pop();
    cout<<"First in line: "<<q.front()<<endl;
    q.pop();
    cout<<"First in line: "<<q.front()<<endl;

    cout<<"Size: "<<q.size()<<endl;

    return 0;
}