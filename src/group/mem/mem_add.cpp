/*
 *  Duarte Santos, 113304
 */

#include "somm24.h"

#include <stdint.h>

namespace group 
{

    /* \author Duarte Santos 113304 */
// ================================================================================== //

    void memAddNodeToFreeList(MemNode *p)
    {
        soProbe(407, "memAddNodeToFreeList(0x%x)\n", p->block.start);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");
        require(p != nullptr, "p must be a valid pointer");

        MemNode *prev = nullptr;
        MemNode *current = memFreeList;

        while (current != nullptr && current->block.start < p->block.start) {
            prev = current;
            current = current->next;
        }

        p->next = current;
        if (prev != nullptr) {
            prev->next = p;
        } else {
            memFreeList = p; 
        }

        if (current != nullptr && (p->block.start + p->block.size == current->block.start)) {
            p->block.size += current->block.size;
            p->next = current->next;
            delete current; 
        }

        if (prev != nullptr && (prev->block.start + prev->block.size == p->block.start)) {
            prev->block.size += p->block.size;
            prev->next = p->next;
            delete p; 
        }
    }



    /* \author Duarte Santos 113304 */
// ================================================================================== //

    void memAddNodeToOccupiedList(MemNode *p)
    {
        soProbe(408, "memAddNodeToOccupiedList(0x%x)\n", p->block.start);

        require(memAllocationPolicy != UndefMemoryAllocationPolicy, "Module is not in a valid open state!");
        require(memFreeList != UNDEF_MEM_NODE and memOccupiedList != UNDEF_MEM_NODE, "Module is not in a valid open state!");
        require(p != nullptr, "p must be a valid pointer");

        if (memOccupiedList == nullptr || p->block.start < memOccupiedList->block.start) {
            p->next = memOccupiedList;
            memOccupiedList = p;
            return;
        }

        MemNode *prev = nullptr;
        MemNode *current = memOccupiedList;

        while (current != nullptr && current->block.start < p->block.start) {
            prev = current;
            current = current->next;
        }

        p->next = current;
        prev->next = p;
    }



// ================================================================================== //

} // end of namespace group
