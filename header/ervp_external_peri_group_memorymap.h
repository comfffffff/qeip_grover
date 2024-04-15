#ifndef __ERVP_EXTERNAL_PERI_GROUP_MEMORYMAP_H__
#define __ERVP_EXTERNAL_PERI_GROUP_MEMORYMAP_H__

#include "platform_info.h"
#include "ervp_external_peri_group_memorymap_offset.h"

#define MMAP_SUBMODULE_EPG_MISC (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_EPG_MISC)
#define MMAP_SUBMODULE_UART0 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_UART0)
#define MMAP_SUBMODULE_UART1 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_UART1)
#define MMAP_SUBMODULE_UART2 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_UART2)
#define MMAP_SUBMODULE_UART3 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_UART3)
#define MMAP_SUBMODULE_I2C0 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C0)
#define MMAP_SUBMODULE_I2C1 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C1)
#define MMAP_SUBMODULE_I2C2 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C2)
#define MMAP_SUBMODULE_I2C3 (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_I2C3)
#define MMAP_SUBMODULE_SPI (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_SPI)
#define MMAP_SUBMODULE_GPIO (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_GPIO)
#define MMAP_SUBMODULE_SPIO (EXTERNAL_PERI_GROUP_BASEADDR+SUBMODULE_ADDR_ERVP_EXTERNAL_PERI_GROUP_SPIO)

// submodule epg_misc
#define MMAP_EPG_MISC_EXTREG00 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG00)
#define MMAP_EPG_MISC_EXTREG01 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG01)
#define MMAP_EPG_MISC_EXTREG02 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG02)
#define MMAP_EPG_MISC_EXTREG03 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG03)
#define MMAP_EPG_MISC_EXTREG04 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG04)
#define MMAP_EPG_MISC_EXTREG05 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG05)
#define MMAP_EPG_MISC_EXTREG06 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG06)
#define MMAP_EPG_MISC_EXTREG07 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_EXTREG07)
#define MMAP_EPG_MISC_GPIO_TICK_CFG (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_EPG_MISC_GPIO_TICK_CFG)

// submodule uart0

// submodule uart1

// submodule uart2

// submodule uart3

// submodule i2c0

// submodule i2c1

// submodule i2c2

// submodule i2c3

// submodule spi

// submodule gpio
#define MMAP_GPIO_USER_GPIO00 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO00)
#define MMAP_GPIO_USER_GPIO01 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO01)
#define MMAP_GPIO_USER_GPIO02 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO02)
#define MMAP_GPIO_USER_GPIO03 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO03)
#define MMAP_GPIO_USER_GPIO04 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO04)
#define MMAP_GPIO_USER_GPIO05 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO05)
#define MMAP_GPIO_USER_GPIO06 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO06)
#define MMAP_GPIO_USER_GPIO07 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO07)
#define MMAP_GPIO_USER_GPIO08 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO08)
#define MMAP_GPIO_USER_GPIO09 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO09)
#define MMAP_GPIO_USER_GPIO10 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO10)
#define MMAP_GPIO_USER_GPIO11 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO11)
#define MMAP_GPIO_USER_GPIO12 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO12)
#define MMAP_GPIO_USER_GPIO13 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO13)
#define MMAP_GPIO_USER_GPIO14 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO14)
#define MMAP_GPIO_USER_GPIO15 (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_GPIO_USER_GPIO15)

// submodule spio
#define MMAP_SPIO_OLED_DCSEL (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_OLED_DCSEL)
#define MMAP_SPIO_OLED_RSTNN (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_OLED_RSTNN)
#define MMAP_SPIO_OLED_VBAT (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_OLED_VBAT)
#define MMAP_SPIO_OLED_VDD (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_OLED_VDD)
#define MMAP_SPIO_WIFI_RSTNN (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_WIFI_RSTNN)
#define MMAP_SPIO_WIFI_WP (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_WIFI_WP)
#define MMAP_SPIO_WIFI_HIBERNATE (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_WIFI_HIBERNATE)
#define MMAP_SPIO_WIFI_ITR_CLEAR (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_WIFI_ITR_CLEAR)
#define MMAP_SPIO_WIFI_ITR_PENDING (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_WIFI_ITR_PENDING)
#define MMAP_SPIO_SPI_CS_ACTIVE_LOW (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_SPI_CS_ACTIVE_LOW)
#define MMAP_SPIO_SPI_SELECT (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_SPI_SELECT)
#define MMAP_SPIO_AIOIF_CONFIG (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_AIOIF_CONFIG)
#define MMAP_SPIO_SERIAL_COMM_CONTROL (EXTERNAL_PERI_GROUP_BASEADDR+MMAP_OFFSET_SPIO_SERIAL_COMM_CONTROL)

// reg spio.spi_cs_active_low
// BW_SPIO_SPI_CS_ACTIVE_LOW 32

