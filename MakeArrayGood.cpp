#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<pair<ll,ll>> a, ans;
        for(int i=1; i<=n; i++){
            ll x ; cin>>x;
            a.push_back({x,i});
        }

        sort(a.begin(), a.end());

        for(int j = 1; j<n; j++){
            if(a[j].first % a[j-1].first != 0){
                int p = ((a[j].first/a[j-1].first) + 1)*a[j-1].first - a[j].first;
                ans.push_back({a[j].second, p});
                a[j].first += p;
            }
        }


        cout << ans.size()<<'\n';
        for(int j=0; j<ans.size(); j++){
            cout << ans[j].first<< " "<<ans[j].second<<'\n';
        }



    }
}