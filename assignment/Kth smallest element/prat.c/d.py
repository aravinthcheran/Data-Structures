import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a pandas DataFrame
df = pd.read_csv('C:\\C\\assignment\\Kth smallest element\\prat.c\\tree_runtimes.csv')

# Extract data for plotting
tree_sizes = df['Tree_Size']
runtimes = df['Runtime']

# Create the line graph
plt.figure(figsize=(10, 6))
plt.plot(tree_sizes, runtimes, marker='o', linestyle='-', color='b')

# Set graph title and labels
plt.title('Runtime vs Tree Size')
plt.xlabel('Tree Size')
plt.ylabel('Runtime (seconds)')

# Show grid
plt.grid(True)

# Show the plot
plt.show()
