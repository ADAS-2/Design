
/**
  ***************************************************************************************************************
  ***************************************************************************************************************
  ***************************************************************************************************************
  File:	      FLASH_PAGE_F1.h
  ***************************************************************************************************************

  ***************************************************************************************************************
*/

#ifndef INC_FLASH_PAGE_F1_H_
#define INC_FLASH_PAGE_F1_H_

#include "stm32l4xx_hal.h"


uint32_t Flash_Write_Data (uint32_t StartPageAddress, uint8_t *Data, uint32_t data_length);
void Flash_Read_Data (uint32_t StartPageAddress, uint8_t *destination, uint16_t length_inByte);
void Flash_Write_NUM (uint32_t StartSectorAddress, float Num);
float Flash_Read_NUM (uint32_t StartSectorAddress);


#endif /* INC_FLASH_PAGE_F1_H_ */
