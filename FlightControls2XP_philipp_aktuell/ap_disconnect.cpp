#include "ap_disconnect.h"
#include <iostream>

//short neg_edge[2];
//short pos_edge[2];
//int stick1_mult;
//int stick2_mult;
//int stick1_ap_prev;
//int stick2_ap_prev;
//static float time[2];
//
//short check_ap_disconnect(float inElapsedSinceLastCall, Stick_2 data_stick2, Stick_1 data_stick1, float &pitch, float &roll)
//{
//	neg_edge[0] = 0;
//	neg_edge[1] = 0;
//	pos_edge[0] = 0;
//	pos_edge[1] = 0;
//
//	count time
//	if ((!stick1_mult || !stick2_mult) && time[0] <= 45)
//	{
//		time[0] += inElapsedSinceLastCall;
//	}
//
//	check for rising/falling edge stick1
//	if (!stick1_ap_prev && data_stick1.ap_disconnect)
//		pos_edge[0] = 1;
//
//	else if (stick1_ap_prev && !data_stick1.ap_disconnect)
//		neg_edge[0] = 1;
//
//	check for rising falling edge stick 2
//	if (!stick2_ap_prev && data_stick2.ap_disconnect)
//		pos_edge[1] = 1;
//	else if (stick2_ap_prev && !data_stick2.ap_disconnect)
//		neg_edge[1] = 1;
//
//
//	case cpt presing button
//	if (pos_edge[0])
//	{
//		stick1_mult = 1;
//		stick2_mult = 0;
//		time[0] = 0;
//	}
//
//	case FO pressing button
//	if (pos_edge[1])
//	{
//		stick1_mult = 0;
//		stick2_mult = 1;
//		time[0] = 0;
//	}
//
//
//	case CPT releasing button
//	if (neg_edge[0] && stick1_mult && (time[0] < 45))
//	{
//		stick1_mult = 1;
//		stick2_mult = 1;
//	}
//
//	case FO releasing button
//	else if (neg_edge[1] && stick2_mult && (time[0] < 45))
//	{
//		stick1_mult = 1;
//		stick2_mult = 1;
//	}
//
//	store last values to check the edge in the next cycle
//	stick1_ap_prev = data_stick1.ap_disconnect;
//	stick2_ap_prev = data_stick2.ap_disconnect;
//
//
//	combining pitch/roll values
//
//	pitch = data_stick1.pitch_a * stick1_mult + data_stick2.pitch_a * stick2_mult;
//	if (pitch > 1)
//		pitch = 1;
//	if (pitch < -1)
//		pitch = -1;
//
//	roll = data_stick1.roll_a * stick1_mult + data_stick2.roll_a * stick2_mult;
//	if (roll > 1)
//		roll = 1;
//	if (roll < -1)
//		roll = -1;
//
//	return 0;
//}