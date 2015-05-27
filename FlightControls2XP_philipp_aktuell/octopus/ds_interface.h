/*****************************************************************************
 *                       MODULHEADER  3D-TEAM VERS. 1.0
 *  Copyright 1992 TH-Darmstadt FG Flugmechanik und Regelungstechnik
 *                 VDO-Luftfahrt
 *  Patent pending
 *****************************************************************************
 * Projektname     : 
 * Modulname       : 
 * Kurzbeschreibung: Header fuer die Schnittstellenfunktionen des Kommunikator
                     Von jedem, der die Schnittstelllenfunktionen verwenden
		     will einzubinden
 *
 * Bearbeiter:   Datum:   Aenderung:
 * ------------- -------- ----------------------------------------------------
 * engels        1.12.97
 *
 * Inhaltsverzeichnis aller Funktionen:
 * ---------------------------------------------------------------------------
 *
 *****************************************************************************
                          "OFFLINE" FUNKTIONEN
 *****************************************************************************
   ds_error ds_new_alias(char *aliasname,
                         char *type,
			 char *def,
                         char *d1,
			 char *d2,
			 char *d3);
   ds_error ds_create_box(char *boxname,
                          int size,
			  char *adr,
			  ...);

 *****************************************************************************
                           "ONLINE" FUNKTIONEN
 *****************************************************************************
   ds_error ds_connect(char *processname,
                       char *worldname,
		       short simstepsize,
		       char  works_for_present_or_future);
   ds_error ds_disconnect();
   ds_error ds_r_announce(char *aliasname);
   ds_error ds_w_announce(char *aliasname);
   ds_error ds_r_resign(char *aliasname);
   ds_error ds_w_resign(char *aliasname);
   ds_error ds_read(char *aliasname, 
                    char *adr);
   ds_error ds_write(char *aliasname, 
                     char *adr);
   ds_error ds_exist(char *aliasname);
   ds_error ds_sync(unsigned int *simtime, 
                    long         *simstep, 
		    short        *simstepsize);


 *****************************************************************************
                               DEBUGFUNKTIONEN
 *****************************************************************************
   ds_error ds_perror(char *comment);
   
 *
 *
 * ---------------------------------------------------------------------------
 * Achtung: Aktuelle kodierte Fehlermeldungen
 * in /local/include/sim/ds_error.h !!!
 * ---------------------------------------------------------------------------
 *
 *****************************************************************************/

#ifndef _DS_INTERFACE_
#define _DS_INTERFACE_


#include"ds_error.h"
/*
 * Einige defines, die fuer die Benutzung der Schnittstellen genommen
 * werden muessen (in ds_connect)
 *
 * define fuer works_for_present_or_future
 */
#define DS_WORKS_FOR_PRESENT 1 /* Prozess arbeitet fuer aktuellen Zeitschritt*/
#define DS_WORKS_FOR_FUTURE  2 /* Prozess arbeitet fuer zukuenft. Zeitschritt*/ 
/*
 * define fuer simstepsize
 */
#define DS_RUN_AFAP          0 /* AFAP: As Fast As Possible
				  Prozess soll nicht im ds_sync schlafen     */



#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
                          "OFFLINE" FUNKTIONEN
(Funktionen, die vor der Verbindung zum Datenpool ausgefuehrt werden koennen)
*****************************************************************************/

/*
 * Erzeugen eines neuen Alias mit allen dazu benoetigten Informationen
 * Dies sind im Einzelnen
 * aliasname    : Name des Alias fuer den oder aus dem Datenpool
 * type         : Typ des Alias (also FLOAT, INT etc.)
 * def          : Defaultwert, den die lokale Variable des Users annehmen
 *                soll, wenn keiner diesen Alias sendet
 * char *d1     : Dummyvariable, wird noch nicht beachtet
 * char *d2     : Dummyvariable, wird noch nicht beachtet
 * char *d3     : Dummyvariable, wird noch nicht beachtet
 */
ds_error ds_new_alias(char *aliasname,
		      char *type,
		      char *def,
		      char *d1,
		      char *d2,
		      char *d3);

/*
 * Erzeugung einer neuen Box, also einer Gruppe aus Aliasen und
 * schon definierten Boxen.
 * boxname         : Name der Box die erzeugt wird
 * size            : Groesse dieser Box
 * adr             : Adresse der Struktur, auf die diese Box abgebildet wird
 *      ...        : Variable Anzahl von Parametern, die mit einem NULL-Pointer
 *                   abgeschlossen werden muss. Die Parameter haben die Form
 * char *aliasname : Name eines schon definierten Alias (oder einer schon 
 *                   definierten Box)
 * char *aliasadr  : Adresse dieses Alias (dieser Box) in einer Struktur, auf
 *                   die die hier angemeldete Box abgebildet wird
 */
ds_error ds_create_box(char *boxname,
		       int size,
		       char *boxadr,
		       ...);


