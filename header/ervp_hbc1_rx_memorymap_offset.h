#ifndef __ERVP_HBC1_RX_MEMORYMAP_OFFSET_H__
#define __ERVP_HBC1_RX_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_ERVP_HBC1_RX 8
#define ERVP_HBC1_RX_ADDR_INTERVAL 8
#define BW_UNUSED_ERVP_HBC1_RX 3
#define NUM_ERVP_HBC1_RX_SUBMODULE 3
#define SUBMODULE_INDEX_ERVP_HBC1_RX_HRX_DEMODULATOR 0
#define SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_DEMODULATOR 0x0
#define SUBMODULE_INDEX_ERVP_HBC1_RX_HRX_FRAME 1
#define SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME 0x40
#define SUBMODULE_INDEX_ERVP_HBC1_RX_HRX_AFE 2
#define SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_AFE 0x80

// submodule hrx_demodulator
#define BW_MMAP_SUBOFFSET_HRX_DEMODULATOR 5
#define BW_UNUSED_HRX_DEMODULATOR 3
#define MMAP_SUBOFFSET_HRX_DEMODULATOR_SW_RESET 0x0
#define MMAP_SUBOFFSET_HRX_DEMODULATOR_VERSION 0x8
#define MMAP_SUBOFFSET_HRX_DEMODULATOR_ENABLE 0x10
#define MMAP_SUBOFFSET_HRX_DEMODULATOR_CONFIG 0x18

#define MMAP_OFFSET_HRX_DEMODULATOR_SW_RESET (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_DEMODULATOR+MMAP_SUBOFFSET_HRX_DEMODULATOR_SW_RESET)
#define MMAP_OFFSET_HRX_DEMODULATOR_VERSION (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_DEMODULATOR+MMAP_SUBOFFSET_HRX_DEMODULATOR_VERSION)
#define MMAP_OFFSET_HRX_DEMODULATOR_ENABLE (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_DEMODULATOR+MMAP_SUBOFFSET_HRX_DEMODULATOR_ENABLE)
#define MMAP_OFFSET_HRX_DEMODULATOR_CONFIG (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_DEMODULATOR+MMAP_SUBOFFSET_HRX_DEMODULATOR_CONFIG)

// submodule hrx_frame
#define BW_MMAP_SUBOFFSET_HRX_FRAME 6
#define BW_UNUSED_HRX_FRAME 3
#define MMAP_SUBOFFSET_HRX_FRAME_STATUS 0x0
#define MMAP_SUBOFFSET_HRX_FRAME_CLEAR 0x8
#define MMAP_SUBOFFSET_HRX_FRAME_CORR 0x10
#define MMAP_SUBOFFSET_HRX_FRAME_HEADER 0x18
#define MMAP_SUBOFFSET_HRX_FRAME_DATA_OUTPUT 0x20

#define MMAP_OFFSET_HRX_FRAME_STATUS (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME+MMAP_SUBOFFSET_HRX_FRAME_STATUS)
#define MMAP_OFFSET_HRX_FRAME_CLEAR (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME+MMAP_SUBOFFSET_HRX_FRAME_CLEAR)
#define MMAP_OFFSET_HRX_FRAME_CORR (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME+MMAP_SUBOFFSET_HRX_FRAME_CORR)
#define MMAP_OFFSET_HRX_FRAME_HEADER (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME+MMAP_SUBOFFSET_HRX_FRAME_HEADER)
#define MMAP_OFFSET_HRX_FRAME_DATA_OUTPUT (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_FRAME+MMAP_SUBOFFSET_HRX_FRAME_DATA_OUTPUT)

// submodule hrx_afe
#define BW_MMAP_SUBOFFSET_HRX_AFE 3
#define BW_UNUSED_HRX_AFE 3
#define MMAP_SUBOFFSET_HRX_AFE_CONFIG 0x0

#define MMAP_OFFSET_HRX_AFE_CONFIG (SUBMODULE_ADDR_ERVP_HBC1_RX_HRX_AFE+MMAP_SUBOFFSET_HRX_AFE_CONFIG)

// reg hrx_frame.status
#define BW_HRX_FRAME_STATUS 3
#define HRX_FRAME_STATUS_BIT_VALID 1
#define HRX_FRAME_STATUS_BIT_HEAD_CRC 2
#define HRX_FRAME_STATUS_BIT_DATA_CRC 4
#define HRX_FRAME_STATUS_INVALID 0
#define HRX_FRAME_STATUS_VALID_NO_CRC 1
#define HRX_FRAME_STATUS_VALID_HEAD_CRC 3
#define HRX_FRAME_STATUS_VALID_DATA_CRC 5

// reg hrx_demodulator.sw_reset
#define BW_HRX_DEMODULATOR_SW_RESET 1

// reg hrx_demodulator.version
#define BW_HRX_DEMODULATOR_VERSION 32

// reg hrx_demodulator.enable
#define BW_HRX_DEMODULATOR_ENABLE 1

// reg hrx_demodulator.config
#define BW_HRX_DEMODULATOR_CONFIG 32

// reg hrx_frame.clear
#define BW_HRX_FRAME_CLEAR 1

// reg hrx_frame.corr
#define BW_HRX_FRAME_CORR 16

// reg hrx_frame.header
#define BW_HRX_FRAME_HEADER 32

// reg hrx_frame.data_output
#define BW_HRX_FRAME_DATA_OUTPUT 32

// reg hrx_afe.config
#define BW_HRX_AFE_CONFIG 32

// reg power_mode
#define BW_POWER_MODE 1
#define POWER_MODE_NORMAL 0
#define POWER_MODE_POWER_DOWN 1

#endif