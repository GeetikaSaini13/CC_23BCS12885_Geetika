#include<bits/stdc++.h>
using namespace std;

const int base = 10;

int hashfun(string str){
    int result = 0;
    for(int i = 0;i<str.size(); i++){
        result = result * base + (str[i] - 'a' + 1);
    }
    return result;
}

int main(){
    string txt = "abcabcbad";
    string patt = "abc";

    int n = txt.size();
    int m = patt.size();

    int pattHash = hashfun(patt);
    int txtHash = hashfun(txt.substr(0, m)); 

    int power = 1;
    for(int i = 0; i < m-1; i++)
        power *= base;

    for(int i = 0; i <= n - m; i++){

        if(txtHash == pattHash){
            cout << "String found at index " << i << endl;
        }

        if(i < n - m){
            txtHash = txtHash - (txt[i] - 'a' + 1) * power;
            txtHash = txtHash * base;
            txtHash = txtHash + (txt[i + m] - 'a' + 1);
        }
    }

    return 0;
}