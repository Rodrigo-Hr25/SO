/*
 *  Rodrigo Moço, 108939
 */

#include "somm24.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{

    /* Rodrigo Moço, 108939 */
// ================================================================================== //

    void memPrint(FILE *fout)
    {
        soProbe(403, "%s(\"%p\")\n", __func__, fout);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");
        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        fprintf(fout, "+===============================+\n");
        fprintf(fout, "|       MEM module state        |\n");
        if (memAllocationPolicy == WorstFit) {
            fprintf(fout, "|          (WorstFit)           |\n");
        } else {
            fprintf(fout, "|           (BestFit)           |\n");
        }
        fprintf(fout, "+-------------------------------+\n");
        fprintf(fout, "|         occupied list         |\n");
        fprintf(fout, "+---------------+---------------+\n");
        fprintf(fout, "|  start frame  |     size      |\n");
        fprintf(fout, "+---------------+---------------+\n");
        for (auto occupied = memOccupiedList; occupied != nullptr; occupied = occupied->next) {
            fprintf(fout, "| %#13x | %#13x |\n", occupied->block.start, occupied->block.size);
        }
        fprintf(fout, "+---------------+---------------+\n");
        fprintf(fout, "|            free list          |\n");
        fprintf(fout, "+---------------+---------------+\n");
        fprintf(fout, "|  start frame  |     size      |\n");
        fprintf(fout, "+---------------+---------------+\n");
        for (auto free = memFreeList; free != nullptr; free = free->next) {
            fprintf(fout, "| %#13x | %#13x |\n", free->block.start, free->block.size);
        }
        fprintf(fout, "+===============================+\n");
    }

// ================================================================================== //

} // end of namespace group

