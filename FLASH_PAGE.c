
/**
  ***************************************************************************************************************
  ***************************************************************************************************************
  ***************************************************************************************************************
  File:	      FLASH_PAGE_F1.c
  ***************************************************************************************************************

  ***************************************************************************************************************
*/

#include <FLASH_PAGE.h>
#include "string.h"
#include "stdio.h"


/* FLASH_PAGE_SIZE should be able to get the size of the Page according to the controller */

// quanDH
static uint32_t GetPage(uint32_t Address)
{
  for (int indx=0; indx<256; indx++)
  {
	  if((Address < (0x08000000 + (FLASH_PAGE_SIZE *(indx+1))) ) && (Address >= (0x08000000 + FLASH_PAGE_SIZE*indx)))
	  {
		  return indx;
	  }
  }

  return 0;
}


uint8_t bytes_temp[4];


void float2Bytes(uint8_t * ftoa_bytes_temp,float float_variable)
{
    union {
      float a;
      uint8_t bytes[4];
    } thing;

    thing.a = float_variable;

    for (uint8_t i = 0; i < 4; i++) {
      ftoa_bytes_temp[i] = thing.bytes[i];
    }

}

float Bytes2float(uint8_t * ftoa_bytes_temp)
{
    union {
      float a;
      uint8_t bytes[4];
    } thing;

    for (uint8_t i = 0; i < 4; i++) {
    	thing.bytes[i] = ftoa_bytes_temp[i];
    }

   float float_variable =  thing.a;
   return float_variable;
}

void Flash_erase(uint32_t Page){
    static FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t PAGEError;
	/* Fill EraseInit structure*/
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.Page = Page;
	EraseInitStruct.NbPages = 1;
    EraseInitStruct.Banks = 1;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
	{
	   /*Error occurred while page erase.*/
	   return HAL_FLASH_GetError();
	}
}

uint32_t Flash_Write_Data (uint32_t StartPageAddress, uint8_t *Data, uint32_t data_length)
{
	uint8_t	*temp_data_address;
	uint16_t i=0;
	uint64_t writeval=0, writetime=0;
	uint32_t	temp_write_address;

	temp_data_address = Data;
	temp_write_address = StartPageAddress;

	  /* Unlock the Flash to enable the flash control register access *************/
	if(data_length%8 == 0){
		//Calculate number of word to write
		writetime = data_length / 8;
		HAL_FLASH_Unlock();
	   /* Erase the user Flash area*/
	   uint32_t Page = GetPage(StartPageAddress);
	   Flash_erase(Page);
	   for (i = 0;i<writetime;i++)
		{
			writeval = *(__IO uint64_t*)(temp_data_address);
		   /* Program the user Flash area word by word*/
			 if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, temp_write_address, writeval) == HAL_OK)
			 {
				 temp_write_address += 8;  // use StartPageAddress += 2 for half word and 8 for double word
				 temp_data_address += 8;
			 }
			 else
			 {
			   /* Error occurred while writing data in Flash memory*/
				 return HAL_FLASH_GetError ();
			 }

		}
	   /* Lock the Flash to disable the flash control register access (recommended
	      to protect the FLASH memory against possible unwanted operation) *********/
	   HAL_FLASH_Lock();
	   }
	   return 0;
}


void Flash_Read_Data (uint32_t StartPageAddress, uint8_t *destination, uint16_t length_inByte)
{
		uint16_t i=0;
		uint32_t temp_address;
		uint8_t *temp_destination;

		temp_address = StartPageAddress;
		temp_destination = destination;

		for (i=0;i<length_inByte;i++)
		{
			*temp_destination = *(__IO uint8_t*)temp_address;
			temp_destination++;
			temp_address++;
		}
}


void Flash_Write_NUM (uint32_t StartSectorAddress, float Num)
{

	float2Bytes(bytes_temp, Num);
	Flash_Write_Data (StartSectorAddress, (uint32_t *)bytes_temp, 1);
}


float Flash_Read_NUM (uint32_t StartSectorAddress)
{
	uint8_t buffer[4];
	float value;

	Flash_Read_Data(StartSectorAddress, (uint32_t *)buffer, 1);
	value = Bytes2float(buffer);
	return value;
}
