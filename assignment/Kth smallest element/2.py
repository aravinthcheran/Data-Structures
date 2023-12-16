import matplotlib.pyplot as plt
import csv

# Lists to store data from CSV file
tree_sizes = []
runtimes = []

# Read data from CSV file
with open(r'assignment\Kth smallest element\unival_trees_runtimes.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        tree_sizes.append(int(row['Tree_Size']))
        runtimes.append(float(row['Runtime']))

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
