/**
 ****************************************************************
 * @file  profile_spi.c
 * @brief a common spi interface
 **************************************************************** 
 */
#include "profile_spi.h"

/**
 * @addtogroup USER_Drivers
 * @{
 */
 
/**
 * @defgroup SPI_INTERFACE Common SPI Interface
 * @{
 */

/**
 * @defgroup SPI_FUNCTIONS_GROUP1 Common SPI Interface
 * @{
 */

uint8_t spi_rw_byte(spi_info_t *spi_info, uint8_t dat)
{
    uint8_t polarity = (spi_info->polarity == 0) ? 0 : 1;
    uint8_t i = 0;
	for(i = 0;i < 8;i++)
	{
        spi_info->spi_mo_output(dat & 0x80);
        dat <<= 1;
        
        spi_info->delay();
        
        if(spi_info->phase != 0)
        {
            if(spi_info->spi_mi_input())
            {
                dat++;
            }
        }  
        
        polarity = polarity ^ 0x01;
        spi_info->spi_clk_output(polarity);
        

        spi_info->delay();

        if(spi_info->phase == 0)
        {
            if(spi_info->spi_mi_input())
            {
                dat++;
            }
        }         
        
        polarity = polarity ^ 0x01;
        spi_info->spi_clk_output(polarity);
        
       
	}
    return dat;
} 

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */



