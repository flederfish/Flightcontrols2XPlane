#ifndef _GLOBAL_H
#define _GLOBAL_H



#define DEBUG	  1
#define XPLM200	  1
#define XPLM2100  1

//-------------------------------------------
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "octopus/ds_error.h"
#include "octopus/ds_init.h"
#include "octopus/ds_interface.h"

#include "NetworkDatapool.h"
#include "guicon.h"
#include "data.h"
#include "global.h"

#include "XPLM/XPLMPlugin.h"
#include "XPLM/XPLMProcessing.h"
#include "XPLM/XPLMDataAccess.h"
#include "XPLM/XPLMUtilities.h"
//---------------------------------------------

XPLMDataRef local_has_joystick;				// Is a joystick being used? (Always Yes) int, boolean
XPLMDataRef local_mouse_is_joystick;		// Is mouse acting as joystick (Always No!!) int, boolean
XPLMDataRef local_yoke_pitch_ratio;			// Deflection of Joystick Pitch Axis [-1...1] float
XPLMDataRef local_yoke_roll_ratio;			// Deflection of Joystick Roll Axis [-1...1] float
XPLMDataRef local_yoke_heading_ratio;		//Deflection of Joystick Rudder Axis float
XPLMDataRef local_ENGN_thro_use;			// Throttle (per engine) when overridden [0...1] float[8] float array maximum 8 engines, Reversers??
XPLMDataRef local_override_joystick;		// Override control of joystick deflections, int boolean (VALUES FOR ALL THREE JOYSTICK AXES MUST BE PROVIDED)
XPLMDataRef local_override_throttles;       // Override throttles, int boolean 
XPLMDataRef local_speedbrake_ratio;			//deflection of speedbrake [0...1] float
XPLMDataRef local_flap_ratio;				//deflection of flaps [0...1] float
XPLMDataRef local_gearlever_position;       //deflection of gear position 0=up 1=down
XPLMDataRef local_parkingbrake_ratio;		//deflection of park brake [0...1] float
XPLMDataRef local_thrustlever_position;     //float[4]
XPLMDataRef local_ENGN_thro;                //float[8] TODO
XPLMDataRef local_throttle_ratio;           //float[8] position of thrust lever itself
XPLMDataRef local_left_brake_ratio;			//deflection of left brake pedal [0...1] float
XPLMDataRef local_right_brake_ratio;        //deflection of right brake pedal [0...1] float
XPLMDataRef local_acr_on_ground;            //is 1 when acr is on the ground

//FCU efis1 (cpt)
XPLMDataRef local_EFIS1_FD_engageCapt;
XPLMDataRef local_EFIS1_ILSonCap;
XPLMDataRef local_EFIS1_Baro_Std_Capt;		//push or pull the knob
XPLMDataRef local_EFIS1_Baro_Setting_in_hg_pilot; // xplane actual barometer value float
XPLMDataRef local_EFIS1_Baro_Unit_Capt;		//select unit for barometer mBar or Inch of mc blbl
XPLMDataRef local_EFIS1_WPTCapt;
XPLMDataRef local_EFIS1_VORDCapt;
XPLMDataRef local_EFIS1_NDBCapt;
XPLMDataRef local_EFIS1_ARPTCapt;
XPLMDataRef local_EFIS1_toggleswitch0;
XPLMDataRef local_EFIS1_toggleswitch1;
XPLMDataRef local_EFIS1_NDmodeCapt;
XPLMDataRef local_EFIS1_NDrangeCapt;

