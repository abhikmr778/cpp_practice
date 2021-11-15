
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Complete the given function
vector<int> solve(vector<int> &A, int B){
    vector<int> ans;
    for(int i=0;i<=A.size()-B;i++){
        int max = INT32_MIN;
        for(int j=i;j<i+B;j++){
            if(A[j]>=max) max = A[j];
        }
        ans.push_back(max);
    }
    return ans;
}



int main()  {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i = 0; i < n; i++){
            cin>>A[i];
        }
        int B;
        cin>>B;
        vector<int> ans = solve(A, B);
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
