#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int empCount, int k, int odd, int even, int A, int B) {
    long long required = 1LL * empCount * k;
    long long avail = min(1LL * A * odd, 1LL * empCount * odd) + min(1LL * B * even, 1LL * empCount * even);
    return avail >= required;
}

int main() {
    int T,N,A,B,K;
    cin>>T>>N>>A>>B>>K;

    int o = (N+1)/2;
    int e = N/2;

    int low = 0;
    int high = T;
    int res = 0;

    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(mid,K,o,e,A,B)){
            res = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout<<res<<endl;
    return 0;
}
