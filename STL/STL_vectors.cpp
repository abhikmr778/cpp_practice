// vector is a dynamic array
// if vector size if exceeded, a new vector of double the size created
// all elements are copied and the original vector is deleted

#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v;
    cout<<"Capacity: "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Capacity: "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity: "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capacity: "<<v.capacity()<<endl; // capacity becomes 4 now as the size doubles
    cout<<"Size: "<<v.size()<<endl;
    // capacity means how much is allocated; size means no of elements
    cout<<"Element at 2nd index "<<v.at(2)<<endl;

    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    v.pop_back();
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    cout<<"Size: "<<v.size()<<endl;
    v.clear();
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;

    //more initializations
    vector<int> a(5,1); //(size, initilization)
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
    vector<int> last(a); // copies element from a
    for(int i=0;i<last.size();i++){
        cout<<last.at(i)<<" ";
    }
    return 0;
}