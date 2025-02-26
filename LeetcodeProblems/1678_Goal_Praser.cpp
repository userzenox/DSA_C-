#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        
        string result;
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(' && command[i + 1] == ')') {
                result += 'o';
                i++; 
            } else if (command[i] == '(' && command[i + 1] == 'a') {
                result += "al";
                i += 3;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string command = "G()(al)";
    string result = solution.interpret(command);
    cout << "Output: " << result << endl;
    return 0;
}
