// 6502 Emulator
// Created by Noah Rose Ledesma - 2018
#include "emulator.h"
#include <stdio.h>
uint8_t program[] = {0};

int main( int argc, char* argv[] ) 
{
    emulator myEmulator;
    initilize_emulator( &myEmulator );
    printProcessorStatus( &myEmulator );

    // clc( &myEmulator );
    // lda( &myEmulator, 0x01 );
    // adc( &myEmulator, 0x01 );
    // printf("\n");
    // myEmulator.printProcessorStatus( &myEmulator );

    // clc( &myEmulator );
    // lda( &myEmulator, 0x01 );
    // adc( &myEmulator, 0xFF );
    // printf("\n");
    // myEmulator.printProcessorStatus( &myEmulator );

    // clc( &myEmulator );
    // lda( &myEmulator, 0x7F );
    // adc( &myEmulator, 0x01 );
    // printf("\n");
    // myEmulator.printProcessorStatus( &myEmulator );

    return 0;
}