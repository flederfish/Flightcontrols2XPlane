/*	\class data
 *	
 *	\brief class for storing data from the datapool
 *
 *	Connects to the Datapool using the NetworkDatapool class.
 */

#pragma once
#include "ds_BoxEFIS1.h"
#include "ds_BoxEFIS2.h"
#include "ds_BoxOverheadHW.h"
#include "ds_BoxPedalbox1.h"
#include "ds_BoxPedalbox2.h"
#include "ds_BoxPedestal.h"
#include "ds_BoxRudTrim.h"
#include "ds_BoxStick1.h"
#include "ds_BoxStick2.h"

#include "NetworkDatapool.h"



class data
{
public:
	data();
	~data();

	/*	\brief	Call this to read from the datapool dp and to store the data.
	 *
	 *  \param dp the NetworkDatapool object for connecting to the network and reading the data.
	 */
	void update(NetworkDatapool *dp);

	/*	\brief	Getter functions, just returns the specified struct with the data.
	 */
	EFIS2 get_efis2();
	EFIS1 get_efis1();
	Overhead_Hardware get_overhead_hw();
	Pedalbox1 get_pedal1();
	Pedalbox2 get_pedal2();
	Pedestal_Basics get_pedestal();
	Rudder_Trim_Panel get_rud_trim();
	Stick_1 get_stick1();
	Stick_2 get_stick2();
	FCU get_FCU();

	/**	\brief	Checks the priority function on the sticks,combines pitch and roll values automatically and writes
	 *			them into the given addresses.
	 *
	 *	\param combined_pitch function writes the combined pitch value from both sticks into this address
	 *	\param combined_roll function writes the combined roll value from both sticks into this address
	 *	\param inElapsedSinceLastCall elapsed time since the function was last called. 
	 */
	void check_stick_priority(float &combined_pitch, float &combined_roll, float inElapsedSinceLastCall);


private:
	//raw data structs
	EFIS1 my_efis1 = *new(EFIS1);
	EFIS2 my_efis2 = *new(EFIS2);
	Overhead_Hardware my_overhead_hw = *new(Overhead_Hardware);
	Pedalbox1 my_pedals1 = *new(Pedalbox1);
	Pedalbox2 my_pedals2 = *new(Pedalbox2);
	Pedestal_Basics my_pedastal = *new(Pedestal_Basics);
	Rudder_Trim_Panel my_rud_trim_panel = *new(Rudder_Trim_Panel);
	Stick_1 my_stick1 = *new(Stick_1);
	Stick_2 my_stick2 = *new(Stick_2);
	FCU my_FCU = *new(FCU);

	//variables for priority function
	short neg_edge[2];
	short pos_edge[2];
	int stick1_mult = 1;
	int stick2_mult = 1;
	int stick1_ap_prev;
	int stick2_ap_prev;
	float time = 0;
};

