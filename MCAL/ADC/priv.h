/*
 * priv.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Basim Osman
 */

#ifndef HAL_ADC_PRIV_H_
#define HAL_ADC_PRIV_H_

#define ADMUX     *((volatile u8*)   0x27 )
#define ADCH      *((volatile u8*)   0x25 )    // adc is 10 bits and devided into 2 bytes , if right  adjust , start from bit 0 in low to bit 7 and get the first two bits of the high reg
                                              // if left adjust , start from bit num 6 of the low till the last bit in high
                                             // to print data mention the address of bit 0 of low reg in right adjustment, or mention bit number 6 of low reg for left adjust
#define ADCL      *((volatile u8*)   0x24 )
#define ADCSRA    *((volatile u8*)   0x26 )    //ADC control status register
#define SFIOR     *((volatile u8*)   0x50 )

//#define ADLAR    5                        //ADLAR: ADC Left Adjust Result, Write one to ADLAR to left adjust the result., (5) == bit number in ADMUX (ADC Multiplexer Selection Register )
//#define ADSC     6                       // ADSC: ADC Start Conversion   ,, (6)==  bit number in ADCSRA  (ADC Control and Status Register A)  register
//#define ADEN     7  				    //ADEN: ADC Enable ,,bit in ADCSRA REG
//#define ADATE    5   				   // ADATE: ADC Auto Trigger Enable ,, bit in ADCSRA REG
//#define ADIF     4                    // ADIF: ADC Interrupt Flag

#endif /* HAL_ADC_PRIV_H_ */
