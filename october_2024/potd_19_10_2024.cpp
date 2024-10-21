#include<bits/stdc++.h>
using namespace std;

   void solve( string &s,int n){
    
     while(n--){
        s += "1";
        for(int i = s.size()-2;i>=0;i--){
            int id = s[i]-'0';
            id = 1-id;
            s.append(1,id+'0');
        }
    }
   }

    char findKthBit(int n, int k) {
       string s = "0";
        solve(s,n);
        return s[k-1];
    }
    int main(){
        int n,k;
        cin>>n>>k;
        char x = findKthBit(n,k);
        cout<<x<<endl;
        return 0;
    }
