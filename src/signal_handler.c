//
// Created by xorz57 on 2/24/2023.
//

#include "signal_handler.h"

#include <stdlib.h>

extern volatile sig_atomic_t signal_status;

void signal_handler(int signal) {
    signal_status = signal;
    if (signal_status == SIGINT) {
        exit(EXIT_FAILURE);
    }
}
