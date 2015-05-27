#include "data.h"
#include "iostream"

data::data()
{
	
}


data::~data()
{

}

/** Uses the NetworkDatapool functions to read from the Datapool.
 */
void data::update(NetworkDatapool *dp)
{
	
	dp->rProceedNet();
	dp->getMyData(my_overhead_hw, my_pedals1, my_pedals2, my_pedastal, my_rud_trim_panel, my_stick1, my_stick2, my_efis1, my_efis2, my_FCU);

}

/** Checks who (Captain or First Officer) last pressed the button on the stick and gives him the full control of the aircraft. (Need to hold the button)
 *  If the button is pressed for more than 45seconds, you can release the button and retain only control.
 */
void data::check_stick_priority(float &combined_pitch, float &combined_roll, float inElapsedSinceLastCall)
{
	neg_edge[0] = 0;
	neg_edge[1] = 0;
	pos_edge[0] = 0;
	pos_edge[1] = 0;

	//count time
	if ((!stick1_mult || !stick2_mult) && time <= 45)
	{
		time += inElapsedSinceLastCall;
	}

	//check for rising/falling edge stick1
	if (!stick1_ap_prev && my_stick1.ap_disconnect)
		pos_edge[0] = 1;

	else if (stick1_ap_prev && !my_stick1.ap_disconnect)
		neg_edge[0] = 1;

	//check for rising falling edge stick 2
	if (!stick2_ap_prev && my_stick2.ap_disconnect)
		pos_edge[1] = 1;
	else if (stick2_ap_prev && !my_stick2.ap_disconnect)
		neg_edge[1] = 1;


	//case cpt presing button
	if (pos_edge[0])
	{
		stick1_mult = 1;
		stick2_mult = 0;
		time = 0;
	}

	//case FO pressing button
	if (pos_edge[1])
	{
		stick1_mult = 0;
		stick2_mult = 1;
		time = 0;
	}


	//case CPT releasing button
	if (neg_edge[0] && stick1_mult && (time < 45))
	{
		stick1_mult = 1;
		stick2_mult = 1;
	}

	//case FO releasing button
	else if (neg_edge[1] && stick2_mult && (time < 45))
	{
		stick1_mult = 1;
		stick2_mult = 1;
	}

	//store last values to check the edge in the next cycle
	stick1_ap_prev = my_stick1.ap_disconnect;
	stick2_ap_prev = my_stick2.ap_disconnect;


	//combining pitch/roll values
	combined_pitch = my_stick1.pitch_a * (-1) * stick1_mult + my_stick2.pitch_a * (-1) * stick2_mult;
	if (combined_pitch > 1)
		combined_pitch = 1;
	if (combined_pitch < -1)
		combined_pitch = -1;

	combined_roll = my_stick1.roll_a * (-1) * stick1_mult + my_stick2.roll_a * (-1) * stick2_mult;
	if (combined_roll > 1)
		combined_roll = 1;
	if (combined_roll < -1)
		combined_roll = -1;
}

FCU data::get_FCU()
{
	return my_FCU;
}

EFIS2 data::get_efis2()
{
	return my_efis2;
}

EFIS1 data::get_efis1() 
{
	return my_efis1;
}

Overhead_Hardware data::get_overhead_hw()
{
	return my_overhead_hw;
}

Pedalbox1 data::get_pedal1()
{
	return my_pedals1;
}

Pedalbox2 data::get_pedal2()
{
	return my_pedals2;
}

Pedestal_Basics data::get_pedestal()
{
	return my_pedastal;
}

Rudder_Trim_Panel data::get_rud_trim()
{
	return my_rud_trim_panel;
}

Stick_1 data::get_stick1()
{
	return my_stick1;
}

Stick_2 data::get_stick2()
{
	return my_stick2;
}

