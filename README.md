# Leetcode-2101.-Detonate-the-Maximum-Bombs
# 💣 Maximum Bomb Detonation (C++)

This project solves the **Maximum Detonation** problem using a **graph-based DFS approach**. Given a list of bombs with coordinates and detonation radii, the goal is to determine the **maximum number of bombs** that can be detonated via a chain reaction starting from **any single bomb**.

---

## 📊 Problem Description

Each bomb has a 2D position `(x, y)` and a radius `r`. A bomb detonates all other bombs that lie within its radius. This program determines the **maximum number of bombs** that can explode if you choose the best starting point.

---

## 🚀 Features

- Converts bomb influence into a **directed graph**
- Efficiently finds connected explosions using **DFS traversal**
- Avoids unnecessary calculations using squared distances (no `sqrt`)
- Handles up to 100 bombs efficiently

---

## 🧠 How It Works

### Step 1: Build a Directed Graph
Each bomb is a node. If bomb `A` can reach bomb `B`, an edge from `A → B` is created.

### Step 2: DFS Search from Each Bomb
For each bomb:
- Perform DFS to count how many bombs it can indirectly detonate.
- Track the maximum across all such DFS runs.

---

## 🛠️ Technologies Used

- **Language**: C++
- **Algorithms**: Depth-First Search
- **Math**: Euclidean distance (squared)

---

## 📦 Usage

### Input Format

```cpp
vector<vector<int>> bombs = {
    {2, 1, 3},
    {6, 1, 4}
};

Output
cpp
int result = 2;  // Maximum bombs detonated starting from any single bomb
✅ Example
Input:

cpp
bombs = {
    {1, 1, 5},
    {10, 10, 5},
    {20, 20, 5}
};
Output:
1
Explanation:
Each bomb is too far to reach any other. Maximum chain is 1.

