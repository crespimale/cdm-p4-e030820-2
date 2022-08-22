/*-----------------------------------------------------------*-
						DISPLAY.c (v1.00)
-*-------------------------------------------------------------
	DETALLES:
	� Inicializaci�n y actualizaci�n del display.
	AUTOR:
	- Crespi, Malena Nerea
-------------------------------------------------------------*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SENSOR.h"
#include "DISPLAY.h"
#include "PORT.h"
// ------------ DEFINICI�N DE VARIABLES PRIVADAS --------------
unsigned char DISPLAY_temp[16] = "TEMP: 25.7 �C\0";
/*-----------------------------------------------------------*-
 * DISPLAY_Init()
 * 	- Descripci�n: Inicializa el display.
 * 	- Par�metros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void DISPLAY_Init(){
	CTRL_DISPLAY = 0xFF;
	PUE_DISPLAY	= 0xFF;
}
/*-----------------------------------------------------------*-
 * DISPLAY_Actualizar()
 * 	- Descripci�n: Actualiza el display con la �ltima tempe-
 * 					ratura calculada.
 * 	- Par�metros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void DISPLAY_Actualizar(){
	short int temp = SENSOR_GetTemperatura();
	DISPLAY_temp[9] = (temp % 10) + 48;
	temp /= 10;
	DISPLAY_temp[7] = (temp % 10) + 48;
	temp /= 10;
	DISPLAY_temp[6] = temp + 48;
}
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
