#include "ds_BoxStick2.h"

ds_error ds_initialize_Stick_2(char *box, char *s1, char *s2)
{
	ds_error fail = DS_EOK;
	Stick_2 tempstruct;
	char aliasname0[64];
	char aliasname1[64];
	char aliasname2[64];
	char aliasname3[64];

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating alias pitch_a
	sprintf(aliasname0, "%s.COP.STI2.pitch_a", s1);
	fail = ds_new_alias(aliasname0, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI2 at creating alias pitch_a\n");
		return fail;
	}

	//creating alias roll_a
	sprintf(aliasname1, "%s.COP.STI2.roll_a", s1);
	fail = ds_new_alias(aliasname1, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI2 at creating alias roll_a\n");
		return fail;
	}

	//creating alias steering_wheel
	sprintf(aliasname2, "%s.COP.STI2.steering_wheel", s1);
	fail = ds_new_alias(aliasname2, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI2 at creating alias steering wheel\n");
		return fail;
	}

	//creating alias ap_disconnect
	sprintf(aliasname3, "%s.COP.STI2.ap_disconnect", s1);
	fail = ds_new_alias(aliasname3, "short", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI2 at creating alias ap_disconnect\n");
		return fail;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating box "box"
	fail = ds_create_box(box, sizeof(Stick_2), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.pitch_a,
		aliasname1, (char *)&tempstruct.roll_a,
		aliasname2, (char *)&tempstruct.steering_wheel,
		aliasname3, (char *)&tempstruct.ap_disconnect,
		(char *)NULL);

	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_STI2 at creating the box\n");
		return fail;
	}
	return fail;
}