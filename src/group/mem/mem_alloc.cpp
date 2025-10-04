/*
 *  Rodrigo Moço, 108939
 */

#include "somm24.h"

#include <stdint.h>
#include <string.h>

namespace group 
{

    /* Rodrigo Moço, 108939 */
// ================================================================================== //

    uint32_t memBiggestFreeBlockSize()
    {
        soProbe(406, "%s()\n", __func__);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");

        MemNode *current = memFreeList;
        uint32_t maxSize = 0;

        while (current != nullptr)
        {
            if (current->block.size > maxSize)
            {
                maxSize = current->block.size;
            }
            current = current->next;
        }

        if (maxSize == 0)
        {
            throw Exception(EINVAL, __func__);
        }

        return maxSize;
    }


    /* \author Rodrigo Moço, 108939 */
// ================================================================================== //

    uint32_t memAlloc(uint32_t size)
    {
        soProbe(404, "memAlloc(0x%x)\n", size);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");

        MemNode *allocatedNode = memRetrieveNodeFromFreeList(size, memAllocationPolicy);
        if (allocatedNode == nullptr)
            return UNDEF_ADDRESS;

        if (allocatedNode->block.size > size)
        {
            MemNode *remainingNode = new MemNode();
            remainingNode->block.start = allocatedNode->block.start + size;
            remainingNode->block.size = allocatedNode->block.size - size;

            allocatedNode->block.size = size;
            memAddNodeToFreeList(remainingNode);
        }

        memAddNodeToOccupiedList(allocatedNode);

        return allocatedNode->block.start;
    }




// ================================================================================== //

} // end of namespace group
