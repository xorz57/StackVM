# StackVM

## Example 1
```c
  memory[0x3000] = 0x10000001; // mov r0, #1
  memory[0x3001] = 0x10010002; // mov r1, #2
  memory[0x3002] = 0x60020001; // add r2, r0, r1
  memory[0x3003] = 0xff000000; // halt
```

## Example 2
```c
  memory[0x3000] = 0x10000001; // mov r0, #1
  memory[0x3001] = 0x10010002; // mov r1, #2
  memory[0x3002] = 0x40000000; // push r0
  memory[0x3003] = 0x40010000; // push r1
  memory[0x3004] = 0x50000000; // pop r0
  memory[0x3005] = 0x50010000; // pop r1
  memory[0x3006] = 0xff000000; // halt
```
