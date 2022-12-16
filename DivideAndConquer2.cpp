#include<bits/stdc++.h>
using namespace std;
#define ll long long

int count(int arr[], int n){
    
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i] % 4 == 1 || arr[i] % 4 == 2){
            ans++;
            break;
        }
        else{
            arr[i]= arr[i]/2;
        }
    }
    if(ans == 1){
        return ans;
    }
    else{
        ans = count(arr, n);
        return 1 + ans;
    }
    
}

int main(){
    ll t; cin>>t;

    while(t--){
        ll n; cin>>n;

        int arr[n];
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }

        if(sum % 2 ==0){
            cout << 0 <<endl;
        }
        else{
            cout << count(arr, n)<<'\n';
        }


    }

}