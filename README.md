# IS2101-ArithmeticOps--NNM24IS178-

Implementation of signed integer **multiplication** and **division** algorithms in C.  

This repository provides C programs that demonstrate three fundamental arithmetic algorithms used in computer organization and architecture:  

1. **Sequential (Shift-Add) Multiplication**  
   - Handles signed integers using **2’s complement representation**.  
   - Demonstrates the **step-by-step shift-and-add process**.  

2. **Restoring Division Algorithm**  
   - Implements division for **positive integers**.  

3. **Non-Restoring Division Algorithm**  
   - Optimized division method compared to restoring division.  
   - Displays **trace outputs** for each step (accumulator, dividend, and quotient bits).  

These programs mimic how arithmetic operations are executed at the **hardware level**, providing hands-on understanding of low-level computation. They also highlight efficiency improvements, such as how non-restoring division reduces extra steps compared to restoring division.  

---

## 📂 File Structure
- `ShiftAddMultiplication.c` – Sequential multiplication implementation  
- `RestoringDivision.c` – Restoring division algorithm  
- `Non_Restoring_Algorithm.c` – Non-restoring division algorithm  
- `README.md` – Project description & usage instructions  

---

## ⚙️ Compilation & Execution
```bash
gcc ShiftAddMultiplication.c -o ShiftAddMultiplication
./ShiftAddMultiplication

gcc RestoringDivision.c -o RestoringDivision
./RestoringDivision

gcc Non_Restoring_Algorithm.c -o NonRestoring
./NonRestoring

