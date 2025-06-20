#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string s)
{
    string ans = "";

    vector<int> count(26, 0);
    
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        
        // if non-repeating element found push it in queue
        if (count[s[i] - 'a'] == 0) {
            q.push(s[i]);
        }
        count[s[i] - 'a']++;

        // if front element is repeating pop it from the queue
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        // if queue is not empty append front element else append "#" in ans string.
        if (!q.empty()) {
            ans += q.front();
        }
        else {
            ans += '#';
        }
    }

    return ans;
}

int main()
{
    string s = "aabc";
    string ans = firstNonRepeating(s);
    cout << ans << "\n";  
    return 0;
}

// O(n) time and O(n) space
