import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a Pandas DataFrame
df = pd.read_csv('C:\\C\\assignment\\Kth smallest element\\kseresults.csv')
avg_runtime = df.groupby('Array Size')['Runtime'].mean().reset_index()

# Create a line graph for Array Size vs Average Runtime
plt.figure(figsize=(10, 6))
plt.plot(avg_runtime['Array Size'], avg_runtime['Runtime'], marker='o', linestyle='-', color='b')
plt.xlabel('Array Size')
plt.ylabel('Average Runtime (seconds)')
plt.title('Average Runtime vs Array Size')
plt.grid(True)
plt.show()

# Calculate and display the overall average runtime
plt.figure(figsize=(10, 6))
plt.hist(avg_runtime['Runtime'], bins=10, color='b')
plt.xlabel('Average Runtime (seconds)')
plt.ylabel('Frequency')
plt.title('Histogram of Average Runtime')
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
plt.plot(avg_runtime['Array Size'], avg_runtime['Runtime'], 'r--o')
plt.xlabel('Array Size')
plt.ylabel('Average Runtime (seconds)')
plt.title('Average Runtime vs Array Size')
plt.grid(True)
plt.show()