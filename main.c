/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 9.0.0   2018-04-24

The MIT License (MIT)
Copyright (c) 2018 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"


/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
const uint32_t picture[76800]={0xFFFFFFFF};

int main(void)
{
  int i = 1;
  int count=0;

  /**
  *  IMPORTANT NOTE!
  *  The symbol VECT_TAB_SRAM needs to be defined when building the project
  *  if code has been located to RAM and interrupts are used.
  *  Otherwise the interrupt table located in flash will be used.
  *  See also the <system_*.c> file and how the SystemInit() function updates
  *  SCB->VTOR register.
  *  E.g.  SCB->VTOR = 0x20000000;
  */

  /* TODO - Add your application code here */

  LCD_Init();
  LCD_LayerInit();
  LTDC_Cmd(ENABLE);
  LCD_SetLayer(LCD_FOREGROUND_LAYER);
  LCD_SetColors(LCD_COLOR_RED, LCD_COLOR_WHITE);
  LCD_Clear(LCD_COLOR_WHITE);

  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);



  /* Infinite loop */
  while (1)
  {
	  STM_EVAL_LEDOff(LED3);
	  STM_EVAL_LEDOn(LED4);

	  //LCD_SetTextColor(LCD_COLOR_RED);
	 // LCD_DisplayStringLine(i, "Hello World");
/*
	  if (i%120 != 0)
	  {
		  LCD_DrawFullCircle(120, 160, i%120);
	  }
	  else
	  {
		  count++;

		  if (count%2 != 0)
		  {
		      LCD_SetColors(LCD_COLOR_GREEN, LCD_COLOR_WHITE);
		  }
		  else
		  {
			  LCD_SetColors(LCD_COLOR_RED, LCD_COLOR_WHITE);
		  }
	  }
*/

	  if (i%320 == 0)
	  {
		  LCD_Clear(LCD_COLOR_WHITE);
	  }

	  uint16_t length = (uint16_t)(rand()%240);

	  if (length != 0)
	  {
	      LCD_DrawLine(0, i%320, length, LCD_DIR_HORIZONTAL);
	  }

	  int val = i%3;

	  if (val == 1)
	  {
		  LCD_SetColors(LCD_COLOR_RED, LCD_COLOR_WHITE);
	  }
	  else if (val == 2)
	  {
		  LCD_SetColors(LCD_COLOR_GREEN, LCD_COLOR_WHITE);
	  }
	  else
	  {
		  LCD_SetColors(LCD_COLOR_BLUE, LCD_COLOR_WHITE);
	  }


	  for (int j=0;j<1000000;j++);

	 // LCD_SetTextColor(LCD_COLOR_GREEN);
	 // LCD_DisplayStringLine(i, "Hello World");

	  STM_EVAL_LEDOn(LED3);
	  STM_EVAL_LEDOff(LED4);

	  for (int j=0;j<1000000;j++);

	  i++;
  }

}

/*
 * Callback used by stm324xg_eval_i2c_ee.c.
 * Refer to stm324xg_eval_i2c_ee.h for more info.
 */
uint32_t sEE_TIMEOUT_UserCallback(void)
{
  /* TODO, implement your code here */
  while (1)
  {
  }
}
