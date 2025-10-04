/*
 *  \author Gabriel Janicas 108689
 */

#include "somm24.h"

namespace group
{

    /* \author Gabriel Janicas 108689    */
// ================================================================================== //

    void rdyTerm()
    {
        soProbe(502, "%s()\n", __func__);

        require(schedulingPolicy == FCFS or schedulingPolicy == SPN, "Module is not in a valid open state!");
        require(rdyList != UNDEF_RDY_NODE and rdyTail != UNDEF_RDY_NODE, "Module is not in a valid open state!");

        /* TODO POINT: Replace next instruction with my code */
        while (rdyList != rdyTail)
        {
            RdyNode*aux = rdyList;
            rdyList = rdyList->next;
            delete aux;
        }
        delete rdyList;
        rdyList = rdyTail = UNDEF_RDY_NODE;
        schedulingPolicy = UndefSchedulingPolicy;

    }

// ================================================================================== //

} // end of namespace group

