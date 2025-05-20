Here’s the simplified and detailed explanation of CPU Scheduling in a clear **TXT format**:

---

### **CPU Scheduling Explained (Chapter 5)**  

#### **1. Basics of CPU Scheduling**  
- **Goal**: Decide which process/thread runs next on the CPU to maximize efficiency.  
- **Why Needed?** The CPU is a single resource, but multiple programs (processes/threads) need to run *simultaneously*.  

#### **2. Key Terms**  
- **Process**: A running program (e.g., Chrome, Spotify).  
- **Thread**: A smaller unit within a process (e.g., tabs in Chrome).  

---

### **Types of Schedulers**  

#### **A. First-Come, First-Served (FCFS)**  
- **Rule**: Runs processes in the order they arrive.  
- **Problem**: Long processes block short ones ("convoy effect").  
- **Example**:  
  - Processes:  
    - P1 (10 ms burst), P2 (29 ms), P3 (3 ms).  
  - Order: P1 → P2 → P3.  
  - **Wait Times**:  
    - P1: 0 ms (runs first).  
    - P2: 10 ms (waits for P1).  
    - P3: 39 ms (waits for P1 + P2).  
  - **Avg Wait Time**: (0 + 10 + 39)/3 = **16.33 ms**.  

#### **B. Shortest Job First (SJF)**  
- **Rule**: Runs the shortest task next.  
- **Example**:  
  - Order: P3 (3 ms) → P1 (10 ms) → P2 (29 ms).  
  - **Wait Times**:  
    - P3: 0 ms.  
    - P1: 3 ms.  
    - P2: 13 ms.  
  - **Avg Wait Time**: (0 + 3 + 13)/3 = **5.33 ms** (better than FCFS!).  

#### **C. Round Robin (RR)**  
- **Rule**: Each process gets a fixed **time slice** (e.g., 10 ms).  
- **Example**:  
  - Processes: P1 (10 ms), P2 (29 ms), P3 (3 ms).  
  - Order: P1 (10 ms) → P2 (10 ms) → P3 (3 ms) → P2 (10 ms) → P2 (9 ms).  
  - **Avg Wait Time**: **14 ms**.  

---

### **Linux Schedulers**  

#### **A. O(1) Scheduler (Old)**  
- **Pros**: Fast (scheduling time doesn’t depend on # of tasks).  
- **Cons**: Poor for interactive tasks (e.g., laggy desktop).  

#### **B. Completely Fair Scheduler (CFS)**  
- **Goal**: Fairly share CPU time based on **priority** (`nice` values).  
  - `nice` range: **-20 (highest priority)** to **+19 (lowest)**.  
- **How it Works**:  
  1. Tracks `vruntime` (virtual runtime) for each task.  
     - High priority → `vruntime` grows **slower**.  
     - Low priority → `vruntime` grows **faster**.  
  2. Always runs the task with the **smallest `vruntime`** (like picking the leftmost task in a sorted tree).  

- **Example**:  
  - **CPU-bound task**: Runs long → `vruntime` ↑ fast → preempted.  
  - **I/O-bound task**: Runs short → `vruntime` ↑ slow → runs more often.  

---

### **Multi-CPU Scheduling**  
- **Challenge**: Balance load across CPU cores.  
- **Solution**:  
  - Each CPU has a **runqueue** (list of runnable tasks).  
  - **Load balancing**: Moves tasks from busy CPUs to idle ones.  

---

### **Algorithm Evaluation**  

#### **Deterministic Modeling**  
- **What?** Compare schedulers using a fixed workload.  
- **Example**:  
  - Processes: P1 (10 ms), P2 (29 ms), P3 (3 ms).  
  - **FCFS Avg Wait**: 16.33 ms.  
  - **SJF Avg Wait**: 5.33 ms (best for this case).  

#### **Metrics**  
- **Throughput**: # tasks completed per second.  
- **Response Time**: Time until first output (e.g., mouse click).  

---

### **Key Takeaways**  
1. **FCFS**: Simple but unfair to short tasks.  
2. **SJF**: Best for minimizing wait time (but needs exact burst times).  
3. **CFS**: Fair, prioritizes interactive tasks (used in modern Linux).  
4. **Multi-CPU**: Balance load to keep all cores busy.  

--- 

*(Think of CPU scheduling like a traffic light: FCFS is a single lane, SJF lets ambulances (short tasks) go first, and CFS dynamically adjusts green lights based on vehicle priority!)*  

--- 

**Format**: Plain Text (.txt)  
**Word Count**: ~500  
**Simplified for**: Students/Beginners  
**Examples Included**: Yes (FCFS, SJF, CFS)  

Let me know if you'd like further clarifications!
