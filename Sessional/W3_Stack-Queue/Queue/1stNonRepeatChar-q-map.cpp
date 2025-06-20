#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string s)
{
    string ans = "";
    
    unordered_map<char, int> mp;
    queue<char> q;
    
    // queue to keep non-repeating element at the front.
    for (int i = 0; i < s.length(); i++)
    {
        // if non-repeating element found push it in queue and count in map
        if (mp.find(s[i]) == mp.end())
        {
            q.push(s[i]);
        }
        mp[s[i]]++;
        
        // if anytime front element is repeating pop it from queue
        while (!q.empty() && mp[q.front()] > 1)
        {
            q.pop();
        }
        
        // if queue is not empty append front element else append "#" in ans string.
        if (!q.empty())
        {
            ans += q.front();
        }
        else
        {
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
