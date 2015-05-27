#include "ds_BoxPedalbox1.h"

ds_error ds_initialize_Pedalbox1(char *box, char *s1)
{
	ds_error fail = DS_EOK;
	Pedalbox1 tempstruct;
	char aliasname0[64];
	char aliasname1[64];
	char aliasname2[64];

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating alias rudder
	sprintf(aliasname0, "%s.COP.PED1.rudder", s1);
	fail = ds_new_alias(aliasname0, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PED1 at creating alias rudder\n");
		return fail;
	}

	//creating alias brake left
	sprintf(aliasname1, "%s.COP.PED1.brake_l", s1);
	fail = ds_new_alias(aliasname1, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PED1 at creating alias brake left\n");
		return fail;
	}

	//creating alias brake right
	sprintf(aliasname2, "%s.COP.PED1.brake_r", s1);
	fail = ds_new_alias(aliasname2, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PED1 at creating alias brake right\n");
		return fail;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating box "box"
	fail = ds_create_box(box, sizeof(Pedalbox1), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.rudder,
		aliasname1, (char *)&tempstruct.brake_l,
		aliasname2, (char *)&tempstruct.brake_r,
		(char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PED1 at creating box\n");
		return fail;
	}

	return fail;
}
