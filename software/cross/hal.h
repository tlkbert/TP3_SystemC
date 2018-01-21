/********************************************************************
 * Copyright (C) 2009, 2012 by Verimag                              *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

/*!
  \file hal.h
  \brief Harwdare Abstraction Layer : implementation for MicroBlaze
  ISS.


*/
#ifndef HAL_H
#define HAL_H

#include <stdint.h>
#include "address_map.h"

/* Dummy implementation of abort(): invalid instruction */
#define abort() do {				\
	printf("abort() function called\r\n");  \
	_hw_exception_handler();		\
} while (0)

/* primitives used for cross compilation */
#define hal_read32(a)     ( *( (volatile uint32_t*) (a) ) )
#define hal_write32(a,d)  ( *( (volatile uint32_t*) (a) ) = (d) )
#define hal_wait_for_irq()  do {						\
		while (!irq_received) {/* nothing */}   \
		irq_received = 0;			\
	}while(0)					
#define hal_cpu_relax() do {/* nothing */}while(0)


void microblaze_enable_interrupts(void) {
	__asm("ori     r3, r0, 2\n"
	      "mts     rmsr, r3");
}

#define printf(s)					\
	do {						\
		volatile uint32_t i = 0;		\
		while ((uint8_t) ((s)[i]) != '\0') {	\
			hal_write32(UART_BASEADDR 	\
				+ UART_FIFO_WRITE,	\
			(uint32_t) ((s)[i]));		\
			i++;				\
		}					\
	} while(0)



#endif /* HAL_H */
