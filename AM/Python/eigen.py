
from numpy import matrix

def matrix_multiply(A, B):
    result=[]
    for i in range(len(A)):
        row=[]
        for j in range(len(B[0])):
            sum=0
            for k in range(len(B)):
                sum+=A[i][k]*B[k][j]
            row.append(sum)
        result.append(row)
    return result

def invert_matrix(matrix):
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    if det == 0:
        raise ValueError("Matrix is singular")
    return [[matrix[1][1] / det, -matrix[0][1] / det],
            [-matrix[1][0] / det, matrix[0][0] / det]]

def compute_eigen_2x2(matrix):
    a=matrix[0][0]
    b=matrix[0][1]
    c=matrix[1][0]
    d=matrix[1][1]
    discriminant = (a+d)**2-4*(a*d-b*c)
    if discriminant<0:
        print("Complex eigenvalue , not supported here.")
        return None,None

    lambda1 = ((a + d) + ((a + d) ** 2 - 4 * (a * d - b * c))**0.5) / 2
    lambda2 = ((a + d) - ((a + d) ** 2 - 4 * (a * d - b * c))**0.5) / 2
    def find_vector(lam):
        return [-b,a-lam] if a-lam !=0 else 1

    eigenvector1=find_vector(lambda1)
    eigenvector2=find_vector(lambda2)
    return [lambda1,lambda2],[eigenvector1,eigenvector2]

A=[[8,-4],
  [2,2]]


eigenvalues,eigenvectors=compute_eigen_2x2(A)
print("Eigenvalues: ",eigenvalues)
print("Eigenvectors:",eigenvectors)
P=[[eigenvectors[0][0],eigenvectors[1][0]],
   [eigenvectors[0][1],eigenvectors[1][1]]]

print("Matrix P:",P)



inv_p =invert_matrix(P)
print("Inverse of P:", inv_p)

D=matrix_multiply(inv_p,matrix_multiply(A,P))
print("Diagonal Matrix D:",D)