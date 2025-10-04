/*
 *  \author Diogo Silva 108212
 */

#include "somm24.h"

namespace group
{

    /* \author Diogo Silva 108212 */
// ================================================================================== //

    uint16_t swpFetch(uint32_t sizeAvailable)
    {
        soProbe(605, "%s(%#x)\n", __func__, sizeAvailable);

        require(swappingPolicy == FIFO or swappingPolicy == FirstFit, "Module is not in a valid open state!");
        require(swpList != UNDEF_SWP_NODE and swpTail != UNDEF_SWP_NODE, "Module is not in a valid open state!");

        if (swpList == NULL) {
            return 0;
        }
        if (swappingPolicy == FIFO) {
            if(sizeAvailable < swpList->process.size){
                return 0;
            };
            uint16_t pid = swpList->process.pid;

            SwpNode* aux = swpList;
            swpList = swpList->next;

            if(swpList == NULL){
                swpTail = NULL;
            };
            delete aux;
            return pid;
        }
        if (swappingPolicy == FirstFit) {
            SwpNode* prev = NULL;
            SwpNode* current = swpList;

            while(current != NULL){
                if(current->process.size <= sizeAvailable){
                    uint16_t pid = current->process.pid;
                    if(prev == NULL){
                        swpList = current->next;
                    }else{
                        prev->next = current->next;
                    }
                    if(swpList == NULL){
                        swpTail = NULL;
                    }
                    delete current;
                    return pid;
                }
                prev = current;
                current = current->next;
            }
            return 0;
        }
        return 0;
    }

// ================================================================================== //

} // end of namespace group

