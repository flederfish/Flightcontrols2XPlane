/*****************************************************************************
* Methodname   : CONTROLS Box
*****************************************************************************
*
* Description  : Contains data read from datapool. For now Sticks and Thrust
*                
* Category     :
*
* Author:       Date:    Change:
  Schulze       10.12.14 new
* ------------- -------- ---------------------------------------------------- 
 * Parameter in : 
 * Parameter out: 
 * Description  : 
 * called by    : 
 * calls        : 
 * Note         : 
 * Bugs         : 
 * Todo         : 
 * Files        :
 * See also     : 
 * Diagnostics  : 
 * Testsuggest. : 
 *                                                         
 *****************************************************************************/

#ifndef _ds_CONTROLS_
#define _ds_CONTROLS_

#include "ds_error.h"
#include "ds_interface.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  /* Stick CPT (STICK 1) Pitch */
  float stick1_pitch;
  /* Stick CPT (STICK 1) Roll */
  float stick1_roll;
  /* Stick FO (STICK 2) Pitch */
  float stick2_pitch;
  /* Stick FO (STICK 2) Roll */
  float stick2_roll;
  /* left Thrust Lever Position */
  float thrust_lever_left;
  /* right Thrust Lever Position */
  float thrust_lever_right;
  /*speedbrake lever position*/
  short speedbrake_lever;
  /*flap lever position*/
  short flap_lever;
  /*parkbrake on/off*/
  short parkbrake;
  /*rudder trim switch*/
  short ruddertrim_switch;
  /*rudder trim reset button*/
  short ruddertrim_resetbutton;

	 
}CONTROLS_T;

ds_error ds_initialize_Controls(char *boxname , char *s1);

#ifdef __cplusplus
}
#endif

#endif
