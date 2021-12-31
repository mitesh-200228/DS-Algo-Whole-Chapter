#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isMajority(int a[], int n, int cand) 
{ 
    int count = 0; 
    for (int i = 0; i<n; i++) 
  
        if (a[i] == cand) 
            count++; 
  
    if (count > n/2) 
        return 1; 
    
    else
        return 0; 
} 

int majorityElement(int a[], int n)
{
    int ans=0,cnt=0;
    for(int i=0;i<n;++i)
    {
        if(cnt==0)
           ans=a[i];
        if(ans==a[i])
           cnt++;
        else
          cnt--;
    }
    
    if(isMajority(a,n,ans))
       return ans;
    return -1; 
    
}


int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends