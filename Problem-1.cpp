#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    
    int n = s.length();
    string t = s + s;
    
    unordered_set<char> st;
    int left = 0, sum = 0, maxSum = 0;
    
    for (int right = 0; right < 2 * n; right++) {
       
        while (st.count(t[right])) {
            st.erase(t[left]);
            sum -= (t[left] - 'a' + 1);
            left++;
        }
        
        st.insert(t[right]);
        sum += (t[right] - 'a' + 1);
        
        // Keep window length ≤ n
        while (right - left + 1 > n) {
            st.erase(t[left]);
            sum -= (t[left] - 'a' + 1);
            left++;
        }
        
        maxSum = max(maxSum, sum);
    }
    
    cout << maxSum << endl;
}
