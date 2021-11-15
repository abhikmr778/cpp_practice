
#include <iostream>
#include <vector>
#include<tuple>
using namespace std;


pair<int, int> findMaxMin(vector<int> &A){
    // First value of pair will be Maximum of array A and second will be Minimum of array A
    int max = INT32_MIN;
    int min = INT32_MAX;

    for(int i=0;i<A.size();i++){
        if(A[i]<min) min = A[i];
        if(A[i]>max) max = A[i];
    }
    pair<int, int> p = make_pair(max,min);
    return p;

    
}

tuple<int, int, int> compute(vector<int> &A){
    // First value of tuple will be sum of array A
    // Second value of tuple will be sum of even values in array A 
    // Third value of tuple will be sum of odd values in array A
    int sum = 0;
    int sum_o = 0;
    int sum_e = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]%2==1) sum_o += A[i];
        else if(A[i]%2==0) sum_e += A[i];
    }
    sum = sum_e+sum_o;
    tuple<int, int, int> t = make_tuple(sum, sum_e, sum_o);
    return t;   
}


int main()  {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    
    pair<int, int> max_min = findMaxMin(A);
    cout<<max_min.first<<" "<<max_min.second<<endl;
    
    tuple<int, int, int> tuple_values = compute(A);
    cout<< get<0>(tuple_values) << " " << get<1>(tuple_values) << " " << get<2>(tuple_values) << endl;
    
    return 0;
}
