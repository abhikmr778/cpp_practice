#include <bits/stdc++.h>

using namespace std;

// ascii value of a char
int val(char c){
    if(c>='0' && c<='9')
        return (int)c - '0';
    else return (int)c - 'A' + 10;
}

int toDeci(string str, int base){
    int len = str.length();

    int power = 1;

    int res = 0;

    for(int i=len-1; i>=0; i--){
        if(val(str[i])>=base){
            cout<<"Invalid Number";
            return -1;
        }

        res += val(str[i])*power;
        power *= base;
    }

    return res;
}

char reVal(int num){
    if(num>=0 && num<=9)
        return (char)(num+'0');
    else
        return (char)(num-10+'A');
}

string fromDeci(int base, int inputNum){
    string res = "";

    while(inputNum > 0){    
        res += reVal(inputNum%base);
        inputNum/=base;
    }
    reverse(res.begin(), res.end());
    return res;
}

void convertBase(string s, int a, int b){
    // first convert base A to decimal
    int num = toDeci(s,a);

    // convert from decimal to base B
    string ans = fromDeci(b, num);

    cout<<ans;
}



int main(){

    string s = "10B";
    int a = 16;
    int b = 10;

    convertBase(s, a, b);
    return 0;
}