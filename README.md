# **Data Structures and Algorithms**

This repository contains a collection of C programs implementing various algorithms and data structures. These implementations cover a wide range of topics, including graph algorithms, dynamic programming, greedy approaches, divide-and-conquer techniques, and more.

---

## **Contents**

### **1. Graph Algorithms**
- **Breadth-First Search (BFS)**:
  - `bfsAdjacencyList.c`: BFS using an adjacency list.
  - `bfsAdjacencyMatrix.c`: BFS using an adjacency matrix.
- **Depth-First Search (DFS)**:
  - `dfsAdjacencyList.c`: DFS using an adjacency list.
  - `dfsAdjacencyMatrix.c`: DFS using an adjacency matrix.
- **Shortest Path Algorithms**:
  - `bellmanFord.c`: Bellman-Ford algorithm.
  - `dijkstraPriQueHeap.c`: Dijkstra's algorithm using a priority queue and heap.
  - `floydWarshel.c`: Floyd-Warshall algorithm for all-pairs shortest paths.
- **Minimum Spanning Tree (MST)**:
  - `KruskalMST_Greedy.c`: Kruskal's algorithm using a greedy approach.
  - `KruskalMST_Heap.c`: Optimized Kruskal's algorithm using a heap.
  - `KruskalMST_PriQueue.c`: Kruskal's algorithm with priority queue optimization.
  - `PrimsMST_Greedy.c`: Prim's algorithm using a greedy approach.
  - `PrimsMST_Heap.c`: Optimized Prim's algorithm using a heap.
  - `PrimsMST_PriQueue.c`: Prim's algorithm with priority queue optimization.
- **Graph Coloring**:
  - `graphcolor_Greedy.c`: Graph coloring using a greedy approach.
  - `graphcolor_Greedy_optimised.c`: Optimized greedy graph coloring.
  - `graphcolor_backtrack.c`: Graph coloring using backtracking.
  - `graphcolor_branchbound.c`: Graph coloring using branch and bound.

---

### **2. Dynamic Programming**
- **Fibonacci Sequence**:
  - `fibonnaciMemoization.c`: Fibonacci using memoization.
  - `fibonnaciBottoumUpApproch.c`: Fibonacci using bottom-up dynamic programming.
- **Longest Common Subsequence (LCS)**:
  - `longestCommanSeqBrute.c`: Brute-force approach.
  - `longestCommanSeqDynamicBottomUp.c`: Bottom-up dynamic programming approach.
  - `longestCommanSeqDynamicDpPrintLcs.c`: LCS with printing the sequence.
- **Coin Change Problem**:
  - `Coin_Dynamic.c`: Coin change problem using dynamic programming.
  - `Coin_Greedy.c`: Coin change problem using a greedy approach.
- **Interval Scheduling**:
  - `IntervalSchedule_Dynamic.c`: Dynamic programming approach.
  - `IntervalSchedule_Greedy.c`: Greedy approach.

---

### **3. Greedy Algorithms**
- **Knapsack Problem**:
  - `FractKnapsack_Backtrack.c`: Fractional knapsack using backtracking.
  - `FractKnapsack_DivConquer.c`: Fractional knapsack using divide and conquer.
  - `FractKnapsack_Dynamic.c`: Fractional knapsack using dynamic programming.
  - `FractKnapsack_Greedy.c`: Fractional knapsack using a greedy approach.
- **Job Scheduling**:
  - `Jobschedule_Greedy.c`: Job scheduling using a greedy approach.
  - `jobSchedulingGreedy.c`: Alternate implementation of job scheduling.
- **Optimal Merge Pattern**:
  - `OptimalMerge_Greedy.c`: Optimal merge using a greedy approach.
  - `OptimalMerge_Heap.c`: Optimized approach using a heap.
- **Set Operations**:
  - `Set_Greedy.c`: Set operations using a greedy approach.
  - `Set_PriQueue.c`: Set operations using a priority queue.

---

### **4. Traveling Salesman Problem (TSP)**
- **TSP Implementations**:
  - `travellingSalesmanProbelmBruteForce.c`: Brute-force solution to TSP.
  - `travellingSalesmanProbelm.c`: General implementation of TSP.
  - `travellingSalesmanProbelmGreedy.c`: TSP using a greedy approach.
  - `Salesman_backtrack.c`: TSP using backtracking.
  - `Salesman_branch.c`: TSP using branch and bound.
  - `Salesman_Greedy.c`: Greedy approach to TSP.

---

### **5. Other Algorithms**
- **Activity Selection Problem**:
  - `activitySelectionBackT.c`: Backtracking solution.
  - `activitySelectionDp.c`: Dynamic programming approach.
  - `activitySelectionGreddy.c`: Greedy approach.
- **Sorting**:
  - `sort012.c`: Algorithm to sort an array with 0s, 1s, and 2s.
- **Huffman Encoding**:
  - `huffmanEncoding.c`: Huffman encoding for file compression.

---

### **6. Problem Statements**
- **File**:
  - `problemStatements.txt`: Contains problem statements and challenges for these implementations.

---

## **How to Compile and Run**

1. Compile any program using `gcc`:
   ```bash
   gcc program_name.c -o output_name
   ```
2. Run the compiled program:
   ```bash
   ./output_name
   ```

---
