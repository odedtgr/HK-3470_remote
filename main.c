/*
 * File:   main.c
 * Author: OTagar119780
 *
 * Created on December 5, 2017, 9:32 PM
 */


// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Detect (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

//INCLUDES
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <PIC12F683.h>

//defines
#define _XTAL_FREQ 8000000
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

/* Prototypes *****************************************************************/
unsigned int readADC(void);
void HK_on (void);
void HK_off (void);
  //void interrupt ISR(void);
/******************************************************************************/
void main(void) {
    double voltage_ratio; //ratio between VDD and AN3
    double VDD;
    
    OSCCON = 0x70; // switch to 8MHz system clock
    GPIO = 0x00;
    ANSEL = 0b00101000; // 010 = FOSC/32, ANS3
    TRISIO = 0b00010000; // GP4/AN3 input
    ADCON0 = 0b00001100; //Analog Channel Select bits = AN3
    //CMCON0 = 7;

    HK_on();

    while (1) {
        voltage_ratio = (double)readADC()/1023;
        VDD = 1.91/voltage_ratio; //Zener diode as AN3 voltage reference; 
        if (VDD <= 4.9)
            HK_off();
        __delay_ms(200);
    }
}

unsigned int readADC() {
    ADCON0bits.ADON = 1; // ADC is enabled, consumes power
    ADCON0bits.GO = 1; // ADC start conversion
    while (CHECK_BIT(ADCON0, 1)) {
        // wait
    }
    ADCON0bits.ADON = 0; // ADC is disabled
    unsigned int ADC_result = ADRESL | (ADRESH << 8);
    return ADC_result;
}

void HK_on() {
    GP0 = 1;
    __delay_us(620);
    GP0 = 0;
    __delay_us(12901);
    GP0 = 1;
    __delay_us(534);
    GP0 = 0;
    __delay_us(554);
    GP0 = 1;
    __delay_us(518);
    GP0 = 0;
    __delay_us(627);
    GP0 = 1;
    __delay_us(483);
    GP0 = 0;
    __delay_us(597);
    GP0 = 1;
    __delay_us(569);
    GP0 = 0;
    __delay_us(540);
    GP0 = 1;
    __delay_us(516);
    GP0 = 0;
    __delay_us(593);
    GP0 = 1;
    __delay_us(553);
    GP0 = 0;
    __delay_us(559);
    GP0 = 1;
    __delay_us(549);
    GP0 = 0;
    __delay_us(566);
    GP0 = 1;
    __delay_us(548);
    GP0 = 0;
    __delay_us(1699);
    GP0 = 1;
    __delay_us(547);
    GP0 = 0;
    __delay_us(560);
    GP0 = 1;
    __delay_us(554);
    GP0 = 0;
    __delay_us(557);
    GP0 = 1;
    __delay_us(514);
    GP0 = 0;
    __delay_us(597);
    GP0 = 1;
    __delay_us(554);
    GP0 = 0;
    __delay_us(557);
    GP0 = 1;
    __delay_us(515);
    GP0 = 0;
    __delay_us(1705);
    GP0 = 1;
    __delay_us(575);
    GP0 = 0;
    __delay_us(1705);
    GP0 = 1;
    __delay_us(506);
    GP0 = 0;
    __delay_us(1739);
    GP0 = 1;
    __delay_us(513);
    GP0 = 0;
    __delay_us(637);
    GP0 = 1;
    __delay_us(511);
    GP0 = 0;
    __delay_us(1701);
    GP0 = 1;
    __delay_us(550);
    GP0 = 0;
    __delay_us(550);
    GP0 = 1;
    __delay_us(559);
    GP0 = 0;
    __delay_us(1758);
    GP0 = 1;
    __delay_us(487);
    GP0 = 0;
    __delay_us(566);
    GP0 = 1;
    __delay_us(561);
    GP0 = 0;
    __delay_us(548);
    GP0 = 1;
    __delay_us(526);
    GP0 = 0;
    __delay_us(584);
    GP0 = 1;
    __delay_us(465);
    GP0 = 0;
    __delay_us(1780);
    GP0 = 1;
    __delay_us(515);
    GP0 = 0;
    __delay_us(1740);
    GP0 = 1;
    __delay_us(509);
    GP0 = 0;
    __delay_us(643);
    GP0 = 1;
    __delay_us(575);
    GP0 = 0;
    __delay_us(1627);
    GP0 = 1;
    __delay_us(515);
    GP0 = 0;
    __delay_us(590);
    GP0 = 1;
    __delay_us(517);
    GP0 = 0;
    __delay_us(1733);
    GP0 = 1;
    __delay_us(557);
    GP0 = 0;
    __delay_us(1699);
    GP0 = 1;
    __delay_us(515);
    GP0 = 0;
    __delay_us(1734);
    GP0 = 1;
    __delay_us(509);
    GP0 = 0;
    __delay_us(621);
    GP0 = 1;
    __delay_us(495);
    GP0 = 0;
    __delay_us(621);
    GP0 = 1;
    __delay_us(461);
    GP0 = 0;
    __delay_us(237800);
    GP0 = 1;
    __delay_us(8972);
    GP0 = 0;
    __delay_us(2252);
    GP0 = 1;
    __delay_us(493);
    GP0 = 0;
    __delay_us(96451);
    GP0 = 1;
    __delay_us(8984);
    GP0 = 0;
    __delay_us(2247);
    GP0 = 1;
    __delay_us(547);
    GP0 = 0;
    __delay_us(96404);
    GP0 = 1;
    __delay_us(8991);
    GP0 = 0;
    __delay_us(2232);
    GP0 = 1;
    __delay_us(559);
    GP0 = 0;
    __delay_us(96395);
    GP0 = 1;
    __delay_us(3525);
    GP0 = 0;
    __delay_us(7721);
    GP0 = 1;
    __delay_us(517);
    GP0 = 0;
    __delay_us(96440);
    GP0 = 1;
    __delay_us(8943);
    GP0 = 0;
    __delay_us(2275);
    GP0 = 1;
    __delay_us(543);
    GP0 = 0;
    __delay_us(96408);
    GP0 = 1;
    __delay_us(8943);
    GP0 = 0;
    __delay_us(2303);
    GP0 = 1;
    __delay_us(494);
    GP0 = 0;
    __delay_us(96435);
    GP0 = 1;
    __delay_us(8953);
    GP0 = 0;
    __delay_us(2274);
    GP0 = 1;
    __delay_us(539);
    GP0 = 0;
}

