/*
 *  \author Tiago Garcia, 114184
 */

#include "somm24.h"

namespace group
{

    /* \author Tiago Garcia, 114184 */
// ================================================================================== //

    bool simStep() {
        soProbe(105, "%s()\n", __func__);

        require(simTime != UNDEF_TIME and stepCount != UNDEF_COUNT, "Module not in a valid open state!");
        require(submissionTime != UNDEF_TIME and runoutTime != UNDEF_TIME, "Module is not in a valid open state!");
        require(runningProcess != UNDEF_PID, "Module is not in a valid open state!");

        if (submissionTime == NEVER and runoutTime == NEVER) {
            return false;
        }

        if (submissionTime == NEVER or (runoutTime <= NEVER and runoutTime <= submissionTime)) {
            simTime = runoutTime;

            memFree(pctMemAddress(runningProcess));
            pctUpdateState(runningProcess, TERMINATED, simTime);

            while (true) {
                const auto pid = swpFetch(memBiggestFreeBlockSize());
                if (pid == 0) break;
                rdyInsert(pid, pctLifetime(pid));
                pctUpdateState(pid, READY, simTime, memAlloc(pctMemSize(pid)));
            }

            runningProcess = 0;
            runoutTime = NEVER;
        } else {
            simTime = submissionTime;

            const auto job = jdtFetchNext();
            const auto pid = pctNewProcess(simTime, job.lifetime, job.memSize);
            if (const auto maxSize = memBiggestFreeBlockSize(); job.memSize > maxSize) {
                swpInsert(pid, job.memSize);
                pctUpdateState(pid, SWAPPED);
            } else {
                rdyInsert(pid, job.lifetime);
                pctUpdateState(pid, READY, simTime, memAlloc(job.memSize));
            }

            submissionTime = jdtNextSubmission();
        }

        if (runningProcess == 0) {
            if (const auto next = rdyFetch(); next != 0) {
                pctUpdateState(next, RUNNING, simTime);
                runningProcess = next;
                runoutTime = simTime + pctLifetime(next);
            }
        }

        stepCount++;
        return true;
    }

// ================================================================================== //

} // end of namespace group

