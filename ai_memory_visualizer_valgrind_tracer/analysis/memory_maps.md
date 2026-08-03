# C Memory Maps

## Program 1: stack_lifetime.c

### Function entry
- `main_value` is created on the stack when `main()` begins.
- Calling `inspect()` creates a new stack frame.
- `value` and `pointer` exist only inside `inspect()`.

### Pointer assignment
- `pointer = &value`
- `pointer` stores the address of `value`.
- `*pointer = 84` modifies `value` because both refer to the same object.

### Function exit
- Returning from `inspect()` destroys its stack frame.
- `value` and `pointer` no longer exist.
- `main_value` is still valid because `main()` has not returned.

---

## Program 2: heap_aliasing.c

### Before malloc
- `first` and `second` exist on the stack.
- No heap memory exists yet.

### After malloc
- `malloc()` allocates one integer on the heap.
- `first` points to that heap object.

### Pointer aliasing
- `second = first`
- Both pointers contain the same address.
- They both refer to the same heap allocation.

### Modification
- Writing through `second`
- `*second = 50`
- Reading through `first` also returns 50 because both pointers alias the same object.

### Free
- `free(first)` ends the lifetime of the heap allocation.
- Both `first` and `second` still contain the old address.
- Both pointers are dangling.
- Setting them to `NULL` only changes the pointer variables.

### AI correction
AI incorrectly stated that `free(first)` automatically makes `first` equal to `NULL`.

Correction:
`free()` never changes the pointer variable.
After `free(first)`, both `first` and `second` still contain the old address until explicitly assigned `NULL`.

---

## Program 3: recursion.c

### First call
A stack frame is created for `countdown(3)`.

### Recursive calls
Each recursive call creates a completely new stack frame containing its own:
- parameter `number`
- local variable `local_value`

No recursive call shares local variables with another call.

### Returning
When `countdown(0)` returns, only that stack frame is destroyed.
The previous frames remain valid until each one returns.

### Final return
When the final recursive call returns, every recursive stack frame has been destroyed.

---

## Summary

- Local variables exist on the stack.
- Heap allocations exist until `free()` is called.
- Copying a pointer does not copy the object.
- Multiple pointers can refer to the same heap allocation.
- Returning from a function destroys its stack frame.
- `free()` releases heap memory but does not change pointer variables.
EOFcat > analysis/memory_maps.md << 'EOF'
# C Memory Maps

## Program 1: stack_lifetime.c

### Function entry
- `main_value` is created on the stack when `main()` begins.
- Calling `inspect()` creates a new stack frame.
- `value` and `pointer` exist only inside `inspect()`.

### Pointer assignment
- `pointer = &value`
- `pointer` stores the address of `value`.
- `*pointer = 84` modifies `value` because both refer to the same object.

### Function exit
- Returning from `inspect()` destroys its stack frame.
- `value` and `pointer` no longer exist.
- `main_value` is still valid because `main()` has not returned.

---

## Program 2: heap_aliasing.c

### Before malloc
- `first` and `second` exist on the stack.
- No heap memory exists yet.

### After malloc
- `malloc()` allocates one integer on the heap.
- `first` points to that heap object.

### Pointer aliasing
- `second = first`
- Both pointers contain the same address.
- They both refer to the same heap allocation.

### Modification
- Writing through `second`
- `*second = 50`
- Reading through `first` also returns 50 because both pointers alias the same object.

### Free
- `free(first)` ends the lifetime of the heap allocation.
- Both `first` and `second` still contain the old address.
- Both pointers are dangling.
- Setting them to `NULL` only changes the pointer variables.

### AI correction
AI incorrectly stated that `free(first)` automatically makes `first` equal to `NULL`.

Correction:
`free()` never changes the pointer variable.
After `free(first)`, both `first` and `second` still contain the old address until explicitly assigned `NULL`.

---

## Program 3: recursion.c

### First call
A stack frame is created for `countdown(3)`.

### Recursive calls
Each recursive call creates a completely new stack frame containing its own:
- parameter `number`
- local variable `local_value`

No recursive call shares local variables with another call.

### Returning
When `countdown(0)` returns, only that stack frame is destroyed.
The previous frames remain valid until each one returns.

### Final return
When the final recursive call returns, every recursive stack frame has been destroyed.

---

## Summary

- Local variables exist on the stack.
- Heap allocations exist until `free()` is called.
- Copying a pointer does not copy the object.
- Multiple pointers can refer to the same heap allocation.
- Returning from a function destroys its stack frame.
- `free()` releases heap memory but does not change pointer variables.
