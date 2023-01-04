/*
Thalia is a Legendary Grandmaster in chess. She has n trophies in a line numbered from 1 to n (from left to right) and a lamp standing next to each of them (the lamps are numbered as the trophies).
A lamp can be directed either to the left or to the right, and it illuminates all trophies in that direction (but not the one it is next to). 
More formally, Thalia has a string s consisting only of characters 'L' and 'R' which represents the lamps' current directions. 

The lamp i illuminates:

trophies 1,2,…,i−1 if si is 'L';
trophies i+1,i+2,…,n if si is 'R'.
She can perform the following operation at most once:

Choose an index i (1≤i<n);
Swap the lamps i and i+1 (without changing their directions). That is, swap si with si+1.
Thalia asked you to illuminate all her trophies (make each trophy illuminated by at least one lamp), or to tell her that it is impossible to do so. 
If it is possible, you can choose to perform an operation or to do nothing. Notice that lamps cannot change direction, it is only allowed to swap adjacent ones.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10000). The description of the test cases follows.
The first line of each test case contains a positive integer n (2≤n≤100000)  — the number of trophies.
The second line of each test case contains a string s of length n consisting only of characters 'L' and 'R'  — the i-th character describes the direction of the i-th lamp.
It is guaranteed that the sum of n over all test cases does not exceed 100000.

Output
For each test case print −1 if it is impossible to illuminate all trophies by performing one operation (or doing nothing). 
Otherwise, print 0 if you choose not to perform the operation (i.e., the trophies are illuminated by the initial positioning of the lamps), 
or an index i (1≤i<n) if you choose to swap lamps i and i+1.
If there are multiple answers, print any.

Example
input
6
2
LL
2
LR
2
RL
2
RR
7
LLRLLLR
7
RRLRRRL


output
-1
1
0
-1
3
6
Note
In the first example, it is possible to swap lamps 1 and 2, or do nothing. In any case, the string "LL" is obtained. Not all trophies are illuminated since trophy 2 is not illuminated by any lamp  — lamp 1 illuminates nothing and lamp 2 illuminates only the trophy 1.
In the second example, it is necessary to swap lamps 1 and 2. The string becomes "RL". Trophy 1 is illuminated by lamp 2 and trophy 2 is illuminated by lamp 1, hence it is possible to illuminate all trophies.
In the third example, all trophies are initially illuminated  — hence, not performing any operation is a valid solution.
In the last two examples performing swaps is not necessary as all trophies are illuminated initially. But, the presented solutions are also valid.

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin>>t;
    while(t--){
        ll n ; cin>>n;
        string s ; cin>>s;

        ll a = -1; ll b= -1;
        for(ll i=0; i<s.size(); i++){
            if(s[i] == 'R'){
                a = i;
                break;
            }
        }
        if(a == -1){
            cout << -1 <<endl;
        }
        else{
            for(ll y = a+1; y<s.size(); y++){
                if(s[y] == 'L'){
                    b = y;
                    break;
                }
            }

            if(b == -1){
                if(a == 0 ){
                    cout << -1 <<endl;
                }
                else if(s[a-1] == 'L'){
                     cout << a <<endl;
                }
            }   
            else {
                cout << 0 <<endl;
            }
        }
        
    }
}