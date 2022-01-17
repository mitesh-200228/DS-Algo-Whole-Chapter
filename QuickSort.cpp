#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include <stdio.h>
#include<numeric>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<climits>
#include<cmath>
#include<math.h>
#include<limits>
#define ll long long int
const ll N = 1e5+ 2,MOD = 1e9+7;
using namespace std;
 
ll partition(ll arr[],ll s,ll e){
    ll pivot = arr[0];
    ll cnt = 0;
    for(ll i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    ll pivotIndex = s + cnt;
    std::swap(arr[pivotIndex],arr[s]);
    ll i = s,j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<arr[pivotIndex]){
            i++;
        }
        while(arr[j]>arr[pivotIndex]){
            j--;
        }
        if(arr[i]>arr[pivotIndex]){
            std::swap(arr[i++],arr[j--]);   
        }
    }
    return pivotIndex;
}

void quicksort(ll arr[],ll s,ll e){
    if(s>=e){
        return;
    }
    ll p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n = 5;
    ll arr[] = {2,4,1,6,9};
    quicksort(arr,0,n-1);
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";   
    }cout<<endl;
    return 0;
}