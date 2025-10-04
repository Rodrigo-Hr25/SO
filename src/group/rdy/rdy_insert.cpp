/*
 *  \author Gabriel Janicas 108689
 */

#include "somm24.h"

namespace group
{

    /* \author Gabriel Janicas 108689 */
// ================================================================================== //

    void rdyInsert(uint16_t pid, double lifetime)
    {
        soProbe(504, "%s(%hu, %.1f)\n", __func__, pid, lifetime);

        require(schedulingPolicy == FCFS or schedulingPolicy == SPN, "Module is not in a valid open state!");
        require(rdyList != UNDEF_RDY_NODE and rdyTail != UNDEF_RDY_NODE, "Module is not in a valid open state!");
        require(pid != 0, "a valid process ID must be greater than zero");
        require(lifetime > 0, "a valid process lifetime must be greater than zero");

        /* TODO POINT: Replace next instruction with my code */
        RdyNode* newNode = new RdyNode;
        newNode->process.pid = pid;
        newNode->process.lifetime = lifetime;
        newNode->next = nullptr;


        if (schedulingPolicy == FCFS)
        {
            if (rdyList == nullptr)
            {
                rdyList = newNode;
                rdyTail = newNode;
            } 
            else
            {
                rdyTail->next = newNode;
                rdyTail = newNode;
            }
        } 
        else if (schedulingPolicy == SPN)
        {
            if (rdyList == nullptr || rdyList->process.lifetime > lifetime)
            {
                newNode->next = rdyList;
                rdyList = newNode;
                if (rdyTail == nullptr) {
                    rdyTail = newNode;
                }
            } 
            else
            {
                RdyNode* current = rdyList;
                while (current->next != nullptr && current->next->process.lifetime <= lifetime)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                if (newNode->next == nullptr)
                {
                    rdyTail = newNode;
                }
            }
        }
    }

// ================================================================================== //

} // end of namespace group

