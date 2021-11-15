#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int query;
        cin>>query;
        vector<int>::iterator lower;
        lower = lower_bound(A.begin(), A.end(), query);
        cout<<lower-A.begin()<<endl;
    }
    return 0;
}