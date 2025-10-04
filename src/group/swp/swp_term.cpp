/*
 *  \author Diogo Silva 108212
 */

#include "somm24.h"

namespace group
{

    /* \author Diogo Silva 108212 */
// ================================================================================== //

    void swpTerm()
    {
        soProbe(602, "%s()\n", __func__);

        require(swappingPolicy == FIFO or swappingPolicy == FirstFit, "Module is not in a valid open state!");
        require(swpList != UNDEF_SWP_NODE and swpTail != UNDEF_SWP_NODE, "Module is not in a valid open state!");

        while(swpList != swpTail){
            SwpNode *aux = swpList;
            swpList = swpList->next;
            delete aux;
        }
        delete swpList;
        swpList = swpTail = UNDEF_SWP_NODE;
        swappingPolicy = UndefSwappingPolicy;
    }

// ================================================================================== //

} // end of namespace group

