/*-----------------------------------------------------------*-
						SENSOR.c (v1.00)
-*-------------------------------------------------------------
	DETALLES:
	� Implementaci�n de las funcionalidades b�sicas del
	  sistema.
	AUTOR:
	- Crespi, Malena Nerea	
-------------------------------------------------------------*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SENSOR.h"
#include "ADC.h"
#include "DISPLAY.h"
#include "PORT.h"
// ------------ DEFINICI�N DE VARIABLES PRIVADAS --------------
static short int temp;	// Almacena la temperatura actual.
/*-----------------------------------------------------------*-
 * SENSOR_Init()
 * 	- Descripci�n: Inicializa el sensor de temperatura.
 * 	- Par�metros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void SENSOR_Init() {
	RTC_Init();
	ADC_Init();
	DISPLAY_Init();
	CTRL_CALEFACTOR = 1;
	CTRL_VENTILADOR = 1;
	PUE_CALEFACTOR = 1;
	PUE_VENTILADOR = 1;
}
/*-----------------------------------------------------------*-
 * SENSOR_Actualizar()
 * 	- Descripci�n: Actualiza el sistema, activando o desacti-
 * 					vando los actuadores seg�n la temperatura
 * 					actual almacenada en 'temp', y actualiza
 * 					el display.
 * 	- Par�metros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void SENSOR_Actualizar() {
	ADCSC1_ADCH = 0;
	while(!ADCSC1_COCO);
	SENSOR_CalcularTemperatura();
	if (temp < 170) {
		VENTILADOR = 0;
		CALEFACTOR = 1;
	} else if ((temp >= 170) && (temp <= 240)) {
		VENTILADOR = 0;
		CALEFACTOR = 0;
	} else if (temp > 240) {
		VENTILADOR = 1;
		CALEFACTOR = 0;
	}
	DISPLAY_Actualizar();
}
/*-----------------------------------------------------------*-
 * SENSOR_CalcularTemperatura()
 * 	- Descripci�n: Calcula la temperatura actual.
 * 	- Par�metros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void SENSOR_CalcularTemperatura() {
	temp = (ADCR * 330UL) / 1024;
}
/*-----------------------------------------------------------*-
 * SENSOR_GetTemperatura()
 * 	- Descripci�n: Devuelve la temperatura actual.
 * 	- Par�metros: Ninguno
 * 	- Retorno: El valor de 'temp' de tipo float.
-*-----------------------------------------------------------*/
short int SENSOR_GetTemperatura() {
	return temp;
}
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
