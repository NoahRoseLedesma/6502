// Defines the 6502 emulator as a class
#ifndef __6502_EMULATOR__
#define __6502_EMULATOR__

#define __6502_EMULATOR_DEBUG__

#include <stdint.h>
#include <stdbool.h>
#ifdef __6502_EMULATOR_DEBUG__
#include <stdio.h>
#endif 

typedef struct e6502 emulator;
#include "operations.h"

struct e6502 {
    // The 6502 provides 5 registers
    // The accumulator handles all arithmetic and logic
    // X and Y are general purpose registers
    // SP is the stack pointer
    // PS is the processor status.
    // PC is the program counter.
    uint8_t accumulator;
    uint8_t X; 
    uint8_t Y;
    uint8_t stack_pointer;
    uint8_t processor_status;
    uint8_t program_counter;

    // Emulated RAM
    // 64KB
    uint8_t memory[ 0x10000 ];

    // Writes a value to memory at the specified address.
    void (*memset)( struct e6502* self, uint16_t address, uint8_t value );

    // Reads a value from memory at the speicified address.
    uint8_t (*memget)( struct e6502* self, uint16_t address );
    
    // Processer flag abstrations
    bool (*is_carry_flag_set)( struct e6502* self );
};

// Emulator functions
void emulator_memset( emulator* self, uint16_t address, uint8_t value );
uint8_t emulator_memget( emulator* self, uint16_t address );
bool emulator_is_carry_flag_set( emulator* self );

// Function pointer assignment
void initilize_emulator( emulator* emu );

#ifdef __6502_EMULATOR_DEBUG__
void printProcessorStatus( emulator *self );
#endif
#endif