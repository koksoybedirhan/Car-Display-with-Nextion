The vehicle screen was designed with the Nextion HMI screen to be used in the 2024 Efficiency Challenge Electric Vehicle Races. Arduino and STM32 can be used separately to manage the display, and codes for both are available. With existing codes speed, remaining energy, total volts, max and min volts, max and min temperature, motor driver phase values, current values ​​of each cell in the BMS are read and visually reflected on the screen. Additionally, vehicle mode and screen brightness can be adjusted on the screen.

Version1: It is possible to use a simple version of the Nextion Screen with Arduino.

Version 2: STM32 is used as a relatively more professional display model and microprocessor.

Version 3: It is the version in which data flow is tested using the STM32 processor, potentiometers, temperature, and communication sensors. Additionally, if you want to view the data coming with STM32 through the application on the computer or save it in a text file or Excel file, the application on the "https://github.com/koksoybedirhan/SerialCommunicationApp" website can be downloaded and used.

Main Materials: 
NX4827K043 Display, STM32F411VET6, Arduino Mega.

Test Materials (Version 3): 
BMP180 Pressure Sensor, 10K Potentiometers, LoRa e32900t30d.