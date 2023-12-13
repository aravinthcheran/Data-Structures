import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a pandas DataFrame
data = pd.read_csv('C:\\C\\assignment\\GST\\bst_runtimes.csv')

# Extracting size and runtime columns
sizes = data['Size']
runtimes = data['Runtime']

# Plotting the line graph
plt.figure(figsize=(10, 6))
plt.plot(sizes, runtimes, marker='o', linestyle='-', color='b')

# Title and labels
plt.title('BST Size vs Runtime')
plt.xlabel('Size of BST')
plt.ylabel('Runtime (seconds)')

# Show grid and display the plot
plt.grid(True)
plt.show()
