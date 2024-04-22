#include "platform_info.h"
#include "ervp_printf.h"
#include "ervp_reg_util.h"
#include <time.h>
#include <stdio.h>

#define OFFSET_FUNC_TABLE 0x00
#define OFFSET_GROVER_ACT 0x100

static inline unsigned int get_addr(unsigned int offset)
{
    return (I_TEST1_SLAVE_BASEADDR + offset);
}


// table_num = 0,1,2, ... ,15
// ex) f(32*1 + 3) = 1 >> table_num = 1, table_bits = 0000....0100
void set_func_table(unsigned int table_bits)
{
    // alligned access of riscv core
    REG32(get_addr(OFFSET_FUNC_TABLE)) = table_bits;
}

int activate_grover_search(void)
{
    return REG32(get_addr(OFFSET_GROVER_ACT));
}
 

int main(void)
{
    int num_success = 0;
    int num_no_solution = 0;
    int i,j;
    int func_table_index;
    int result = 0;
    // clock_t begin, end;

    func_table_index = -1;



    for(j = 0; j <= 8; j++)
    {
        set_func_table(j-1);
        result = activate_grover_search();

        // printf("result = %d", result);
    }

    return result;

}