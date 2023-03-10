
#include <FLASH_PAGE.h>

#define  		ADDRESS_DATA_STORAGE1				0x801F800	// d?a ch? mu?n write vào flash
#define  		ADDRESS_DATA_STORAGE2				0x8019000
#define  		ADDRESS_DATA_STORAGE_FLOAT			0x8023000

/* USER CODE BEGIN PV */
int value;
float vr_read;
/* USER CODE END P */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t data[] = {1,2,3,4,5,6,7,8,9,3}; // d? li?u luu vào flash
uint8_t data1[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8_t buffer[100];
/* USER CODE END 0 */
 Flash_Write_Data((uint32_t)ADDRESS_DATA_STORAGE1, data, sizeof(data));
