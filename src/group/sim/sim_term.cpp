/*
 *  Rodrigo Moço, 108939
 */

#include "somm24.h"

namespace group 
{

    /* \author Rodrigo Moço, 108939 */
// ================================================================================== //

void simTerm() 
{
    soProbe(102, "%s()\n", __func__);

    require(simTime != UNDEF_TIME and stepCount != UNDEF_COUNT, "Module not in a valid open state!");
    require(submissionTime != UNDEF_TIME and runoutTime != UNDEF_TIME, "Module is not in a valid open state!");
    require(runningProcess != UNDEF_PID, "Module is not in a valid open state!");

    // Finalize or terminate subsystems
    jdtTerm();      // Terminate job dispatch table
    pctTerm();      // Terminate process control table
    memTerm();      // Terminate memory manager
    rdyTerm();      // Terminate ready queue
    swpTerm();      // Terminate swapper module

    // Reset global simulation variables to undefined state
    runoutTime = UNDEF_TIME;      // Mark runoutTime as undefined
    submissionTime = UNDEF_TIME; // Mark submissionTime as undefined
    simTime = UNDEF_TIME;        // Reset simulation time
    stepCount = UNDEF_COUNT;     // Reset step count
    runningProcess = UNDEF_PID;  // Mark running process as undefined
}

// ================================================================================== //

} // end of namespace group

