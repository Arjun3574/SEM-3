import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm


population=np.random.uniform(0,1,10000)

sample_size=50
num_sample=1000
sample_means=[]

for _ in range(num_sample):
    sample=np.random.choice(population,size=sample_size,replace=True)
    sample_means.append(np.mean(sample))

plt.figure(figsize=(12,6))

plt.subplot(1,2,1)
plt.hist(population,bins=50,color="purple",edgecolor='black',density=True)
plt.title("Original Population(Uniform)")
plt.xlabel("Value")
plt.ylabel("Probablity Density")

plt.subplot(1,2,2)
plt.hist(sample_means,bins=50,color="Red",edgecolor='black',density=True)

mean=np.mean(sample_means)
std=np.std(sample_means)

x=np.linspace(min(sample_means),max(sample_means),1000)
pdf=norm.pdf(x,mean,std)
plt.plot(x,pdf,color='blue',linewidth=2)
plt.title("Distribution of Sample Means")
plt.xlabel("Sample Mean")
plt.ylabel("Probability Density")
lable="Normal Distribution(CLT Prediction)"
plt.legend()
plt.tight_layout()
plt.show()



