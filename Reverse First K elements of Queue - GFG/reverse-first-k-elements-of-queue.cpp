//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    
    //step1 - pop first k elements from queue and push into stack
    for(int i=0;i<k;i++){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    
    //step2 - push k elements from stack into queue
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    
    //step3 - fetch first n-k from queue and push back to queue 
    int t=q.size()-k;
    
    while(t--){
        int element=q.front();
        q.pop();
        q.push(element);
    }
    return q;
}