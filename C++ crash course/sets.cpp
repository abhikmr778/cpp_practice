#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int q;
    cin>>q;
    set<int> s;
    while(q){
        int x,y;
        cin>>y>>x;
        switch(y){
            case 1:
                s.insert(x);
                break;
            case 2:
                s.erase(s.find(x));
                break;
            case 3:
                if(s.find(x)!=s.end()) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
                break;
        }
        q--;
    }
    if(s.size()>0){
        // sort(s.begin(),s.end());
        for(set<int>::iterator it = s.begin();it!=s.end();it++){
            cout<<*it<<endl;
        }
    }
    return 0;
}