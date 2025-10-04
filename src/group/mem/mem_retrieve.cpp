/*
 *  Duarte Santos, 113304
 *  Rodrigo Moço, 108939
 */

#include "somm24.h"

#include <stdint.h>

namespace group
{

    /* \author Duarte Santos 113304 */
// ================================================================================== //

    MemNode *memRetrieveNodeFromFreeList(uint32_t size, MemoryAllocationPolicy policy)
    {
        soProbe(409, "memRetrieveNodeFromFreeList(0x%x, %d)\n", size, policy);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");
        require(policy == BestFit or policy == WorstFit, "Allocation policy must be 'BestFit' or 'WorstFit'");

        MemNode *current = memFreeList;
        MemNode *bestCandidate = nullptr;

        while (current != nullptr)
        {
            if (current->block.size >= size)
            {
                if (bestCandidate == nullptr ||
                    (policy == BestFit && current->block.size < bestCandidate->block.size) ||
                    (policy == WorstFit && current->block.size > bestCandidate->block.size))
                {
                    bestCandidate = current;
                }
            }
            current = current->next;
        }

        if (bestCandidate == nullptr)
            return nullptr;

        if (bestCandidate == memFreeList)
        {
            memFreeList = bestCandidate->next;
        }
        else
        {
            MemNode *prev = memFreeList;
            while (prev->next != bestCandidate)
                prev = prev->next;
            prev->next = bestCandidate->next;
        }

        bestCandidate->next = nullptr;
        return bestCandidate;
    }

    /* \author Rodrigo Moço, 108939 */
// ================================================================================== //

    MemNode *memRetrieveNodeFromOccupiedList(uint32_t address)
    {
        soProbe(410, "%s(0x%x)\n", __func__, address);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");

        MemNode *current = memOccupiedList;
        MemNode *previous = nullptr;

        while (current != nullptr)
        {
            if (current->block.start == address)
            {
                if (previous == nullptr)
                {
                    memOccupiedList = current->next;
                }
                else
                {
                    previous->next = current->next;
                }

                current->next = nullptr;
                return current;
            }

            previous = current;
            current = current->next;
        }

        return nullptr;
    }


// ================================================================================== //

} // end of namespace group
