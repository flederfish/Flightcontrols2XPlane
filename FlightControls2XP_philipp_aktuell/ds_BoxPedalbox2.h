#ifndef DS_BOX_PEDALBOX2_
#define DS_BOX_PEDALBOX2_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {

		/* Prefix of following variables: ACR#.COP.PED1-2                            */

		float rudder;            /* normalized rudder cmd, angle (-1 - 1)      [-] */
		/* positive means pos rudder means yaw to left    */
		float brake_l;           /* normalized brake cmd, left (0-1)           [-] */
		float brake_r;           /* normalized brake cmd, right (0-1)          [-] */
	} Pedalbox2;

	ds_error ds_initialize_Pedalbox2(char *box, char *s1);

#ifdef __cplusplus
}
#endif
#endif