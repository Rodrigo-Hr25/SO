/*
 *  \author Diogo Silva, 108212
 */

#include "somm24.h"

#include <ctime>
#include <unistd.h>

namespace group
{

    /* \author Diogo Silva, 108212 */
// ================================================================================== //

    void simInit(FILE *fin)
    {
        soProbe(101, "%s(%p)\n", __func__, fin);

        require(simTime == UNDEF_TIME and stepCount == UNDEF_COUNT, "Module is not in a valid closed state!");
        require(submissionTime == UNDEF_TIME and runoutTime == UNDEF_TIME, "Module is not in a valid closed state!");
        require(runningProcess == UNDEF_PID, "Module is not in a valid closed state!");
        require(fin == nullptr or fileno(fin) != -1, "fin must be NULL or a valid file pointer");

        SimParameters params = {};
        params.jobLoadStream = nullptr;
        params.jobMaxSize = 0x10000;
        params.jobRandomSeed = UNDEF_SEED;
        params.jobCount = 0;
        params.pidStart = 1001;
        params.pidRandomSeed = UNDEF_SEED;
        params.memorySize = 0x100000;
        params.memoryKernelSize = 0x10000;
        params.memoryAllocPolicy = MemoryAllocationPolicy::WorstFit;
        params.schedulingPolicy = SchedulingPolicy::FCFS;
        params.swappingPolicy = SwappingPolicy::FIFO;

        if (fin != NULL){
            simConfig(fin, &params);
        }

        jdtInit();
        int jobsLoaded;

        if (params.jobLoadStream == nullptr) {
            if (params.jobCount == 0) {
                params.jobCount = rand() % (MAX_JOBS - 1) + 2;
            }
            if (params.jobRandomSeed == UNDEF_SEED) {
                params.jobRandomSeed = getpid();
            }
            jobsLoaded = jdtRandomFill(params.jobRandomSeed, params.jobCount, params.jobMaxSize);
        } else {
            jobsLoaded = jdtLoad(params.jobLoadStream, params.jobMaxSize);
        }

        if (params.pidRandomSeed == UNDEF_SEED) {
            params.pidRandomSeed = time(nullptr);
        }

        pctInit(params.pidStart, jobsLoaded, params.pidRandomSeed);
        memInit(params.memorySize, params.memoryKernelSize, params.memoryAllocPolicy);
        rdyInit(params.schedulingPolicy);
        swpInit(params.swappingPolicy);

        stepCount = 0;
        simTime = 0.0;
        runoutTime = INFINITY;
        submissionTime = jdtNextSubmission();
        runningProcess = 0;
    }

// ================================================================================== //

} // end of namespace group

