// Defines some common functions and features used in the emulator
#ifndef __6502_STDLIB__
#define __6502_STDLIB__

// stdint and stdbool included via emulator.h
#include "emulator.h"

// Processor status flags:
//  B7  B6  B5  B4  B3  B2  B1  B0
// +---+---+---+---+---+---+---+---+
// | N | O | . | B | D | I | Z | C |
// +---+---+---+---+---+---+---+---+
// Bit 5 of the processor status byte is unused.

// Define processor flag masks
#define NEGATIVE_FLAG 0b10000000
#define OVERFLOW_FLAG 0b01000000
#define BREAK_FLAG    0b00010000
#define DECIMAL_FLAG  0b00001000
#define INTERRUPT_DISABLE_FLAG 0b00000100
#define ZERO_FLAG     0b00000010
#define CARRY_FLAG    0b00000001

static inline void set_flag(emulator *emu, uint8_t flag_mask, bool set )
{
    if( set )
        emu->processor_status |= flag_mask;
    else
        emu->processor_status &= ~flag_mask;
}

static inline bool get_flag(emulator *emu, uint8_t flag_mask )
{
    return (emu->processor_status & flag_mask) > 0;
}

// Returns the value of a byte interpreted as a binary coded decimal
static inline uint8_t byte_as_bcd( uint8_t byte )
{
    // Multiply the high nibble by ten and add it to the low nibble.
    return 10 * ( byte >> 4 ) + (0x0F & byte);
}

#endif