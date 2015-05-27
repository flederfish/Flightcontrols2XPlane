#ifndef DS_BOXSTICK1_
#define DS_BOXSTICK1_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif


	typedef struct {

		/* Prefix of following variables: ACR#.COP.STI1-2                          */

		float pitch_a;           /* normalized pitch cmd, angle (-1 - 1)       [-] */
		/* positive means pos elevator means nose down    */
		float roll_a;            /* normalized roll cmd, angle (-1 - 1)        [-] */
		/* positive means pos aileron means roll left     */
		float steering_wheel;    /* steering wheel angle                     [deg] */
		short ap_disconnect;     /* autopilot disconnect (0,1)                 [-] */
	} Stick_1;

	ds_error ds_initialize_Stick_1(char *boxname, char *s1);

#ifdef __cplusplus
}
#endif
#endif