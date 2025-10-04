/*
 *  \author Duarte Santos 113304
 */

#include "somm24.h"

namespace group 
{

// ================================================================================== //

    void jdtTerm() 
    {
        soProbe(202, "%s()\n", __func__);

        require(jdtIn != UNDEF_JOB_INDEX and jdtOut != UNDEF_JOB_INDEX, "Module is not in a valid open state!");
        require(jdtCount != UNDEF_JOB_COUNT, "Module is not in a valid open state!");

        for (int i=0; i<MAX_JOBS; ++i) {
            jdtTable[i] = {};
        }

        jdtOut = UNDEF_JOB_INDEX;
        jdtIn = UNDEF_JOB_INDEX;
        jdtCount = UNDEF_JOB_COUNT;
    }

// ================================================================================== //

} // end of namespace group

