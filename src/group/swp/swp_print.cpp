/*
 *  \author Diogo Silva 108212
 */

#include "somm24.h"

#include <stdio.h>
#include <stdint.h>

namespace group
{

    /* \author Diogo Silva 108212 */
// ================================================================================== //

    void swpPrint(FILE *fout)
    {
        soProbe(603, "%s(%p)\n", __func__, fout);

        require(swappingPolicy == FIFO or swappingPolicy == FirstFit, "Module is not in a valid open state!");
        require(swpList != UNDEF_SWP_NODE and swpTail != UNDEF_SWP_NODE, "Module is not in a valid open state!");
        require(fout != NULL and fileno(fout) != -1, "fout must be a valid file stream");

        fprintf(fout,"+=====================+\n");
        fprintf(fout,"|  SWP Module State   |\n");
        if(swappingPolicy == 1){
            fprintf(fout,"|       (FIFO)        |\n");
        }else if(swappingPolicy == 2){
            fprintf(fout,"|     (FirstFit)      |\n");
        }
        fprintf(fout,"+-------+-------------+\n");
        fprintf(fout,"|  PID  | memory size |\n");
        fprintf(fout,"+-------+-------------+\n");
        SwpNode *aux = swpList;
        while(aux != NULL){
            fprintf(fout,"| %5d | %11d |\n", aux->process.pid, aux->process.size);
            aux = aux->next;
        }
        fprintf(fout,"+=====================+\n");
        fprintf(fout,"\n");

    }

// ================================================================================== //

} // end of namespace group

