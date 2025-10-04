/*
 *  \author Gabriel Janicas 108689
 */

#include "somm24.h"

namespace group
{

    /* \author Gabriel Janicas 108689 */
// ================================================================================== //

    uint16_t rdyFetch()
    {
        soProbe(505, "%s()\n", __func__);

        require(schedulingPolicy == FCFS or schedulingPolicy == SPN, "Module is not in a valid open state!");
        require(rdyList != UNDEF_RDY_NODE and rdyTail != UNDEF_RDY_NODE, "Module is not in a valid open state!");

        /* TODO POINT: Replace next instruction with my code */
        if (rdyList == nullptr)
        {
            return 0;
        }

        uint16_t pid = rdyList->process.pid;

        RdyNode* temp = rdyList;
        rdyList = rdyList->next;

        if (rdyList == nullptr)
        {
            rdyTail = nullptr;
        }

        delete temp;
        return pid;
    }
} // end of namespace group

// ================================================================================== //

