/*
 *  \author Diogo Silva 108212
 */

#include "somm24.h"

namespace group
{

    /* \author Diogo Silva 108212 */
// ================================================================================== //

    void simRun(uint32_t cnt)
    {
        soProbe(106, "%s(%u)\n", __func__, cnt);

        require(simTime != UNDEF_TIME and stepCount != UNDEF_COUNT, "Module not in a valid open state!");
        require(submissionTime != UNDEF_TIME and runoutTime != UNDEF_TIME, "Module is not in a valid open state!");
        require(runningProcess != UNDEF_PID, "Module is not in a valid open state!");

        while (cnt-- > 0 && simStep());
    }

// ================================================================================== //

} // end of namespace group

