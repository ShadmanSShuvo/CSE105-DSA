#include <iostream>
#include <vector>
using namespace std;

string firstNonRepeating(string &s) {
    int n = s.size();
    
    // Frequency array
    vector<int> f(26, 0);    
    
     // Last occurrence array
    vector<int> last(26, -1); 

    // Update last occurrence of each character
    for (int i = 0; i < n; i++) {
        if (last[s[i] - 'a'] == -1)
            last[s[i] - 'a'] = i;
    }

    string ans = "";

    // Find the first non-repeating character
    for (int i = 0; i < n; i++) {
        f[s[i] - 'a']++;

        char ch = '#';
        int x = n + 1;

        // Find the first non-repeating character 
        // based on frequency and last occurrence
        for (int j = 0; j < 26; j++) {
            if (f[j] == 1 && x > last[j]) {
                ch = char(j + 'a');
                x = last[j];
            }
        }

        ans += ch;
    }

    return ans;
}

int main() {
    string s = "aabc";
    string ans = firstNonRepeating(s);
    cout << ans << endl;  
    return 0;
}

// O(n) time and O(1) space