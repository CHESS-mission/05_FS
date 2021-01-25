
#ifdef __cplusplus
extern "C" {
#endif

#include "pusopen.h"

po_result_t subnet_request(
        uint8_t * const data,
        const uint16_t len,
        const po_apid_t apid,
        const uint16_t vcid)
{
    po_result_t res = PO_SUCCESS;     /* Result of this function */

    (void)apid;
    (void)vcid;

    /* Forward requested data directly down to FESS */
    res = fessChannelAccess_request(PO_DEF_FESS, data, len);

    return res;
}

po_result_t subnet_indication(uint8_t * const data, uint16_t *len)
{
    po_result_t res = PO_SUCCESS;  /* Result of this function */
    uint8_t quality = 0U;
    uint8_t sequence = 0U;

    /* Call FESS indication API to retrieve received data */
    res = fessChannelAccess_indication(PO_DEF_FESS, data, len, &quality, &sequence);

    return res;
}

#ifdef __cplusplus
}
#endif