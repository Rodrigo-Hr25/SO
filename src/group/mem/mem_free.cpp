/*
 *  Rodrigo Moço, 108939
 */

#include "somm24.h"

#include <stdint.h>

namespace group 
{

    /* Rodrigo Moço, 108939 */
// ================================================================================== //

    void memFree(uint32_t address)
    {
        soProbe(405, "%s(0x%x)\n", __func__, address);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");

        MemNode *node = memRetrieveNodeFromOccupiedList(address);
        if (node == nullptr)
        {
            throw Exception(EINVAL, __func__);
        }

        memAddNodeToFreeList(node);
    }

// ================================================================================== //

} // end of namespace group

