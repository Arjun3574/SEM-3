def inputmat(r, c):
    mat = []
    for i in range(r):
        row = []
        for j in range(c):
            d = int(input(""))
            row.append(d)
        mat.append(row)
    return mat

def printmat(m):
    for i in range(len(m)):
        for j in range(len(m[0])):
            print(m[i][j], end=" ")
        print()

def addmat(m1, m2):
    res = []
    for i in range(len(m1)):
        row = []
        for j in range(len(m1[0])):
            d = m1[i][j] + m2[i][j]
            row.append(d)
        res.append(row)
    return res


A = []
B = []

r = int(input("No of rows: "))
c = int(input("No of columns: "))

print("Enter Matrix A:")
A = inputmat(r, c)

print("Enter Matrix B:")
B = inputmat(r, c)

print("Matrix 1:")
printmat(A)

print("Matrix 2:")
printmat(B)

C = addmat(A, B)

print("Addition")
printmat(C)