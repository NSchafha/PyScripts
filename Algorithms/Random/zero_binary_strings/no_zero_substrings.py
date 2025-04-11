def Z(n, z):
    if n == 4 and z == 3:
        print("n == 4 and z == 3")
    if z > n:
        return 2**n
    else:
        total = 0
        for i in range(1,z+1):
            total += Z(n - i, z)
        return total

print(Z(7, 3)) 