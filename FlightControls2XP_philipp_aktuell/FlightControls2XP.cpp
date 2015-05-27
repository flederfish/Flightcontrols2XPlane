
#include "global.h"

PLUGIN_API int XPluginStart(char *outName, char *outSig, char *outDesc){
	//activate console
    #ifdef DEBUG
		RedirectIOToConsole();
    #endif

	//Define Name, Signature and Description of Plugin
	strcpy(outName, "FlightControls2XP");
	strcpy(outSig, "tud.fsr.CuF.FlightControls2XP");
	strcpy(outDesc, "Writes Hardwareoutput from Datapool to X-Plane");

	//Find XPLM Datarefs, only at startup (otherwise time consuming)
	local_override_joystick = XPLMFindDataRef("sim/operation/override/override_joystick");
	local_has_joystick = XPLMFindDataRef("sim/joystick/has_joystick");
	local_mouse_is_joystick = XPLMFindDataRef("sim/joystick/mouse_is_joystick");
	local_yoke_pitch_ratio = XPLMFindDataRef("sim/joystick/yoke_pitch_ratio");
	local_yoke_roll_ratio = XPLMFindDataRef("sim/joystick/yoke_roll_ratio");
	local_yoke_heading_ratio = XPLMFindDataRef("sim/joystick/yoke_heading_ratio");

	local_gearlever_position = XPLMFindDataRef("sim/cockpit2/controls/gear_handle_down");
	local_left_brake_ratio = XPLMFindDataRef("sim/cockpit2/controls/left_brake_ratio");
	local_right_brake_ratio = XPLMFindDataRef("sim/cockpit2/controls/right_brake_ratio");
	local_flap_ratio = XPLMFindDataRef("sim/cockpit2/controls/flap_ratio");
	local_speedbrake_ratio = XPLMFindDataRef("sim/cockpit2/controls/speedbrake_ratio");
	local_throttle_ratio = XPLMFindDataRef("sim/cockpit2/engine/actuators/throttle_ratio");

	local_ENGN_thro_use = XPLMFindDataRef("sim/flightmodel/engine/ENGN_thro_use");
	local_ENGN_thro = XPLMFindDataRef("sim/flightmodel/engine/ENGN_thro");
	
	local_override_throttles = XPLMFindDataRef("sim/operation/override/override_throttles");

	local_acr_on_ground = XPLMFindDataRef("sim/flightmodel/failures/onground_any");

	//Find XPLM Commands
	local_ruddertrim_left = XPLMFindCommand("sim/flight_controls/rudder_trim_left");
	local_ruddertrim_right = XPLMFindCommand("sim/flight_controls/rudder_trim_right");
	local_ruddertrim_center = XPLMFindCommand("sim/flight_controls/rudder_trim_center");
	
	
	std::cout << "PluginStart" << std::endl;
	return 1;
};


PLUGIN_API int XPluginEnable(void){
	/////Open Datapool Connection
	short success;
	std::cout << "enable, not connected" << std::endl;
	dp = new NetworkDatapool(World,Acr,1,success);		
	std::cout << "enable,  connected" << std::endl;

	/////Register/Start Flight Loop Callback
	XPLMRegisterFlightLoopCallback(		
		MyFlightLoopCallback,	/* Callback */
		-1.0,					/* Interval */
		NULL);					/* refcon not used. */



	std::cout << "PluginEnable" << std::endl;
	return 1;
};

PLUGIN_API void XPluginDisable(void){
	/////Disconnect Datapool
	dp->disconnect(); 

	/////Unregister/Stop Flight Loop Callback
	XPLMUnregisterFlightLoopCallback(MyFlightLoopCallback, NULL);
};

PLUGIN_API void XPluginStop(void)
{

};


