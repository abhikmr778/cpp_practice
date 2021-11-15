#include <bits/stdc++.h>
using namespace std;
 
int childrensday(int n, int k, int vals[]){
    sort(vals,vals+n, greater<int>());
    //assuming k<n always
    return vals[k-1];
}
int main(){
    int arr[] = {100,20,40,20,50,50};
    cout<<childrensday(6,4,arr);

    return 0;
}
// int add(int n, int k, int arr[]){
//     sort(arr,arr+n);
//     int sum=0;
//     bool odd = false;
//     if(n%2!=0){
//         odd = true;
//     }
//     for(int i=0;i<n-2;i+=2){
//         sum += k*(arr[i]+arr[i+1]);
//     }
//     if(odd){
//         sum += k*(arr[n-1]+arr[n-1]);
//     }
//     return sum;
// }