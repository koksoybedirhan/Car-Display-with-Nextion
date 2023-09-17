/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART6_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
uint16_t speedvalue=0;
uint16_t fuelvalue=0;
uint16_t totalvoltvalue=0;
uint16_t totalcurrentvalue=0;
uint16_t maxtempvalue=0;
uint16_t mintempvalue=0;
uint16_t maxvoltvalue=0;
uint16_t minvoltvalue=0;
uint16_t phase1value=0;
uint16_t phase2value=0;
uint16_t phase3value=0;
uint16_t cell1num1value=0;
uint16_t cell1num2value=0;
uint16_t cell1num3value=0;
uint16_t cell1num4value=0;
uint16_t cell1num5value=0;
uint16_t cell1num6value=0;
uint16_t cell1num7value=0;
uint16_t cell1num8value=0;
uint16_t cell1num9value=0;
uint16_t cell1num10value=0;
uint16_t cell2num1value=0;
uint16_t cell2num2value=0;
uint16_t cell2num3value=0;
uint16_t cell2num4value=0;
uint16_t cell2num5value=0;
uint16_t cell2num6value=0;
uint16_t cell2num7value=0;
uint16_t cell2num8value=0;
uint16_t cell2num9value=0;
uint16_t cell2num10value=0;


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART6_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(speedvalue < 288)
	  {
		  SpeedGauge("z0.val", speedvalue);

		  float speedFloat = ((float)speedvalue/288.0)*100;
		  SpeedNum("n1.val", speedFloat);

		  speedvalue++;

		  HAL_Delay (10);
	  }

	  if(fuelvalue < 180)
	  {
		  FuelGauge("z1.val", fuelvalue);
		  FuelNum("n0.val", fuelvalue);
		  fuelvalue++;
		  HAL_Delay(10);
	  }

	  if(totalvoltvalue<50)
	  {
		  TotalVoltNum("n2.val", totalvoltvalue);
		  totalvoltvalue++;
		  HAL_Delay(10);
	  }

	  if(maxtempvalue<500)
	  {
		  TotalVoltNum("n0s.val", maxtempvalue);
		  maxtempvalue++;
		  HAL_Delay(10);
	  }

	  if(cell1num1value<100)
	  {
		  Cell1Num1Num("n0t.val", cell1num1value);
		  cell1num1value++;
		  HAL_Delay(10);
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 9600;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
