#include <iostream>
#include <string>

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        int n = s.size();
        int n2 = part.size();
        
        for (int i = 0; i < n; i++) {
            int k = 0;  // Initialize k to compare part
            while ((k < n2) && (s[i + k] == part[k])) {
                k++;
            }
            if (k == n2) {  // Full match found
                s.erase(i, n2);
                n = s.size();  // Update the size of s
                i = -1;  // Restart the loop from the beginning
            }
        }
        return s;  // Return the modified string
    }
};

int main() {
    Solution sol;
    std::string s = "daabcbaabcbc";
    std::string part = "abc";
    
    std::string result = sol.removeOccurrences(s, part);
    std::cout << "Resulting string: " << result << std::endl;
    
    return 0;
}
