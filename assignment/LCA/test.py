import pandas as pd
import matplotlib.pyplot as plt

# Load data from the CSV file
data = pd.read_csv('C:\\C\\assignment\\LCA\\average_runtimes.csv')

# Extracting test case numbers and average runtimes
test_cases = data['Test Case']
average_runtimes = data['Average Runtime']

# Plotting the graph
plt.figure(figsize=(10, 6))
plt.plot(test_cases, average_runtimes, marker='o', linestyle='-', color='b')
plt.title('Average Runtimes for Determination of Common Ancestor')
plt.xlabel('Test Case')
plt.ylabel('Average Runtime (seconds)')
plt.grid(True)
plt.tight_layout()

# Display the plot
plt.show()
