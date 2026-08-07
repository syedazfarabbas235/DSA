<div align="center">

# 🌐 Graph Data Structure Library

### A Complete Graph Implementation Using C++ & Manual Data Structures

<img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge">
<img src="https://img.shields.io/badge/Topic-Data%20Structures-green?style=for-the-badge">
<img src="https://img.shields.io/badge/Graph-Algorithms-orange?style=for-the-badge">

<br><br>

```
        ●────●────●
       /     |     \
      ●──────●──────●
       \           /
        ●─────────●
```

</div>


# 📌 Overview

This folder contains different implementations of the **Graph Data Structure** using C++.

The purpose of this implementation is to understand how graphs work internally by building every component manually without using STL graph libraries.

The project covers:

- Vertex management
- Edge management
- Graph traversal
- Path searching
- Cycle detection
- Degree calculation
- Different graph representations


---

# 🗂️ Implementations


## 1️⃣ Adjacency List Graph

```
A → B → C
|
↓
D → E
```

### Concept

In adjacency list representation, every vertex maintains a linked list of its connected vertices.

### Features

✅ Add vertex  
✅ Remove vertex  
✅ Add edge  
✅ Remove edge  
✅ Directed graph support  
✅ Undirected graph support  
✅ Degree calculation  


### Structure

```
Vertex
 |
 |---- Edge → Vertex
 |
 |---- Edge → Vertex
```


---

# 2️⃣ Adjacency Matrix Graph


```
       A B C D

A      0 1 1 0

B      1 0 1 1

C      1 1 0 0

D      0 1 0 0

```

### Concept

A matrix is used where:

- 1 represents an existing edge
- 0 represents no connection


### Features

✅ Graph storage using matrix  
✅ Easy edge lookup  
✅ Supports graph operations  


---

# 🔍 Graph Traversal Algorithms


## 🌊 Breadth First Search (BFS)

BFS explores the graph level by level.

Example:

```
        A

      /   \

     B     C

    /       \

   D         E


BFS:

A → B → C → D → E

```


Implementation uses:

```
Queue
 |
Front → [A][B][C]
             ↑
           Rear
```


Features:

✔ Shortest path in unweighted graphs  
✔ Level order exploration  
✔ Queue based traversal



---

## 🔥 Depth First Search (DFS)


DFS explores as deep as possible before backtracking.


Example:

```
        A

      /   \

     B     C

    /
   D


DFS:

A → B → D → C

```


Implementation uses:

```
Stack
```

Features:

✔ Path searching  
✔ Cycle detection  
✔ Backtracking approach


---

# 🛣️ Path Finding


The implementation supports finding paths between two vertices.


Example:

```
A → B → C → D


Path:

A → B → C → D

```


Available methods:

- DFS based path search
- BFS based path search


---

# 🔄 Cycle Detection


## Undirected Graph Cycle Detection


Uses:

- Visited tracking
- Parent checking


Example:

```
A ─── B
|     |
D ─── C

Cycle Found
```


---

## Directed Graph Cycle Detection


Uses:

- In-degree calculation
- Visitation state tracking


Example:

```
A → B → C
↑       |
|_______|

Cycle Found

```


---

# 📊 Graph Operations


| Operation | Description |
|-----------|-------------|
| Add Vertex | Inserts a new node |
| Remove Vertex | Deletes vertex and related edges |
| Add Edge | Creates connection |
| Remove Edge | Deletes connection |
| BFS | Level traversal |
| DFS | Depth traversal |
| Degree | Finds vertex connections |
| Cycle Detection | Checks circular paths |


---

# 🧩 Internal Data Structures Used


## Vertex Node

Stores:

```
Vertex Data
↓
Next Vertex
↓
Edge List
↓
Visited Status
```


## Edge Node

Stores:

```
Destination Vertex
↓
Next Edge
```


Custom implementations:

```
✔ Linked Lists
✔ Queue
✔ Stack
✔ Dynamic Memory Allocation
```


---

# 🚀 Learning Objectives


This implementation helps understand:

```
Graph Theory
      ↓
Graph Representation
      ↓
Traversal Algorithms
      ↓
Path Finding
      ↓
Cycle Detection
```


---

# 📁 Files


```
Graphs/

│
├── array_graph.cpp
│   └── Adjacency Matrix Implementation
│
├── list_graph.cpp
│   └── Adjacency List Implementation
│
└── mouse.cpp
    └── Graph traversal experiments
```


---

# ⭐ Highlights


<div align="center">

| Feature | Status |
|---|---|
| Manual Implementation | ✅ |
| No STL Graph Library | ✅ |
| BFS | ✅ |
| DFS | ✅ |
| Path Finding | ✅ |
| Cycle Detection | ✅ |
| Directed Graph | ✅ |
| Undirected Graph | ✅ |

</div>


---

<div align="center">

## 🌟 Built With Curiosity & C++

### Data Structures & Algorithms Repository

</div>