void HK_off() {
    GP0 = 1;
    __delay_us(8995);
    GP0 = 0;
    __delay_us(4416);
    GP0 = 1;
    __delay_us(580);
    GP0 = 0;
    __delay_us(545);
    GP0 = 1;
    __delay_us(568);
    GP0 = 0;
    __delay_us(562);
    GP0 = 1;
    __delay_us(596);
    GP0 = 0;
    __delay_us(485);
    GP0 = 1;
    __delay_us(633);
    GP0 = 0;
    __delay_us(487);
    GP0 = 1;
    __delay_us(811);
    GP0 = 0;
    __delay_us(305);
    GP0 = 1;
    __delay_us(629);
    GP0 = 0;
    __delay_us(507);
    GP0 = 1;
    __delay_us(613);
    GP0 = 0;
    __delay_us(497);
    GP0 = 1;
    __delay_us(612);
    GP0 = 0;
    __delay_us(1615);
    GP0 = 1;
    __delay_us(584);
    GP0 = 0;
    __delay_us(537);
    GP0 = 1;
    __delay_us(619);
    GP0 = 0;
    __delay_us(506);
    GP0 = 1;
    __delay_us(578);
    GP0 = 0;
    __delay_us(531);
    GP0 = 1;
    __delay_us(745);
    GP0 = 0;
    __delay_us(367);
    GP0 = 1;
    __delay_us(680);
    GP0 = 0;
    __delay_us(1561);
    GP0 = 1;
    __delay_us(582);
    GP0 = 0;
    __delay_us(1654);
    GP0 = 1;
    __delay_us(626);
    GP0 = 0;
    __delay_us(1606);
    GP0 = 1;
    __delay_us(630);
    GP0 = 0;
    __delay_us(480);
    GP0 = 1;
    __delay_us(633);
    GP0 = 0;
    __delay_us(1612);
    GP0 = 1;
    __delay_us(627);
    GP0 = 0;
    __delay_us(1610);
    GP0 = 1;
    __delay_us(628);
    GP0 = 0;
    __delay_us(1609);
    GP0 = 1;
    __delay_us(623);
    GP0 = 0;
    __delay_us(1616);
    GP0 = 1;
    __delay_us(587);
    GP0 = 0;
    __delay_us(1649);
    GP0 = 1;
    __delay_us(592);
    GP0 = 0;
    __delay_us(520);
    GP0 = 1;
    __delay_us(608);
    GP0 = 0;
    __delay_us(515);
    GP0 = 1;
    __delay_us(642);
    GP0 = 0;
    __delay_us(1597);
    GP0 = 1;
    __delay_us(581);
    GP0 = 0;
    __delay_us(571);
    GP0 = 1;
    __delay_us(604);
    GP0 = 0;
    __delay_us(514);
    GP0 = 1;
    __delay_us(546);
    GP0 = 0;
    __delay_us(523);
    GP0 = 1;
    __delay_us(633);
    GP0 = 0;
    __delay_us(488);
    GP0 = 1;
    __delay_us(629);
    GP0 = 0;
    __delay_us(483);
    GP0 = 1;
    __delay_us(632);
    GP0 = 0;
    __delay_us(1610);
    GP0 = 1;
    __delay_us(627);
    GP0 = 0;
    __delay_us(1609);
    GP0 = 1;
    __delay_us(628);
    GP0 = 0;
    __delay_us(488);
    GP0 = 1;
    __delay_us(591);
    GP0 = 0;
    __delay_us(44665);
    GP0 = 1;
    __delay_us(8957);
    GP0 = 0;
    __delay_us(2222);
    GP0 = 1;
    __delay_us(585);
    GP0 = 0;
    __delay_us(96011);
    GP0 = 1;
    __delay_us(9017);
    GP0 = 0;
    __delay_us(2161);
    GP0 = 1;
    __delay_us(622);
    GP0 = 0;
}