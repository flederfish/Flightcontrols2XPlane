#ifndef DS_BOX_PEDESTAL_
#define DS_BOX_PEDESTAL_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {

		/* Prefix of following variables: ACR#.COP.PNL.PDS                         */
		/* basic input devices of pedestal                                         */

		float thrust_lev1;       /* normalized (0-1) CPT side                  [-] */
		float thrust_lev2;       /* normalized (0-1) FO  side                  [-] */

		short rev_thrust;        /* reverse thrust (0,1)                       [-] */
		short athr_disconnect;   /* autothrust disconnect (0,1)                [-] */

		short flaps;             /* flap position (0-4)                        [-] */
		short speed_brakes;      /* speed brake position (0-4)                 [-] */
		short park_brakes;       /* park brake ON/OFF (0-1)                    [-] */

	} Pedestal_Basics;

	ds_error ds_initialize_Pedestal(char *box, char *s1);


#ifdef __cplusplus
}
#endif
#endif