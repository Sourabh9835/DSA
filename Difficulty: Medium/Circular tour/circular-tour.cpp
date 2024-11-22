//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        
        int balance = 0;
        int deficiency = 0;
        int start = 0;
        
        for(int i=0; i<a2.size();i++){
            balance += a1[i] - a2[i];
            if(balance < 0){
                deficiency += balance;
                start = i+1;
                balance = 0;
            }
        }
        
        if(deficiency + balance >= 0)
        return start;
        else
        return -1;
    }
};


//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        // vector<int> v;
        int ans = ob.circularTour(arr1, arr2);

        cout << ans << endl;

        cout << "~" << endl;
        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends