/*
 *  \author Tiago Garcia, 114184
 */

#include "somm24.h"

namespace group
{

    /* \author Tiago Garcia, 114184 */
// ================================================================================== //

    void pctInit(const uint16_t pid0, const uint16_t cnt, const uint32_t seed)
    {
        soProbe(301, "%s(%hu, %hu, %u)\n", __func__, pid0, cnt, seed);

        require(pctList == UNDEF_PCT_NODE, "The module is not in a valid closed state");
        require(cnt > 1 and cnt <= MAX_JOBS, "cnt must be > 1 and <= MAX_JOBS");

        srand(seed);
        pctList = nullptr;

        for (unsigned short i = 0; i < cnt; i++) pctPID[i] = pid0 + i;
        for (unsigned short i = cnt - 1; i > 0; i--) {
            unsigned short j = rand() % (i + 1);
            unsigned short tmp = pctPID[i];
            pctPID[i] = pctPID[j];
            pctPID[j] = tmp;
        }
        for (unsigned short i = cnt; i < MAX_JOBS; i++) pctPID[i] = 0;
    }

// ================================================================================== //

} // end of namespace group
