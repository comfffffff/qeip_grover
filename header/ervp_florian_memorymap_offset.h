#ifndef __ERVP_FLORIAN_MEMORYMAP_OFFSET_H__
#define __ERVP_FLORIAN_MEMORYMAP_OFFSET_H__



// total
#define BW_MMAP_OFFSET_ERVP_FLORIAN 5
#define ERVP_FLORIAN_ADDR_INTERVAL 8
#define BW_UNUSED_ERVP_FLORIAN 3
#define NUM_ERVP_FLORIAN_SUBMODULE 1

// submodule florian
#define MMAP_SUBOFFSET_FLORIAN_INPUT 0x0
#define MMAP_SUBOFFSET_FLORIAN_OUTPUT 0x8
#define MMAP_SUBOFFSET_FLORIAN_OUTPUT_VALID_NUM 0x10

#define MMAP_OFFSET_FLORIAN_INPUT (MMAP_SUBOFFSET_FLORIAN_INPUT)
#define MMAP_OFFSET_FLORIAN_OUTPUT (MMAP_SUBOFFSET_FLORIAN_OUTPUT)
#define MMAP_OFFSET_FLORIAN_OUTPUT_VALID_NUM (MMAP_SUBOFFSET_FLORIAN_OUTPUT_VALID_NUM)

// reg florian.input
#define BW_FLORIAN_INPUT 32

// reg florian.output
#define BW_FLORIAN_OUTPUT 32

// reg florian.output_valid_num
#define BW_FLORIAN_OUTPUT_VALID_NUM 2

// reg florian_op
#define BW_FLORIAN_OP 5
#define FLORIAN_OP_CONV 1
#define FLORIAN_OP_ADD 2
#define FLORIAN_OP_SUB 4
#define FLORIAN_OP_MULT 8
#define FLORIAN_OP_DIV 16
#define FLORIAN_OP_INDEX_CONV 0
#define FLORIAN_OP_INDEX_ADD 1
#define FLORIAN_OP_INDEX_SUB 2
#define FLORIAN_OP_INDEX_MULT 3
#define FLORIAN_OP_INDEX_DIV 4
#define FLORIAN_OP_NONE 0

// reg florian_value_type
#define BW_FLORIAN_VALUE_TYPE 2
#define FLORIAN_VALUE_TYPE_SI32 0
#define FLORIAN_VALUE_TYPE_UI32 1
#define FLORIAN_VALUE_TYPE_F32 2
#define FLORIAN_VALUE_TYPE_F64 3
#define FLORIAN_VALUE_TYPE_INDEX_UI32 0
#define FLORIAN_VALUE_TYPE_INDEX_F32 1

// reg florian_state
#define BW_FLORIAN_STATE 3
#define FLORIAN_STATE_WAIT 0
#define FLORIAN_STATE_ARGS 1
#define FLORIAN_STATE_CAL 2
#define FLORIAN_STATE_NORMALIZE 3
#define FLORIAN_STATE_ENCODE 4
#define FLORIAN_STATE_RETURN 5
#define FLORIAN_STATE_INDEX_ARGS 0
#define FLORIAN_STATE_INDEX_CAL 1
#define FLORIAN_STATE_INDEX_ENCODE 2

#endif