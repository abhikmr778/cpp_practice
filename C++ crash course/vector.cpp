#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        A[i] = t;
    }
    int d;
    cin>>d;
    A.erase(A.begin()+d);
    sort(A.begin(),A.end());
    for(int i=0;i<n-1;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}