#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first+a.second<b.first+b.second) return true; //ascending order
    else return false;
}

void sortArray(vector<pair<int, int>> &A){
    sort(A.begin(),A.end(),comp);
    
    // for(int i=0;i<A.size();i++){
    //     for(int j=0;j<A.size()-1;j++){
    //         if(comp(A[j],A[j+1])){
    //             pair<int,int> temp = make_pair(A[j].first,A[j].second);
    //             A[j] = A[j+1];
    //             A[j+1] = temp;
    //         }
    //     }
    // }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++) cin>>A[i].first>>A[i].second;
    sortArray(A);
    for(int i=0;i<n;i++){
        cout<<A[i].first+A[i].second<<":"<<A[i].first<<" "<<A[i].second<<endl;
    }
}