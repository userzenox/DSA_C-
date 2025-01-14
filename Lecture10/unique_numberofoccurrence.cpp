
// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         vector<int> ans;

//         int size = arr.size();
//         sort(arr.begin(), arr.end());
//         int n = 0;
//         while (n < size) {
//             int count = 1;
//             for (int i = 1 + n; i < size; i++) {
//                 if (arr[i] == arr[n]) {
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//             ans.push_back(count);
//             n = n + count;
//         }

//         size = ans.size();
//         sort(ans.begin(), ans.end());

//         for (int i = 0; i < size - 1; i++) {
//             if (ans[i] == ans[i + 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

