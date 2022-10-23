#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long mm(long long a,long long b){
        long long m=1e9 +7;
        return ((a%m)*(b%m))%m;
    }
    vector<long long> factorial(vector<long long> a, int n) {
        vector<long long>tmp;
        vector<long long> ans(n,0);
        map<long long, int>mp;
        for(int i=0;i<n;i++){
            mp.insert(make_pair(a[i],i));
        }
        long long curr=1;
        long long j=1;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            for(;j<=a[i];j++){
                curr=mm(curr,j);
            }
            tmp.push_back(curr);
        }
        int i=0;
        for(auto it:mp){
            ans[it.second]=tmp[i++];
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
