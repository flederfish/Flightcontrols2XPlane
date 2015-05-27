

#ifndef DS_BOXRUFTRIM_
#define DS_BOXRUFTRIM_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif


	typedef struct 
	{

		/* Prefix of following variables: ACR#.COP.PNL.PDS.RUD_TR                  */

		short touch_button0;     /* by pushing (1) the reset button the zero trim  */
		/* position is ordered; if not touched (0),       */
		/* nothing happens                                */

		short rot_switch0;       /* -1 = moves the neutral point of the rudder trim*/
		/*      actuator to the right                     */
		/*  0 = no action                                 */
		/* +1 = moves the neutral point of the rudder trim*/
		/*      actuator to the left                      */

	}Rudder_Trim_Panel;

	ds_error ds_initialize_RUD_TRIM(char *boxname, char *s1);



#ifdef __cplusplus
}
#endif
#endif