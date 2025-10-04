/*
 *  \author Tiago Garcia, 114184
 *          Gabriel Janicas, 108689
 */

#include "somm24.h"

#include <stdint.h>

namespace group
{
    /*     \author Gabriel Janicas 108689       */
    /* ======================================================================== */
    double pctLifetime(uint16_t pid)
    {
        soProbe(305, "%s(%u)\n", __func__, pid);

        require(pctList != UNDEF_PCT_NODE, "The PCT linked list must exist");
        require(pid > 0, "a valid process ID must be greater than zero");

        auto *current = pctList;

        while (current != nullptr) {
            if (current->pcb.pid == pid)
                return current->pcb.lifetime;
            current = current->next;
        }

        throw Exception(EINVAL, __func__);
    }

        /* \author Tiago Garcia, 114184 */
    /* ======================================================================== */

    uint32_t pctMemSize(uint16_t pid)
    {
        soProbe(306, "%s(%u)\n", __func__, pid);

        require(pctList != UNDEF_PCT_NODE, "The PCT linked list must exist");
        require(pid > 0, "a valid process ID must be greater than zero");

        auto *current = pctList;

        while (current != nullptr) {
            if (current->pcb.pid == pid)
                return current->pcb.memSize;
            current = current->next;
        }

        throw Exception(EINVAL, __func__);
    }

        /* \author Tiago Garcia, 114184 */
    /* ======================================================================== */

    uint32_t pctMemAddress(uint16_t pid)
    {
        soProbe(307, "%s(%u)\n", __func__, pid);

        require(pctList != UNDEF_PCT_NODE, "The PCT linked list must exist");
        require(pid > 0, "a valid process ID must be greater than zero");

        auto *current = pctList;

        while (current != nullptr) {
            if (current->pcb.pid == pid)
                return current->pcb.memStart;
            current = current->next;
        }

        throw Exception(EINVAL, __func__);
    }

    /* ======================================================================== */

} // end of namespace somm22
