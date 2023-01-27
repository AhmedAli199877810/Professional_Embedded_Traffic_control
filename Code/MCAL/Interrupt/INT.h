/*
 * INT.h
 *
 * Created: 10/4/2022 12:20:57 AM
 *  Author: Ahmed
 */ 
/**************************************************************/
/*                     Interrupt Vectors                      */
/**************************************************************/
#ifndef INT_H_
#define INT_H_
/* External Interrupt Vectors*/

/* External Interrupt Request0*/
#define EXT_INT_0 __vector_1

/*Set Global Interrrupts, Set the I-bit in status register to 1 */
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")

/*Clear Global Interrrupts, Set the I-bit in status register to 0 */
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition,no return */
#define ISR(INT_VECT)void INT_VECT (void) __attribute__ ((signal,used));\
void INT_VECT (void)

#endif /* INT_H_ */