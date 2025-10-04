/*
 *  \author Gabriel Janicas 108689
 */

#include "somm24.h"

namespace group
{

    /* \author Gabriel Janicas 108689 */
// ================================================================================== //

    void jdtInit()
    {
        soProbe(201, "%s()\n", __func__);

        require(jdtIn == UNDEF_JOB_INDEX and jdtOut == UNDEF_JOB_INDEX, "Module is not in a valid closed state!");
        require(jdtCount == UNDEF_JOB_COUNT, "Module is not in a valid closed state!");

        /* TODO POINT: Replace next instruction with your code */
        for (int i = 0; i < MAX_JOBS; ++i) {
            jdtTable[i] = {};
        }

        jdtCount = 0;
        jdtOut = 0;
        jdtIn = 0;
    }

// ================================================================================== //

} // end of namespace group

