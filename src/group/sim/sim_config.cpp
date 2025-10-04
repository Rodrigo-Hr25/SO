/*
 *  \author Diogo Silva, 108212
 */

#include "somm24.h"

#include <cstring>

namespace group
{

    /* \author Diogo Silva, 108212 */
// ================================================================================== //

    void simConfig(FILE *fin, SimParameters *spp)
    {
        soProbe(104, "%s(\"%p\")\n", __func__, fin);

        require(simTime == UNDEF_TIME and stepCount == UNDEF_COUNT, "Module is not in a valid closed state!");
        require(submissionTime == UNDEF_TIME and runoutTime == UNDEF_TIME, "Module is not in a valid closed state!");
        require(runningProcess == UNDEF_PID, "Module is not in a valid closed state!");
        require(fin != nullptr and fileno(fin) != -1, "fin must be a valid file stream");
        require(spp != nullptr, "spp must be a valid pointer");

        rewind(fin);

        char line[2048];
        while(fscanf(fin, "%[^\n]\n", line) != EOF) {
            if (*line == '\0' || *line == '#') {
                continue;
            }

            // check if there is a '=' in the line, dot use std::string
            if (char kv[2][2048]; sscanf(line, "%s = %s", kv[0], kv[1]) == 2) {
                int value;
                char *policy = new char[2048];
                char *checker = new char[2048];
                if (strcmp(kv[0], "JobMaxSize") == 0) {
                    if (sscanf(kv[1], "%x", &value) != 1) {
                        fprintf(stderr, "JobMaxSize: 0x%x\n", value);
                        continue;
                    }
                    sprintf(checker, "0x%x", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "JobMaxSize: 0x%x\n", value);
                        continue;
                    }
                    spp->jobMaxSize = value;
                } else if (strcmp(kv[0], "JobCount") == 0) {
                    if (sscanf(kv[1], "%d", &value) != 1) {
                        fprintf(stderr, "JobCount: %d\n", value);
                        continue;
                    }
                    sprintf(checker, "%d", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "JobCount: %d\n", value);
                        continue;
                    }
                    spp->jobCount = value;
                } else if (strcmp(kv[0], "JobRandomSeed") == 0) {
                    if (sscanf(kv[1], "%d", &value) != 1) {
                        fprintf(stderr, "JobRandomSeed: %d\n", value);
                        continue;
                    }
                    sprintf(checker, "%d", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "JobRandomSeed: %d\n", value);
                        continue;
                    }
                    spp->jobRandomSeed = value;
                } else if (strcmp(kv[0], "PIDStart") == 0) {
                    if (sscanf(kv[1], "%d", &value) != 1) {
                        fprintf(stderr, "PIDStart: %d\n", value);
                        continue;
                    }
                    sprintf(checker, "%d", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "PIDStart: %d\n", value);
                        continue;
                    }
                    spp->pidStart = value;
                } else if (strcmp(kv[0], "PIDRandomSeed") == 0) {
                    if (sscanf(kv[1], "%d", &value) != 1) {
                        fprintf(stderr, "PIDRandomSeed: %d\n", value);
                        continue;
                    }
                    sprintf(checker, "%d", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "PIDRandomSeed: %d\n", value);
                        continue;
                    }
                    spp->pidRandomSeed = value;
                } else if (strcmp(kv[0], "MemorySize") == 0) {
                    if (sscanf(kv[1], "%x", &value) != 1) {
                        fprintf(stderr, "MemorySize: 0x%x\n", value);
                        continue;
                    }
                    sprintf(checker, "0x%x", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "MemorySize: 0x%x\n", value);
                        continue;
                    }
                    spp->memorySize = value;
                } else if (strcmp(kv[0], "MemoryKernelSize") == 0) {
                    if (sscanf(kv[1], "%x", &value) != 1) {
                        fprintf(stderr, "MemoryKernelSize: 0x%x\n", value);
                        continue;
                    }
                    sprintf(checker, "0x%x", value);
                    if (strcmp(kv[1], checker) != 0) {
                        fprintf(stderr, "MemoryKernelSize: 0x%x\n", value);
                        continue;
                    }
                    spp->memoryKernelSize = value;
                } else if (strcmp(kv[0], "MemoryAllocationPolicy") == 0) {
                    if (sscanf(kv[1], "%s", policy) != 1) {
                        fprintf(stderr, "MemoryAllocationPolicy: %s\n", policy);
                        continue;
                    }
                    if (strcmp(policy, "BestFit") == 0) {
                        spp->memoryAllocPolicy = MemoryAllocationPolicy::BestFit;
                    } else if (strcmp(policy, "WorstFit") == 0) {
                        spp->memoryAllocPolicy = MemoryAllocationPolicy::WorstFit;
                    } else {
                        fprintf(stderr, "MemoryAllocationPolicy: %s\n", policy);
                    }
                } else if (strcmp(kv[0], "SchedulingPolicy") == 0) {
                    if (sscanf(kv[1], "%s", policy) != 1) {
                        fprintf(stderr, "SchedulingPolicy: %s\n", policy);
                        continue;
                    }
                    if (strcmp(policy, "FCFS") == 0) {
                        spp->schedulingPolicy = SchedulingPolicy::FCFS;
                    } else if (strcmp(policy, "SPN") == 0) {
                        spp->schedulingPolicy = SchedulingPolicy::SPN;
                    } else {
                        fprintf(stderr, "SchedulingPolicy: %s\n", policy);
                    }
                } else if (strcmp(kv[0], "SwappingPolicy") == 0) {
                    if (sscanf(kv[1], "%s", policy) != 1) {
                        fprintf(stderr, "SwappingPolicy: %s\n", policy);
                        continue;
                    }
                    if (strcmp(policy, "FIFO") == 0) {
                        spp->swappingPolicy = SwappingPolicy::FIFO;
                    } else if (strcmp(policy, "FirstFit") == 0) {
                        spp->swappingPolicy = SwappingPolicy::FirstFit;
                    } else {
                        fprintf(stderr, "SwappingPolicy: %s\n", policy);
                    }
                }
            }

            if (strcmp(line, "Begin Jobs") == 0) {
                while(fscanf(fin, "%[^\n]\n", line) != EOF) {
                    if (strcmp(line, "End Jobs") == 0) {
                        break;
                    }
                }
                spp->jobLoadStream = fin;
            }
        }

        rewind(fin);
    }

// ================================================================================== //

} // end of namespace group

