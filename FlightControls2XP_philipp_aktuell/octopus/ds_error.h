/*****************************************************************************
 *                       MODULHEADER  3D-TEAM VERS. 1.0
 *  Copyright 1992 TH-Darmstadt FG Flugmechanik und Regelungstechnik
 *                 VDO-Luftfahrt
 *  Patent pending
 *****************************************************************************
 * Projektname     : Datenserver
 * Modulname       : ds_error.h
 * Kurzbeschreibung: Kodierte Fehlermeldungen 
 *
 * Bearbeiter:   Datum:   Aenderung:
 * ------------- -------- ----------------------------------------------------
 * engels        4.1.97
 *
 * Inhaltsverzeichnis aller Funktionen:
 * ---------------------------------------------------------------------------

 *
 *****************************************************************************/
#ifndef _DS_ERROR_
#define _DS_ERROR_

typedef short ds_error;

#define DS_EOK       0      /* everything ok*/
#define DS_NCA       1      /* no communication available (cause ???) */
#define DS_WV        2      /* wrong version of interface */
#define DS_STL       3      /* string too long */
#define DS_PWPE      4      /* process with pid exists*/
#define DS_QF        5      /* Queue is full */



#define DS_APAWA    30      /* another process already writes alias */
#define DS_SI       31      /* sending impossible */



#define DS_RADNE    51      /* read alias does not exist
			       (wasn't initialized?) */
#define DS_WADNE    52      /* write alias does not exist	
			       (wasn't initialized?) */
#define DS_ADNE     53      /* alias or box does not exist (not decided yet 
			       if for writing or reading) */
#define DS_EL       54      /* endless loop, this will occur if one tries
			       to add an alias as a child to itself */
#define DS_TNS      55      /* type not supported */
#define DS_DNS      56      /* defaultvalue hasn't the type expected*/
#define DS_WVFCP    57      /* wrong value of calling parameter*/
#define DS_ABHMN    58      /* Another Boxtype has this Boxname already */ 
#define DS_GNC      59      /* Got No Confirmation */ 
#define DS_NSI      60      /* Failure during question for system information*/
#define DS_CWS      61      /* Client has wrong Status*/
#define DS_NSE      62      /* No Sender For This Box exists*/
#define DS_ABAA     63      /* Alias or Box already announced */
#define DS_AAC      64      /* Alias already created (but different!) */

/************************************************************************
                            INTERNAL ERRORS
*************************************************************************/

#define DS_NB       50      /* tried to add a childalias to a normal alias,
			       not a box */
#define DS_OMTM     100      /* (internal error) */
#define DS_LMQU     101      /* (internal error) */
#define DS_LSMQU    102      /* (internal error) */
#define DS_NMP      103      /* (internal error) */



#endif








