#include "operations.h"
#include "stdlib.h"

// Add value to accumulator with carry
void adc( emulator* self, uint8_t value )
{
    // Check which arithmitic mode we are in
    if( get_flag(self, DECIMAL_FLAG) )
    {
        value = byte_as_bcd(value) + byte_as_bcd(self->accumulator) + get_flag(self, CARRY_FLAG);
        set_flag(self, CARRY_FLAG, value > 99 );
        printf("\nValue: %d\n", value);
    }
    else
    {
        value += self->accumulator + get_flag(self, CARRY_FLAG);
        set_flag(self, CARRY_FLAG, value < self->accumulator );
    }
    set_flag(self, OVERFLOW_FLAG, (value & 0b10000000) != (self->accumulator & 0b10000000 ) );
    set_flag(self, NEGATIVE_FLAG, value & 0b10000000 );
    set_flag(self, ZERO_FLAG, value == 0 );
    
    self->accumulator = value;
}

// Subtract value from the accumulator with carry
void sbc( emulator* self, uint8_t value )
{
    // Check which arithmitic mode we are in
    if( get_flag(self, DECIMAL_FLAG) )
    {
        // Perform decimal mode bullshit
    }
    else
    {
        value = self->accumulator - value + !get_flag(self, CARRY_FLAG);
    }
    set_flag(self, CARRY_FLAG, value > self->accumulator );
    set_flag(self, OVERFLOW_FLAG, (value & 0b10000000) != (self->accumulator & 0b10000000) );
    set_flag(self, NEGATIVE_FLAG, value & 0b10000000 );
    set_flag(self, ZERO_FLAG, value == 0 );
}

// Clear the carry flag
void clc( emulator* self )
{
    set_flag(self, CARRY_FLAG, false);
}

// Load a value into the accumulator
void lda( emulator* self, uint8_t value )
{
    self->accumulator = value;
    set_flag(self, NEGATIVE_FLAG, value & 0b10000000 );
    set_flag(self, ZERO_FLAG, value == 0 );
}

void sed( emulator* self )
{
    set_flag(self, DECIMAL_FLAG, true);
}

void cld( emulator* self )
{
    set_flag(self, DECIMAL_FLAG, false);
}