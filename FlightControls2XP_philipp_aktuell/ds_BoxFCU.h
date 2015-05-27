#ifndef _DS_BOXFCU_H_
#define _DS_BOXFCU_H_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct
	{
		//2 if knob has been pushed; 1 if knob has been pulled

		short control_knob0;			//Speed Select
		short control_knob1;			//Heading Select
		short control_knob2;			//Altitude Select
		short control_knob3;			//Vertical Speed Select

		short inc_dial0;			
		short inc_dial1;
		short inc_dial2;
		short inc_dial3;

		float lcd_counter0;
		float lcd_counter1;
		float lcd_counter2;
		float lcd_counter3;

		short lcd_light0;
		short lcd_light1;
		short lcd_light2;

		short lcd_textlight0;
		short lcd_textlight1;
		short lcd_textlight2;
		short lcd_textlight3;
		short lcd_textlight4;

		short push_button0;			//speed mach selector button
		short push_button1;			//heading track selector button
		short push_button2;			//
		short push_button3;			//AP1 engage
		short push_button4;			//AP2 engage
		short push_button5;			//loc button
		short push_button6;			//auto throttle engage
		short push_button7;
		short push_button8;			//APPR button

		short rot_switch0;
	}FCU;

	ds_error ds_initialize_FCU(char *box, char *s1);


#ifdef __cplusplus
}
#endif

#endif
