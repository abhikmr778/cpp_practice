#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    
    //binary search
    cout<<"Is 6 present? "<<binary_search(v.begin(),v.end(),6)<<endl;

    //lower bound
    cout<<"Lower bound for 4 is an element at position-> "<<lower_bound(v.begin(),v.end(),4) - v.begin()<<endl;

    //max;min;swap
    int a=3;
    int b=5;
    cout<<"Max(a,b)-> "<<max(a,b)<<endl;
    cout<<"Min(a,b)-> "<<min(a,b)<<endl;
    swap(a,b);
    cout<<"After swap; a-> "<<a<<endl;

    //reverse
    // string s = "abcd";
    // reverse(s.begin(), s.end());
    // cout<<"Reverse: "<<s<<endl;

    //rotate
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    rotate(v.begin(),v.begin()+2,v.end()); //(start, rotate till, end)
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    //sort
    sort(v.begin(),v.end()); //intro sort using quick sort, heap sort and insertion sort
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    string s="";
    s+=to_string(1);
    s+=to_string(10);
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;
    return 0;
}