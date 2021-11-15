#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main ()
{
  char str[] = "almost every programmer should know memset!";
  memset (str,1,6);
  puts (str);
  cout<<int('1');
  return 0;
}