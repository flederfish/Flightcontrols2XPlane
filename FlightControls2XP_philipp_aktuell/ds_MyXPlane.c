/*****************************************************************
 Box to be Read from Datapool
 Contains Hardware Ouputs
 *****************************************************************/

#include "ds_MyXPlane.h"

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Stick_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     my_ds_initialize_STI(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.STI1.pitch_a
 *         "box"---|-----"s1".COP.STI1.roll_a
 *                 |-----"s1".COP.STI2.pitch_a
 *                 |-----"s1".COP.STI2.roll_a
 *                 |-----"s1".COP.PNL.PDS.thrust_lev1
 *
 *	a = angle, f = force (both normalized)
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 *               s2  : STI1, STI2
 ****************************************************************************/
ds_error ds_initialize_Controls(char *boxname , char *s1) {

  CONTROLS_T tempstruct;

  char string1 [255];
  char string2 [255];
  char string3 [255];
  char string4 [255];
  char string5 [255];
  char string6 [255];
  char string7[255];
  char string8[255];
  char string9[255];
  char string10[255];
  char string11[255];
  

  sprintf(string1,"%s.COP.STI1.pitch_a" ,s1);
  ds_new_alias(string1,"float","0",(char*)  0,(char*)  0,(char*)  0); 

  sprintf(string2,"%s.COP.STI1.roll_a" ,s1);
  ds_new_alias(string2,"float","0",(char*)  0,(char*)  0,(char*)  0); 

  sprintf(string3,"%s.COP.STI2.pitch_a" ,s1);
  ds_new_alias(string3,"float","0",(char*)  0,(char*)  0,(char*)  0); 

  sprintf(string4,"%s.COP.STI2.roll_a" ,s1);
  ds_new_alias(string4,"float","0",(char*)  0,(char*)  0,(char*)  0); 

  sprintf(string5,"%s.COP.PNL.PDS.thrust_lev1" ,s1);
  ds_new_alias(string5,"float","0",(char*)  0,(char*)  0,(char*)  0);

  sprintf(string6, "%s.COP.PNL.PDS.thrust_lev2", s1);
  ds_new_alias(string6, "float", "0", (char*)0, (char*)0, (char*)0);

  sprintf(string7, "%s.COP.PNL.PDS.speed_brakes", s1);
  ds_new_alias(string7, "short", "0", (char*)0, (char*)0, (char*)0);

  sprintf(string8, "%s.COP.PNL.PDS.flaps", s1);
  ds_new_alias(string8, "short", "0", (char*)0, (char*)0, (char*)0);

  sprintf(string9, "%s.COP.PNL.PDS.park_brakes", s1);
  ds_new_alias(string9, "short", "0", (char*)0, (char*)0, (char*)0);
  
  sprintf(string10, "%s.COP.PNL.PDS.RUD_TR.touch_button0", s1);
  ds_new_alias(string10, "short", "0", (char*)0, (char*)0, (char*)0);

  sprintf(string11, "%s.COP.PNL.PDS.RUD_TR.rot_switch0", s1);
  ds_new_alias(string11, "short", "0", (char*)0, (char*)0, (char*)0);


  ds_create_box (boxname, sizeof(CONTROLS_T) , (char *)&tempstruct,
                 string1,            (char *)&tempstruct.stick1_pitch,
                 string2,            (char *)&tempstruct.stick1_roll,
                 string3,            (char *)&tempstruct.stick2_pitch,
                 string4,            (char *)&tempstruct.stick2_roll,
                 string5,            (char *)&tempstruct.thrust_lever_left,
				 string6,			 (char *)&tempstruct.thrust_lever_right,
				 string7,			 (char *)&tempstruct.speedbrake_lever,
				 string8,            (char *)&tempstruct.flap_lever,
				 string9,            (char *)&tempstruct.parkbrake,
				 string10,			 (char *)&tempstruct.ruddertrim_resetbutton,
				 string11,			 (char *)&tempstruct.ruddertrim_switch,
                 (char *) 0);

  return DS_EOK;

}


