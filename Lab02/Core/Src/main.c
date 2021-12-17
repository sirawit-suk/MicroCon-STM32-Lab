/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
GPIO_PinState buttonOnboard = 0;
GPIO_PinState button1 = 1;
GPIO_PinState led1 = 1;
GPIO_PinState loop = 0;
uint8_t led = 0;
int8_t num = 0;
GPIO_PinState special;

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
  /* USER CODE BEGIN 2 */


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */



	  //No.1

//	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1){
//		  isOn = 1;
//		  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
//		  HAL_Delay(1000);
//		  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
//		  isOn = 0;
//	  }

	  //No.2
//	  button1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13); // incoming... 1 (Pull up)
//
//	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET); //led1 force to SET (Pull up)
//	  led1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8); //READ led1
//
//	  if(button1 == 0){
//		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
//		  led1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8); //READ led1
//		  HAL_Delay(1000);
//
//		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
//	  }

	  //No.3
	  buttonOnboard = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0); // (Pull down)
	  button1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13); // incoming... 1 (Pull up)

	  special = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12);

	  //Press switch on board
	  if(buttonOnboard == 1){
		  if(led == 0b10000000){
			  led = 1;
			  num = 0;
			  continue;

		  }else{
			  led = (1 << num); // set bit << how many
			  num++;
		  }
	  }

	  //Press switch peripheral
	  if(button1 == 0){
		  num = 7;
		  loop = 1;
	  }

	  if(loop == 1){

		  led = (1 << num);

		  if(num == -1){
			  loop = 0;
			  num = 0;
			  continue;
		  }

		  num--;
	  }

	  //Lighting
	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_13, !((led >> 0) & 1));
	  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_15, !((led >> 1) & 1));
	  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, !((led >> 2) & 1));
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, !((led >> 3) & 1));
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, !((led >> 4) & 1));
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, !((led >> 5) & 1));
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, !((led >> 6) & 1));
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, !((led >> 7) & 1));

	  HAL_Delay(500);

	  //Behind Lab Question No.1
//	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, !0);

	  //Behind Lab Question No.2
//	  for (uint8_t n=0; n<=2; n++)
//	  {
//		//Light Off		//RESET SET
//		GPIOC -> BSRR = (0x00000700);
//		HAL_Delay(500);
//
//		//Light On
//		GPIOC -> BSRR = (0x04000000 >> n);
//		HAL_Delay(500);
//	  }



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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
