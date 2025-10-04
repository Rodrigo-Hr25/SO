/*
 *  \author Duarte Santos 113304
 */

#include "somm24.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{
    
    /* \author Duarte Santos 113304 */
// ================================================================================== //

    void simPrint(FILE *fout, uint32_t satelliteModules)
    {
        soProbe(103, "%s(\"%p\")\n", __func__, fout);

        require(simTime != UNDEF_TIME && stepCount != UNDEF_COUNT, "Module not in a valid open state!");
        require(submissionTime != UNDEF_TIME && runoutTime != UNDEF_TIME, "Module is not in a valid open state!");
        require(runningProcess != UNDEF_PID, "Module is not in a valid open state!");
        require(fout != NULL && fileno(fout) != -1, "fout must be a valid file stream");

        if (satelliteModules & 1) { 
            jdtPrint(fout);
            fputc('\n', fout);
        }
        if (satelliteModules & 2) { 
            pctPrint(fout);
            fputc('\n', fout);
        }
        if (satelliteModules & 4) { 
            memPrint(fout);
            fputc('\n', fout);
        }
        if (satelliteModules & 8) { 
            rdyPrint(fout);
            fputc('\n', fout);
        }
        if (satelliteModules & 16) { 
            swpPrint(fout);
            fputc('\n', fout);
        }

        char buffer[256];
        char *ptr = buffer;

        ptr += sprintf(ptr, "| %15.1f |", simTime); 
        ptr += sprintf(ptr, " %12u |", stepCount); 

        if (runningProcess == 0) {
            ptr += sprintf(ptr, " %15s |", "---"); 
        } else {
            ptr += sprintf(ptr, " %15u |", runningProcess); 
        }

        if (submissionTime == INFINITY) {
            ptr += sprintf(ptr, " %15s |", "NEVER"); 
        } else {
            ptr += sprintf(ptr, " %15.1f |", submissionTime); 
        }

        if (runoutTime == INFINITY) {
            sprintf(ptr, " %13s |", "NEVER"); 
        } else {
            sprintf(ptr, " %13.1f |", runoutTime); 
        }

        fprintf(fout, "+====================================================================================+\n");
        fprintf(fout, "+ -------------------------------- SIM Module State -------------------------------- +\n");
        fprintf(fout, "+====================================================================================+\n");
        fprintf(fout, "| simulation time |  step count  | running process | next submission |  next runout  |\n");
        fprintf(fout, "+-----------------+--------------+-----------------+-----------------+---------------+\n");
        fprintf(fout, "%s\n", buffer);
        fprintf(fout, "+====================================================================================+\n");
    }

// ================================================================================== //

} // end of namespace group

