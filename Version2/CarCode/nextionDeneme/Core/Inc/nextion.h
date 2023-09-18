/*
 * nextion.h
 *
 *  Created on: 18 Eyl 2023
 *      Author: Lenovo
 */

#ifndef INC_NEXTION_H_
#define INC_NEXTION_H_

#include <stdio.h>
#include "stm32f4xx_hal.h"

extern uint16_t speedvalue;
extern uint16_t fuelvalue;
extern uint16_t totalvoltvalue;
extern uint16_t totalcurrentvalue;
extern uint16_t maxtempvalue;
extern uint16_t mintempvalue;
extern uint16_t maxvoltvalue;
extern uint16_t minvoltvalue;
extern uint16_t phase1value;
extern uint16_t phase2value;
extern uint16_t phase3value;
extern uint16_t cell1num1value;
extern uint16_t cell1num2value;
extern uint16_t cell1num3value;
extern uint16_t cell1num4value;
extern uint16_t cell1num5value;
extern uint16_t cell1num6value;
extern uint16_t cell1num7value;
extern uint16_t cell1num8value;
extern uint16_t cell1num9value;
extern uint16_t cell1num10value;
extern uint16_t cell2num1value;
extern uint16_t cell2num2value;
extern uint16_t cell2num3value;
extern uint16_t cell2num4value;
extern uint16_t cell2num5value;
extern uint16_t cell2num6value;
extern uint16_t cell2num7value;
extern uint16_t cell2num8value;
extern uint16_t cell2num9value;
extern uint16_t cell2num10value;
extern float speedFloat;

void SpeedGauge (char *obj, uint16_t speedvalue);

void SpeedNum (char *obj, uint16_t speedvalue);

void FuelGauge (char *obj, uint16_t fuelvalue);

void FuelNum (char *obj, uint16_t fuelvalue);

void TotalVoltNum (char *obj, uint16_t totalvoltvalue);

void TotalCurrentNum (char *obj, uint16_t totalcurrentvalue);

void MaxTempNum (char *obj, uint16_t maxtempvalue);

void MinTempNum (char *obj, uint16_t mintempvalue);

void MaxVoltNum (char *obj, uint16_t maxvoltvalue);

void MinVoltNum (char *obj, uint16_t minvoltvalue);

void Phase1Num (char *obj, uint16_t phase1value);

void Phase2Num (char *obj, uint16_t phase2value);

void Phase3Num (char *obj, uint16_t phase3value);

void Cell1Num1Num (char *obj, uint16_t cell1num1value);

void Cell1Num2Num (char *obj, uint16_t cell1num2value);


#endif /* INC_NEXTION_H_ */
