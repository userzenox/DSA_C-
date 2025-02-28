#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
   int sumOfDigit(int n) {
       int sum = 0;
       while (n != 0) {
           sum += n % 10;
           n /= 10;
       }
       return sum;
   }

   string digitSum(string s, int k) {
       while (s.size() > k) {
           string newStr = "";
           for (int i = 0; i < s.size(); i += k) {
               int sum = 0;
               for (int j = i; j < i + k && j < s.size(); ++j) {
                   sum += s[j] - '0';  // Convert character to integer and add
               }
               newStr += to_string(sum);  // Append the sum directly
           }
           s = newStr;
       }
       return s;
   }
};

int main() {
   Solution solution;
   string s = "123456789";
   int k = 3;

   string result = solution.digitSum(s, k);
   cout << "The digit sum of \"" << s << "\" with k = " << k << " is: " << result << endl;

   return 0;
}
