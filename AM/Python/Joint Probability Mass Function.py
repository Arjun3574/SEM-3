import numpy as np
import matplotlib.pyplot as plt

coin_outcomes = ["H", "T"]

# Create a 2x2 matrix for the joint PMF
joint_pmf = np.zeros((2, 2))

# Each outcome (H,H), (H,T), (T,H), (T,T) has equal probability = 1/4
for i in range(2):
    for j in range(2):
        joint_pmf[i, j] = 1 / 4

# Plotting the PMF
plt.figure(figsize=(5, 4))
plt.imshow(joint_pmf, cmap="Oranges", interpolation="nearest")

# Display probability values inside the boxes
for i in range(2):
    for j in range(2):
        plt.text(j, i, round(joint_pmf[i, j], 2), ha='center', va='center')


plt.title("Joint Probability Mass Function (2 Coins)")
plt.xlabel("Coin 1")
plt.ylabel("Coin 2")
plt.xticks(np.arange(2), coin_outcomes)
plt.yticks(np.arange(2), coin_outcomes)
plt.colorbar(label="Probability")
plt.show()
