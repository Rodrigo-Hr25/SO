/*
 *  \author Gabriel Janicas 108689
 */

#include "somm24.h"

#include <stdio.h>
#include <stdint.h>

namespace group 
{

    /* \author Gabriel Janicas 108689 */
// ================================================================================== //

    void rdyPrint(FILE *fout)
    {
        soProbe(503, "%s(%p)\n", __func__, fout);

        require(schedulingPolicy == FCFS or schedulingPolicy == SPN, "Module is not in a valid open state!");
        require(rdyList != UNDEF_RDY_NODE and rdyTail != UNDEF_RDY_NODE, "Module is not in a valid open state!");

        /* TODO POINT: Replace next instruction with my code */
        fprintf(fout,"+====================+\n");
        fprintf(fout,"|  RDY Module State  |\n");
        if(schedulingPolicy == 1)
        {
            fprintf(fout,"|       (FCFS)       |\n");
        }
        else if(schedulingPolicy == 2)
        {
            fprintf(fout,"|       (SPN)        |\n");
        }
        
        fprintf(fout,"+-------+------------+\n");
        fprintf(fout,"|  PID  |  lifetime  |\n");
        fprintf(fout,"+-------+------------+\n");
        RdyNode *aux = rdyList;

        while(aux != NULL)
        {
            fprintf(fout,"|%6d | %10.1f |\n", aux->process.pid, aux->process.lifetime);
            aux = aux->next;
        }
        fprintf(fout,"+====================+\n");
        fprintf(fout,"\n");
    }

// ================================================================================== //

} // end of namespace group

