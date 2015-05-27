#include "ds_BoxFCU.h"

ds_error ds_initialize_FCU(char *box, char *s1)
{
	ds_error fail = DS_EOK;

	FCU tempstruct;

	char control_knob0[64];
	char control_knob1[64];
	char control_knob2[64];
	char control_knob3[64];

	char inc_dial0[64];
	char inc_dial1[64];
	char inc_dial2[64];
	char inc_dial3[64];

	char lcd_counter0[64];
	char lcd_counter1[64];
	char lcd_counter2[64];
	char lcd_counter3[64];

	char lcd_light0[64];
	char lcd_light1[64];
	char lcd_light2[64];

	char lcd_textlight0[64];
	char lcd_textlight1[64];
	char lcd_textlight2[64];
	char lcd_textlight3[64];
	char lcd_textlight4[64];

	char push_button0[64];
	char push_button1[64];
	char push_button2[64];
	char push_button3[64];
	char push_button4[64];
	char push_button5[64];
	char push_button6[64];
	char push_button7[64];
	char push_button8[64];

	char rot_switch0[64];


	//------------------------------------------------

	//creating alias

	sprintf(control_knob0, "%s.COP.PNL.GLA.FCU.control_knob0", s1);
	sprintf(control_knob1, "%s.COP.PNL.GLA.FCU.control_knob1", s1);
	sprintf(control_knob2, "%s.COP.PNL.GLA.FCU.control_knob2", s1);
	sprintf(control_knob3, "%s.COP.PNL.GLA.FCU.control_knob3", s1);

	sprintf(inc_dial0, "%s.COP.PNL.GLA.FCU.inc_dial0", s1);
	sprintf(inc_dial1, "%s.COP.PNL.GLA.FCU.inc_dial1", s1);
	sprintf(inc_dial2, "%s.COP.PNL.GLA.FCU.inc_dial2", s1);
	sprintf(inc_dial3, "%s.COP.PNL.GLA.FCU.inc_dial3", s1);

	sprintf(lcd_counter0, "%s.COP.PNL.GLA.FCU.lcd_counter0", s1);
	sprintf(lcd_counter1, "%s.COP.PNL.GLA.FCU.lcd_counter1", s1);
	sprintf(lcd_counter2, "%s.COP.PNL.GLA.FCU.lcd_counter2", s1);
	sprintf(lcd_counter3, "%s.COP.PNL.GLA.FCU.lcd_counter3", s1);

	sprintf(lcd_light0, "%s.COP.PNL.GLA.FCU.lcd_light0", s1);
	sprintf(lcd_light1, "%s.COP.PNL.GLA.FCU.lcd_light1", s1);
	sprintf(lcd_light2, "%s.COP.PNL.GLA.FCU.lcd_light2", s1);

	sprintf(lcd_textlight0, "%s.COP.PNL.GLA.FCU.lcd_textlight0", s1);
	sprintf(lcd_textlight1, "%s.COP.PNL.GLA.FCU.lcd_textlight1", s1);
	sprintf(lcd_textlight2, "%s.COP.PNL.GLA.FCU.lcd_textlight2", s1);
	sprintf(lcd_textlight3, "%s.COP.PNL.GLA.FCU.lcd_textlight3", s1);
	sprintf(lcd_textlight4, "%s.COP.PNL.GLA.FCU.lcd_textlight4", s1);

	sprintf(push_button0, "%s.COP.PNL.GLA.FCU.push_button0", s1);
	sprintf(push_button1, "%s.COP.PNL.GLA.FCU.push_button1", s1);
	sprintf(push_button2, "%s.COP.PNL.GLA.FCU.push_button2", s1);
	sprintf(push_button3, "%s.COP.PNL.GLA.FCU.push_button3", s1);
	sprintf(push_button4, "%s.COP.PNL.GLA.FCU.push_button4", s1);
	sprintf(push_button5, "%s.COP.PNL.GLA.FCU.push_button5", s1);
	sprintf(push_button6, "%s.COP.PNL.GLA.FCU.push_button6", s1);
	sprintf(push_button7, "%s.COP.PNL.GLA.FCU.push_button7", s1);
	sprintf(push_button8, "%s.COP.PNL.GLA.FCU.push_button8", s1);

	sprintf(rot_switch0, "%s.COP.PNL.GLA.FCU.rot_switch0", s1);

	//control_knob0...3
	fail = ds_new_alias(control_knob0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", control_knob0);
		return fail;
	}

	fail = ds_new_alias(control_knob1, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", control_knob1);
		return fail;
	}

	fail = ds_new_alias(control_knob2, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", control_knob2);
		return fail;
	}

	fail = ds_new_alias(control_knob3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", control_knob3);
		return fail;
	}



	//inc_dial0...3
	fail = ds_new_alias(inc_dial0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", inc_dial0);
		return fail;
	}

	fail = ds_new_alias(inc_dial1, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", inc_dial1);
		return fail;
	}

	fail = ds_new_alias(inc_dial2, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", inc_dial2);
		return fail;
	}

	fail = ds_new_alias(inc_dial3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", inc_dial3);
		return fail;
	}
	

	//lcd_counter0...3
	fail = ds_new_alias(lcd_counter0, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_counter0);
		return fail;
	}

	fail = ds_new_alias(lcd_counter1, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_counter1);
		return fail;
	}

	fail = ds_new_alias(lcd_counter2, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_counter2);
		return fail;
	}

	fail = ds_new_alias(lcd_counter3, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_counter3);
		return fail;
	}


	//lcd_light0...2
	fail = ds_new_alias(lcd_light0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_light0);
		return fail;
	}

	fail = ds_new_alias(lcd_light1, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_light1);
		return fail;
	}

	fail = ds_new_alias(lcd_light2, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_light2);
		return fail;
	}


	//lcd_textlight0...4
	fail = ds_new_alias(lcd_textlight0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_textlight0);
		return fail;
	}

	fail = ds_new_alias(lcd_textlight1, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_textlight1);
		return fail;
	}

	fail = ds_new_alias(lcd_textlight2, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_textlight2);
		return fail;
	}

	fail = ds_new_alias(lcd_textlight3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_textlight3);
		return fail;
	}

	fail = ds_new_alias(lcd_textlight4, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", lcd_textlight4);
		return fail;
	}


	//push_button0...8
	fail = ds_new_alias(push_button0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button0);
		return fail;
	}

	fail = ds_new_alias(push_button1, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button1);
		return fail;
	}

	fail = ds_new_alias(push_button2, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button2);
		return fail;
	}

	fail = ds_new_alias(push_button3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button3);
		return fail;
	}

	fail = ds_new_alias(push_button4, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button4);
		return fail;
	}

	fail = ds_new_alias(push_button5, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button5);
		return fail;
	}

	fail = ds_new_alias(push_button6, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button6);
		return fail;
	}

	fail = ds_new_alias(push_button7, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button7);
		return fail;
	}

	fail = ds_new_alias(push_button8, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", push_button8);
		return fail;
	}


	//rot_switch0

	fail = ds_new_alias(rot_switch0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", rot_switch0);
		return fail;
	}

	//-----------------------------------------------------------------------------------------------------------------

	//creating box

	fail = ds_create_box(box, sizeof(FCU), (char *)&tempstruct,
		control_knob0, (char *)&tempstruct.control_knob0,
		control_knob1, (char *)&tempstruct.control_knob1,
		control_knob2, (char *)&tempstruct.control_knob2,
		control_knob3, (char *)&tempstruct.control_knob3,

		inc_dial0, (char *)&tempstruct.inc_dial0,
		inc_dial1, (char *)&tempstruct.inc_dial1,
		inc_dial2, (char *)&tempstruct.inc_dial2,

		lcd_counter0, (char *)&tempstruct.lcd_counter0,
		lcd_counter1, (char *)&tempstruct.lcd_counter1,
		lcd_counter2, (char *)&tempstruct.lcd_counter2,
		lcd_counter3, (char *)&tempstruct.lcd_counter3,

		lcd_light0, (char *)&tempstruct.lcd_light0,
		lcd_light1, (char *)&tempstruct.lcd_light1,
		lcd_light2, (char *)&tempstruct.lcd_light2,

		lcd_textlight0, (char *)&tempstruct.lcd_textlight0,
		lcd_textlight1, (char *)&tempstruct.lcd_textlight1,
		lcd_textlight2, (char *)&tempstruct.lcd_textlight2,
		lcd_textlight3, (char *)&tempstruct.lcd_textlight3,
		lcd_textlight4, (char *)&tempstruct.lcd_textlight4,

		push_button0, (char *)&tempstruct.push_button0,
		push_button1, (char *)&tempstruct.push_button1,
		push_button2, (char *)&tempstruct.push_button2,
		push_button3, (char *)&tempstruct.push_button3,
		push_button4, (char *)&tempstruct.push_button4,
		push_button5, (char *)&tempstruct.push_button5,
		push_button6, (char *)&tempstruct.push_button6,
		push_button7, (char *)&tempstruct.push_button7,
		push_button8, (char *)&tempstruct.push_button8,
		(char *)NULL
		);

	if (fail != DS_EOK)
	{
		printf("Fail in creating new box %s\n", box);
		return fail;
	}
}