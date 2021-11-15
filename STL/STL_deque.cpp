// doubly ended queue
// can do deletion and insertion at both ends
// its dynamic

#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    d.pop_back();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.push_back(1);
    d.pop_front();
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.push_front(2);
    cout<<d.at(0)<<endl;

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<d.empty()<<endl;

    cout<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);
    cout<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<d.max_size()<<endl;
    return 0;
}