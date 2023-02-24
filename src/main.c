#include "execute.h"
#include "signal_handler.h"

#include <stdbool.h>
#include <stdint.h>

bool running;

uint32_t memory[65536];
uint32_t reg[16];
uint32_t stack[16];

#define SP reg[14] // Stack Pointer
#define PC reg[15] // Program Counter

uint32_t fetch() { return memory[PC++]; }

volatile sig_atomic_t signal_status;

int main() {
    signal(SIGINT, signal_handler);

    SP = 0x0000;
    PC = 0x3000;

    memory[0x3000] = 0x10000001; // mov r0, #1
    memory[0x3001] = 0x10010002; // mov r1, #2
    memory[0x3002] = 0x60020001; // add r2, r0, r1
    memory[0x3003] = 0xff000000; // halt

//    memory[0x3000] = 0x10000001; // mov r0, #1
//    memory[0x3001] = 0x10010002; // mov r1, #2
//    memory[0x3002] = 0x40000000; // push r0
//    memory[0x3003] = 0x40010000; // push r1
//    memory[0x3004] = 0x50000000; // pop r0
//    memory[0x3005] = 0x50010000; // pop r1
//    memory[0x3006] = 0xff000000; // halt

    running = true;

    while (running) {
        uint32_t instruction = fetch();
        execute(instruction);
    }

    return 0;
}
