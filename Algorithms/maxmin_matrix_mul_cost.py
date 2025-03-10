def matrix_chain_order(dimensions):
    n = len(dimensions) - 1
    dp_min = [[0 for _ in range(n)] for _ in range(n)]
    dp_max = [[0 for _ in range(n)] for _ in range(n)]
    
    # Fill the dp tables for minimum and maximum costs
    for length in range(2, n+1):  # length of the chain
        for i in range(n-length+1):
            j = i + length - 1
            dp_min[i][j] = float('inf')
            dp_max[i][j] = -float('inf')
            
            for k in range(i, j):
                q_min = dp_min[i][k] + dp_min[k+1][j] + dimensions[i]*dimensions[k+1]*dimensions[j+1]
                q_max = dp_max[i][k] + dp_max[k+1][j] + dimensions[i]*dimensions[k+1]*dimensions[j+1]
                
                dp_min[i][j] = min(dp_min[i][j], q_min)
                dp_max[i][j] = max(dp_max[i][j], q_max)
    
    return dp_min[0][n-1], dp_max[0][n-1]


# Example usage
dimensions = [10, 5, 2, 100, 20]  # Given dimensions
min_cost, max_cost = matrix_chain_order(dimensions)

print(f"Minimum cost = {min_cost}")
print(f"Maximum cost = {max_cost}")
