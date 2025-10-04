/*
 *  \author Rodrigo Moço, 108939
 */

#include "somm24.h"

namespace group 
{

    /* \author Rodrigo Moço, 108939 */
// ================================================================================== //

    void memTerm() 
    {
        soProbe(402, "%s()\n", __func__);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");

        while(memFreeList != nullptr){
            MemNode* temp = memFreeList;
            memFreeList = memFreeList->next;
            delete temp;
        }

        while(memOccupiedList != nullptr){
            MemNode* temp = memOccupiedList;
            memOccupiedList = memOccupiedList->next;
            delete temp;
        }

        memFreeList = UNDEF_MEM_NODE;
        memOccupiedList = UNDEF_MEM_NODE;
        memAllocationPolicy = UndefMemoryAllocationPolicy;

    }

// ================================================================================== //

} // end of namespace group

