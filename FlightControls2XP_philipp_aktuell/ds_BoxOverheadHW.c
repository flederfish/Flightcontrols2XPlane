#include "ds_BoxOverheadHW.h"

ds_error ds_initialize_OVH_HW(char *box, char *s1)
{
	ds_error fail = DS_EOK;
	Overhead_Hardware tempstruct;

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

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating alias toggleswitch0
	sprintf(aliasname0, "%s.COP.PNL.OVH_HW.toggle_switch0", s1);
	fail = ds_new_alias(aliasname0, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname0);
		return fail;
	}

	//creating alias toggleswitch1
	sprintf(aliasname1, "%s.COP.PNL.OVH_HW.toggle_switch1", s1);
	fail = ds_new_alias(aliasname1, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname1);
		return fail;
	}

	//creating alias toggleswitch2
	sprintf(aliasname2, "%s.COP.PNL.OVH_HW.toggle_switch2", s1);
	fail = ds_new_alias(aliasname2, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname2);
		return fail;
	}

	//creating alias toggleswitch3
	sprintf(aliasname3, "%s.COP.PNL.OVH_HW.toggle_switch3", s1);
	fail = ds_new_alias(aliasname3, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname3);
		return fail;
	}

	//creating alias toggleswitch4
	sprintf(aliasname4, "%s.COP.PNL.OVH_HW.toggle_switch4", s1);
	fail = ds_new_alias(aliasname4, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname4);
		return fail;
	}

	//creating alias toggleswitch5
	sprintf(aliasname5, "%s.COP.PNL.OVH_HW.toggle_switch5", s1);
	fail = ds_new_alias(aliasname5, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname5);
		return fail;
	}

	//creating alias toggleswitch6
	sprintf(aliasname6, "%s.COP.PNL.OVH_HW.toggle_switch6", s1);
	fail = ds_new_alias(aliasname6, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname6);
		return fail;
	}

	//creating alias toggleswitch7
	sprintf(aliasname7, "%s.COP.PNL.OVH_HW.toggle_switch7", s1);
	fail = ds_new_alias(aliasname7, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname7);
		return fail;
	}

	//creating alias toggleswitch8
	sprintf(aliasname8, "%s.COP.PNL.OVH_HW.toggle_switch8", s1);
	fail = ds_new_alias(aliasname8, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname8);
		return fail;
	}

	//creating alias toggleswitch9
	sprintf(aliasname9, "%s.COP.PNL.OVH_HW.toggle_switch9", s1);
	fail = ds_new_alias(aliasname9, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname9);
		return fail;
	}

	//creating alias toggleswitch10
	sprintf(aliasname10, "%s.COP.PNL.OVH_HW.toggle_switch10", s1);
	fail = ds_new_alias(aliasname10, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname10);
		return fail;
	}

	//creating alias toggleswitch11
	sprintf(aliasname11, "%s.COP.PNL.OVH_HW.toggle_switch11", s1);
	fail = ds_new_alias(aliasname11, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname11);
		return fail;
	}

	//creating alias toggleswitch12
	sprintf(aliasname12, "%s.COP.PNL.OVH_HW.toggle_switch12", s1);
	fail = ds_new_alias(aliasname12, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname12);
		return fail;
	}

	//creating alias toggleswitch13
	sprintf(aliasname13, "%s.COP.PNL.OVH_HW.toggle_switch13", s1);
	fail = ds_new_alias(aliasname13, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating alias %s \n", aliasname13);
		return fail;
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//creating box "box"
	fail = ds_create_box(box, sizeof(Overhead_Hardware), (char *)&tempstruct,
		aliasname0, (char *)&tempstruct.toggle_switch0,
		aliasname1, (char *)&tempstruct.toggle_switch1,
		aliasname2, (char *)&tempstruct.toggle_switch2,
		aliasname3, (char *)&tempstruct.toggle_switch3,
		aliasname4, (char *)&tempstruct.toggle_switch4,
		aliasname5, (char *)&tempstruct.toggle_switch5,
		aliasname6, (char *)&tempstruct.toggle_switch6,
		aliasname7, (char *)&tempstruct.toggle_switch7,
		aliasname8, (char *)&tempstruct.toggle_switch8,
		aliasname9, (char *)&tempstruct.toggle_switch9,
		aliasname10, (char *)&tempstruct.toggle_switch10,
		aliasname11, (char *)&tempstruct.toggle_switch11,
		aliasname12, (char *)&tempstruct.toggle_switch12,
		aliasname13, (char *)&tempstruct.toggle_switch13,
		(char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_OVH_HW at creating box %s \n", box);
		return fail;
	}

	return fail;
}