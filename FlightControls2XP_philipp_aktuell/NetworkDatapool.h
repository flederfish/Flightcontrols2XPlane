/*****************************************************************************
 *
 *  Copyright 1992 TH-Darmstadt FG Flugmechanik und Regelungstechnik
 *  Patent pending
 *
 *****************************************************************************
 * Projektname     : CAVOK Flight Mechanics
 * Modulname       : Network.h
 * Kurzbeschreibung: connects to the Datapool and reads and writes data
 *
 * Bearbeiter:   Datum:   Aenderung:
 * ------------- -------- ----------------------------------------------------
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
 * $Id: NetworkDatapool.h,v 1.2 2007-08-20 11:00:02 barraci Exp $
 *****************************************************************************/
#ifndef _NETWORK_DATAPOOL_H_
#define _NETWORK_DATAPOOL_H_
/*****************************************************************************
 * Includes
 *****************************************************************************/
#include <stdlib.h>

#ifdef WIN32
#include <iostream.h>
#else
#include <iostream>
using namespace std;
#endif

#include <string.h>
#include <stdio.h>
#include "ds_BoxXplane.h"
#include "ds_MyXPlane.h"
#include "ds_BoxRudTrim.h"
#include "ds_BoxStick1.h"
#include "ds_BoxStick2.h"
#include "ds_BoxPedestal.h"
#include "ds_BoxOverheadHW.h"
#include "ds_BoxPedalbox1.h"
#include "ds_BoxPedalbox2.h"

#include "ds_BoxEFIS1.h"
#include "ds_BoxEFIS2.h"
#include "ds_BoxFCU.h"
 /*****************************************************************************
 * defines
 *****************************************************************************/
#define BOXXPLANE	"BoxXlane"
#define MYXPDATASET	"MyXpDataset"
#define BOX_RUDDER_TRIM "BOX_RUDDER_TRIM"
#define BOX_STI_1 "BOX_STI_1"
#define BOX_STI_2 "BOX_STI_2"
#define BOX_PEDESTAL "BOX_PEDESTAL"
#define BOX_OVERHEAD_HW "BOX_OVERHEAD_HW"
#define BOX_PEDALBOX1 "BOX_PEDALBOX_1"
#define BOX_PEDALBOX2 "BOX_PEDALBOX_2"
#define BOX_EFIS1 "BOX_EFIS1"
#define BOX_EFIS2 "BOX_EFIS2"
#define BOX_FCU "BOX_FCU"
/*****************************************************************************
 * Class Definitions
 *****************************************************************************/
class NetworkDatapool{

public:
    NetworkDatapool(char *WorldName,char *AcrName, short ConnectedOnStartup, short &Success);

    ~NetworkDatapool();
  
	/** Connects to the Datapool
	 *
	 * @return returns DS_EOK (=1) if the connection was successfull.
	 */
    short connect();

	/** Disonnects from the Datapool
	 *
	 * @return returns DS_EOK (=1) if the connection was successfully closed.
	 */
    short disconnect();

	/** Read Data from the Datapool
	 *
	 * @return returns DS_EOK (=1) if data was successfully read from the datapool.
	 */
    short rProceedNet();

	/** Disonnects from the Datapool
	 *
	 * @return returns DS_EOK (=1) if data was successfully read from the datapool.
	 */
    short wProceedNet();

	/** Not needed...
	 */
	 CONTROLS_T	getData();

	 /** Not needed...
	 */
	 void	setData(CONTROLS_T _data);

	 /** Used to get the data previously read from the datapool
	  *  
	  * @param adr1.. Function writes into the data to the given variable.
	  */
	 void	getMyData(Overhead_Hardware &adr1,
		 Pedalbox1 &adr2,
		 Pedalbox2 &adr3,
		 Pedestal_Basics &adr4,
		 Rudder_Trim_Panel &adr5,
		 Stick_1 &adr6,
		 Stick_2 &adr7,
		 EFIS1 &adr8,
		 EFIS2 &adr9,
		 FCU &adr10
		 );


	 void	setMyData(CONTROLS_T _data);

	 
    short isError();
  
	/** Are we connected to the datapool?
	 *
	 *  @return returns 1 if we are connected, 0 if we are not
	 */
    inline short isConnected(){return Connected;}


private:
		
	char					AcrName   [255];              /* name of aircraft to be used.        */
	char					WorldName [255];              /* name of world to be used            */
	short					Error;                        /* error occured.                      */		
	short					Connected;                    /* 0=disconnected;1=connected          */
    CONTROLS_T		     mydata_Xplane;			
	Rudder_Trim_Panel    mydata_Rudder_Trim;
	Stick_1			     mydata_Stick_1;
	Stick_2				 mydata_Stick_2;
	Pedestal_Basics      mydata_Pedestal;
	Overhead_Hardware    mydata_OverheadHW;
	Pedalbox1            mydata_Pedalbox1;
	Pedalbox2			 mydata_Pedalbox2;
	EFIS1				 mydata_EFIS1;
	EFIS2				 mydata_EFIS2;
	FCU					 mydata_FCU;
	
}/*NetworkDatapool*/;
#endif  