//FCU efis2 (fo)
XPLMDataRef local_EFIS2_FD_engageFO;
XPLMDataRef local_EFIS2_ILSonFO;
XPLMDataRef local_EFIS2_Baro_StdFO;
XPLMDataRef local_EFIS2_Baro_setting_in_hg_fo;
XPLMDataRef local_EFIS2_Baro_Unit_FO;
XPLMDataRef local_EFIS2_WPTFO;
XPLMDataRef local_EFIS2_VORDFO;
XPLMDataRef local_EFIS2_NDBFO;
XPLMDataRef local_EFIS2_ARPTFO;
XPLMDataRef local_EFIS2_toggleswitch0_FO;
XPLMDataRef local_EFIS2_toggleswitch1_FO;
XPLMDataRef local_EFIS2_NDmodeFO;
XPLMDataRef local_EFIS2_NDrangeFO;

//FCU FCU
XPLMCommandRef local_FCU_LOCButton;					//command for pressing the LOC button on the fcu
XPLMCommandRef local_FCU_ATHRButton;				//command for pressing auto throttle button
XPLMCommandRef local_FCU_APPRButton;				//...

XPLMCommandRef local_FCU_PullSPDSelect;				//Command for pulling the Speed selector knob 
XPLMCommandRef local_FCU_PushSPDSelect;				//Command for pushing the Speed selector knob

XPLMCommandRef local_FCU_PullHDGSelect;				//heading selector knob
XPLMCommandRef local_FCU_PushHDGSelect;

XPLMCommandRef local_FCU_PullALTSelect;				//altitude selector knob
XPLMCommandRef local_FCU_PushALTSelect;

XPLMCommandRef local_FCU_PullVSSelect;				//vertical speed selector knob
XPLMCommandRef local_FCU_PushVSSelect;

XPLMDataRef local_FCU_airspeedismach;
XPLMDataRef local_FCU_airspeed;						//value for velocity shown on the fcu display
XPLMDataRef local_FCU_AP1Engange;
XPLMDataRef local_FCU_AP2Engange;
XPLMDataRef local_FCU_HDGTRKmode;
XPLMDataRef local_FCU_MetricAltmode;
XPLMDataRef local_FCU_heading_mag;					//value for heading shown on the fcu
XPLMDataRef local_FCU_vertical_velocity;			//value for vertical velocity shown on fcu
XPLMDataRef local_FCU_Altitude;						//value for altitude shown on fcu


XPLMCommandRef local_ruddertrim_right;		//command if you turn the switch right
XPLMCommandRef local_ruddertrim_left;
XPLMCommandRef local_ruddertrim_center;		//command to be executed when the reset button is pressed

//-------------------------------------------------------------------------------------------------------
NetworkDatapool *dp;

char		World[64] = "WORLD1";
char		Acr[8] = "ACR1";

float time_since_last_loop = 0;

data da;

//------------------------------------------------------------------------------------------------------

/*	\brief	maps 1 Value from one specific output range to another specific output range.
 *	
 *	\param	x	the value to be mapped
 *	\param in_min	minimum value x can have
 *	\param in_max	maximum value x can have
 *	\param out_min	minimum value you want the output to have
 *	\param out_max	maximum value you want the output to have
 *
 *	\return the mapped value
 */
float map(float x, float in_min, float in_max, float out_min, float out_max);


/*	\brief	Reads the data from the data object (only FCU data) and writes the matching datarefs or 
 *	 uses matching commands in xplane
 */
void write_FCU();


/*	\brief	Reads the data from the data object (only EFIS1 + EFIS2 data) and writes the matching datarefs or
 *	 uses matching commands in xplane
 */
void write_EFIS();


/*	\brief	Reads the data from the data object (data for control e.g. sticks, pedals, flaps, gears....) and writes the matching datarefs or
 *	 uses matching commands in xplane
 */
void write_general_controls();


/*	\brief	Function which is registered as the flightloop and is called periodically by xplane
 */
float	MyFlightLoopCallback(float inElapsedSinceLastCall,
	float inElapsedTimeSinceLastFlightLoop,
	int   inCounter,
	void *inRefcon);


/*	\brief	Function which searches all qpac datarefs and should be called once in the flightloop
 */
void find_qpac_datarefs();

#endif