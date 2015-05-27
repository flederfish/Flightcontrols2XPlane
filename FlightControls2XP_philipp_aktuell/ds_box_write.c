#include "ds_box_write.h"

ds_error ds_initialize_box_write(char *boxname, char *s1)
{
	ds_error fail = DS_EOK;
	flags tempstruct;
	char aliasname0[64];
	char aliasname1[64];
	char aliasname2[64];

	//creating alias ap1_flag
	sprintf(aliasname0, "%s.AST.API.ap1_flag", s1);
	fail = ds_new_alias(aliasname0, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_box_write at creating alias ap1_flag\n");
		return fail;
	}

	//creating alias ap2_flag
	sprintf(aliasname1, "%s.AST.API.ap2_flag", s1);
	fail = ds_new_alias(aliasname1, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_box_write at creating alias ap2_flag\n");
		return fail;
	}

	//creating alias athr_flag
	sprintf(aliasname2, "%sAST.API.athr_flag", s1);
	fail = ds_new_alias(aliasname2, "short", "0", (char *)NULL, (char *)NULL, (char *)NULL);
	if (fail != DS_EOK)
	{
		printf("Fail in ds_initialize_box_write at creating alias athr_flag\n");
		return fail;
	}

}