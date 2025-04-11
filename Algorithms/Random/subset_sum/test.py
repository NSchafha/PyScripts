def countSubsets(i, currentSum, target, arr, memo):
    n = len(arr)

    # Base case: If we've processed all elements
    if i == n:
        return 1 if currentSum == target else 0

    # Check if result is already computed
    if memo[i][currentSum] != -1:
        return memo[i][currentSum]

    # Case 1: Exclude the current element
    exclude = countSubsets(i + 1, currentSum, target, arr, memo)

    # Case 2: Include the current element
    include = 0
    if currentSum + arr[i] <= target:
        include = countSubsets(i + 1, currentSum + arr[i], target, arr, memo)

    # Store result in memoization table and return it
    memo[i][currentSum] = include + exclude
    return memo[i][currentSum]


def perfectSum(arr, target):
    n = len(arr)
    
    # Initialize a 2D memoization table with -1
    # We use (target + 1) because we are going to use sums from 0 to target
    # Also, the current sum is shifted to avoid negative indexing
    memo = [[-1 for _ in range(target + 1)] for _ in range(n + 1)]

    return countSubsets(0, 0, target, arr, memo)


if __name__ == "__main__":
    arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33]
    target1 = 540
    print(perfectSum(arr1, target1))  # Example 1

    arr2 = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40]
    target2 = 390
    print(perfectSum(arr2, target2))  # Example 2

    arr3 = [1, 2, 4, 5, 7, 8, 11, 13, 14, 15, 21, 55, 99, 111, 128, 200, 210, 230, 300, 333]
    target3 = 444
    print(perfectSum(arr3, target3))  # Example 3
