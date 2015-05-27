#ifndef DS_BOX_OVERHEAD_HW_
#define DS_BOX_OVERHEAD_HW_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {

		short toggle_switch0;  // hardware toggle switch 0 on the overhead
		short toggle_switch1;  // hardware toggle switch 1 on the overhead
		short toggle_switch2;  // hardware toggle switch 2 on the overhead
		short toggle_switch3;  // hardware toggle switch 3 on the overhead
		short toggle_switch4;  // hardware toggle switch 4 on the overhead
		short toggle_switch5;  // hardware toggle switch 6 on the overhead
		short toggle_switch6;  // hardware toggle switch 7 on the overhead
		short toggle_switch7;  // hardware toggle switch 8 on the overhead
		short toggle_switch8;  // hardware toggle switch 9 on the overhead
		short toggle_switch9;  // hardware toggle switch 10 on the overhead
		short toggle_switch10;  // hardware toggle switch 11 on the overhead
		short toggle_switch11;  // hardware toggle switch 12 on the overhead
		short toggle_switch12;  // hardware toggle switch 13 on the overhead
		short toggle_switch13;  // hardware toggle switch 14 on the overhead

	} Overhead_Hardware;

	ds_error ds_initialize_OVH_HW(char *box, char *s1);

#ifdef __cplusplus
}
#endif
#endif