float MyFlightLoopCallback(		   float                inElapsedSinceLastCall,    
                                   float                inElapsedTimeSinceLastFlightLoop,    
                                   int                  inCounter,    
                                   void *               inRefcon)
{

	//Find XPLM Datarefs, find custom (qpac) datarefs in flightloop, because otherwise it will be looked for before plane is loaded
	static int first_callback = 0;
	if (first_callback == 0)
	{
		first_callback = 1;
		find_qpac_datarefs();
	}

	/////Declare all Variables
	float yaw_pedals;
	float yaw_steeringwheel;
	float yaw_combined;
	float pitch_combined;
	float roll_combined;

	float thrust_array[8];
	
	float Ped1_left_brake_ratio;
	float Ped1_right_brake_ratio;
	float Ped2_left_brake_ratio;
	float Ped2_right_brake_ratio;
	float combined_left_brake_ratio;
	float combined_right_brake_ratio;
	float speedbrake_lever;
	float flap_lever;
	short parkbrake;

	int acr_on_ground;

	da.update(dp);
	
	//read data to see if the aircraft is on the ground
	acr_on_ground = XPLMGetDatai(local_acr_on_ground);

	yaw_pedals = da.get_pedal1().rudder * (-1) + da.get_pedal2().rudder * (-1);
	yaw_steeringwheel = da.get_stick1().steering_wheel * (-1) + da.get_stick2().steering_wheel * (-1);

	//check if maximum/minimum value is reached
	if (yaw_pedals > 1.0)
		yaw_pedals = 1.0;
	if(yaw_pedals < -1.0)
		yaw_pedals = -1.0;

	if (yaw_steeringwheel > 1.0)
		yaw_steeringwheel = 1.0;
	if (yaw_steeringwheel < -1.0)
		yaw_steeringwheel = -1.0;

	//get combined pitch/roll and check priority function
	da.check_stick_priority(pitch_combined, roll_combined, inElapsedSinceLastCall);

	parkbrake = da.get_pedestal().park_brakes;

	//map these values from 0..4 to 0..1
	speedbrake_lever = map( (float)da.get_pedestal().speed_brakes, 0, 4, 0, 1); 
	flap_lever = map( (float)da.get_pedestal().flaps, 0, 4, 0, 1);

	

	//----------------------------------------------------------------------------------------------------------------------------

	//combine pedals and steering wheel
	if (acr_on_ground)
	{
		yaw_combined = yaw_steeringwheel + ( (6 / 75) * yaw_pedals );
		if (yaw_combined > 1)
			yaw_combined = 1;

		if (yaw_combined < -1)
			yaw_combined = -1;
	}

	else
	{
		yaw_combined = yaw_pedals;
	}
	

	//calculate combined brake ratio
	combined_left_brake_ratio = da.get_pedal1().brake_l + da.get_pedal2().brake_l;
	combined_right_brake_ratio = da.get_pedal1().brake_r + da.get_pedal2().brake_r;

	//check if maximum/minimum value is reached
	if (combined_left_brake_ratio > 1)  
		combined_left_brake_ratio = 1;

	if (combined_right_brake_ratio > 1)
		combined_right_brake_ratio = 1;

	//Put Thrust Values in Array
	thrust_array[0] = da.get_pedestal().thrust_lev1;
	thrust_array[1] = da.get_pedestal().thrust_lev2;
	thrust_array[2] = 0;
	thrust_array[3] = 0;
	thrust_array[4] = 0;
	thrust_array[5] = 0;
	thrust_array[6] = 0;
	thrust_array[7] = 0;

	if ((thrust_array[0] >= 0) && (thrust_array[0] <= 0.59))
	{
		thrust_array[0] = map(thrust_array[0], 0, 0.6, 0, 0.9);
	}
	if (thrust_array[0] > 0.59)
		thrust_array[0] = map(thrust_array[0], 0.59, 1, 0.9, 1);
	if ((thrust_array[1] >= 0) && (thrust_array[1] <= 0.59))
	{
		thrust_array[1] = map(thrust_array[1], 0, 0.6, 0, 0.9);
	}
	if (thrust_array[1] > 0.59)
		thrust_array[1] = map(thrust_array[1], 0.59, 1, 0.9, 1);
	if (thrust_array[0] < 0.1)
		thrust_array[0] = 0;
	if (thrust_array[1] < 0.1)
		thrust_array[1] = 0;
	//////////////////////////////////////////
	//Set XPLM Values----------------------------------------------------------------------------------------------------------------------------

	//Static
	XPLMSetDatai(local_has_joystick, 1);
	XPLMSetDatai(local_mouse_is_joystick, 0);
	XPLMSetDatai(local_override_joystick, 1);
	XPLMSetDatai(local_override_throttles, 1);

	//set datarefs----------------------------------------------------------------------------------------------------------------------------------
	//combined controls
	XPLMSetDataf(local_yoke_pitch_ratio, pitch_combined);
	XPLMSetDataf(local_yoke_roll_ratio, roll_combined);
	XPLMSetDataf(local_yoke_heading_ratio, yaw_combined);

	//thrust values for engines
	XPLMSetDatavf(local_ENGN_thro_use, thrust_array,0,8);	//Array with elements as number of engines!!
	XPLMSetDatavf(local_ENGN_thro, thrust_array, 0, 8);
	XPLMSetDatavf(local_throttle_ratio, thrust_array, 0, 8);

	//combined brake values
	XPLMSetDataf(local_left_brake_ratio, combined_left_brake_ratio);
	XPLMSetDataf(local_right_brake_ratio, combined_right_brake_ratio);

	//pedestal levers
	XPLMSetDataf(local_speedbrake_ratio, speedbrake_lever);
	XPLMSetDataf(local_flap_ratio, flap_lever);
	XPLMSetDatai(local_parkingbrake_ratio, (int)parkbrake);

	//gear lever
	//XPLMSetDatai(local_gearlever_position, da.get_overhead_hw().toggle_switch0);
	
	

	write_FCU();

	//Use XPLM Commands---------------------------------------------------------------------------------------------------------------------------------

	if (da.get_rud_trim().rot_switch0 == -1)
	{
		XPLMCommandBegin(local_ruddertrim_right);
		std::cout << " rudtrim right" << std::endl;
	}
	else if (da.get_rud_trim().rot_switch0 == 1)
	{
		XPLMCommandBegin(local_ruddertrim_left);
		std::cout << " rudtrim left" << std::endl;
	}
	else if (da.get_rud_trim().rot_switch0 == 0)
	{
		XPLMCommandEnd(local_ruddertrim_left);
		XPLMCommandEnd(local_ruddertrim_right);
	}

	if (da.get_rud_trim().touch_button0 == 1)
	{
		XPLMCommandBegin(local_ruddertrim_center);
		std::cout << "reset" << std::endl;
	}
	return -1.0;
};

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
};

