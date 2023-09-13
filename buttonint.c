

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "buttonint.h"
#include "led.h"
#include "extint.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Button interrupt Handler
  * @retval none
  */
void vButtonIntHandler(void)
{
	/* For re enabling for next interrupt or clearing the current interrupt */
	vExtIntSel(EINT0,EXTINTENABLE);

	/* When interrupt occurs the leds will be ON */
	vLedOn(LED_0);
	vLedOn(LED_1);
	vLedOn(LED_2);

}
/**
  * @brief Initializing the button as external interrupt
  * @return None
  **/
void vButtonIntInitialize(void)
{
	vExtIntInitialize(EINT0);
	vExtIntAttachCallback(EINT0,vButtonIntHandler);
}
