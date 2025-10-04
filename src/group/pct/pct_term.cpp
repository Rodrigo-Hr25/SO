/*
 *  \author Rodrigo Moço, 108939
 */

#include "somm24.h"

namespace group
{

    /* \author Rodrigo Moço, 108939 */
// ================================================================================== //

    void pctTerm()
    {
        soProbe(302, "%s()\n", __func__);

        PctNode *current = pctList;

        while(current != nullptr){
            PctNode *next = current->next;
            delete current;
            current = next;
        }

        pctList = UNDEF_PCT_NODE;
    }

// ================================================================================== //

} // end of namespace group

