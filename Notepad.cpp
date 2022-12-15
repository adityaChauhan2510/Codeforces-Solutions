/*

You want to type the string s, consisting of n lowercase Latin letters, using your favorite text editor Notepad#.

Notepad# supports two kinds of operations:

1)append any letter to the end of the string;
2)copy a continuous substring of an already typed string and paste this substring to the end of the string.
Can you type string s in strictly less than n operations?

Input
The first line contains a single integer t (1≤t≤10^4) — the number of testcases.
The first line of each testcase contains a single integer n (1≤n≤2⋅105) — the length of the string s.

The second line contains a string s, consisting of n lowercase Latin letters.
The sum of n doesn't exceed 2⋅10^5 over all testcases.

Output
For each testcase, print "YES" if you can type string s in strictly less than n operations. Otherwise, print "NO".

Example

input
6
10
codeforces
8
labacaba
5
uohhh
16
isthissuffixtree
1
x
4
momo


output
NO
YES
NO
YES
NO
YES

*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ll t;cin>>t;
    while(t--){
        ll n; cin>>n;
        string s; cin>>s;
        unordered_map <string,ll> mp;
        bool flag = true;

        for(ll i=0; i<n-1; i++){
            string temp = "";
            temp+=s[i]; 
            temp+=s[i+1];

            if(mp.find(temp) == mp.end()){
                mp[temp] = i;
            }
            else{
                if(mp[temp] != i-1){
                    cout<<"YES"<<"\n";
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            cout<<"NO"<<"\n";
    }
}