// reg spio.serial_comm_control
// BW_SPIO_SERIAL_COMM_CONTROL 4
// SPIO_SERIAL_COMM_CONTROL_SPI_CLK_USER_OE 1
// SPIO_SERIAL_COMM_CONTROL_SPI_CLK_USER_VALUE 2
// SPIO_SERIAL_COMM_CONTROL_SPI_DQ0_USER_OE 4
// SPIO_SERIAL_COMM_CONTROL_SPI_DQ0_USER_VALUE 8
// SPIO_SERIAL_COMM_CONTROL_INDEX_SPI_CLK_USER_OE 0
// SPIO_SERIAL_COMM_CONTROL_INDEX_SPI_CLK_USER_VALUE 1
// SPIO_SERIAL_COMM_CONTROL_INDEX_SPI_DQ0_USER_OE 2
// SPIO_SERIAL_COMM_CONTROL_INDEX_SPI_DQ0_USER_VALUE 3
// SPIO_SERIAL_COMM_CONTROL_NONE 0

// reg epg_misc.extreg
// BW_EPG_MISC_EXTREG 32

// reg epg_misc.gpio_tick_cfg
// BW_EPG_MISC_GPIO_TICK_CFG 16

// reg gpio.user_gpio
// BW_GPIO_USER_GPIO 32

// reg spio.oled_dcsel
// BW_SPIO_OLED_DCSEL 1

// reg spio.oled_rstnn
// BW_SPIO_OLED_RSTNN 1

// reg spio.oled_vbat
// BW_SPIO_OLED_VBAT 1

// reg spio.oled_vdd
// BW_SPIO_OLED_VDD 1

// reg spio.wifi_rstnn
// BW_SPIO_WIFI_RSTNN 1

// reg spio.wifi_wp
// BW_SPIO_WIFI_WP 1

// reg spio.wifi_hibernate
// BW_SPIO_WIFI_HIBERNATE 1

// reg spio.wifi_itr_clear
// BW_SPIO_WIFI_ITR_CLEAR 1

// reg spio.wifi_itr_pending
// BW_SPIO_WIFI_ITR_PENDING 1

// reg spio.spi_select
// BW_SPIO_SPI_SELECT 32

// reg spio.aioif_config
// BW_SPIO_AIOIF_CONFIG 32

// reg oled_dc_sel
// BW_OLED_DC_SEL 1
// OLED_DC_SEL_COMMAND 0
// OLED_DC_SEL_DATA 1
// OLED_DC_SEL_INDEX_DATA 0

// reg ocd_flash_cmd
// BW_OCD_FLASH_CMD 3
// OCD_FLASH_CMD_IDLE 0
// OCD_FLASH_CMD_CHECK 1
// OCD_FLASH_CMD_ERASE 2
// OCD_FLASH_CMD_READ 3
// OCD_FLASH_CMD_WRITE 4
// OCD_FLASH_CMD_INDEX_CHECK 0
// OCD_FLASH_CMD_INDEX_ERASE 1
// OCD_FLASH_CMD_INDEX_WRITE 2

// reg boot_status
// BW_BOOT_STATUS 2
// BOOT_STATUS_RESETED 0
// BOOT_STATUS_APP_LOAD 1
// BOOT_STATUS_ALL_READY 2
// BOOT_STATUS_INDEX_APP_LOAD 0
// BOOT_STATUS_INDEX_ALL_READY 1

// reg gpio_config
// BW_GPIO_CONFIG 5
// GPIO_CONFIG_IS_SIGNED_VALUE 1
// GPIO_CONFIG_IS_OUTPUT_PORT 2
// GPIO_CONFIG_ITR_ENABLE 4
// GPIO_CONFIG_DEBOUNCE_ENABLE 8
// GPIO_CONFIG_USER_IO_SELECT 16
// GPIO_CONFIG_INDEX_IS_SIGNED_VALUE 0
// GPIO_CONFIG_INDEX_IS_OUTPUT_PORT 1
// GPIO_CONFIG_INDEX_ITR_ENABLE 2
// GPIO_CONFIG_INDEX_DEBOUNCE_ENABLE 3
// GPIO_CONFIG_INDEX_USER_IO_SELECT 4
// GPIO_CONFIG_NONE 0

// reg gpio_cmd
// BW_GPIO_CMD 4
// GPIO_CMD_WE_VALUE 1
// GPIO_CMD_WE_CONFIG 2
// GPIO_CMD_WE_ITR_COND 4
// GPIO_CMD_CLEAR_ITR 8
// GPIO_CMD_INDEX_WE_VALUE 0
// GPIO_CMD_INDEX_WE_CONFIG 1
// GPIO_CMD_INDEX_WE_ITR_COND 2
// GPIO_CMD_INDEX_CLEAR_ITR 3
// GPIO_CMD_NONE 0

// reg aioif_type
// BW_AIOIF_TYPE 4
// AIOIF_TYPE_GPIO 1
// AIOIF_TYPE_I2C 2
// AIOIF_TYPE_SPI 4
// AIOIF_TYPE_UART 8
// AIOIF_TYPE_INDEX_GPIO 0
// AIOIF_TYPE_INDEX_I2C 1
// AIOIF_TYPE_INDEX_SPI 2
// AIOIF_TYPE_INDEX_UART 3
// AIOIF_TYPE_NONE 0

// reg gpio_value
// BW_GPIO_VALUE 16

#endif