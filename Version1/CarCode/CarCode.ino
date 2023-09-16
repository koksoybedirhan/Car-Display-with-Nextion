#include "Nextion.h"

NexNumber n0 = NexNumber(0, 14, "n0");
NexNumber n8 = NexNumber(0, 81, "n8");
NexGauge z1 = NexGauge(0, 12, "z1");
NexGauge z0 = NexGauge(0, 1, "z0");
NexCheckbox c0 = NexCheckbox(0, 61, "c0");
NexCheckbox c1 = NexCheckbox(0, 62, "c1");
NexCheckbox c2 = NexCheckbox(0, 63, "c2");
NexNumber n1 = NexNumber(0, 18, "n1");
NexNumber n2 = NexNumber(0, 19, "n2");
NexNumber n3 = NexNumber(0, 73, "n3");
NexNumber n4 = NexNumber(0, 74, "n4");
NexNumber n5 = NexNumber(0, 75, "n5");
NexNumber n6 = NexNumber(0, 78, "n6");
NexNumber n7 = NexNumber(0, 79, "n7");
NexNumber ns0 = NexNumber(1, 47, "ns0");
NexNumber ns1 = NexNumber(1, 48, "ns1");
NexNumber ns2 = NexNumber(1, 49, "ns2");
NexNumber ns3 = NexNumber(1, 50, "ns3");
NexNumber ns4 = NexNumber(1, 51, "ns4");
NexNumber ns5 = NexNumber(1, 52, "ns5");
NexNumber ns6 = NexNumber(1, 59, "ns6");
NexNumber ns7 = NexNumber(1, 60, "ns7");
NexNumber ns8 = NexNumber(1, 61, "ns8");
NexNumber ns9 = NexNumber(1, 62, "ns9");
NexNumber ns10 = NexNumber(1, 63, "ns10");
NexNumber ns11 = NexNumber(1, 64, "ns11");
NexNumber ns12 = NexNumber(1, 65, "ns12");
NexNumber ns13 = NexNumber(1, 66, "ns13");
NexNumber ns14 = NexNumber(1, 67, "ns14");
NexNumber ns15 = NexNumber(1, 68, "ns15");
NexNumber ns16 = NexNumber(1, 69, "ns16");
NexNumber ns17 = NexNumber(1, 70, "ns17");
NexNumber ns18 = NexNumber(1, 71, "ns18");
NexNumber ns19 = NexNumber(1, 93, "ns19");
NexProgressBar j0 = NexProgressBar(1, 118, "j0");
NexProgressBar j1 = NexProgressBar(1, 120, "j1");

int NexNumberBatChargeVal = 0;
int NexGaugeBatChargeVal = 0;
int NexNumberSpeedVal = 0;
int NexGaugeSpeedVal = 0;
int NexCheckboxNat = 0;
int NexCheckboxSpeed = 0;
int NexCheckboxCharce = 0;
int NexNumberTempMax = 0;
int NexNumberTempMin = 0;
int NexNumberPhaseOne = 0;
int NexNumberPhaseTwo = 0;
int NexNumberPhaseThree = 0;
int NexNumberTotalVolt = 0;
int NexNumberCurrent = 0;
int NexNumberCellOneVal1 = 0;
int NexNumberCellOneVal2 = 0;
int NexNumberCellOneVal3 = 0;
int NexNumberCellOneVal4 = 0;
int NexNumberCellOneVal5 = 0;
int NexNumberCellOneVal6 = 0;
int NexNumberCellOneVal7 = 0;
int NexNumberCellOneVal8 = 0;
int NexNumberCellOneVal9 = 0;
int NexNumberCellOneVal10 = 0;
int NexNumberCellTwoVal1 = 0;
int NexNumberCellTwoVal2 = 0;
int NexNumberCellTwoVal3 = 0;
int NexNumberCellTwoVal4 = 0;
int NexNumberCellTwoVal5 = 0;
int NexNumberCellTwoVal6 = 0;
int NexNumberCellTwoVal7 = 0;
int NexNumberCellTwoVal8 = 0;
int NexNumberCellTwoVal9 = 0;
int NexNumberCellTwoVal10 = 0;
int NexProgressBarMaxVolt = 0;
int NexProgressBarMinVolt = 0;

void setup(void)
{
  /* Set the baudrate which is for debug and communicate with Nextion screen. */
  dbSerialPrintln("setup begin");
  nexInit();
  dbSerialPrintln("setup done");
  NexNumberSpeedVal = NexNumberSpeedVal+50;
  NexGaugeSpeedVal = NexNumberSpeedVal+17;
 
  n8.setValue(NexNumberSpeedVal);
  z0.setValue(NexGaugeSpeedVal);
  
}

void loop(void)
{
  NexCheckboxSpeed = 1;
  c1.setValue(NexCheckboxSpeed);
  NexCheckboxNat = 0;
  c0.setValue(NexCheckboxNat);
  NexNumberTempMax = 40;
  n1.setValue(NexNumberTempMax);
  NexNumberTempMin = 30;
  n2.setValue(NexNumberTempMin);
  NexNumberPhaseOne = 3;
  n3.setValue(NexNumberPhaseOne);
  NexNumberTotalVolt = 302;
  n6.setValue(NexNumberTotalVolt);
  NexNumberCurrent = 540;
  n7.setValue(NexNumberCurrent);
  NexNumberCellOneVal8 = 1;
  ns7.setValue(NexNumberCellOneVal8);
  if(NexNumberBatChargeVal<120)
  {
     NexNumberBatChargeVal++;
     NexGaugeBatChargeVal = NexNumberBatChargeVal + 30;
     n0.setValue(NexNumberBatChargeVal);
     z1.setValue(NexGaugeBatChargeVal);
     delay(10);
  }
  if(NexProgressBarMaxVolt<80)
  {
    NexProgressBarMaxVolt++;
    j0.setValue(NexGaugeBatChargeVal);
    delay(10);
  }
}
