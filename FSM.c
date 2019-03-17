/*  Carlos Leonel Romo Villaseñor
*/

/*
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    FSM.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */


#define On 1
#define Off 0

typedef enum          //Kind of states
	{
	 Normal,
	 AirConditionerSystem,
	 HeatingSystem
	}state_position;

typedef enum
	{temperature_fresh,
	 temperature_medium,
	 temperature_hot
	}temperature;

typedef enum
	{
	False,
	True,	I
	}E_BOOl;

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */

    static int reset = True;
    static int state = Normal;
    static int next_state = Normal;
    static int sensor = Off;
    static int Led_Green = Off;
    static int Led_Blue = Off;
    static int Led_Red = Off;
    static int heating = Off;
    static int cooling = Off;

    if (reset == True)
    {   Led_Green = Off;
    	Led_Blue = Off;
    	Led_Red = Off;
    	reset = False;
    }
    while(1) {

    switch(state)
    {
    case Normal: 	if(sensor < temperature_fresh)
    			{
    				 Led_Green = Off;
    	    	 	 Led_Blue = On;
    	    	 	 Led_Red = Off;
    				 heating = On;
    				 state = HeatingSystem;
    			}
    			else if(sensor > temperature_hot)
    			{

        			 Led_Green = Off;
        	    	 Led_Blue = Off;
        	    	 Led_Red = On;
        	    	 cooling = On;
        			 next_state = AirConditionerSystem;
        			 state = next_state;
    			}
    			else
    			{
    				Led_Green = On;
    				Led_Blue = Off;
    				Led_Red = Off;
    				cooling = Off;
    				heating = Off;
    				next_state = Normal;
    				state = next_state;
    			}
    			break;


	AirConditionerSystem: if(sensor < temperature_medium)
				{
					Led_Green = On;
					Led_Blue = Off;
					Led_Red = Off;
					cooling = Off;
					next_state = Normal;
					state = next_state;
				}

				else
				{
					Led_Green = Off;
					Led_Blue = Off;
					Led_Red = On;
					cooling = On;
					next_state = AirConditionerSystem;
					state = next_state;
				}
	  	  	  	  break;


    case HeatingSystem:  if(sensor > temperature_medium)
				{
    				 Led_Green = On;
		 	 	 	 Led_Blue = Off;
		 	 	 	 Led_Red = Off;
					 heating = Off;
					 next_state = Normal;
					 state = next_state;
				}

				else
				{
   				     Led_Green = Off;
		 	 	 	 Led_Blue = On;
		 	 	 	 Led_Red = Off;
					 heating = On;
					 next_state = HeatingSystem;
					 state = next_state;
				}
     	 	 	 	 break;

    default: state = Normal;
    			break;
    	}

        i++ ;
    }
    return 0 ;
}