void write_FCU()
{
	short knob0 = da.get_FCU().control_knob0;
	static short knob0_prev = knob0;

	short knob1 = da.get_FCU().control_knob1;
	static short knob1_prev = knob1;

	short knob2 = da.get_FCU().control_knob2;
	static short knob2_prev = knob2;

	short knob3 = da.get_FCU().control_knob3;
	static short knob3_prev = knob3;
	
	short button8 = da.get_FCU().push_button8;
	static short button8_prev = button8;

	short button5 = da.get_FCU().push_button5;
	static short button5_prev = button5;

	short button3 = da.get_FCU().push_button3;
	static short button3_check = 0;				//needed for debounce

	short button4 = da.get_FCU().push_button4;
	static short button4_check = 0;				//needed for debounce

	short button6 = da.get_FCU().push_button6;
	static short button6_check = 0;				//needed for debounce

	XPLMSetDataf(local_FCU_airspeed, da.get_FCU().lcd_counter0);

	XPLMSetDatai(local_FCU_airspeedismach, da.get_FCU().push_button0);

	XPLMSetDatai(local_FCU_HDGTRKmode, da.get_FCU().push_button1);

	XPLMSetDataf(local_FCU_heading_mag, da.get_FCU().lcd_counter1);

	XPLMSetDataf(local_FCU_Altitude, da.get_FCU().lcd_counter2);

	//XPLMSetDataf(local_FCU_vertical_velocity, da.get_FCU().lcd_counter3);

	//ap1 buttonpressed
	if ((button3 == 1) && (button3_check == 0))
	{
		XPLMSetDatai(local_FCU_AP1Engange, !(XPLMGetDatai(local_FCU_AP1Engange)));
		button3_check = 1;

	}
	else if (button3 == 0)
		button3_check = 0;
	
	//ap2 button pressed
	if ((button4 == 1) && (button4_check == 0))
	{
		XPLMSetDatai(local_FCU_AP2Engange, !(XPLMGetDatai(local_FCU_AP1Engange)));
		button4_check = 1;
	}
	else if (button4 == 0)
		button4_check = 0;
	//loc button pressed
	if ((button5 && (!button5_prev)))
	{
		XPLMCommandOnce(local_FCU_LOCButton);
		button5_prev = button5;
		std::cout << " button 5 pressed (LOC)" << std::endl;
	}
	//loc button released
	if (!(button5) && (button5_prev))
	{
		XPLMCommandOnce(local_FCU_LOCButton);
		button5_prev = button5;
		std::cout << " button 5 released (LOC)" << std::endl;
	}
	//autothrottle button pressed
	if ((button6) && (button6_check == 0))
	{
		XPLMCommandOnce(local_FCU_ATHRButton);
		button6_check = 1;
	}
	else if (button6 == 0)
		button6_check = 0;

	//button8 pressed
	if ((button8) && !(button8_prev))
	{
		XPLMCommandOnce(local_FCU_APPRButton);
		button8_prev = button8;
		std::cout << " button 8 pressed (APPR)" << std::endl;
	}
	//button8 released
	if (!(button8) && (button8_prev))
	{
		XPLMCommandOnce(local_FCU_APPRButton);
		button8_prev = button8;
		std::cout << " button 8 released (APPR)" << std::endl;
	}

	//SPDSelect knob pulled
	if ((knob0 == 1) && (knob0_prev == 2))
	{
		XPLMCommandOnce(local_FCU_PullSPDSelect);
		knob0_prev = knob0;
		std::cout << " SPDselect pulled" << std::endl;
	}

	//SPDSelect knob pushed
	if ((knob0 == 2) && (knob0_prev == 1))
	{
		XPLMCommandOnce(local_FCU_PushSPDSelect);
		knob0_prev = knob0;
		std::cout << "SPDselect pushed" << std::endl;
	}

	//HDGSelect knob pulled
	if ((knob1 == 1) && (knob1_prev == 2))
	{
		XPLMCommandOnce(local_FCU_PullHDGSelect);
		knob1_prev = knob1;
		std::cout << "HDG select pulled" << std::endl;
	}

	//HDGSelect knob pushed
	if ((knob1 == 2) && (knob1_prev == 1))
	{
		XPLMCommandOnce(local_FCU_PushHDGSelect);
		knob1_prev = knob1;
		std::cout << "HDG select pushed" << std::endl;
	}

	//ALTSelect knob pulled
	if ((knob2 == 1) && (knob2_prev == 2))
	{
		XPLMCommandOnce(local_FCU_PullALTSelect);
		knob2_prev = knob2;
		std::cout << "ALTselect pulled" << std::endl;
	}

	//ALTSelect knob pushed
	if ((knob2 == 2) && (knob2_prev == 1))
	{
		XPLMCommandOnce(local_FCU_PushALTSelect);
		knob2_prev = knob2;
		std::cout << "ALTselect pushed" << std::endl;
	}

	////VS Select knob pulled
	if ((knob3 == 1) && (knob3_prev == 2))
	{
		XPLMCommandOnce(local_FCU_PullVSSelect);
		knob3_prev = knob3;
	}

	//VS Select knob pushed
	if ((knob3 == 2) && (knob3_prev == 1))
	{
		XPLMCommandOnce(local_FCU_PushVSSelect);
		knob3_prev = knob3;
	}

}

