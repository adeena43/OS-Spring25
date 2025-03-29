# c)
  By uncommenting int counter = 0; inside the mythread() function, each thread now has its own local copy of counter. This means:
  Each thread initializes its own counter = 0, rather than modifying the shared counter.
  Both threads increment their own local counter instead of updating a global variable.
  The final value printed in main() remains unchanged (0) because the global counter is never modified by threads.
  This fixes the race condition but also makes the counter updates useless since they no longer affect the shared variable.
  
![Q2(c)_inlab](https://github.com/user-attachments/assets/8bc06191-c020-426b-ba7e-f97fc907a0d3)
