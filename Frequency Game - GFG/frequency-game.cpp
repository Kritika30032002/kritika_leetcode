//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int maxNum=INT_MIN;
        int minfreq=INT_MAX;
        
        for(auto itr: mp){
            if(itr.first>=maxNum && itr.second<=minfreq){
                maxNum=itr.first;
                minfreq=itr.second;
            }
        }
        
        return maxNum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends