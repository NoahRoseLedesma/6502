#include "emulator.h"

void emulator_memset( emulator* self, uint16_t address, uint8_t value )
{
    self->memory[address] = value;
}

uint8_t emulator_memget( emulator* self, uint16_t address )
{
    return self->memory[address];
}

#ifdef __6502_EMULATOR_DEBUG__
    void printProcessorStatus( emulator* self )
    {
        printf("Accumulator: ");
        printf("%#02x BCD: ", self->accumulator);
        printf("%d\n", self->accumulator);
        printf("X: ");
        printf("%#02x ", self->X);
        printf("Y: ");
        printf("%#02x\n", self->Y);
        printf("Stack pointer: ");
        printf("%#02x\n", self->stack_pointer);
        printf("Program Counter: ");
        printf("%#02x\n", self->program_counter);
        printf("Processor Status: ");
        printf("%#02x\n", self->processor_status);
    }
#endif

// Function pointer assignment
void initilize_emulator( emulator* emu )
{
    if( emu ) 
    {
        emu->memset = &emulator_memset;
        emu->memget = &emulator_memget;
    }
}