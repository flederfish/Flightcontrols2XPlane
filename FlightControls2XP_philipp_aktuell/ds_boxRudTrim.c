#include "ds_BoxRudTrim.h"

ds_error ds_initialize_RUD_TRIM(char *box, char *s1)
{
	ds_error fail = DS_EOK;
	Rudder_Trim_Panel tempstruct;
	char aliasname0[64];
	char aliasname1[64];

	//creating alias for touchbutton0
	sprintf(aliasname0, "%s.COP.PNL.PDS.RUD_TR.touch_button0", s1);
	fail = ds_new_alias(aliasname0, "short", "0", (char*)0, (char*)0, (char*)0);
	if (fail != DS_EOK)
	{
		printf("Error in ds_initialize_RUD_TRIM at new_alias for touch_button0\n");
		return fail;
	}

	//creating alias for rot_switch
	sprintf(aliasname1, "%s.COP.PNL.PDS.RUD_TR.rot_switch0", s1);
	fail = ds_new_alias(aliasname1, "short", "0", (char*)0, (char*)0, (char*)0);
	if (fail != DS_EOK)
	{
		printf("Error in ds_initialize_RUD_TRIM at new_alias for rot_switch0\n");
		return fail;
	}

	//creating box RUD_TRIM
	fail = ds_create_box(box, sizeof(Rudder_Trim_Panel), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.touch_button0,
		aliasname1, (char *)&tempstruct.rot_switch0,
		(char *)0);
	if (fail != DS_EOK)
	{
		printf("Fail at ds_initialize_RUD_TRIM at creating box\n");
		return fail;
	}

	return fail;
}