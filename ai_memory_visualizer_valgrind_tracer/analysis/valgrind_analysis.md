# Valgrind Analysis

## Program: stack_lifetime.c

### Valgrind Output
No memory errors were reported.

### Analysis
- No heap allocation occurs.
- All variables are stored on the stack.
- Every stack object reaches the end of its lifetime normally.
- No invalid read, invalid write or memory leak occurs.

---

## Program: heap_aliasing.c

### Valgrind Output
No memory leaks were reported.

### Analysis
- Memory is allocated using malloc().
- Two pointers alias the same heap allocation.
- The allocation is released using free().
- Both pointers are later assigned NULL.
- No memory leak occurs.
- No use-after-free occurs because the freed memory is never dereferenced.

---

## Program: recursion.c

### Valgrind Output
No memory errors were reported.

### Analysis
- The program only creates stack frames through recursion.
- Every recursive frame is destroyed when the function returns.
- No heap memory is allocated.
- No lifetime violations occur.

---

## AI Explanation Correction

An AI explanation claimed that free(pointer) automatically changes the pointer to NULL.

This is incorrect.

free() only releases the heap allocation.
The pointer variable still stores the previous address until it is explicitly assigned NULL.

