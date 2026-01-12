import numpy as np
def Gauss_Elimination(A):
    n=A.shape[0]
    for i in range(n):
        max_row=i
        for k in range(i+1,n):
            if abs(A[k,i])>abs(A[max_row,i]):
                max_row=k
        A[[i,max_row]]=A[[max_row,i]]
        if A[i,i]==0:
            print("Divide by zero detected or singular matrix.No unique solution exists.")
            return None
        for k in range(i+1,n):
            factor =A[k,i]/A[i,i]
            A[k,i:]=A[k,i:]-factor*A[i,i:]
    x=np.zeros(n)
    for i in range(n-1,-1,-1):
        if A[i,i]==0:
            print("Singular matrix detected during back substitution . No unique solution exists.")
            return None
        x[i]=A[i,n]/A[i,i]       
        for k in range(i-1,-1,-1):
            A[k,n]=A[k,n]-A[k,i]*x[i]
    return x

argumented_matrix=np.array([
    [-3.0,2.0,5.0,2.0,3.0],
    [2.0,3.0,6.0,5.0,2.0],
    [14.0,4.0,5.0,14.0,11.0],
    [4.0,5.0,10.0,8.0,4.0]
])

print("Original Augmented Matrix: ")
print(argumented_matrix)


solution=Gauss_Elimination(argumented_matrix)
if solution is not None:
    print("\nSolution:")
    print(solution)