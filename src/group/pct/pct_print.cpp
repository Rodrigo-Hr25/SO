/*
 *  \author Tiago Garcia, 114184
 */

#include "somm24.h"

namespace group 
{

    /* \author Tiago Garcia, 114184 */
// ================================================================================== //

    void pctPrint(FILE *fout)
    {
        soProbe(303, "%s(%p)\n", __func__, fout);

        require(pctList != UNDEF_PCT_NODE, "Module is not in a valid open state!");
        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        PctNode *current = pctList;

        fprintf(fout, "+======================================================================================================================+\n");
        fprintf(fout, "|                                                   PCT module state                                                   |\n");
        fprintf(fout, "+-------+-------------+-------------+-------------+------------+------------+-------------+--------------+-------------+\n");
        fprintf(fout, "|  PID  |    state    |  admission  |  lifetime   | store time | start time | finish time | memory start | memory size |\n");
        fprintf(fout, "+-------+-------------+-------------+-------------+------------+------------+-------------+--------------+-------------+\n");

        while(current != nullptr)
        {
            const char *stateStr;
            switch (current->pcb.state) {
                case RUNNING:
                    stateStr = "RUNNING";
                    break;
                case READY:
                    stateStr = "READY";
                    break;
                case SWAPPED:
                    stateStr = "SWAPPED";
                    break;
                case TERMINATED:
                    stateStr = "TERMINATED";
                    break;
                default:
                    stateStr = "UNKNOWN";
                    break;
            }

            char storeTimeStr[20];
            char startTimeStr[20];
            char finishTimeStr[20];
            char memStartStr[20];
            char memSizeStr[20];
            snprintf(storeTimeStr, sizeof(storeTimeStr), current->pcb.storeTime == UNDEF_TIME ? "UNDEF" : "%.1f", current->pcb.storeTime);
            snprintf(startTimeStr, sizeof(startTimeStr), current->pcb.startTime == UNDEF_TIME ? "UNDEF" : "%.1f", current->pcb.startTime);
            snprintf(finishTimeStr, sizeof(finishTimeStr), current->pcb.finishTime == UNDEF_TIME ? "UNDEF" : "%.1f", current->pcb.finishTime);
            snprintf(memStartStr, sizeof(memStartStr), current->pcb.memStart == UNDEF_ADDRESS ? "UNDEF" : "0x%x", current->pcb.memStart);
            snprintf(memSizeStr, sizeof(memSizeStr), current->pcb.memSize == 0 ? "0" : "0x%x", current->pcb.memSize);

            fprintf(fout, "| %5u | %-11s | %11.1f | %11.1f | %10s | %10s | %11s | %12s | %11s |\n",
                current->pcb.pid,
                stateStr,
                current->pcb.admissionTime,
                current->pcb.lifetime,
                storeTimeStr,
                startTimeStr,
                finishTimeStr,
                memStartStr,
                memSizeStr
            );

            current = current->next;
        }

        fprintf(fout, "+======================================================================================================================+\n");
    }

// ================================================================================== //

} // end of namespace group

