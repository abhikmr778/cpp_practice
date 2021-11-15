// stored as key:value pairs is like python dictionary

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, string> m;
    m[1] = "Nissan GTR"; //m[key] = "value"
    m[2] = "BMW M5";
    m[13] = "Porsche Cayman";

    m.insert({5, "Lamboghini Hurracan"});

    for(auto i:m){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    cout<<endl;

    m.erase(13); //erase requires key

    for(auto i:m){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    cout<<endl;
    // map<int, string>::iterator it = m.find(5);
    // cout<<"What is at key 5? "<<it->second<<endl;

    auto itr = m.find(5);
    for(auto i=itr;i!=m.end();i++){
        cout<<(*i).first<<endl;
    }
    // search complexity is O(logn) in map, O(1) in unordered map
    int k = 5;
    char c = '0'+char(k);
    cout<<c<<endl;
    return 0;
}