/*****************************************************************************
                           "ONLINE" FUNKTIONEN
          (Funktionen, die erst nach der Verbindung zum Datenpool 
	  ausgefuehrt werden koennen bzw. zur Verbindung fuehren)
*****************************************************************************/
/*
 * Und jetzt die Schnittstellenfunktionen
 * Zuerst einmal die Grundfunktionen. Der User muss seinen Prozess anmelden
 * und abmelden. 
 * Bei der Anmeldung muss der Prozess seinen Namen, der beliebig
 * festgelegt werden kann, angeben, bei der Abmeldung ist dies nicht
 * mehr noetig.
 * Wenn die Verbindung bzw. die Abtrennung erfolgreich war, wird DS_EOK 
 * zurueckgegeben, sonst eine Zahl, die den Fehler naeher beschreibt.
 * (siehe Inhaltsverzeichnis aller Funktionen)
 *
 * processname: Frei waehlbarer Name fuer den Prozess
 * Worldname  : Welt, in der sich der Prozess bewegen soll
 * simstepsize: Schrittweite, die der Kunde gerne haette. 
                Arbeitet der Kunde nicht synchronisiert, wird der Prozess 
		entsprechend dieser Vorgabe schlafen gelegt.
		Wird DS_RUN_AFAP uebergeben, dann laeuft der Kunde so schnell er kann.
		step_size kann vom System ueberschrieben werden, wenn der 
		Kunde synchronisiert arbeitet.
   works_for_present_or_future: Festlegung, ob der Client seine Werte fuer 
                                einen zukuenftigen Zeitschritt oder fuer die 
				Gegenwart berechnet. 
				Gegenwart ist Normalfall. Bitte oben 
				festgelegte defines hierfuer benutzen
				(DS_WORKS_FOR_PRESENT oder
				 DS_WORKS_FOR_FUTURE)
 * 
 */
ds_error ds_connect(char *processname, 
		    char *worldname,
		    short simstepsize,
		    char  works_for_present_or_future);
ds_error ds_disconnect(void);


/*
 * Bekanntmachen der Aliase, die man senden oder empfangen will.
 *
 * Syntax beim Lesen:
 * ds_r_announce("ALIAS")
 *
 * Wenn die Bekanntmachung erfolgreich war, wird DS_EOK 
 * zurueckgegeben, sonst eine Zahl, die den Fehler naeher beschreibt.
 * (siehe ds_error.h)
 * 
 */
ds_error    ds_r_announce(char *aliasname);
ds_error    ds_w_announce(char *aliasname);

/*
 * Abmelden der Aliase oder Boxen vom Datenpool. Dies geschieht automatisch
 * beim Beenden des Prozesses oder durch Aufruf dieser Funktion 
 * (ohne dass der Prozess sich beenden muss)
 *
 * Wenn die Abmeldung erfolgreich war, wird DS_EOK 
 * zurueckgegeben, sonst eine Zahl, die den Fehler naeher beschreibt.
 * (siehe ds_error.h)
 * 
 */
ds_error    ds_r_resign(char *aliasname);
ds_error    ds_w_resign(char *aliasname);


/*
 *                                    LESEN
 * Der User sollte hier den Namen des Alias, den er announced hat, angeben.
 * Der zweite uebergebene Wert ist der Speicherbereich, den der User allokiert
 * haben muss, damit die Funktion dort die zu sendenden Werte lesen und an den
 * Datenpool weiterleiten kann.
 * 
 *                                  SCHREIBEN
 * Der User sollte hier den Namen des Alias, den er announced hat, angeben.
 * Der zweite uebergebene Wert ist der Speicherbereich, den der User allokiert
 * haben muss, damit die Funktion dort die zu empfangenden Werte 
 * hineinschreiben kann.
 */
ds_error ds_read(char *aliasname, char *adr);
ds_error ds_write(char *aliasname, char *adr);
/*
 *                              SYNCHRONISATION
 * Synchronisationsfunktion ds_sync()
 * darueber kann die aktuelle Simulationszeit und der aktuelle Zeitschritt
 * abgefragt werden. Diese Funktion erfuellt mehrere Aufgaben
 *
 * Wird der Customer nicht synchronisiert, dann schlaeft er hier entsprechend
 * der Angabe "step_size" in ds_connect. Der Custimer DARF an keiner anderen
 * Stelle sleep() oder gettimeofday aufrufen, das uebernimmt jetzt ds_sync
 *
 * simtime     gibt die Simulationszeit in msec zurueck. Im unsynchronisierten
 *             Fall ist das die vergangene Zeit seit Start der Simulation 
 * simstep     ist der Simulationsschritt, in dem der Customer sich befindet
 * simstepsize ist die Simulationsschrittweite, die sich zur Laufzeit aendern
 *             kann
 *
 * Es wird davon ausgegangen, dass der Customer die Funktionen im main-loop 
 * in der Reihenfolge
 *
 * while(Bedingung == TRUE) {
 *    ds_sync();
 *    ds_read();
 *    ds_write();
 * }// end while
 *
 * aufruft. Er darf an keiner anderen Stelle ausser in diesen Funktionen
 * blockiert werden oder auf etwas warten, da er so die gesamte Simulation 
 * blockieren kann.
 */
ds_error ds_sync(unsigned int *simtime, 
		 unsigned int *simstep, 
		 short        *simstepsize);

/*
 * Veraendern der Schrittweite, die in ds_connect uebergeben wurde. 
 * Auf diese Weise kann die Berechnungsfrequenz der Prozesse dynamisch 
 * angepasst werden. Diese Funktion arbeitet nur im unsynchronisierten Fall.
 * Wird der Prozess durch das System synchronisiert, hat dieser AUfruf keine
 * Auswirkungen
 * simstepsize ist die Simulationsschrittweite, die sich zur Laufzeit aendern
 *             kann (in [ms])
 */                             
ds_error ds_change_stepsize(short simstepsize);

/*****************************************************************************
                              DEBUGFUNKTIONEN
 *****************************************************************************/

/*
 * Diese Funktion gibt in Textform die Fehlermeldungen aus, die der
 * Aufruf der letzten ds_funktion erzeugt hat.
 * Der Parameter "comment" wird vor der Fehlermeldung ausgedruckt, gefolgt
 * von einem Zeilenumbruch. Wenn nichts ausgegeben werden soll, hier einen
 * NULL-Pointer uebergeben.
 * Angelehnt an die Systemfunktion perror().
 */
ds_error ds_perror(char *comment);


#ifdef __cplusplus
}
#endif


#endif















