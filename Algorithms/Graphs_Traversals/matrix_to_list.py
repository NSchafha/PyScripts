def matrix_to_listlist(matrix):
    return [[j for j, val in enumerate(row) if val] for row in matrix]

def matrix_to_dictlist(matrix):
    adj_list = {}
    for i, row in enumerate(matrix):
        adj_list[i] = [j for j, val in enumerate(row) if val]
    return adj_list
