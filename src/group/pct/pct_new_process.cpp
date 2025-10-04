/*
 *  \author Tiago Garcia, 114184
 */

#include "somm24.h"

#include <stdint.h>

namespace group
{

    /* \author Tiago Garcia, 114184 */
// ================================================================================== //

    uint16_t pctNewProcess(double admissionTime, double lifetime, uint32_t memSize)
    {
        soProbe(304, "%s(%0.1f, %0.1f, %#x)\n", __func__, admissionTime, lifetime, memSize);

        require(pctList != UNDEF_PCT_NODE, "Module is not in a valid open state!");
        require(admissionTime >= 0, "Bad admission time");
        require(lifetime > 0, "Bad lifetime");
        require(memSize > 0, "Bad memory size");

        static uint8_t nextPIDIndex = 0;
        if (nextPIDIndex >= MAX_JOBS || pctPID[nextPIDIndex] == 0) {
            throw Exception(ENOSYS, __func__);
        }

        uint16_t pid = pctPID[nextPIDIndex++];

        auto *node = new PctNode;
        require(node != nullptr, "Memory allocation error");

        node->pcb.pid = pid;
        node->pcb.state = NEW;
        node->pcb.storeTime = UNDEF_TIME;
        node->pcb.startTime = UNDEF_TIME;
        node->pcb.finishTime = UNDEF_TIME;
        node->pcb.memStart = UNDEF_ADDRESS;
        node->pcb.admissionTime = admissionTime;
        node->pcb.lifetime = lifetime;
        node->pcb.memSize = memSize;

        if (pctList == nullptr || pctList == UNDEF_PCT_NODE || pctList->pcb.pid > pid) {
            node->next = pctList;
            pctList = node;
        } else {
            PctNode *prev = pctList;
            while (prev->next != nullptr && prev->next->pcb.pid < pid) {
                prev = prev->next;
            }
            node->next = prev->next;
            prev->next = node;
        }

        return pid;

    }

// ================================================================================== //

} // end of namespace group

