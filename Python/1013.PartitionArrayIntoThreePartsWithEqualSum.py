class Solution(object):
    def canThreePartsEqualSum(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        total = sum(arr)
        if total % 3 != 0:
            return False

        target = total // 3
        parts = 0
        running = 0

        for x in arr:
            running += x
            if running == target:
                parts += 1
                running = 0

        return parts >= 3


def main():
    s = Solution()

    # Example test cases
    arr1 = [0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]   # True
    arr2 = [0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1]   # False
    arr3 = [3, 3, 6, 5, -2, 2, 5, 1, -9, 4]      # True

    print(s.canThreePartsEqualSum(arr1))
    print(s.canThreePartsEqualSum(arr2))
    print(s.canThreePartsEqualSum(arr3))


if __name__ == "__main__":
    main()
