# PROBABILITY-SIMULATOR

## 📌 Overview
The **Probability Simulator** is a C-based console application that allows users to explore various probability concepts interactively.  
It includes both **random probability simulations** and **deterministic probability calculations**.

---

## ✨ Features
### 🎲 Random Probability Generators
- **Coin Toss Simulation** – Simulates multiple coin tosses and counts Heads/Tails.
- **Dice Roll Simulation** – Rolls a dice multiple times and records the frequency of each face.
- **Card Draw Simulation** – Simulates random card suit draws from a standard deck.

### 📊 Deterministic Calculations
- **Binomial Distribution Probability**
- **Poisson Distribution Probability**
- **Basic Statistical Measures** – Mean, Variance, and Standard Deviation.

---

## 🛠 How It Works
- The program uses the C standard library functions (`rand()`, `pow()`, `exp()`) to perform simulations and probability calculations.
- A **menu-driven system** allows users to choose between simulations and deterministic calculations.
- Probability formulas implemented:
    - **Binomial Probability**:  
      \( P(X = k) = \frac{n!}{k!(n-k)!} p^k (1-p)^{n-k} \)
    - **Poisson Probability**:  
      \( P(X = k) = \frac{λ^k e^{-λ}}{k!} \)

---

## 📂 File Structure
```
main.c                   # Main source code
README.md                # Project documentation
project_report           # project report
```

---

## 🚀 Compilation & Execution
### Compile:
```bash
gcc probability_simulator.c -o probability_simulator -lm
```

### Run:
```bash
./probability_simulator
```

> **Note:** The `-lm` flag is required to link the math library.

---

## 📷 Example Output
```
=== Probability Simulator ===
1. Random Probability Generator
2. Deterministic Calculator
3. Exit
Enter your choice: 1

--- Random Probability Generator ---
1. Coin Toss Simulation
2. Dice Roll Simulation
3. Card Draw Simulation
4. Back to Main Menu
Enter your choice: 1

--- Coin Toss Simulation ---
Enter number of tosses: 5
Results: Heads = 3, Tails = 2
```

---

## 📌 Author
- **Shivam Semwal**  
  📧 shivamsemwal1999@gmail.com

---

## 📜 License
This project is open-source and free to use.
