//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        
        //for first window of k size
        for(int i=0; i<k; i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        
        //stores answer for first k size window
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }else{
            ans.push_back(0);
        }
        
        //process for remaining window
        for(int i=k;i<arr.size();i++){
            if(!dq.empty() && dq.front() <= i - k){
                //removal
                dq.pop_front();
            }
            
            //addition
            if(arr[i]<0){
                dq.push_back(i);
            }
            
            //ans store
            if(dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends