/*****************************************************************************
 *
 *  Copyright 1992 TH-Darmstadt FG Flugmechanik und Regelungstechnik
 *  Patent pending
 *
 *****************************************************************************
 * Projektname     : CAVOK Flight Mechanics
 * Modulname       : Network.cc
 * Kurzbeschreibung: connects to the network and reads and writes data
 *
 * Bearbeiter:   Datum:   Aenderung:
 * ------------- -------- ----------------------------------------------------
 * schiefele     20.8.97   development
 * schiefele     20.3.98   adapted to next generation of communication
 * 
 * Inhaltsverzeichnis aller Funktionen:
 * ---------------------------------------------------------------------------
 * 
 * 
 * 
 * 
 * ---------------------------------------------------------------------------
 *                                                      CAVOK MODULHEADER V1.2
 *****************************************************************************
 * $Id: NetworkDatapool.cpp,v 1.2 2007-08-20 11:00:02 barraci Exp $
 *****************************************************************************/
#include "NetworkDatapool.h"
#include "iostream"
#define SLEEP_WIN_ATM 100


NetworkDatapool::NetworkDatapool(char *WorldName_,char *_AcrName, short ConnectedOnStartup, short &Success){
    /***************************************************************************
     * DESCRIPTION
     *  initalizes recorder
     ***************************************************************************/

    Success= 1;
    Error  = 0;

    strcpy(AcrName,_AcrName);
    strcpy(WorldName,WorldName_);

    ds_initialize_Controls(MYXPDATASET,AcrName);
	ds_initialize_RUD_TRIM(BOX_RUDDER_TRIM, AcrName);
	ds_initialize_Stick_1(BOX_STI_1,AcrName);
	ds_initialize_Stick_2(BOX_STI_2, AcrName);
	ds_initialize_Pedestal(BOX_PEDESTAL, AcrName);
	ds_initialize_OVH_HW(BOX_OVERHEAD_HW, AcrName);
	ds_initialize_Pedalbox1(BOX_PEDALBOX1, AcrName);
	ds_initialize_Pedalbox2(BOX_PEDALBOX2, AcrName);
	ds_initialize_EFIS_1(BOX_EFIS1, AcrName);
	ds_initialize_EFIS_2(BOX_EFIS2, AcrName);
	ds_initialize_FCU(BOX_FCU, AcrName);

    if ( ConnectedOnStartup )
        Success &= connect();

}/*NetworkDatapool*/

NetworkDatapool::~NetworkDatapool(){
    /***************************************************************************
     * DESCRIPTION
     *  closes NetworkDatapool
     ***************************************************************************/
    ds_disconnect();
    Connected = 0;
}/*~NetworkDatapool*/
  
short NetworkDatapool::connect(){

    char Name[255];
    short Success = 1;
    short ds_err;

    sprintf(Name,"%s_%s","FlightControls2XP",AcrName);
	 
	
    ds_err = ds_connect(Name, WorldName, 0,
//        50,
//         1000,
                        DS_WORKS_FOR_PRESENT);
	
    Success&= (ds_err == DS_EOK);
    if (Success)
        Connected = 1;

    /* read announce varaibles*/
   // ds_err = ds_w_announce(BOXXPLANE);
//    ds_err = ds_w_announce(BOXXPDATASET);
    ds_err = ds_r_announce(MYXPDATASET);
	ds_err = ds_r_announce(BOX_RUDDER_TRIM);
	ds_err = ds_r_announce(BOX_STI_1);
	ds_err = ds_r_announce(BOX_STI_2);
	ds_err = ds_r_announce(BOX_PEDESTAL);
	ds_err = ds_r_announce(BOX_OVERHEAD_HW);
	ds_err = ds_r_announce(BOX_PEDALBOX1);
	ds_err = ds_r_announce(BOX_PEDALBOX2);
	ds_err = ds_r_announce(BOX_EFIS1);
	ds_err = ds_r_announce(BOX_EFIS2);
	ds_err = ds_r_announce(BOX_FCU);
    Success&= (ds_err == DS_EOK);


    return Success;
}

short NetworkDatapool::disconnect(){

    short ds_err, Success=1;

    /* read resign varaibles*/

    //ds_err = ds_w_resign(BOXXPLANE);
    //Success &= (ds_err == DS_EOK);

    ds_err = ds_r_resign(MYXPDATASET);
    Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_RUDDER_TRIM);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_STI_1);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_STI_2);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_PEDESTAL);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_OVERHEAD_HW);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_PEDALBOX1);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_PEDALBOX2);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_EFIS1);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_EFIS2);
	Success &= (ds_err == DS_EOK);

	ds_err = ds_r_resign(BOX_FCU);
	Success &= (ds_err == DS_EOK);

    ds_err = ds_disconnect();
    Success &= (ds_err == DS_EOK);

    Connected = 0;

    return Success;
}

inline static void printTest(short Error,char *Name){
    /***************************************************************************
     * DESCRIPTION
     *  print error statement.
     ***************************************************************************/
    if(Error!=DS_EOK){
        cout << "Error in " << Name << " Error Type:" << Error <<endl;
    }/*if*/
    return;
}/*printTest*/

short NetworkDatapool::rProceedNet(){
    /***************************************************************************
     * DESCRIPTION
     *  read data from net
     ***************************************************************************/
 
 if (Connected){

        Error= ds_read (MYXPDATASET,(char*)&mydata_Xplane);
        printTest(Error,MYXPDATASET);

		Error = ds_read(BOX_RUDDER_TRIM,(char*)&mydata_Rudder_Trim);
		printTest(Error, BOX_RUDDER_TRIM);

		Error = ds_read(BOX_STI_1, (char *)&mydata_Stick_1);
		printTest(Error, BOX_STI_1);

		Error = ds_read(BOX_STI_2, (char *)&mydata_Stick_2);
		printTest(Error, BOX_STI_2);

		Error = ds_read(BOX_PEDESTAL, (char *)&mydata_Pedestal);
		printTest(Error, BOX_PEDESTAL);

		Error = ds_read(BOX_OVERHEAD_HW, (char *)&mydata_OverheadHW);
		printTest(Error, BOX_OVERHEAD_HW);

		Error = ds_read(BOX_PEDALBOX1, (char *)&mydata_Pedalbox1);
		printTest(Error, BOX_PEDALBOX1);
		
		Error = ds_read(BOX_PEDALBOX2, (char *)&mydata_Pedalbox2);
		printTest(Error, BOX_PEDALBOX2);

		Error = ds_read(BOX_EFIS1, (char *)&mydata_EFIS1);
		printTest(Error, BOX_EFIS1);

		Error = ds_read(BOX_EFIS2, (char *)&mydata_EFIS2);
		printTest(Error, BOX_EFIS2);

		Error = ds_read(BOX_FCU, (char *)&mydata_FCU);
		printTest(Error, BOX_FCU);
    }
    return(Error);
}/*readNet*/

short NetworkDatapool::wProceedNet(){
    /***************************************************************************
     * DESCRIPTION
     *  read data from net (write data? disabled. we dont write)
     ***************************************************************************/

//Error = DS_EOK;
//
//
//if (Connected){
//      
//    Error= ds_write (BOXXPLANE,(char*)&data_Xplane);
//    printTest(Error,BOXXPLANE);
//}
//
return(0);
}/*readNet*/



short NetworkDatapool::isError(){
    /***************************************************************************
     * DESCRIPTION
     *  has error occured in last step.
     ***************************************************************************/
    return(Error!=DS_EOK);
}/*isError*/


//void NetworkDatapool::setData(CONTROLS_T _data)
//{
//   data_Xplane = _data; 
//}

void NetworkDatapool::setMyData(CONTROLS_T _data)
{
   mydata_Xplane = _data; 
}


void NetworkDatapool::getMyData(Overhead_Hardware &adr1,
				  Pedalbox1 &adr2,
				  Pedalbox2 &adr3,
				  Pedestal_Basics &adr4,
				  Rudder_Trim_Panel &adr5,
				  Stick_1 &adr6,
				  Stick_2 &adr7,
				  EFIS1 &adr8,
				  EFIS2 &adr9,
				  FCU &adr10)
{
	adr1 = mydata_OverheadHW;
	adr2 = mydata_Pedalbox1;
	adr3 = mydata_Pedalbox2;
	adr4 = mydata_Pedestal;
	adr5 = mydata_Rudder_Trim;
	adr6 = mydata_Stick_1;
	adr7 = mydata_Stick_2;
	adr8 = mydata_EFIS1;
	adr9 = mydata_EFIS2;
	adr10 = mydata_FCU;
}
