#include <cinttypes>
#include <iostream>
#include <algorithm>
using namespace std;

uint64_t descendingOrder(uint64_t a)
{
  string s="";
  while(a){
    int temp = a%10;
    a=a/10;
    s+='0'+temp;
  }
  sort(s.begin(), s.end(), greater<char>());
  uint64_t b = stoi(s);
  return b;
}

int main(){
    int ans = descendingOrder(1264343);
    cout<<ans;
    return 0;
}