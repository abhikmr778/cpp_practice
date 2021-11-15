// implemented in STL using doubly linked lists
// direct access not allowed
#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> l;

    l.push_back(1);
    l.push_front(2);

    for(int i:l) cout<<i<<" "; cout<<endl;
    l.erase(l.begin()); //iterator pointing to the element gets deleted
    for(int i:l) cout<<i<<" "; cout<<endl;

    cout<<"Size: "<<l.size()<<endl;
    

    list<int> n(l);
    for(int i:n) cout<<i<<" "; cout<<endl;
    list<int> m(5,100);
    for(int i:m) cout<<i<<" "; cout<<endl;
    return 0;
}