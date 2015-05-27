#ifndef _DS_BOX_WRITE
#define _DS_BOX_WRITE

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct
	{
		short AP1;		//flag to indicate autopilot1 is on/off
		short AP2;		//flag to indicate autopilot2 is on/off
		short AThr;		//flag to indicate autothrottle is on/off
	}flags;

	ds_error ds_initialize_box_write(char *boxname, char *s1);




#ifdef __cplusplus
}
#endif
#endif//_DS_BOX_WRITE