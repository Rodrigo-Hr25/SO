/*
 *  \author Duarte Santos 113304
 */

#include "somm24.h"

namespace group
{
    /* \author Duarte Santos 113304 */
// ================================================================================== //

    double jdtNextSubmission()
    {
        soProbe(206, "%s()\n", __func__);

        require(jdtIn != UNDEF_JOB_INDEX and jdtOut != UNDEF_JOB_INDEX, "Module is not in a valid open state!");
        require(jdtCount != UNDEF_JOB_COUNT, "Module is not in a valid open state!");

        if (jdtCount == 0)
            return INFINITY;
        return jdtTable[jdtOut].submissionTime;
    }

    /* \author Duarte Santos 113304 */
// ================================================================================== //

    Job jdtFetchNext()
    {
        soProbe(207, "%s()\n", __func__);

        require(jdtIn != UNDEF_JOB_INDEX && jdtOut != UNDEF_JOB_INDEX, "Module is not in a valid open state!");
        require(jdtCount != UNDEF_JOB_COUNT, "Module is not in a valid open state!");

        if (jdtCount == 0) {
            throw Exception(EINVAL, __func__);
        }

        Job nextJob = jdtTable[jdtOut];

        jdtOut = (jdtOut + 1) % MAX_JOBS;
        jdtCount--;

        return nextJob;
    }

// ================================================================================== //

} // end of namespace group