void write_EFIS()
{
	//EFIS1
	XPLMSetDatai(local_EFIS1_FD_engageCapt, da.get_efis1().pushbutton0);
	XPLMSetDatai(local_EFIS1_ILSonCap, da.get_efis1().pushbutton1);

	XPLMSetDataf(local_EFIS1_Baro_Setting_in_hg_pilot, (da.get_efis1().lcd_counter0) * 0.0295);
	XPLMSetDatai(local_EFIS1_Baro_Std_Capt, !da.get_efis1().control_knob0);
	XPLMSetDatai(local_EFIS1_Baro_Unit_Capt, da.get_overhead_hw().toggle_switch1);

	//static variables to make sure the dataref gets written 0 only once
	static short check1 = 0;
	static short check2 = 0;
	static short check3 = 0;
	static short check4 = 0;

	static short check5 = 0;
	static short check6 = 0;
	static short check7 = 0;
	static short check8 = 0;
	//check if one button is turned on and write the dataref = 1
	//button 1
	if (da.get_efis1().radiobutton1)
	{
		XPLMSetDatai(local_EFIS1_WPTCapt, 1);
		check1 = 0;
	}
	//button2
	else if (da.get_efis1().radiobutton2)
	{
		XPLMSetDatai(local_EFIS1_VORDCapt, 1);
		check2 = 0;
	}
	//button3
	else if (da.get_efis1().radiobutton3)
	{
		XPLMSetDatai(local_EFIS1_NDBCapt, 1);
		check3 = 0;
	}
	//button4
	else if (da.get_efis1().radiobutton4)
	{
		XPLMSetDatai(local_EFIS1_ARPTCapt, 1);
		check4 = 0;
	}

	//check if the button is turned off and write the dataref = 0 only ONCE!!
	//button1
	if ((da.get_efis1().radiobutton1) == 0 && (check1 == 0))
	{
		XPLMSetDatai(local_EFIS1_WPTCapt, 0);
		check1 = 1;
	}
	//button2
	else if ((da.get_efis1().radiobutton2) == 0 && (check2 == 0))
	{
		XPLMSetDatai(local_EFIS1_VORDCapt, 0);
		check2 = 1;
	}
	//button3
	else if ((da.get_efis1().radiobutton3) == 0 && (check3 == 0))
	{
		XPLMSetDatai(local_EFIS1_NDBCapt, 0);
		check3 = 1;
	}
	//button4
	else if ((da.get_efis1().radiobutton4) == 0 && (check4 == 0))
	{
		XPLMSetDatai(local_EFIS1_ARPTCapt, 0);
		check4 = 1;
	}

	//EFIS2
	XPLMSetDatai(local_EFIS2_FD_engageFO, da.get_efis2().pushbutton0);
	XPLMSetDatai(local_EFIS2_ILSonFO, da.get_efis2().pushbutton1);

	XPLMSetDataf(local_EFIS2_Baro_setting_in_hg_fo, da.get_efis2().lcd_counter0 / 100);
	XPLMSetDatai(local_EFIS2_Baro_StdFO, !da.get_efis2().control_knob0);
	XPLMSetDatai(local_EFIS2_Baro_Unit_FO, 1);

	//check if one button is turned on and write the dataref = 1
	//button 1
	if (da.get_efis2().radiobutton1)
	{
		XPLMSetDatai(local_EFIS2_WPTFO, 1);
		check5 = 0;
	}
	else if (da.get_efis2().radiobutton2)
	{
		XPLMSetDatai(local_EFIS2_VORDFO, 1);
		check6 = 0;
	}
	else if (da.get_efis2().radiobutton3)
	{
		XPLMSetDatai(local_EFIS2_NDBFO, 1);
		check7 = 0;
	}
	else if (da.get_efis2().radiobutton4)
	{
		XPLMSetDatai(local_EFIS2_ARPTFO, 1);
		check8 = 0;
	}
	//check if the button is turned off and write the dataref = 0 only ONCE!!
	//button1
	if ((da.get_efis2().radiobutton1) == 0 && (check5 == 0))
	{
		XPLMSetDatai(local_EFIS2_WPTFO, 0);
		check5 = 1;
	}
	//button2
	else if ((da.get_efis2().radiobutton2) == 0 && (check6 == 0))
	{
		XPLMSetDatai(local_EFIS2_VORDFO, 0);
		check6 = 1;
	}
	//button3
	else if ((da.get_efis2().radiobutton3) == 0 && (check7 == 0))
	{
		XPLMSetDatai(local_EFIS2_NDBFO, 0);
		check7 = 1;
	}
	//button4
	else if ((da.get_efis2().radiobutton4) == 0 && (check8 == 0))
	{
		XPLMSetDatai(local_EFIS2_ARPTFO, 0);
		check8 = 1;
	}

	//3state switches CAPT
	if (da.get_efis1().toggle_switch0 == 0 || da.get_efis1().toggle_switch0 == 1)
		XPLMSetDatai(local_EFIS1_toggleswitch0, !da.get_efis1().toggle_switch0);
	else
		XPLMSetDatai(local_EFIS1_toggleswitch0, 2);

	if (da.get_efis1().toggle_switch1 == 0 || da.get_efis1().toggle_switch1 == 1)
		XPLMSetDatai(local_EFIS1_toggleswitch1, !da.get_efis1().toggle_switch1);
	else
		XPLMSetDatai(local_EFIS1_toggleswitch1, 2);

	//3 state switches FO
	if (da.get_efis2().toggle_switch0 == 0 || da.get_efis2().toggle_switch0 == 1)
		XPLMSetDatai(local_EFIS2_toggleswitch0_FO, !da.get_efis2().toggle_switch0);
	else
		XPLMSetDatai(local_EFIS2_toggleswitch0_FO, 2);

	if (da.get_efis2().toggle_switch1 == 0 || da.get_efis2().toggle_switch1 == 1)
		XPLMSetDatai(local_EFIS2_toggleswitch1_FO, !da.get_efis2().toggle_switch1);
	else
		XPLMSetDatai(local_EFIS2_toggleswitch1_FO, 2);

	//rotary switch1
	XPLMSetDatai(local_EFIS1_NDmodeCapt, da.get_efis1().rot_switch1);
	XPLMSetDatai(local_EFIS2_NDmodeFO, da.get_efis2().rot_switch1);

	//rot switch2
	if (da.get_efis1().rot_switch2 == 10)
		XPLMSetDatai(local_EFIS1_NDrangeCapt, 0);
	else if (da.get_efis1().rot_switch2 == 20)
		XPLMSetDatai(local_EFIS1_NDrangeCapt, 1);
	else if (da.get_efis1().rot_switch2 == 40)
		XPLMSetDatai(local_EFIS1_NDrangeCapt, 2);
	else if (da.get_efis1().rot_switch2 == 80)
		XPLMSetDatai(local_EFIS1_NDrangeCapt, 3);
	else if (da.get_efis1().rot_switch2 == 160)
		XPLMSetDatai(local_EFIS1_NDrangeCapt, 4);
	else if (da.get_efis1().rot_switch2 == 320)
		XPLMSetDatai(local_EFIS1_NDrangeCapt, 5);

	if (da.get_efis2().rot_switch2 == 10)
		XPLMSetDatai(local_EFIS2_NDrangeFO, 0);
	else if (da.get_efis2().rot_switch2 == 20)
		XPLMSetDatai(local_EFIS2_NDrangeFO, 1);
	else if (da.get_efis2().rot_switch2 == 40)
		XPLMSetDatai(local_EFIS2_NDrangeFO, 2);
	else if (da.get_efis2().rot_switch2 == 80)
		XPLMSetDatai(local_EFIS2_NDrangeFO, 3);
	else if (da.get_efis2().rot_switch2 == 160)
		XPLMSetDatai(local_EFIS2_NDrangeFO, 4);
	else if (da.get_efis2().rot_switch2 == 320)
		XPLMSetDatai(local_EFIS2_NDrangeFO, 5);
}


