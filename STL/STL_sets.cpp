// implemented using binary search tree
// elements are returned in sorted ordered

// unordered set is not sorted but random
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    set<int> s;

    s.insert(5); // insetion takes O(logn)
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(1);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(int i: s) cout<<i<<" "; cout<<endl;
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it); 
    for(int i: s) cout<<i<<" "; cout<<endl;

    cout<<"Is '5' present? "<<s.count(5)<<endl; // count tells present or not
    
    set<int>::iterator itr = s.find(5); //returns iterator to 5

    cout<<"Value at itr: "<<*itr<<endl;
    
    for(auto i=itr; i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    // insert, find, erase and count have O(logn)
    unordered_set<string> str;
    str.insert("code");
    str.insert("in");
    str.insert("c++");
    str.insert("is");
    str.insert("fast");
    for(auto i:str){
        cout<<i<<" ";
    }
    return 0;
}