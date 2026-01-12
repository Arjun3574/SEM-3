import random
import math
import matplotlib.pyplot as plt

def normal_random():
    return sum(random.random() for _ in range(12)) - 6  

def t_random(df):
    z = normal_random()
    v = sum(normal_random()**2 for _ in range(df))  
    return z / math.sqrt(v / df)

def f_random(d1, d2):
    u = sum(normal_random()**2 for _ in range(d1)) / d1
    v = sum(normal_random()**2 for _ in range(d2)) / d2
    return u / v

def generate_samples(func, n, *args):
    return [func(*args) for _ in range(n)]

t_samples = generate_samples(t_random, 5000, 10)    

f_samples = generate_samples(f_random, 5000, 5, 10) 

plt.figure(figsize=(12,5))
# t-distribution
plt.subplot(1,2,1)
plt.hist(t_samples, bins=50, density=True, color="skyblue", edgecolor="black")
plt.title("t-distribution (df=10)")
# F-distribution
plt.subplot(1,2,2)
plt.hist(f_samples, bins=50, density=True, color="salmon", edgecolor="black")
plt.title("F-distribution (d1=5, d2=10)")
plt.show()