#include "ds_BoxStick1.h"

ds_error ds_initialize_Stick_1(char *box, char *s1, char *s2)
{
	ds_error fail = DS_EOK;
	Stick_1 tempstruct;
	char aliasname0[64];
	char aliasname1[64];
	char aliasname2[64];
	char aliasname3[64];

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating alias pitch_a
	sprintf(aliasname0, "%s.COP.STI1.pitch_a", s1);
	fail = ds_new_alias(aliasname0, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI at creating alias pitch_a\n");
		return fail;
	}

	//creating alias roll_a
	sprintf(aliasname1, "%s.COP.STI1.roll_a", s1);
	fail = ds_new_alias(aliasname1, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI at creating alias roll_a\n");
		return fail;
	}

	//creating alias steering_wheel
	sprintf(aliasname2, "%s.COP.STI1.steering_wheel", s1);
	fail = ds_new_alias(aliasname2, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI at creating alias steering wheel\n");
		return fail;
	}

	//creating alias ap_disconnect
	sprintf(aliasname3, "%s.COP.STI1.ap_disconnect", s1);
	fail = ds_new_alias(aliasname3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI at creating alias ap_disconnect\n");
		return fail;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating box "box"
	fail = ds_create_box(box, sizeof(Stick_1), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.pitch_a,
		aliasname1, (char *)&tempstruct.roll_a,
		aliasname2, (char *)&tempstruct.steering_wheel,
		aliasname3, (char *)&tempstruct.ap_disconnect,
		(char *)NULL);

	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI at creating the box\n");
		return fail;
	}
	return fail;
}