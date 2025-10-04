/*
 *  \author Gabriel Janicas 108689
 */

#include "somm24.h"

namespace group
{

    /* \author Gabriel Janicas 108689 */
// ================================================================================== //

    uint16_t jdtRandomFill(uint32_t seed, uint16_t cnt, uint32_t maxSize)
    {
        soProbe(205, "%s(%u, %u, %#x)\n", __func__, seed, cnt, maxSize);

        require(jdtIn != UNDEF_JOB_INDEX and jdtOut != UNDEF_JOB_INDEX, "Module is not in a valid open state!");
        require(jdtCount != UNDEF_JOB_COUNT, "Module is not in a valid open state!");
        require(cnt == 0 or (cnt >= 2 and cnt <= MAX_JOBS), "Number of jobs is invalid");

        srand(seed);

        if (cnt == 0)
        {
            cnt = 2 + rand() % (MAX_JOBS - 2 + 1);
        }

        uint16_t jobsFilled = 0;
        uint32_t submissionTime = 0;

        for (uint16_t i = 0; i < cnt; i++)
        {

            uint32_t submissionStep = rand() % 101;
            submissionTime += submissionStep;

            uint32_t lifetime = 10 + (rand() % 991);

            uint32_t size = 1 + (rand() % maxSize);

            require(size > 0 and size <= maxSize, "Invalid job size");

            jdtTable[jdtIn].submissionTime = submissionTime;
            jdtTable[jdtIn].lifetime = lifetime;
            jdtTable[jdtIn].memSize = size;

            jdtIn = (jdtIn + 1) % MAX_JOBS;
            jdtCount++;
            jobsFilled++;
        }

        return jobsFilled;
    
    }

// ================================================================================== //

} // end of namespace group

