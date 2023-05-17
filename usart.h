/* Functions to initialize, send, receive over USART

   initUSART requires BAUD to be defined in order to calculate
     the bit-rate multiplier.
 */
#include <stdint.h>

#ifndef BAUD      /* if not defined in Makefile... */
#define BAUD 9600 /* set a safe default baud rate */
#endif

/* These are defined for convenience */
#define USART_HAS_DATA bit_is_set(UCSR0A, RXC0)
#define USART_READY bit_is_set(UCSR0A, UDRE0)

/* Takes the defined BAUD and F_CPU,
   calculates the bit-clock multiplier,
   and configures the hardware USART                   */
void usart_init(void);

/// Send a byte over UART
void usart_send(uint8_t data);
/// Receive a byte over UART
uint8_t usart_recv(void);

/* Utility function to transmit an entire string from RAM */
void usart_print(const char *s);

/* Define a string variable, pass it to this function
   The string will contain whatever you typed over serial */
void usart_read(char *s, uint8_t maxLength);

/* Prints a byte out as its 3-digit ascii equivalent */
void usart_print_byte(uint8_t byte);

/* Prints a word (16-bits) out as its 5-digit ascii equivalent */
void usart_print_word(uint16_t word);

/* Prints a byte out in 1s and 0s */
void usart_print_bin(uint8_t byte);

/* Prints a byte out in hexadecimal */
void usart_print_hex(uint8_t byte);

/* takes in up to three ascii digits,
 converts them to a byte when press enter */
uint8_t usart_read_number(void);
