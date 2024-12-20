//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        unordered_map<char,int> count;
        queue<int> q;
        string ans = "";
        
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            
            //increase the count of character.
            count[ch]++;
            
            //push the character to queue.
            q.push(ch);
            
            while(!q.empty()){
                if(count[q.front()] > 1){
                    //repeating character
                    q.pop();
                }else{
                    //non-repeating
                    ans.push_back(q.front());
                    break;
                }
            }
            
            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends