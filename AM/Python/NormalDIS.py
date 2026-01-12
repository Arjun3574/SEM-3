import math
import numpy as np
import matplotlib.pyplot as plt

def normal_pdf(x, mu, sigma):
  coeff = 1/ (sigma * ( (2*(22/7))**0.5))
  exponent = -((x-mu) ** 2) / (2 * sigma ** 2)
  return coeff * math.exp(exponent)

mu = 0
sigma = 1
# Generate x values
x_values = np.linspace(-4,4,100)
pdf_values = [normal_pdf(x, mu, sigma) for x in x_values]

# Plotting
plt.plot(x_values, pdf_values)
plt.title('Normal Distribution PDF (without built-in functions)')
plt.xlabel('x')
plt.ylabel('Probability Density')
plt.grid(True)
plt.show()