void find_qpac_datarefs()
{
	local_parkingbrake_ratio = XPLMFindDataRef("AirbusFBW/ParkBrake");
	local_thrustlever_position = XPLMFindDataRef("AirbusFBW/throttle_input");

	//efis 1 (captain)
	local_EFIS1_FD_engageCapt = XPLMFindDataRef("AirbusFBW/FD1Engage");
	local_EFIS1_ILSonCap = XPLMFindDataRef("AirbusFBW/ILSonCapt");
	local_EFIS1_Baro_Setting_in_hg_pilot = XPLMFindDataRef("sim/cockpit2/gauges/actuators/barometer_setting_in_hg_pilot");
	local_EFIS1_Baro_Std_Capt = XPLMFindDataRef("AirbusFBW/BaroStdCapt");
	local_EFIS1_Baro_Unit_Capt = XPLMFindDataRef("AirbusFBW/BaroUnitCapt");
	local_EFIS1_WPTCapt = XPLMFindDataRef("AirbusFBW/NDShowWPTCapt");
	local_EFIS1_VORDCapt = XPLMFindDataRef("AirbusFBW/NDShowVORDCapt");
	local_EFIS1_NDBCapt = XPLMFindDataRef("AirbusFBW/NDShowNDPCapt");
	local_EFIS1_ARPTCapt = XPLMFindDataRef("AirbusFBW/NDShowARPTCapt");
	local_EFIS1_toggleswitch0 = XPLMFindDataRef("sim/cockpit2/EFIS/EFIS_1_selection_pilot");
	local_EFIS1_toggleswitch1 = XPLMFindDataRef("sim/cockpit2/EFIS/EFIS_2_selection_pilot");
	local_EFIS1_NDmodeCapt = XPLMFindDataRef("AirbusFBW/NDmodeCapt");
	local_EFIS1_NDrangeCapt = XPLMFindDataRef("AirbusFBW/NDrangeCapt");

	//efis2 (first officer)
	local_EFIS2_ARPTFO = XPLMFindDataRef("AirbusFBW/NDShowARPTFO");
	local_EFIS2_Baro_setting_in_hg_fo = XPLMFindDataRef("sim/cockpit2/gauges/actuators/barometer_setting_in_hg_copilot");
	local_EFIS2_Baro_StdFO = XPLMFindDataRef("AirbusFBW/BaroStdFO");
	local_EFIS2_Baro_Unit_FO = XPLMFindDataRef("AirbusFBW/BaroUnitFO");
	local_EFIS2_FD_engageFO = XPLMFindDataRef("AirbusFBW/FD2Engage");
	local_EFIS2_ILSonFO = XPLMFindDataRef("AirbusFBW/ILSonFO");
	local_EFIS2_NDBFO = XPLMFindDataRef("AirbusFBW/NDShowNDPFO");
	local_EFIS2_NDmodeFO = XPLMFindDataRef("AirbusFBW/NDmodeFO");
	local_EFIS2_NDrangeFO = XPLMFindDataRef("AirbusFBW/NDrangeFO");
	local_EFIS2_toggleswitch0_FO = XPLMFindDataRef("sim/cockpit2/EFIS/EFIS_1_selection_copilot");
	local_EFIS2_toggleswitch1_FO = XPLMFindDataRef("sim/cockpit2/EFIS/EFIS_2_selection_copilot");
	local_EFIS2_VORDFO = XPLMFindDataRef("AirbusFBW/NDShowVORDFO");
	local_EFIS2_WPTFO = XPLMFindDataRef("AirbusFBW/NDShowWPTFO");

	//fcu
	local_FCU_AP1Engange = XPLMFindDataRef("AirbusFBW/AP1Engage");
	local_FCU_AP2Engange = XPLMFindDataRef("AirbusFBW/AP2Engage");
	local_FCU_ATHRButton = XPLMFindCommand("AirbusFBW/ATHRbutton");
	local_FCU_APPRButton = XPLMFindCommand("AirbusFBW/APPRbutton");
	local_FCU_LOCButton = XPLMFindCommand("AirbusFBW/LOCbutton");

	//local_FCU_PullSPDSelect =			   XPLMFindCommand("AirbusFBW/PullSPDSel");
	local_FCU_PullSPDSelect = XPLMFindCommand("airbus_qpac/spd_pull");
	//local_FCU_PushSPDSelect =			   XPLMFindCommand("AirbusFBW/PushSPDSel");
	local_FCU_PushSPDSelect = XPLMFindCommand("airbus_qpac/spd_push");

	local_FCU_PullHDGSelect = XPLMFindCommand("AirbusFBW/PullHDGSel");
	local_FCU_PushHDGSelect = XPLMFindCommand("AirbusFBW/PushHDGSel");

	local_FCU_PullALTSelect = XPLMFindCommand("AirbusFBW/PushAltitude");
	local_FCU_PushALTSelect = XPLMFindCommand("AirbusFBW/PullAltitude");

	local_FCU_PullVSSelect = XPLMFindCommand("airbus_qpac/vs_push");
	local_FCU_PushVSSelect = XPLMFindCommand("airbus_qpac/vs_pull");

	local_FCU_airspeed = XPLMFindDataRef("sim/cockpit/autopilot/airspeed");
	local_FCU_airspeedismach = XPLMFindDataRef("sim/cockpit/autopilot/airspeed_is_mach");
	local_FCU_HDGTRKmode = XPLMFindDataRef("AirbusFBW/HDGTRKmode");
	local_FCU_heading_mag = XPLMFindDataRef("sim/cockpit/autopilot/heading_mag");
	local_FCU_vertical_velocity = XPLMFindDataRef("sim/cockpit/autopilot/vertical_velocity");
	local_FCU_Altitude = XPLMFindDataRef("sim/cockpit/autopilot/altitude");
}