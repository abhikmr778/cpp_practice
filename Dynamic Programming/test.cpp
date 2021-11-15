#include <iostream>
#include <vector>

using namespace std;

int h1, h2;
int sum1, sum2;
int res;

void solve(int N, int K, vector<int> arr, int ind){ //N = length of arr, K=target sum, arr = contains values, ind=curr index
  if (sum1 >= K && sum2 >= K){//subsets need to have sum at least K
    if (h1 + h2 < res) // take min result
      res = h1 + h2;
    return;
  }
  if (ind == N) // if reached beyond last index then return
    return;

  solve(N, K, arr, ind + 1); // exclude curr element

  // include curr index in first subset
  sum1 += arr[ind];
  h1++;
  solve(N, K, arr, ind + 1);

  //exclude this element from first subset and include curr element in second subset
  sum1 -= arr[ind];
  h1--;
  sum2 += arr[ind];
  h2++;
  solve(N, K, arr, ind + 1);
  
  // backtrack
  sum2 -= arr[ind];
  h2--;
}

int main() 
{
  vector<int> arr = {14, 3, 7, 8, 9, 7, 12, 15, 10, 6};
  int N = arr.size(), K = 40;

  h1 = 0; h2 = 0;// lengths of subsets

  sum1 = 0; sum2 = 0;//sum of subsets

  res = N + 1; //initialize as maximum value
  
  solve(N, K, arr, 0);
  if (res == N + 1)
    cout << "No solution!" << endl;
  else
    cout << res << endl;
  return 0;
}