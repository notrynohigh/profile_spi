/**
 ****************************************************************
 * @file  profile_spi.h
 * @brief a common spi interface
 **************************************************************** 
 */
#ifndef __PROFILE_SPI_H__
#define __PROFILE_SPI_H__


#include "stdint.h"
/**
 * @addtogroup USER_Drivers
 * @{
 */
 
/**
 * @addtogroup SPI_INTERFACE
 * @{
 */
 

/**
 * @brief SPI interface
 */
typedef struct
{
	uint8_t polarity;                        /**< 0 or 1  */
	uint8_t phase;                           /**< 0 or 1  */
	void (*spi_clk_output)(uint8_t);         /**< control clock pin */
	void (*spi_mo_output)(uint8_t);          /**< control mo pin */
	uint8_t (*spi_mi_input)();               /**< read mi pin */
	void (*delay)();                       
}spi_info_t;

/**
 * @addtogroup SPI_FUNCTIONS_GROUP1
 * @{
 */

uint8_t spi_rw_byte(spi_info_t *spi_info, uint8_t dat);


/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#endif


