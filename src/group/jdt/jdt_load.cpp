/*
 *  \author Tiago Garcia, 114184
 */

#include "somm24.h"

namespace group
{

    /* \author Tiago Garcia, 114184 */
// ================================================================================== //

    uint16_t jdtLoad(FILE *fin, uint32_t maxSize)
    {
        soProbe(204, "%s(%p, %#x)\n", __func__, fin, maxSize);

        require(jdtIn != UNDEF_JOB_INDEX and jdtOut != UNDEF_JOB_INDEX, "Module is not in a valid open state!");
        require(jdtCount != UNDEF_JOB_COUNT, "Module is not in a valid open state!");
        require(fin != nullptr and fileno(fin) != -1, "fin must be a valid file stream");

        uint16_t jobsLoaded = 0;
        rewind(fin);

        char line[2048];
        while(fscanf(fin, "%[^\n]\n", line) != EOF) {
            char beginJobs[] = "Begin Jobs";
            int i = 0;
            int isEqual = 1;
            while (line[i] != '\0' && beginJobs[i] != '\0') {
                if (line[i] != beginJobs[i]) {
                    isEqual = 0;
                    break;
                }
                i++;
            }
            if (isEqual && line[i] == beginJobs[i]) break;
        }

        while(fscanf(fin, "%[^\n]\n", line) != EOF) {
            if (*line == '\0' || *line == '#') {
                continue;
            }

            char endJobs[] = "End Jobs";
            int i = 0;
            int isEqual = 1;
            while (line[i] != '\0' && endJobs[i] != '\0') {
                if (line[i] != endJobs[i]) {
                    isEqual = 0;
                    break;
                }
                i++;
            }
            if (isEqual && line[i] == endJobs[i]) break;

            double submissionTime;
            double lifetime;
            uint32_t memorySize;
            if (sscanf(line, "%lf ; %lf ; %x", &submissionTime, &lifetime, &memorySize) == 3) {
                jdtTable[jdtIn].submissionTime = submissionTime;
                jdtTable[jdtIn].lifetime = lifetime;
                jdtTable[jdtIn].memSize = memorySize <= maxSize ? memorySize : maxSize;

                jdtCount++;
                jdtIn = (jdtIn + 1) % MAX_JOBS;

                jobsLoaded++;
            }
        }

        rewind(fin);
        return jobsLoaded;
    }

// ================================================================================== //

} // end of namespace group

