/*
 * nextion.c
 *
 *  Created on: 18 Eyl 2023
 *      Author: Lenovo
 */

#include "nextion.h"

extern UART_HandleTypeDef huart6;

uint8_t Cmd_End[3] = {0xFF,0xFF,0xFF};  // command end sequence

void SpeedGauge (char *obj, uint16_t speedvalue)
{
	char buf[30];
	speedvalue = speedvalue + 306;
	if (speedvalue >= 360) speedvalue = speedvalue-360;

	int len = sprintf (buf, "%s=%u", obj, speedvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void SpeedNum (char *obj, uint16_t speedvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, speedvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void FuelGauge (char *obj, uint16_t fuelvalue)
{
	char buf[30];
	if (fuelvalue >= 360) fuelvalue = fuelvalue-360;

	int len = sprintf (buf, "%s=%u", obj, fuelvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void FuelNum (char *obj, uint16_t fuelvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, fuelvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void TotalVoltNum (char *obj, uint16_t totalvoltvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, totalvoltvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void TotalCurrentNum (char *obj, uint16_t totalcurrentvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, totalcurrentvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void MaxTempNum (char *obj, uint16_t maxtempvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, maxtempvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void MinTempNum (char *obj, uint16_t mintempvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, mintempvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void MaxVoltNum (char *obj, uint16_t maxvoltvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, maxvoltvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void MinVoltNum (char *obj, uint16_t minvoltvalue)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, minvoltvalue);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void Phase1Num (char *obj, uint16_t phase1value)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, phase1value);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void Phase2Num (char *obj, uint16_t phase2value)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, phase2value);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void Phase3Num (char *obj, uint16_t phase3value)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, phase3value);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void Cell1Num1Num (char *obj, uint16_t cell1num1value)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, cell1num1value);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}

void Cell1Num2Num (char *obj, uint16_t cell1num2value)
{
	char buf[30];
	int len = sprintf (buf, "%s=%u", obj, cell1num2value);
	HAL_UART_Transmit(&huart6, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart6, Cmd_End, 3, 1000);
}


