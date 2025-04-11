def listlist_to_matrix(adj_list):
    size = len(adj_list)
    matrix = [[0] * size for _ in range(size)]
    for src, neighbors in enumerate(adj_list):
        for dest in neighbors:
            matrix[src][dest] = 1
    return matrix

def dictlist_to_matrix(adj_list):
    size = max(adj_list.keys()) + 1
    matrix = [[0] * size for _ in range(size)]
    for src, neighbors in adj_list.items():
        for dest in neighbors:
            matrix[src][dest] = 1
    return matrix

adj_list_list = [[1, 2], [2], [0]]          # list[list]
adj_list_dict = {0: [1, 2], 1: [2], 2: [0]}  # dict[list]