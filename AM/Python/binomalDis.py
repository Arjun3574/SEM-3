import matplotlib.pyplot as plt
def fac(n):
    if n==1 or n==0:
        return 1
    else:
        return n*fac(n-1)
    
def bio(n,p):
    pro = []
    q=1-p
    for r in range(0,n+1):
        b= (fac(n)/(fac(r)*fac(n-r)))*(p**r)*(q**(n-r))
        pro.append(b)

    return pro

n=int(input("Enter the value of n: "))
p=float(input("Enter the value of p: "))
ans=bio(n,p)
print("The answer is:",ans)

plt.bar(range(0, n+1), ans, color='blue')
plt.xlabel('Number of Successes')
plt.ylabel('Probability')
plt.title('Binomial Distribution')
plt.show()
