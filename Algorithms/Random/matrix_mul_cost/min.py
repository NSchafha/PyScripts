def min_mul(dimensions):
    n = len(dimensions) - 1  # Number of matrices is len(dimensions) - 1

    # dp[i][j] stores the minimum cost of multiplying matrices from i to j
    dp = [[0] * n for _ in range(n)]

    # l is the chain length
    for length in range(2, n + 1):  # start from length 2 to n
        for i in range(n - length + 1):  # i is the starting matrix index
            j = i + length - 1  # j is the ending matrix index
            dp[i][j] = float('inf')
            for k in range(i, j):  # k is the split index
                # Calculate cost of splitting at k
                q = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1]
                if q < dp[i][j]:
                    dp[i][j] = q

    return dp[0][n - 1]  # The minimum cost to multiply matrices from 0 to n-1

# Example usage:
dimensions = [10, 5, 2, 100, 20]  # Example input: 4 matrices
min_cost = min_mul(dimensions)
print(f"Minimum cost of matrix chain multiplication: {min_cost}")
