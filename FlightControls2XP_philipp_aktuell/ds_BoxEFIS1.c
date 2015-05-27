#include "ds_BoxEFIS1.h"

ds_error ds_initialize_EFIS_1(char *box, char *s1)
{
	ds_error fail = DS_EOK;
	EFIS1 tempstruct;
	char aliasname0[64];
	char aliasname1[64];
	char aliasname2[64];
	char aliasname3[64];
	char aliasname4[64];
	char aliasname5[64];
	char aliasname6[64];
	char aliasname7[64];
	char aliasname8[64];
	char aliasname9[64];
	char aliasname10[64];
	char aliasname11[64];
	char aliasname12[64];
	char aliasname13[64];
	char aliasname14[64];
	char aliasname15[64];

	//---------------------------------------------------------------------------------

	//creating alias button1
	
	sprintf(aliasname0, "%s.COP.PNL.GLA.EFIS1.control_knob0", s1);
	sprintf(aliasname1, "%s.COP.PNL.GLA.EFIS1.inc_dial0", s1);
	sprintf(aliasname2, "%s.COP.PNL.GLA.EFIS1.lcd_counter0", s1);
	sprintf(aliasname3, "%s.COP.PNL.GLA.EFIS1.lcd_textlight0", s1);
	sprintf(aliasname4, "%s.COP.PNL.GLA.EFIS1.push_button0", s1);
	sprintf(aliasname5, "%s.COP.PNL.GLA.EFIS1.push_button1", s1);
	sprintf(aliasname6, "%s.COP.PNL.GLA.EFIS1.radio_button0", s1);
	sprintf(aliasname7, "%s.COP.PNL.GLA.EFIS1.radio_button1", s1);
	sprintf(aliasname8, "%s.COP.PNL.GLA.EFIS1.radio_button2", s1);
	sprintf(aliasname9, "%s.COP.PNL.GLA.EFIS1.radio_button3", s1);
	sprintf(aliasname10, "%s.COP.PNL.GLA.EFIS1.radio_button4", s1);
	sprintf(aliasname11, "%s.COP.PNL.GLA.EFIS1.rot_switch0", s1);
	sprintf(aliasname12, "%s.COP.PNL.GLA.EFIS1.rot_switch1", s1);
	sprintf(aliasname13, "%s.COP.PNL.GLA.EFIS1.rot_switch2", s1);
	sprintf(aliasname14, "%s.COP.PNL.GLA.EFIS1.toggle_switch0", s1);
	sprintf(aliasname15, "%s.COP.PNL.GLA.EFIS1.toggle_switch1", s1);

	fail = ds_new_alias(aliasname0, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname0);
		return fail;
	}

	fail = ds_new_alias(aliasname1, "int", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname1);
		return fail;
	}

	fail = ds_new_alias(aliasname2, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname2);
		return fail;
	}

	fail = ds_new_alias(aliasname3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname3);
		return fail;
	}

	fail = ds_new_alias(aliasname4, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname4);
		return fail;
	}

	fail = ds_new_alias(aliasname5, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname5);
		return fail;
	}

	fail = ds_new_alias(aliasname6, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname6);
		return fail;
	}

	fail = ds_new_alias(aliasname7, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname7);
		return fail;
	}

	fail = ds_new_alias(aliasname8, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname8);
		return fail;
	}

	fail = ds_new_alias(aliasname9, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname9);
		return fail;
	}

	fail = ds_new_alias(aliasname10, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname10);
		return fail;
	}

	fail = ds_new_alias(aliasname11, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname11);
		return fail;
	}

	fail = ds_new_alias(aliasname12, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname12);
		return fail;
	}

	fail = ds_new_alias(aliasname13, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname13);
		return fail;
	}

	fail = ds_new_alias(aliasname14, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname14);
		return fail;
	}

	fail = ds_new_alias(aliasname15, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in creating new alias %s\n", aliasname15);
		return fail;
	}

	//-------------------------------------------------------------------------------------

	//creating box

	fail = ds_create_box(box, sizeof(EFIS1), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.control_knob0,
		aliasname1, (char *)&tempstruct.inc_dial0,
		aliasname2, (char *)&tempstruct.lcd_counter0,
		aliasname3, (char *)&tempstruct.lcd_textlight0,
		aliasname4, (char *)&tempstruct.pushbutton0,
		aliasname5, (char *)&tempstruct.pushbutton1,
		aliasname6, (char *)&tempstruct.radiobutton0,
		aliasname7, (char *)&tempstruct.radiobutton1,
		aliasname8, (char *)&tempstruct.radiobutton2,
		aliasname9, (char *)&tempstruct.radiobutton3,
		aliasname10, (char *)&tempstruct.radiobutton4,
		aliasname11, (char *)&tempstruct.rot_switch0,
		aliasname12, (char *)&tempstruct.rot_switch1,
		aliasname13, (char *)&tempstruct.rot_switch2,
		aliasname14, (char *)&tempstruct.toggle_switch0,
		aliasname15, (char *)&tempstruct.toggle_switch1,
		(char *)NULL);

	if (fail != DS_EOK)
	{
		printf("Fail in creating new box %s\n", box);
		return fail;
	}
}