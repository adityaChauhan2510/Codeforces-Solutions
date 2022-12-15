/*

Let's call a positive integer extremely round if it has only one non-zero digit. For example, 5000, 4, 1, 10, 200 are extremely round integers; 42, 13, 666, 77, 101 are not.
You are given an integer n. You have to calculate the number of extremely round integers x such that 1≤x≤n.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases.
Then, t lines follow. The i-th of them contains one integer n (1≤n≤999999) — the description of the i-th test case.

Output
For each test case, print one integer — the number of extremely round integers x such that 1≤x≤n.

Example
inputCopy
5
9
42
13
100
111
outputCopy
9
13
10
19
19

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> v;   // global vector declaration

void calc(){

    for(int i=1; i<=100000; i *= 10){
        for(int j=1; j<=9; j++){
            v.push_back(i*j);
        }
    }
}

void solve(){
    int x; cin>>x;
    int ans = 0;
    for(int y : v){
        if( y <= x){
            ans++;
        }
        else{
            break;
        }
    }

    cout << ans <<endl;
    return;
}

int main(){
    int t; cin>>t;
    calc();
    while(t--){
        solve();
    }

    return 0;

}