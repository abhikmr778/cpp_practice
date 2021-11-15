/***
 F. Number of Subsequences
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s consisting of lowercase Latin letters "a", "b" and "c" and question marks "?".

Let the number of question marks in the string s be k. Let's replace each question mark with one of the letters "a", "b" and "c". Here we can obtain all 3k possible strings consisting only of letters "a", "b" and "c". For example, if s="ac?b?c" then we can obtain the following strings: ["acabac", "acabbc", "acabcc", "acbbac", "acbbbc", "acbbcc", "accbac", "accbbc", "accbcc"].

Your task is to count the total number of subsequences "abc" in all resulting strings. Since the answer can be very large, print it modulo 109+7.

A subsequence of the string t is such a sequence that can be derived from the string t after removing some (possibly, zero) number of letters without changing the order of remaining letters. For example, the string "baacbc" contains two subsequences "abc" — a subsequence consisting of letters at positions (2,5,6) and a subsequence consisting of letters at positions (3,5,6).

Input
The first line of the input contains one integer n (3≤n≤200000) — the length of s.

The second line of the input contains the string s of length n consisting of lowercase Latin letters "a", "b" and "c" and question marks"?".

Output
Print the total number of subsequences "abc" in all strings you can obtain if you replace all question marks with letters "a", "b" and "c", modulo 109+7.
 
 
 
 ***/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = int(1e9) + 7;

ll power(ll a, ll b){
    ll result = 1;
    while(b>0){
        if(b&1){
            result *= a;
            result %= MOD;
        }
        a *=a;
        a %= MOD;
        b/=2;

    }
    return result;
}
int solve(int n, string s){
    ll la = 0, ra=0, lc=0, rc=0, lq=0, rq=0;

    for(char c: s){
        if(c=='a') ra++;
        if(c=='c') rc++;
        if(c=='?') rq++;
    }
    ll ans = 0;

    for(int i=0; i<n; i++){
        ra -= s[i]=='a';
        rc -= s[i]=='c';
        rq -= s[i]=='?';

        if(s[i]=='b' || s[i]=='?'){
            // case (a,c)
            ans += (la*rc)%MOD * power(3,lq+rq)%MOD;

            // (?,c)
            if(lq) ans+= (lq*rc)%MOD * power(3, lq+rq-1)%MOD;
            //(a,?)
            if(rq) ans += (rq*la)%MOD * power(3, lq+rq-1)%MOD;
            //(?,?)
            if(rq&&lq) ans+= (rq*lq)%MOD * power(3, lq+rq-2)%MOD;
        }
        ans %= MOD;
        la+= s[i] =='a';
        lc += s[i] == 'c';
        lq += s[i]=='?';
    }
    return ans;
}

int main(){

    int n = 6;
    string s = "ac?b?c";

    cout<<solve(n,s);

    return 0;
}