
This repository provides all the topics under DSA you need to know for an SDE Interview or competitive programming.

# Topics
1. [Array](https://atigit15.github.io/Data-Structures-and-Algorithms/#array)
2. [LinkedList](https://atigit15.github.io/Data-Structures-and-Algorithms/#linkedlist)
3. [Greedy Algorithms](https://atigit15.github.io/Data-Structures-and-Algorithms/#greedy)
4. [Recursion](https://atigit15.github.io/Data-Structures-and-Algorithms/#topics)
5. [Backtracking](https://atigit15.github.io/Data-Structures-and-Algorithms/#topics)
6. [Binary Search](https://atigit15.github.io/Data-Structures-and-Algorithms/#topics)
7. [Heaps](https://atigit15.github.io/Data-Structures-and-Algorithms/#heaps)
8. [Stacks and Queues](https://atigit15.github.io/Data-Structures-and-Algorithms/#stack-and-queues)
9. [Strings](https://atigit15.github.io/Data-Structures-and-Algorithms/#strings)
10. [STL]()
11. [Binary Tree and BST](https://atigit15.github.io/Data-Structures-and-Algorithms/#binary-tree-and-bst)
12. [Trees](https://atigit15.github.io/Data-Structures-and-Algorithms/#trees)
13. [Graphs](https://atigit15.github.io/Data-Structures-and-Algorithms/#graph)
14. [Dynamic Programming](https://atigit15.github.io/Data-Structures-and-Algorithms/#dp)
15. [Tries](https://atigit15.github.io/Data-Structures-and-Algorithms/#tries)
16. [Bit Manipulation](https://atigit15.github.io/Data-Structures-and-Algorithms/#bit-manipulation)
17. [Range Queries](https://atigit15.github.io/Data-Structures-and-Algorithms/#range-queries)
18. [Number Theory](https://atigit15.github.io/Data-Structures-and-Algorithms/#number-theory)
19. [Geometry](https://atigit15.github.io/Data-Structures-and-Algorithms/#geometry)
20. [Additional Topics](https://atigit15.github.io/Data-Structures-and-Algorithms/#additional-topics)

# Array
- [Sorting Algorithms](https://github.com/Atigit15/Sorting_Algorithms)
- Prefix/Suffix Sum
- Two Pointers
- [Sliding Window](https://leetcode.com/discuss/general-discussion/1122776/summary-of-sliding-window-patterns-for-subarray-substring)
- Count Inversions
  - Using Merge Sort
  - Using Fenwick Tree
  - Using [Ordered Set](https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/)
- Kadane's Algorithm
- Dutch National Flag
- [Boyre Moore Voting Algorithms](https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/)
- All Subsets Generation
    - Using Recursion
    - Using Bitmasks
- Permutation
- Quick Select
  
# LinkedList
- Reversing a LL
- Slow and fast pointer technique
- Doubly and circular LL
### Resources
- [Leetcode Problems](https://leetcode.com/tag/linked-list/)

# Greedy
- Activity Selection
- Minimum number of platforms required
- Fractional Knapsack

# Recursion

# BackTracking

# Binary Search

# Heaps

# Stack and Queues
- Next/Previous Greater/Smaller Element in O(N)
- Doubly Ended Queue - Deque
- Circular Queue
- Real-life use cases

# Strings
- String Hashing
- KMP Algorithm
- Z Algorithm
- Rabin Karp Algo
- Manacher Algorithm
### Resources
- [CP-Algorthms](https://cp-algorithms.com/string/string-hashing.html)

# STL (C++)



# Binary Tree and BST
- AVL Trees
- Red Black Trees
- B/B+ Trees
- Traversal
- Serialization and Deserialization

# Trees
- DFS/BFS Traversal
- DP on Trees
- Height/Level and Diameter
- [Binary Lifting](https://codeforces.com/blog/entry/100826)
   - Finding kth parent of a node
   - Path aggregates
- Euler Tour (and Range Queries) or Flattening the tree
- [LCA of two nodes](https://www.topcoder.com/thrive/articles/Range%20Minimum%20Query%20and%20Lowest%20Common%20Ancestor)
  - Using SQRT decomposition <O(N), O(SQRT(N))>*
  - Using Binary Lifting <O(N LOGN, O(LOGN)>
  - Using EulerTour and RMQ
    - (Sparse Table) <O(N + NLOGN), O(1)> [Better Choice]
    - (Segment Tree) <O(N), O(LOGN)>
- Heavy Light Decomposition
- Centroid Decomposition**
- Note: *<O(N), O(SQRT(N))> means O(N) precomputation and O(SQRTN) query processing
  
 -| Query | Query and Update |
 --|-------|------------------|
Subtree Queries |   Precompute    |   Euler Tour |
Path Queries | Binary Lifting | HLD|

### Resources
- [Pepcoding - Euler Tour](https://www.youtube.com/playlist?list=PL-Jc9J83PIiHymm1DHZBkac0_hhFBXryO)
- [CSES Problem Set](https://cses.fi/problemset)

# Graph
- Representation
- DFS traversal
- BFS traversal
- Multisource BFS
- Detecting cycles (Both directed/undirected using DFS/BFS)
- Topological Sorting (using DFS/BFS - Kahn's Algo)
- Bipartite Check (using DFS/BFS)
- Shortest Path
  - BFS (edge weight = 1)
  - [0/1 BFS](https://codeforces.com/blog/entry/22276) (edge weight = 0 or x, where x >= 0)
  - Bellman-Ford (no negative cycles)
  - SPFA (optimized BF)
  - Dijkstra (no negative edge, least TC)
  - Floyd Warshal (no negative cycles, small graphs)
- Detecting negative cycles using Bellman Ford and Floyd Warshal
- Disjoint Set Union
  - Union by rank
  - Union by size
  - Path compression in findParent()
- Minimum Spanning Tree
  - Kruskals Algo
  - Prims Algo
- Strongly Connected Components
  - Kosaraju Algo
  - Tarjans Algo
- Finding Bridges
- Finding Articulation Points
### Resource
- [Strivers Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn)
- [CSES Graph](https://cses.fi/problemset/)

# DP
- 0/1 Knapsack
- Unbounded Knapsack
- Longest Common Subsequence
- Matrix Chain Multiplication
- [DP on Trees](https://www.youtube.com/playlist?list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s)
- [Bitmask DP]((https://www.youtube.com/playlist?list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s))
- [Digit DP](https://www.youtube.com/playlist?list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s)
- DP on Ranges
  
### Resources
- [Atcoder DP Problems](https://atcoder.jp/contests/dp/tasks)
- [CSES DP](https://cses.fi/problemset/)
- [Kartik Arora](https://www.youtube.com/playlist?list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s)
- [Striver's Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY)
- [Aditya Verma](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
- [DP Handbook - Arpan Banerjee](https://github.com/Atigit15/Interview-Prep/blob/main/DSA/Dynamic_Programming.pdf)

# Tries
- Implementation (Insert, Search, StartsWith)
- Number of distinct substrings in a string
- Power Set
- XOR queries on arrays
### Resources
- [Striver Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp)

# Bit Manipulation
- Representation and operations (AND OR XOR NOT)
- Set or check a bit position, toggle, get last bit, etc
- Generating all subsets
- Builtin C++ functions (__builtin_popcount(), etc.)
- Properties of XOR
- Optimisation techniques using bitmasking

# Range Queries
- Prefix/Suffix Sum Array
- Difference Array (Range Updates Point Query)
- Sparse Table
  - <O(NLOGN), O(1)> Time Complexity
  - O(NLOGN) Space Complexity
  - Use for idempotent/overlap friendly function - MIN, MAX, GCD, AND, OR
- [Fenwick Tree / Binary Indexed Tree](https://cp-algorithms.com/data_structures/fenwick.html)
  - Ordinary BIT (Point Update and Range Query)
  - Reverse BIT (Range Update and Point Query)
  - 2 BITs (Range Updates and Range Queries)
- Segment Tree (Point Update Range Query)
  - Fenwick tree supports SUM query but Seg tree can support any associative o/p - MIN, MAX, GCD, AND, OR, XOR.
  - It takes more memory
- Lazy Segment Tree (Range Update Range Query)
- Index/ Coordinate compression

# Number Theory
- Primality Test
- Sieve of Eratosthenes <O(N*LOG(LOGN)), O(1)>
  - Segmented Sieve - Finding primes in a range
  - Linear Sieve - Finding primes less than 1e7 in O(N)
  - Can be used to compute the smallest prime factor of all numbers b/w [1, 1e6]
- Prime factorization
  - Trial Division O(SQRTN)
  - Using sieve <O(N*LOG(LOGN)), O(LOGN)>
- Binary Exponentiation 
- Euclidean GCD <O(LOG(MIN(a,b)))>
  - Properties of GCD
- Extended Euclidean Algorithm
  - Solving Linear Diophantine Equations.
  - Finding the modular inverse of a number
- Modular Arithmetic
  - Congruence
  - Addition, Multiplication, Subtraction
  - Calculation of Modulo Inverse `𝑎^−1 mod m`
    - Only exists when `gcd(a, m) = 1` 
    - Fermat's Little Theorem and Binary Exponentiation (only when `m` is prime)
    - Euler theorem and Extended Euclidean Theorem
- Binomial Coefficient (both with and without the mod)
- Euler Totient Function
  - Using Factorisation O(SQRTN)
  - Using Sieve O(NLOG(LOG(N)))
- Misc
   - Number of Divisors/Sum of Divisors formulae
   - Chicken McNugget Theorem
   - [Legendre's formula](https://en.wikipedia.org/wiki/Legendre%27s_formula)
   - Catalan Numbers
   - Dearrangments
   - Josephus Problem
   - Burnside Lemma
   - [Star and Bar Theorem](https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics))
### Resources
  - [PPT](https://drive.google.com/file/d/1JDppLNkemgZsk23AQjBzbMD7HL68g7BS/view?usp=sharing)

# Geometry
- Sweep Line Algorithms
- Convex Hull
- Closest Pair Problem
  
# Additional Topics
- Expected Value and Probability
- Burnside Lemma
- Game Theory (Nim / Sprague Grundy)
- Flows and Cuts
- Sqrt decomposition (Mo's Algorithm)
- Meet in the Middle
- Offline Queries
- Reservoir Sampling
- 2 SAT


