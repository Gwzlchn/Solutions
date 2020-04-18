#include<bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i == 0) return false;
    }
    return true;
}


int main(){

    int len,k;
    string s;
    cin>>len>>k>>s;
    for(int i=0;i<=len-k;i++){
        string cur_str = s.substr(i,k);
        int num = stoi(cur_str);
        if(isPrime(num)){
            cout<<cur_str;
            return 0;
        }
    }   
    cout<<"404\n";
    return 0;
}