#include "ds_BoxPedestal.h"

ds_error ds_initialize_Pedestal(char *box, char *s1)
{
	ds_error fail = DS_EOK;
	Pedestal_Basics tempstruct;
	char aliasname0[64];
	char aliasname1[64];
	char aliasname2[64];
	char aliasname3[64];
	char aliasname4[64];
	char aliasname5[64];
	char aliasname6[64];

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating new alias thrust_lev1
	sprintf(aliasname0, "%s.COP.PNL.PDS.thrust_lev1", s1);
	fail = ds_new_alias(aliasname0, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias thrust_lev1\n");
		return fail;
	}

	//creatring new alias thrust_lev2
	sprintf(aliasname1, "%s.COP.PNL.PDS.thrust_lev2", s1);
	fail = ds_new_alias(aliasname1, "float", "0.0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias thrust_lev2\n");
		return fail;
	}

	//creating new alias rev_thrust
	sprintf(aliasname2, "%s.COP.PNL.PDS.rev_thrust", s1);
	fail = ds_new_alias(aliasname2, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias rev_thrust\n");
		return fail;
	}

	//creating new alias athr_disconnect
	sprintf(aliasname3, "%s.COP.PNL.PDS.athr_disconnect", s1);
	fail = ds_new_alias(aliasname3, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias athr_disconnect\n");
		return fail;
	}

	//creating new alias flaps
	sprintf(aliasname4, "%s.COP.PNL.PDS.flaps", s1);
	fail = ds_new_alias(aliasname4, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias flaps\n");
		return fail;
	}

	//creating new alias speedbrakes
	sprintf(aliasname5, "%s.COP.PNL.PDS.speed_brakes", s1);
	fail = ds_new_alias(aliasname5, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias speed_brakes\n");
		return fail;
	}

	//creating new alias park_brake
	sprintf(aliasname6, "%s.COP.PNL.PDS.park_brakes", s1);
	fail = ds_new_alias(aliasname6, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating new alias park_brake\n");
		return fail;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating box PDS

	fail = ds_create_box(box, sizeof(tempstruct), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.thrust_lev1,
		aliasname1, (char *)&tempstruct.thrust_lev2,
		aliasname2, (char *)&tempstruct.rev_thrust,
		aliasname3, (char *)&tempstruct.athr_disconnect,
		aliasname4, (char *)&tempstruct.flaps,
		aliasname5, (char *)&tempstruct.speed_brakes,
		aliasname6, (char *)&tempstruct.park_brakes,
		(char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_PDS at creating the box\n");
		return fail;
	}

	return fail;
}