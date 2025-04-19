#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);  // Sentinel value for no smaller element
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (st.top() >= arr[i]) {
            st.pop();
        }

        result[i] = st.top();  // Next smaller element
        st.push(arr[i]);

        // Debug: print stack contents
        stack<int> temp = st;
        vector<int> stack_elements;
        while (!temp.empty()) {
            stack_elements.push_back(temp.top());
            temp.pop();
        }

        cout << "Stack after processing arr[" << i << "] = " << arr[i] << ": ";
        for (int j = stack_elements.size() - 1; j >= 0; j--) {
            cout << stack_elements[j] << " ";
        }
        cout << endl;
    }

    return result;
}

int main() {
    vector<int> input = {4, 8, 5, 2, 25};
    int n = input.size();

    vector<int> output = nextSmallerElement(input, n);

    cout << "\nNext Smaller Elements: ";
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
