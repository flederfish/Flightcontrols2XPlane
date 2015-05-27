#ifndef _DS_BOXEFIS2
#define _DS_BOXEFIS2

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct 
	{

		short control_knob0;
		int inc_dial0;
		float lcd_counter0;
		short lcd_textlight0;
		short pushbutton0;
		short pushbutton1;
		short radiobutton0;
		short radiobutton1;
		short radiobutton2;
		short radiobutton3;
		short radiobutton4;
		short rot_switch0;
		short rot_switch1;
		short rot_switch2;
		short toggle_switch0;
		short toggle_switch1;

	}EFIS2;

	ds_error ds_initialize_EFIS_2(char *box, char *s1);

#ifdef __cplusplus
}

#endif
#endif