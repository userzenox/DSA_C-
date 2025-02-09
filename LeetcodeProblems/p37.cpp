// class Solution {
//     public:
//         int searchInsert(vector<int>& nums, int target) {
//             int n = nums.size();
//             int s = 0, e = n - 1;
//             int mid;
    
//             while (s <= e) {
//                 mid = s + ((e - s) / 2);
//                 if (target == nums[mid]) {
//                     return mid;
//                 }
//                 if (target > nums[mid]) {
//                     s = mid + 1;
//                 } else {
//                     e = mid - 1;
//                 }
//             }
//             return s; 
//         }
//     };