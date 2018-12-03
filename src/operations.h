// Operations.h
// Defines the instruction set for the 6502 emulator
#ifndef EMULATOR_INSTRUCITON_SET
#define EMULATOR_INSTRUCITON_SET

#include "emulator.h"

// Add value to accumulator with carry
void adc( emulator* self, uint8_t value );

// AND value with accumulator
void logical_and( emulator* self, uint8_t value );

// Shift the value in memory one bit left
void asl( emulator* self, uint16_t address );
// Shift the accumulator one bit left
void asl_accumulator( emulator* self );

// Branch on carry clear
void bcc( emulator* self, uint16_t relative_address );

// Branch on carry set
void bcs( emulator* self, uint16_t relative_address );

// Branch on result zero
void beq( emulator* self, uint16_t relative_address );

// Test bits with accumulator
void bit( emulator* self, uint8_t value );

// Branch on result minus
void bri( emulator* self, uint16_t relative_address );

// Branch on result not equal to zero
void bne( emulator* self, uint16_t relative_address );

// Branch on result positive
void bpl( emulator* self, uint16_t relative_address );

// Force break
void brk( emulator* self );

// Branch on overflow clear
void bvc( emulator* self, uint16_t relative_address );

// Branch on overflow set
void bvs( emulator* self, uint16_t relative_address );

// Clear carry flag
void clc( emulator* self );

// Clear decimal mode
void cld( emulator* self );

// Clear interrupt disable bit
void cli( emulator* self );

// Clear overflow flag
void clv( emulator* self );

// Compare value with accumulator
void cmp( emulator* self, uint8_t value );

// Compare value with X register
void cpx( emulator* self, uint8_t value );

// Compare value with Y register
void cpy( emulator* self, uint8_t value );

// Decrement memory by one
void dec( emulator* self, uint16_t address );

// Decrement X register by one
void dex( emulator* self );

// Decrement Y register by one
void dey( emulator* self );

// Exclusive-OR Memory with Accumulator
void eor( emulator* self );

// Increment memory by one
void inc( emulator* self, uint16_t address );

// Increment X register by one
void inx( emulator* self );

// Increment Y index by one
void iny( emulator* self );

// Set the program counter to the specified address
void jmp( emulator* self, uint16_t address );

// Jump to a new location, saving return address
void jsr( emulator* self, uint16_t address );

// Load a value into the accumulator
void lda( emulator* self, uint8_t value );

// Load a value into the X register
void ldx( emulator* self, uint8_t value );

// Load a value into the Y register
void ldy( emulator* self, uint8_t value );

// Shift the value in memory one bit right
void lsr( emulator* self, uint16_t address );
// Shift the accumulator one bit right
void lsr_accumulator( emulator* self );

// No operation
void nop( emulator* self );

// OR value with accumulator
void logical_or( emulator* self, uint16_t address );

// Push accumulator onto the stack
void pha( emulator* self );

// Push processor status onto the stack
void php( emulator* self );

// Pull accumulator from stack
void pla( emulator* self );

// Pull processor status from stack
void plp( emulator* self );

// Rotate the value in memory one bit left
void rol( emulator* self, uint16_t address );
// Rotate the accumulator one bit left
void rol_accumulator( emulator* self );

// Rotate the value in memory one bit right
void ror( emulator* self, uint16_t address );
// Rotate the accumulator one bit right
void ror_accumulator( emulator* self );

// Return from interupt
void rti( emulator* self );

// Return from subroutine
void rts( emulator* self );

// Subtract value from accumulator with borrow
void sbc( emulator* self, uint8_t value );

// Set carry flag
void sec( emulator* self );

// Set the decimal flag
void sed( emulator* self );

// Set interrupt disable status
void sei( emulator* self );

// Store the accumulator in memory
void sta( emulator* self, uint16_t address );

// Store the X register in memory
void stx( emulator* self, uint16_t address );

// Store the Y register in memory
void sty( emulator* self, uint16_t address );

// Transfer the accumulator to the X register
void tax( emulator* self );

// Transfer the accumulator to the Y register
void tay( emulator* self );

// Transfer the stack pointer to the accumulator
void tsx( emulator* self );

// Transfer the X register to the accumulator
void txa( emulator* self );

// Transfer the Y register to the accumulator
void tya( emulator* self );

#endif