/*
 *  \author Gabriel Janicas, 108689
 */

#include "somm24.h"

#include <stdint.h>
#include <exception.h>

namespace group
{

    /* \author Gabriel Janicas 108689 */
// ================================================================================== //

    void pctUpdateState(uint16_t pid, ProcessState state, double time = UNDEF_TIME, uint32_t address = UNDEF_ADDRESS)
    {
        bool validState = true;
        const char *sas = "UNKOWN";
        switch (state) {
            case NEW: sas = "NEW"; break;
            case RUNNING: sas = "RUNNING"; break;
            case READY: sas = "READY"; break;
            case SWAPPED: sas = "SWAPPED"; break;
            case TERMINATED: sas = "TERMINATED"; break;
            default: validState = false; break;
        }
        soProbe(308, "%s(%hu, %s, %.1f, %#x)\n", __func__, pid, sas, time, address);

        require(pctList != UNDEF_PCT_NODE, "Module is not in valid open state");
        require(pid != 0, "PID can't be zero");
        require(state != NEW, "on updating, state can not be NEW");
        require(validState, "Wrong state value");

        /* TODO POINT: Replace next instruction with your code */
        PctNode *current = pctList;
        while (current != nullptr) {
            if (current->pcb.pid == pid) {

                current->pcb.state = state;

                switch (state) {
                    case RUNNING:
                        current->pcb.startTime = time;
                        break;
                    case READY:
                        current->pcb.storeTime = time;
                        current->pcb.memStart = address;
                        break;
                    case TERMINATED:
                        current->pcb.finishTime = time;
                        break;
                    default:
                        break;
                }
                return;
            }
            current = current->next;
        }

        throw Exception(EINVAL, "Process not found in the PCT");
    }

// ================================================================================== //

} // end of namespace group

