#include <bits/stdc++.h>
// #include<>
using namespace std;

int noOfRotations(string A){
    int n=A.length();
    string B=A;
    int itr=1;
    do{
        for(int k=0;k<itr;k++){
            for(int j=0;j<n-1;j++){
                char c=B[j];
                B[j] = B[(j+n-1)%n];
                B[(j+n-1)%n] = c;
            }
            // cout<<B<<" "<<itr<<" "<<k<<endl;
        }
        itr++;
    }while(A!=B);
    return itr-1;
}

int lcm(vector<int> &itr){
    int maxitr = *max_element(itr.begin(),itr.end());
    int ans = 1;
    for(int i=2;i<=sqrt(maxitr);i++){
        int countDivisbleByi = 0;
        cout<<"Array: ";
        for(int k=0;k<itr.size();k++){
            cout<<itr[k]<<" ";
        }
        cout<<endl;
        for(int j=0;j<itr.size();j++){
            if(itr[j]%i==0) {
                itr[j]=itr[j]/i;
                countDivisbleByi++;
            }
        }
        if(countDivisbleByi!=0){
            ans=ans*i;
            cout<<"Answer: "<<ans<<" "<<i<<endl;
            i--;
        } 

    }
    for(int k=0;k<itr.size();k++){
        ans*=itr[k];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<int> itr(n);
    for(int j=0;j<n;j++){
        itr[j] = noOfRotations(A[j]);
        // cout<<A[j]<<" "<<itr[j]<<endl;
    }
    int ans = lcm(itr);
    cout<<"Minimum unit time: "<<ans<<endl;
    return 0;
}