/*
 *  \author Duarte Santos (113304)
 */

#include "somm24.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{

// ================================================================================== //

    void jdtPrint(FILE *fout)
    {
        soProbe(203, "%s(%p)\n", __func__, fout);

        require(jdtIn != UNDEF_JOB_INDEX and jdtOut != UNDEF_JOB_INDEX, "Module is not in a valid open state!");
        require(jdtCount != UNDEF_JOB_COUNT, "Module is not in a valid open state!");
        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        fprintf(fout, "+=====================================+\n");
        fprintf(fout, "|          JDT module state           |\n");
        fprintf(fout, "+------------+------------+-----------+\n");
        fprintf(fout, "| submission |  lifetime  |  memory   |\n");
        fprintf(fout, "|    time    |            | requested |\n");
        fprintf(fout, "+------------+------------+-----------+\n");

        // Iterate over the job table and print each entry
        ushort currentOut = jdtOut;
        for (ushort i = 0; i < jdtCount; ++i) {
            size_t index = currentOut % MAX_JOBS; // Wrap around circular buffer
            fprintf(fout, "| %10.1f | %10.1f | %#9x |\n", 
                    jdtTable[index].submissionTime, 
                    jdtTable[index].lifetime, 
                    jdtTable[index].memSize);

            currentOut = (currentOut + 1) % MAX_JOBS; // Move to next index
        }

        // Print footer
        fprintf(fout, "+=====================================+\n");
    }

// ================================================================================== //

} // end of namespace group
