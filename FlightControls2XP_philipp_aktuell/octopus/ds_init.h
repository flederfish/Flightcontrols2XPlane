/*****************************************************************************
 *
 *  Copyright 1992 TH-Darmstadt FG Flugmechanik und Regelungstechnik
 *  Patent pending
 *
 *****************************************************************************
 * Projektname     : Kommunikationsmanager 
 *
 * Modulname       : ds_init.h  
 *
 * Kurzbeschreibung: lokal definierter Header, der automatisch durch ein Tool
                     erzeugt wurde. Dies trifft erst auf spaetere versionen 
		     dieses Headers zu
 *
 * Bearbeiter:   Datum:   Aenderung:
 * ------------- -------- ----------------------------------------------------
 * huth , engels
 * huth          13.07.98 change
 * huth          13.01.99 change
 * huth          01.03.00 change
 * ---------------------------------------------------------------------------
 *                                                      CAVOK MODULHEADER V1.2
 *****************************************************************************/

#ifndef _DS_INIT_
#define _DS_INIT_

/*
 * typedefs
 * ----------------------------------------------------------------------------
 */
/*
 * Defaultposition of non existing aircrafts
 */
#define DEFAULT_LAT  342000000
#define DEFAULT_LON  660000000
#define DEFAULT_ELEV 100000

/* NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE 
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE 
 *
 * all these variables in this header are single variables, nevertheless the
 * variables are grouped into boxes (here: C-structures) in order to reduce
 * workload of writing and reading many variables. In future these boxes can 
 * be defined by the user, now only the boxes which are defined in this header
 * can be used
 *
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE 
 * NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE 
 */


typedef struct {
/* 
 * Prefix of following variables: This is an example structure according
 * to the manual                            
 */
  char c;     
  float f;
  short i;
} example_T;

typedef struct {

/* Prefix of following variables: ACR1-2.GEN.CON                             */

  int   phase_of_flight;   /* 0 - Preflight                                  */
                           /* 1 - Taxi Out                                   */
                           /* 2 - Take Off                                   */
                           /* 3 - Cruise                                     */
                           /* 4 - Approach                                   */
                           /* 5 - Taxi Back                                  */
                           /* 6 - Holding                                    */
  int   conf_no;           /* present configuration number, ac specific   [-]*/
  float underspeed;        /* min speed for present configuration      [kts] */
  float overspeed;         /* max speed for present configuration      [kts] */
  float v_flap;            /* flap setting speed                       [kts] */
  float v1;                /* speed v1 - decision speed                [kts] */
  float v_rot;             /* rotation speed                           [kts] */
  float high_bank;         /* bank angle protection                    [deg] */
  float decision_height;   /* decision height for go around             [ft] */
  float weight;            /* weight of airplane                        [kg] */
  float max_thrust;        /* max thrust of airplane                     [N] */
  float v_cruise;          /* speed during cruise                      [kts] */
  float v_touch;           /* speed while touching the ground          [kts] */
  float v_to;              /* speed for takeoff                        [kts] */
} Konfiguration_T;

typedef struct {

/* Prefix of following variables: ACR1-2.GEN.CON                             */

  float v2;                /* take off climbspeed                      [kts] */
  float v_ls;              /* minimum selectable speed                 [kts] */
  float v_sw;              /* stall warning speed                      [kts] */

  float aoa_limit;         /* maximum angle of attack                  [deg] */
  float prot_speed;        /* at that speed overspeed protection becomes
			    * active                                   [kts] */
  float aoa_prot_speed;    /* at that speed alpha protection becomes
			    * active                                   [kts] */
  float aoa_max_speed;     /* speed corresponding to maximum angle of 
			    * attack                                   [kts] */
  float vmin_flap_retract; /* minimum flap retraction speed            [kts] */
  float vmin_slat_retract; /* minimum slat retraction speed            [kts] */

  short weight_on_wheels;  /* 0 = no weight on wheels               
			    * 1 = left and right main gear touches ground    */

  float fuel_on_board;     /* actual amount of fuel on board            [kg] */
} Konfiguration_II_T;

typedef struct {

/* Prefix of following variables: ACR1-10.GEN.IDE                            */

  char aircraft_id[50];    /* name of AC e.g. "ATTAS"                        */
  char typ[50];            /* AC-type                                        */     
  char company[5];         /* AC-company                                     */
} Identifikation_T;

/* ------------------------------------------------------------------------- */

typedef struct {

/* Prefix of following variables: ACR1-2.COP.GEOM.BODY                       */

  float nose[3];           /* nose position of acr w.r.t aircraft reference
			    * point (ARP), body fixed axes                     [m] */
  float tail[3];           /* tail position of acr w.r.t aircraft reference
			    * point (ARP), body fixed axes                     [m] */

  float l_wingtip[3];      /* left wingtip position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */
  float r_wingtip[3];      /* right wingtip position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */

  float l_elev_tip[3];     /* left elevator tip position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */
  float r_elev_tip[3];     /* right elevator tip position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */
  float rudder_top[3];     /* rudder top position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */

  float nose_gear[3];      /* nose gear position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */
  float l_main_gear[3];    /* left main gear position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */
  float r_main_gear[3];    /* right main gear position of acr w.r.t. aircraft
			    * reference point (ARP), body fixed axes           [m] */

  float acr_cog[3];        /* aircraft center of gravity w.r.t aircraft
                            * reference point (ARP), body-fixed-axes           [m] */
  float cockpit_orig[3];   /* origin of cockpit geometry w.r.t aircraft
                            * reference point (ARP), body-fixed-axes           [m] */
  float cp_eye_point[3];   /* cockpit eye point w.r.t aircraft 
                            * reference point (ARP), body-fixed-axes           [m] */

} Geometry_Aircraft_Body_T;


typedef struct {

  /* Prefix of following variables: ACR#.COP.PNL.MIP.DISP.WARN               */

  unsigned char alarmType; /* O=Resolution Advisory AL
			    * 1=Traffic Advisory AL (can TCAS or other System 
			    * like ADS-B )
			    * 2=CPA Warning Vertical AL
			    * 3=CPA Warning Horitontal AL
			    * 4=CPA caution AL
			    * 5=Mode 1 Warning AL
			    * 5=Mode 1 Caution AL
			    * 6=Mode 2 Warning AL
			    * 7=Mode 3 Warning AL
			    * 9=Mode 4 Gear AL
			    * 10=Mode 4 Terrain AL
			    * 11=Mode 4 Flap AL
			    * 12=Mode 5 AL
			    * 13=rews AL
			    * 14=prws Advisory AL
			    * 15=prws Caution AL
			    * 16= prws Warning AL
			    * 17=Wake Vortex caution AL
			    * 18=Wake Vortex Waring AL
			    * CPA means ?
			    * AL means Alarm 
			    * prws means Windshear                           */
  unsigned char alarmTotalNum; /* 0 - 18 total number of alarms              */
  unsigned char alarmIdent;    /* 0 - 18 Identification of the actual alarm  */
  unsigned char alarmPrio;     /* 0 - 17 Priority of the actual alarm        */
} General_Display_Warnings_T;


typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.DISP.PFD1-2           */
  /* if not stated, all flags can only become TRUE(=1) or FALSE(=0)          */
  int   feat_number;       /* number of feature to switch                    */
  short feat_flag;         /* state of feature: 0=off, 1=on, 2=selected      */
  char  feat_ident[20];    /* identifier of selected feature                 */

  short x_pos_off[15];     /* x position offset                              */
  short y_pos_off[15];     /* y position offset                              */
  float x_scale[15];       /* x scale factor                                 */
  float y_scale[15];       /* y scale factor                                
                              0 speed,   1 heading, 2 altitude, 3 vario,
                              4 radio,   5 baro,    6 pitch,    7 bank,
                              8 text,    9 wind,    10 ILS                   */

  int   ILS_flag;          /* bitfield, show ILS elements                    */
  int   altitude_flag;     /* bitfield, show altitude scale elements         */
  int   speed_flag;        /* bitfield, show speed scale elements            */
  int   heading_flag;      /* bitfield, show heading scale elements          */
  int   attitude_flag;     /* bitfield, show attitude elements               */
  int   text_flag;         /* bitfield, show text elements                   */
  int   wind_flag;         /* bitfield, show wind elements                   */
  int   nav_recv1_flag;    /* bitfield, nav reciever 1 elements              */
  int   nav_recv2_flag;    /* bitfield, nav reciever 2 elements              */
  int   predictor_flag;    /* bitfield, show predictor                       */
  int   fp_vector_flag;    /* bitfield, show flight path vector              */
  int   f_director_flag;   /* bitfield, show flight director                 */

  short art_horizon_flag;  /* show artificial horizon                        */
  short pitch_sky_flag;    /* TRUE: all 10 deg another colour                */
                           /* FALSE: single colour blue sky                  */
  short energyheight_flag; /* show energy heighy colouring                   */
  short alpha_blending;    /* value for alpha blending of scales             */
  short perf_stat_flag;    /* show performer statistic                       */
  short intruder_flag;     /* show intruders (0=Off, 1=On)                   */

  short baro_set_flag;     /* 0 = baromode QFE                               */
                           /* 1 = baromode QNH                               */
                           /* 2 = baromode STD                               */
  int   baro_set_value;    /* value of pressure altitude                     */

  int   terrain_model;     /* type of height line model                      */
  float terrain_color_exponent; /* determines the relationship between colour 
                                 * and height                                */
  int   terrain_height_steps; /* distance inbetween layers of height line
                               * model                                    [m]*/

  float sun_pos[3];        /* normalized sun position(-1 -> +1)              */
  float sun_rgb[3];        /* sun colour value (0-1)                         */
  float sun_gain;          /* gain factor for colour values (0-10)           */

  float alt_offset;        /* offset in altitude                             */
  float specific_dh;       /* specific decision height,
			    * if different from FMS value               [ft] */
  
  short track_load_flag;   /* signal for new track loading                   */

} PF_Display_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.DISP.PFD1-2.PRED      */

  short ac_ground_flag;    /* 0 -> False, 1 ->True                           */
                           /* default value:False(0)                         */
  int   no_element;        /* Number of element for the predictor: 0<n<=20.  */
                           /* default value: 5                               */
  short angle_flag;        /* if True(1) then the draw process must use the  */
                           /* angle of climb and track angle else the draw   */
                           /* process must use the heading and pitch.        */
                           /* default value: False(0)                        */
  float scaleX;            /* scale factor on the X axe*/
  float scaleY;            /* scale factor on the Y axe*/
  float scaleZ;            /* scale factor on the Z axe*/
  float offset;            /* offset if 2 element are used for an element of the 
			      predictor*/

  float ptime[20];         /* prediction time for the ac state of flight  [s] 
			      default -1 */
  long  lat[20];           /* latitude (north) WGS84                [1/1000s] 
			       Default value: 0 */
  long  lon[20];           /* longitude (east) WGS84                [1/1000s]
			      Default value: 0 */
  float elev[20];          /* elevation (down, ASL) WGS84            [1/100m] 
			      Default value 0*/

  float heading[20];       /* heading                                    [deg]
			      Default value 0*/
  float bank[20];          /* bank                                       [deg]
			      Default value 0*/
  float pitch[20];         /* pitch                                      [deg]
			      Default value 0*/
  float climb[20];         /* angle of the climb                         [deg]
			      Default value 0 */
  float track[20];         /* track                                      [deg]
			      Default value 0 */
  int   warning[20];       /* warning:
			      0x00     NO WARNING
			      0x01     OVERSPEED
			      0x02     UNDERSPEED
			      0x04     HIGH PITCH
			      0x08     LO PITCH
			      0x10     HIGH BANK LEFT
			      0x20     HIGH BANK RIGHT
			      Default value: 0x00*/
} Predictor_PF_Display_T;


typedef struct {

  /* Prefix of following variables: ACR#.COP.PNL.MIP.DISP.NAV1-2             */
  /* if not stated, all variables can only become TRUE(=1) or FALSE(=0)      */
  int   feat_number;       /* number of feature to switch                    */
  short feat_flag;         /* state of feature: 0=off, 1=on, 2=selected      */
  char  feat_ident[20];    /* identifier of selected feature                 */

  short around_flag;       /* TRUE = look around                             */
                           /* FALSE = look forward                           */

  int   taxi_pred_flag;    /* bitfield, taxi predcitor elements              */
  int   left_up_box_flag;  /* bitfield, element of the left upper box        */
  int   right_up_box_flag; /* bitfield, element of the right upper box       */
  int   AC_symb_flag;      /* bitfield, modis of our plane model on display  */
  int   nav_recv1_flag;    /* bitfield, nav reciever 1 elements              */
  int   nav_recv2_flag;    /* bitfield, nav reciever 2 elements              */

  short track_flag;        /* show actual track                              */
  short PFD_view_flag;     /* area of PFD-view shown on NAV display          */
  short airport_map_flag;  /* map of airport in a little window              */
  short rose_flag;         /* show arc rose with heading readout and track   */
                           /* marker                                         */
  short range_circ_flag;   /* circles indicating scale                       */
  short heading_flag;      /* show heading scale                             */
  short sel_heading_flag;  /* show selected heading                          */
  short intruder_flag;     /* show intruders (0=Off, 1=On)                   */

  float zoom;              /* zoom of NAV view                          [nm] */
                           /* half width of display shows <zoom> naut. miles */

  short alpha_blending;    /* value for alpha blending of scales             */
  short perf_stat_flag;    /* show performer statistics                      */

  int   terrain_model;     /* type of height line model                      */
  float terrain_color_exponent; /* determines the relationship between colour 
                                 * and height                                */
  int   terrain_height_steps; /* distance inbetween layers of height line
                               * model                                    [m]*/

  float sun_pos[3];        /* normalized sun position(-1 -> +1)              */
  float sun_rgb[3];        /* sun colour value (0-1)                         */
  float sun_gain;          /* gain factor for colour values (0-10)           */

  short track_load_flag;   /* signal for new track loading                   */

  short northUp;           /* To draw the navigation display with O 
			    * for heading up, 1 for North Up                 */
} NAV_Display_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.DISP.NAV1-2.PRED      */

  short ac_ground_flag;    /* 0 -> False, 1 ->True                           */
                           /* default value:False(0)                         */
  int   no_element;        /* Number of element for the predictor: 0<n<=20.  */
                           /* default value: 5                               */
  short angle_flag;        /* if True(1) then the draw process must use the  */
                           /* track angle else the draw process must use the */
                           /* heading. default value: False(0)               */
  float scaleX;            /* scale factor on the X axe*/
  float scaleY;            /* scale factor on the Y axe*/
  float scaleZ;            /* scale factor on the Z axe*/
  float offset;            /* offset if 2 element are used for an element of the 
			      predictor*/

  float ptime[20];         /* prediction time for the ac state of flight  [s] 
			      default -1 */
  long  lat[20];           /* latitude (north) WGS84                [1/1000s] 
			      Default value: 0 */
  long  lon[20];           /* longitude (east) WGS84                [1/1000s]
			      Default value: 0 */

  float heading[20];       /* heading                                    [deg]
			      Default value 0*/
  float track[20];         /* track                                      [deg]
			      Default value 0 */

  int   warning[20];       /* warning:
			      0x00     NO WARNING
			      0x01     OVERSPEED
			      0x02     UNDERSPEED
			      0x04     HIGH PITCH
			      0x08     LO PITCH
			      0x10     HIGH BANK LEFT
			      0x20     HIGH BANK RIGHT
			      Default value: 0x00*/
} Predictor_NAV_Display_T;

/* typedef struct { */

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.DISP.ECAM1-2          */

  /* no variables yet defined, not available                                 */

/* } ECAM_Display_T; */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.DISP.TOUCH1-2         */
  /* these variables are to control the configuration of PFD/NAV displays    */
  /* with the help of a touch screen                                         */

  short counter0;          /* zoom value                                     */
  short counter1;          /* baro value                                     */

  short push_button0;      /* Terrain ON/OFF                                 */
  short push_button1;      /* buildings ON/OFF                               */
  short push_button2;      /* Fixed Track ON/OFF                             */
  short push_button3;      /* Predictor and Shadow ON/OFF                    */
  short push_button4;      /* airport view                                   */
                           /* OFF = everything                               */
                           /* ON  = only runways                             */
  short push_button5;      /* airport window ON/OFF                          */
  short push_button6;      /* parking AC's ON/OFF                            */
  short push_button7;      /* taxiing AC's ON/OFF                            */
  short push_button8;      /* flying AC's ON/OFF                             */
  short push_button9;      /* taxiline ON/OFF                                */
  short push_button10;     /* taxi predictor ON/OFF                          */
  short push_button11;     /* ND view                                        */
                           /* OFF = around                                   */
                           /* ON  = forward                                  */
  short push_button12;     /* ILS channel1 ON/OFF                            */
  short push_button13;     /* ILS channel2 ON/OFF                            */
  short push_button14;     /* ILS channel3 ON/OFF                            */
  short push_button15;     /* waypoint forward ON/OFF                        */
  short push_button16;     /* waypoint backward ON/OFF                       */
  short push_button17;     /* waypoint actual ON/OFF                         */
  

  short toggle_switch0;    /* Glideslope                                     */
                           /* 0 = Off                                        */
                           /* 1 = ILS Kanal                                  */
                           /* 2 = ILS Ablage                                 */
  short toggle_switch1;    /* Baroset                                        */
                           /* 0 = QNH                                        */
                           /* 1 = QFE                                        */
                           /* 2 = STD                                        */

  short rot_switch0;       /* phase of flight                                */
                           /* 0 = Preflight                                  */
                           /* 1 = Taxi Out                                   */
                           /* 2 = Take Off                                   */
                           /* 3 = Cruise                                     */
                           /* 4 = Approach                                   */
                           /* 5 = Taxi Back                                  */
  short rot_switch1;       /* rotary switch for navaids                      */
                           /* 0 = OFF                                        */
                           /* 1 = all                                        */
                           /* 2 = only selected                              */
                           /* 3 = VOR                                        */
                           /* 4 = NDB                                        */
                           /* 5 = VOR/NDB                                    */

  short send_to_other_flag;/* TRUE = send configuration to other touch display */
                           /* FALSE = no action                              */
} Touch_Display_T;


typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.CEN.LG                */

  int   gear_lever;        /* landing gear (0,1)                         [-] */
} LG_Control_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.MIP.CEN.LDG              */

  short autobrake_low;     /* autobrake mode Low ON/OFF                     */
  short autobrake_med;     /* autobrake mode Medium ON/OFF                  */
  short autobrake_max;     /* autobrake mode Maximum ON/OFF                 */
} Autobrake_T;


/* ------------------------------------------------------------------------- */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.GLA.FCU                   */

  short lcd_light0;        /* Managed SPD/Mach Light On/Off                  */
  short lcd_light1;        /* Managed lateral Light On/Off                   */
  short lcd_light2;        /* Managed LVL/CH Light On/Off                    */

  float lcd_counter0;      /* SPD/Mach Value                                 */
  float lcd_counter1;      /* HDG/Track Value                                */
  float lcd_counter2;      /* Altitude Value                                 */
  float lcd_counter3;      /* V/S FPA Value                                  */

  short lcd_textlight0;    /* Display: SPD or Mach                           */
  short lcd_textlight1;    /* Display: HDG or Track                          */
  short lcd_textlight2;    /* Display: ALT                                   */
  short lcd_textlight3;    /* Display: V/S or FPA                            */
  short lcd_textlight4;    /* Display: HDG V/S or TRK FPA                    */

  short push_button0;      /* SPD/Mach Conversion                            */
  short push_button1;      /* HDG V/S / TRK FPA conversion                   */
  short push_button2;      /* METERS selection                               */
  short push_button3;      /* AP1 ON/OFF                                     */
  short push_button4;      /* AP2 ON/OFF                                     */
  short push_button5;      /* LOC Mode ON/OFF                                */
  short push_button6;      /* A/THR ON/OFF                                   */
  short push_button7;      /* EXPED Mode ON/OFF                              */
  short push_button8;      /* APPR Mode ON/OFF                               */

  short control_knob0;     /* SPD/Mach Selected or Managed                   */
  short control_knob1;     /* HDG/TRK Selected or Managed                    */
  short control_knob2;     /* Alt Selected or Managed                        */
  short control_knob3;     /* V/S / FPA Selected or Managed                  */

  int   inc_dial0;         /* incremental dial for SPD/Mach                  */
  int   inc_dial1;         /* incremental dial for HDG/TRK                   */
  int   inc_dial2;         /* incremental dial for ALT                       */
  int   inc_dial3;         /* incremental dial for V/S / FPA                 */

  short rot_switch0;       /* rotary switch for ALT increment                */
} FCU_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.GLA.EFIS1-2               */

  float lcd_counter0;      /* Baro Reference Value                           */

  short lcd_textlight0;    /* Display: QFE or QNH                            */


  short push_button0;      /* FD button                                      */
  short push_button1;      /* LS button                                      */

                           /* NOTE: Only one can be ON !!!                   */
  short radio_button0;     /* Constraint (CSTR) Display ON/OFF               */
  short radio_button1;     /* Waypoint (WYP) Display ON/OFF                  */
  short radio_button2;     /* VOR-DME (VOR-D) Display ON/OFF                 */
  short radio_button3;     /* NDB Display ON/OFF                             */
  short radio_button4;     /* Airport (ARPT) Display ON/OFF                  */

  short control_knob0;     /* Baro Reference Selection                       */

  int   inc_dial0;         /* incremental dial for Baro Reference            */

  short rot_switch0;       /* Baro Reference Unit                            */
  short rot_switch1;       /* ND-Mode selection (Range ?)                    */
  short rot_switch2;       /* ND-Range selection (Range ?)                   */

  short toggle_switch0;    /* ADF-VOR Selection 1 (Range ?)                  */
  short toggle_switch1;    /* ADF-VOR Selection 2 (Range ?)                  */
} EFIS_T;


/* ------------------------------------------------------------------------- */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.PDS.ECAM_CTL              */

  short touch_button0;     /* Take Off Configuration Test                    */
  short touch_button1;     /* Emergency Cancel                               */
  short touch_button2;     /* Clear Messages                                 */
  short touch_button3;     /* Display Status Side                            */
  short touch_button4;     /* Recall Warnings/Cautions                       */
  short touch_button5;     /* Clear Messages                                 */
  short touch_button6;     /* Show successively all system pages             */

  short radio_button0;     /* Engine Page                                    */
  short radio_button1;     /* Air Bleed Page                                 */
  short radio_button2;     /* Cabin Pressurization Page                      */
  short radio_button3;     /* AC Electrical Power Page                       */
  short radio_button4;     /* DC Electrical Power Page                       */
  short radio_button5;     /* Hydraulic Page                                 */
  short radio_button6;     /* Circuit Breakers Page                          */
  short radio_button7;     /* APU Page                                       */
  short radio_button8;     /* Air Conditioning Page                          */
  short radio_button9;     /* Door/Oxygen Page                               */
  short radio_button10;    /* Wheel Page                                     */
  short radio_button11;    /* Flight Control Page                            */
  short radio_button12;    /* Fuel Page                                      */
} ECAM_CTL_Panel_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.PDS.ENG_MAS               */

  short toggle_switch0;    /* Engine 1 ON/OFF                                */
  short toggle_switch1;    /* Engine 2 ON/OFF                                */
  short toggle_switch2;    /* Engine 3 ON/OFF                                */
  short toggle_switch3;    /* Engine 4 ON/OFF                                */
} Engine_Master_Panel_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.PDS.ENG_ST                */

  short rot_switch0;       /* 0 = Crank                                      */
                           /* 1 = Norm                                       */
                           /* 2 = Ign/Start                                  */
} Engine_Start_Panel_T;


/* ----------------------- */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.PDS.RUD_TR                */

  float lcd_counter0;      /* value of rudder trim                     [deg] */
                           /* positive according to z-axis-direction down    */
                           /* negative = rudder to the right                 */
                           /* positive = rudder to the left                  */

  short touch_button0;     /* by pushing (1) the reset button the zero trim  */
                           /* position is ordered; if not touched (0),       */
                           /* nothing happens                                */

  short rot_switch0;       /* -1 = moves the neutral point of the rudder trim*/
                           /*      actuator to the right                     */
                           /*  0 = no action                                 */
                           /* +1 = moves the neutral point of the rudder trim*/
                           /*      actuator to the left                      */

} Rudder_Trim_Panel_T;

/* ----------------------- */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.PDS                       */
  /* basic input devices of pedestal                                         */

  float thrust_lev1;       /* normalized (0-1) CPT side                  [-] */
  float thrust_lev2;       /* normalized (0-1) FO  side                  [-] */

                           /* if there are four engines, then use            */
			   /* additionally                                   */

  float thrust_lev3;       /* normalized (0-1)                           [-] */
  float thrust_lev4;       /* normalized (0-1) FO side                   [-] */

  short rev_thrust;        /* reverse thrust (0,1)                       [-] */
  float trim;              /* normalized trim wheel postion (-1.0 - 0.2) [-] */
                           /* positive means pos stabilizer means nose down  */
  short flaps;             /* flap position (0-4)                        [-] */
  short speed_brakes;      /* speed brake position (0-4)                 [-] */
  short park_brakes;       /* park brake ON/OFF (0-1)                    [-] */

} Pedestal_Basics_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.PDS                       */
  /* basic input devices of pedestal                                         */

  short athr_disconnect1;  /* autothrust disconnect CPT (0,1)            [-] */
  short athr_disconnect2;  /* autothrust disconnect FO  (0,1)            [-] */

} Pedestal_Basics_II_T;
/* ------------------------------------------------------------------------- */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.OVH.APU                   */

  short push_button0;      /* APU-Master Switch                              */
  short push_button1;      /* APU-Start Switch                               */
} APU_Panel_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.OVH.EXTLT                 */

  short toggle_switch0;    /* Strobe Light ON/OFF                            */
  short toggle_switch1;    /* Beacon Light ON/OFF                            */
  short toggle_switch2;    /* Wing Light ON/OFF                              */
  short toggle_switch3;    /* Nav&Logo Light ON/OFF                          */
                           /* 0 = Navigation and Logo lights are off         */
                           /* 1 = first set of lights activated              */
                           /* 2 = second set of lights activated             */
  short toggle_switch4;    /* Runway Turn-OFF Light ON/OFF                   */
  short toggle_switch5;    /* Landing Lights ON/OFF                          */
  short toggle_switch6;    /* Taxi/TakeOff Light ON/OFF                      */
                           /* 0 = Taxi and TakeOff lights are off            */
                           /* 1 = only Taxi lights are on                    */
                           /* 2 = Taxi and TakeOff lights are on             */
} External_Lighting_Panel_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.OVH.AIR                   */

  short push_button0;      /* APU/BLEED ON/OFF                               */
} APU_Bleed_Panel_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.PNL.OVH.ELEC                  */

  short push_button0;      /* External Power A ON/OFF                        */
  short push_button1;      /* External Power B ON/OFF                        */
} External_Power_Panel_T;

/* ------------------------------------------------------------------------- */

typedef struct {

  /* Prefix of following variables: ACR1-2.COP.STI1-2                        */

  float pitch_a;           /* normalized pitch cmd, angle (-1 - 1)       [-] */
                           /* positive means pos elevator means nose down    */
  float roll_a;            /* normalized roll cmd, angle (-1 - 1)        [-] */
                           /* positive means pos aileron means roll left     */
  float pitch_f;           /* normalized pitch cmd, force (-1 - 1)       [-] */
                           /* positive means pos elevator means nose down    */
  float roll_f;            /* normalized roll cmd, force (-1 - 1)        [-] */
                           /* positive means pos aileron means roll left     */
  float steering_wheel;    /* steering wheel angle                     [deg] */
} Stick_T;

typedef struct {

/* Prefix of following variables: ACR1-2.COP.PED1-2                          */

  float rudder;            /* normalized rudder cmd, angle (-1 - 1)      [-] */
                           /* positive means pos rudder means yaw to left    */
  float brake_l;           /* normalized brake cmd, left (0-1)           [-] */
  float brake_r;           /* normalized brake cmd, right (0-1)          [-] */
} Pedal_T;


/* ------------------------------------------------------------------------- */
typedef struct {

/* Prefix of following variables: ACR1-2.ATT.STATE                           */

  float  u;                /* translatoric velocity of cg of aircraft in body
                            * fixed x-axis                             [m/s] */
  float  v;                /* translatoric velocity of cg of aircraft in body
                            * fixed y-axis                             [m/s] */
  float  w;                /* translatoric velocity of cg of aircraft in body
                            * fixed z-axis                             [m/s] */

  float  u_dot;            /* translatoric acceler. of cg of aircraft in body
                            * fixed x-axis                           [m/s/s] */
  float  v_dot;            /* translatoric acceler. of cg of aircraft in body
                            * fixed y-axis                           [m/s/s] */
  float  w_dot;            /* translatoric acceler. of cg of aircraft in body
                            * fixed z-axis                           [m/s/s] */

  float  p;                /* rotatoric velocity of cg of aircraft around body
                            * fixed x-axis                             [1/s] */
  float  q;                /* rotatoric velocity of cg of aircraft around body
                            * fixed y-axis                             [1/s] */
  float  r;                /* rotatoric velocity of cg of aircraft around body
                            * fixed z-axis                             [1/s] */

  float  p_dot;            /* rotatoric acceler. of cg of aircraft around body
                            * fixed x-axis                           [1/s/s] */
  float  q_dot;            /* rotatoric acceler. of cg of aircraft around body
                            * fixed y-axis                           [1/s/s] */
  float  r_dot;            /* rotatoric acceler. of cg of aircraft around body
                            * fixed z-axis                           [1/s/s] */

  float  Q0;                /* quaternion                                 [-]
                            *   COS(phi/2)*COS(theta/2)*COS(psi/2) + 
                            *   SIN(phi/2)*SIN(theta/2)*SIN(psi/2)           */
  float  Q1;               /* quaternion                                 [-]
                            *   COS(phi/2)*SIN(theta/2)*SIN(psi/2) - 
                            *   SIN(phi/2)*COS(theta/2)*COS(psi/2)           */
  float  Q2;               /* quaternion                                 [-]
                            * - COS(phi/2)*SIN(theta/2)*COS(psi/2) - 
                            *   SIN(phi/2)*COS(theta/2)*SIN(psi/2)           */
  float  Q3;               /* quaternion                                 [-]
                            * - COS(phi/2)*COS(theta/2)*SIN(psi/2) + 
                            *   SIN(phi/2)*SIN(theta/2)*COS(psi/2)           */

} State_Space_T;

typedef struct {

/* Prefix of following variables: ACR1-10.ATT.NAV                            */

  long   lat;              /* latitude  (north) ARP    WGS 84    [1/1000sec] */
  long   lon;              /* longitude (east)  ARP    WGS 84    [1/1000sec] */
  float  elev;             /* elevation (down)  ARP    WGS 84 geoid [1/100m] */
  float  geo_velo[3];      /* geodetic velocity X,Y,Z (z down)         [m/s] */
  float  geo_accel[3];     /* geodetic acceleration X,Y,Z (z down)   [m/s/s] */

  float  bank;             /* bank angle                               [deg] */
  float  bank_d;           /* bank speed                             [deg/s] */
  float  bank_dd;          /* bank acceleration                    [deg/s/s]
                            * not supported at the moment                    */
  float  pitch;            /* pitch angle                              [deg] */
  float  pitch_d;          /* pitch speed                            [deg/s] */
  float  pitch_dd;         /* pitch acceleration                   [deg/s/s]
                            * not supported at the moment                    */
  float  head;             /* heading                                  [deg] */
  float  head_d;           /* head speed                             [deg/s] */
  float  head_dd;          /* head acceleration                    [deg/s/s]
                            * not supported at the moment                    */
  float  track;            /* track over ground                        [deg] */
  float  v_tot;            /* groundspeed                              [kts] */
  float  fpa;              /* flight path angle                        [deg] */
} Navigation_T;


typedef struct {

/* Prefix of following variables: ACR1-2.ATT.AIR                             */

  float ias;               /* indicated airspeed                       [kts] */
  float speed_trend;       /* predicted ias in ten seconds             [kts] */
  float tas;               /* true airspeed                            [kts] */
  float mach;              /* Mach number                                [-] */
  float radio_alt;         /* radio altitude                            [ft] */
  float baro_alt;          /* barometric altitude                       [ft] */
  int   baro_mode;         /* QNH=1, QFE=2, STD=0                        [-] */
  float baro_setting;      /* present baro setting                    [mbar] */
  float vario;             /* vario                                 [ft/min] */
  float aoa;               /* angle of attack [up]                     [deg] */
  float slip;              /* slip angle                               [deg] */
} Luftdaten_T;

typedef struct {

/* Prefix of following variables: ACR1-2.ATT.AIR                             */

  float SAP;               /* static air pressure                      [hPa] */
  float TAP;               /* total air pressure                       [hPa] */
  float SAT;               /* static air temperature                     [K] */
  float TAT;               /* total air temperature                      [K] */
  float rho;               /* air density                         [kg/m/m/m] */ 
  float vel_of_sound;      /* velocity of sound                        [m/s] */
  float baro_alt2;         /* barometric altitude                       [ft] */
  int   baro_mode2;        /* STD=0, QNH=1, QFE=2                        [-] */
  float baro_setting2;     /* present baro setting                     [hPa] */
  float wind_dir;          /* wind direction                           [deg] */
  float wind_speed;        /* wind speed                               [kts] */
} Luftdaten_II_T;


typedef struct {

/* Prefic of following variables : ACR#.ATT.LLF                           */

  short mode;              /* mode (0 .. 5)                           [-] */
  short track;             /* track number                            [-] */
  float clearance_height;  /* set clearance height                   [ft] */
  short status;            /* status / error                          [-] */
  short figure_of_merit;   /* figure of merit (0 .. 5)                [-] */
  short sensor_state;      /* sensor state                            [-] */
} LowLevelFlight_T;


typedef struct {

/* Prefix of following variables: ACR1-2.ATT.RAD.NAVAID1-2                   */

  short status;            /* ALL: 0=off  1=on                               */
  int   type;              /* ALL: FIC number                                */
  float radial;            /* VOR: selected VOR-radial                 [deg] */
  float loc_dev;           /* VOR+ILS: localizer deviation             [dot] */
  float gls_dev;           /* ILS: glide slope deviation               [dot] */
  float dme;               /* VOR+ILS: distance to sender               [nm] */
  float direction;         /* NDB: direction to NDB                    [deg] */
  char  id[4];             /* ALL: NAVAID-ID                                 */
  char  freq[7];           /* ALL: tuned frequency                     [MHz] */
} Radio_NAVAID_T;

typedef struct {

/* Prefix of following variables: ACR1-2.ATT.ENG1, ACR1-2.ATT.ENG2           */
/*                                ACR1-2.ATT.ENG3, ACR1-2.ATT.ENG4           */
  /* these variables describe the state of the engines, they are no input    */
  /* variables, they are output from the engine module                       */

  float throttle;          /* n1 according to thrust lever position      [%] */
  float thrust;            /* thrust                                     [%] */
  float n1;                /* shaft speed of high pressure circuit       [%} */
  float n2;                /* shaft speed of low pressure circuit        [%} */
  float epr;               /* exhaust pressure ratio                     [-] */
  float egt;               /* exhaust gas temperature                [deg C] */
  float fuel_flow;         /* fuel flow                               [kg/h] */
} Engine_T;

typedef struct {

/* Prefix of following variables: ACR1-2.ATT.ENG1, ACR1-2.ATT.ENG2           */
/*                                ACR1-2.ATT.ENG3, ACR1-2.ATT.ENG4           */
  /* these variables describe the state of the engines, they are no input    */
  /* variables, they are output from the engine module                       */

  float athr_cmd;          /* n1 according to autothrust command         [%] */
} Engine_II_T;

typedef struct {

/* Prefix of following variables: ACR1-2.ATT.AKT                             */

  float elevator_l;        /* position of actuator                     [deg] */
  float elevator_r;        /* position of actuator                     [deg] */
  float hori_stab;         /* position of actuator                     [deg] */
  float airbrake_l_i;      /* position of actuator                     [deg] */
  float airbrake_l_o;      /* position of actuator                     [deg] */
  float airbrake_r_i;      /* position of actuator                     [deg] */
  float airbrake_r_o;      /* position of actuator                     [deg] */
  float spoiler_i_l;       /* position of actuator                     [deg] */
  float spoiler_i_r;       /* position of actuator                     [deg] */
  float spoiler_o_l;       /* position of actuator                     [deg] */
  float spoiler_o_r;       /* position of actuator                     [deg] */
  float aileron_i_l;       /* position of actuator                     [deg] */
  float aileron_i_r;       /* position of actuator                     [deg] */
  float aileron_o_l;       /* position of actuator                     [deg] */
  float aileron_o_r;       /* position of actuator                     [deg] */
  float rudder_u;          /* position of actuator                     [deg] */
  float rudder_l;          /* position of actuator                     [deg] */
  float rudder_trim;       /* neutral point of rudder                  [deg] */
  float slat_l;            /* position of actuator                     [deg] */
  float slat_r;            /* position of actuator                     [deg] */
  float flap_l;            /* position of actuator                     [deg] */
  float flap_r;            /* position of actuator                     [deg] */
  float gear;              /* position of actuator (0.0 - 1.0)           [-]
			    * 0.0 = full retracted
			    * 1.0 = full extended                            */
} Aktuatoren_T;


/* ------------------------------------------------------------------------- */
typedef struct {

  /* Prefix of following variables: ACR#.AST.FCC                             */
  /* in future all control surface commands must be included here !!!        */

  float fc_elevator_cmd;   /* elevator command of flight controller      [-] */
                           /* range: -1 to +1                                */
                           /* positive means pos elevator means nose down    */
  short fc_trim_sw_cmd;    /* trim switch                                [-]
                            * -1 = move hori_stabilizer into neg direction
                            *  0 = leave hori_stabilizer stays untouched
                            * +1 = move hori_stabilizer into pos direction
                            * pos stabilizer means nose down
                            * NOTE: trim_switch has higher priority than
                            *       trim, which gives an absolute position   */

  float fc_hori_stab_cmd;  /* hor. stabilizer cmd of flight controller   [-] */
                           /* range: -1 to +0.2                              */
                           /* positive means pos stabilizer means nose down  */
  float fc_aileron_cmd;    /* aileron command of flight controller       [-] */
                           /* range: -1 to +1                                */
                           /* positive means pos aileron means roll left     */
  float fc_rudder_cmd;     /* rudder command of flight controller        [-] */
                           /* range: -1 to +1                                */
                           /* positive means pos rudder means yaw to left    */
  float fc_rud_trim_cmd;   /* rudder trim command of flight controller   [-] */
                           /* range: -1 to +1                                */
                           /* positive means pos rudder means yaw to left    */
  short fc_rudtr_res_cmd;  /* ON  orders rudder trim to zero/reset           */


  float fc_thrust_lev1_cmd;/* normalized (0-1) CPT side                  [-] */
  float fc_thrust_lev2_cmd;/* normalized (0-1) FO  side                  [-] */

                           /* if there are four engines, then use            */
                           /* additionally                                   */

  float fc_thrust_lev3_cmd;/* normalized (0-1)                           [-] */
  float fc_thrust_lev4_cmd;/* normalized (0-1) FO side                   [-] */
  short fc_rev_thrust_cmd; /* reverse thrust (0,1)                       [-] */

  short fc_flap_slat_cmd;  /* flap slat command (0-4)                    [-] */
  short fc_speed_brakes_cmd; /* speed brake position (0-4)               [-] */
  short fc_groundspoiler_cmd; /* groundspoiler command (not defined yet) [-] */
} Flight_Controller_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.AST.API                           */

  short ap1_flag;          /* autopilot 1: 0=off, 1=on                       */
  short ap2_flag;          /* autopilot 2: 0=off, 1=on                       */
  short athr_flag;         /* autothrust : 0=off, 1=on                       */

  float sel_speed;         /* selected speed autopilot, autothrust     [kts] */
  float sel_altitude;      /* selected altitude                         [ft] */
  float sel_heading;       /* selected heading                         [deg] */
  float sel_track;         /* selected track over ground               [deg] */
  float sel_vert_speed;    /* selected vertical speed               [ft/min] */
  float sel_fpa;           /* selected flight path angle               [deg] */
  short sel_nav_mode;      /* 0 - ILS                                        */
                           /* 1 - VOR                                        */
                           /* 2 - NDB                                        */
} Autopilot_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.AST.API                           */

  short speed_mode;        /* -1 = no current target
			    *  0 = selected
			    *  1 = managed                                   */
  short altitude_mode;     /* -1 = no current target
			    *  0 = selected
			    *  1 = managed                                   */
  short heading_mode;      /* -1 = no current target
			    *  0 = selected
			    *  1 = managed                                   */
  short track_mode;        /* -1 = no current target
			    *  0 = selected
			    *  1 = managed                                   */
  short vert_speed_mode;   /* -1 = no current target
			    *  0 = selected
			    *  1 = managed                                   */

  short fpa_mode;          /* -1 = no current target
			    *  0 = selected
			    *  1 = managed                                   */

} Autopilot_II_T;



typedef struct {

  /* Prefix of following variables: ACR#.AST.FD.ATT                          */

  float bank;              /* commanded bank                           [deg] */
  float pitch;             /* commanded pitch                          [deg] */
  float head;              /* commanded heading                        [deg] */

} Flight_Director_Attitude_T;

typedef struct {

  /* Prefix of following variables: ACR#.AST.FD.FP                           */

  float gamma;             /* commanded gamma                          [deg] */
  float track;             /* commanded track                          [deg] */

} Flight_Director_Flightpath_T;

typedef struct {

  /* Prefix of following variables: ACR#.AST.FD.LLF                          */
  
  float x;                 /* commanded difference horizontal            [-] */
  float y;                 /* commanded difference vertical              [-] */
  float bank;              /* commanded bank                           [deg] */
  float time_diff;         /* difference to planned time               [sec]
			    * negative means too slow                        */

} Flight_Director_LowLevelFlight_T;

typedef struct {

/* Prefix of following variables: ACR#.AST.FMA                               */

  float ptime;                /* time offset (ptime> 0)                [sec] */
  float lat;                  /* latitude                 [WGS 84 1/1000sec] */
  float lon;                  /* longitude                [WGS 84 1/1000sec] */
  float elev;                 /* elevation            [WGS 84  geoid 1/100m] */
  float head;                 /* azimuth heading                       [deg] */
  float bank;                 /* bank angle                            [deg] */
  float pitch;                /* pitch angle                           [deg] */
} FollowMeACR_T;

typedef struct {

  /* Prefix of following variables: ACR#.AST.TCAS.RA                         */

  unsigned char raUp;       /* 0= none
			     * 1=climb
			     * 2= don't descend 0
			     * 3=don't descend 500
			     * 4=don't descend 1000
			     * 5=don't descend 2000                          */
  unsigned char raDown;     /* 0= none
			     * 1=descend
			     * 2=don't climb 0
			     * 3=don't climb 500
			     * 4=don't climb 1000
			     * 5=don't climb 2000                            */
  unsigned char raCombined; /* 0=none
			     * 1=clear of conflict
			     * 2=up corrective
			     * 3=down corrective
			     * 4=preventive                                  */
  unsigned char raVerticalControl; /* 0=none
				    * 1=crossing
				    * 2=reversal
				    * 3=increase
				    * 4=maintain                             */
  float raRate;              /*[ft/min] -6300;+6300                          */
} TCAS_Resolution_Advisory_T;


typedef struct {

  /* Prefix of following variables: ACR#.AST.GCAS.RA                         */

  float flightPathAdvisoryAngle; /* -30 - +30 [deg]                          */

} GCAS_Resolution_Advisory_T;

typedef struct {

  /* Prefix of following variables: ACR1-30.AST.FLP.TSK1-10                  */

  int  tasktype;           /* type of task the airplanbe has to follow
			    * can be:
			    * 1 START for start from airport (communicate
			    *   to airport)
			    * 2 LAND for Landing on airport (communicate 
			    *   to airport)
			    * 3 PARK for parking on airport (communicate 
			    *   to airport)
			    * 4 WAIT for waiting at last WP
			    * 5 WAYPOINT (the airplane has to reach)
			    * 6 AGAIN for repeating the full task (from TSK1)
			    *
			    * Some of the variables are only filled in special
			    * cases (1 - 6). 
			    */
  long  lat_fp;            /* 5 : latitude of waypoint WGS84     [1/1000sec] */
  long  lon_fp;            /* 5 : longitude of waypoint WGS84    [1/1000sec] */
  float alt_fp;            /* 5 : altitude of waypoint  WGS84       [1/100m] */
  float v_ground_fp;       /* 5 : from flightplan dedicated  speed over 
			    *     ground at this waypoint   
			    */
  int   flight_phase;      /* 5 : the waypoint belongs to a taxiline, which 
			    *     can be of type
			    *     0 - Preflight (parking-line)
			    *     1 - Taxi Out
			    *     2 - Take Off
			    *     3 - Cruise
			    *     4 - Approach 
			    *     5 - Taxi Back
			    *     6 - Holding
			    */
  char  apic[5];           /* 1,2,3 : ICAO airport identification code  
			    *         eg. "EDDF"   
			    */
  int   time_to_wait;      /* 3 : Time to PARK on dedicated airport    [sec]
			    * 4 : Time to WAIT at WP                   [sec]
			    */

} Flightplan_T;


typedef struct {

  /* Prefix of following variables: ACR1-2.AST.FLP.TAXI.TXL1-10              */
  /*                                ACR1-2.AST.FLP.TAXI.PRES                 */

  char  airport[8];        /* name of airport                                */
  char  name[5];           /* name of taxiway                                */
  short taxi_seg  ;        /* taxi segment                                   */
  short line_seg;          /* taxiline segment                               */
} Taxilines_T;

/* ------------------------------------------------------------------------- */

typedef struct {

  /* Prefix of following variables: ACR#.SUR.INTR1-10.PRES                   */

  long  lat;               /* intruder geografic latitude  WGS84 [1/1000sec] */
  long  lon;               /* intruder geografic longitude WGS84 [1/1000sec] */
  float elev;              /* intruder altitude WGS84               [1/100m] */

  float bank;              /* bank angle of intruder                   [deg] */
  float pitch;             /* pitch angle of intruder                  [deg] */
  float head;              /* heading angle of intruder                [deg] */

  float  geo_velo[3];      /* geodetic velocity X,Y,Z (z down)         [m/s] */

} Intruder_Present_T;

typedef struct {

  /* Prefix of following variables: ACR1-2.SUR.COLL                          */

  short collision_flag;    /* collision with database objects                */
  long  collision_ID;      /* Feature Identification Code (FIC) for          */
                           /* collision object                               */

  long  object_ID;         /* Current Feature (FIC code) directly under      */
                           /* aircraft                                       */
  float object_alt;        /* altitude [1/100m] of this object above MSL     */

  float calc_rate;         /* calculation rate in [runs/sec]                 */
}DBcollision_T;

/* ------------------------------------------------------------------------- */

typedef struct {

/* structure of single cloud in data pool                                    */
/* Prefix of following variables: ACR1-2.SUR.WEA.CLD1-10                     */

  long     ID;               /* ID number from 1 to 1 000 000 000 */

/* a bounding box in WGS84 coordinates, box is parallel to the ground        */
/* and defined by:                                                           */
/* center point in WGS84 coordinates                                         */
/* length of box in x, y and z                                               */
/* rotation angle of box around WGS z-axis                                   */

  long     center_lat;       /* latitude of center (north) WGS 84    [1/1000sec] */
  long     center_lon;       /* longitude of center (east) WGS 84    [1/1000sec] */
  float   center_elev;	     /* elevation of center (down) WGS 84 geoid [1/100m] */
  float    dx,dy,dz;         /* length of box in x, y and z                  */
                             /* units according to lat, lon, elev            */
  float    z_rot;            /* rotation angle of box around z-axis          */

/* type of single cloud                                                      */
  short    subtyp;           /* cloud type */
                             /* 1 = Cumulus */
                             /* 2 = Altocumulus_undulatus */
                             /* 3 = Altocumulus_lacunosus */
                             /* 4 = Altocumulus_lenticularis */
                             /* 5 = Cumulus_nimbus */
                             /* 6 = Stratus */
                             /* 7 = Nimbostratus */
                             /* 8 = Altostratus */
                             /* 9 = Fog */
  int      density;          /* density from 0 to 100 */
  int      rain;             /* rain intensity from 0 to 100 */
  float    bolt_fr;          /* frequency in sec */
  short    is_a_cloud;         
} Cloud_T;

/* ------------------------------------------------------------------------- */




typedef struct {

/* structure of single wind data set                                         */
/* Prefix of following variables: ACR1-2.SUR.WEA.WIND1                       */

/* position of wind vektor relative to center of gravity in body-fixed-axes  */
  float    dx;         /* positive in direction of nose                 [m]  */
  float    dy;         /* positive in direction of right wing           [m]  */
  float    dz;         /* positive down                                 [m]  */

  float    u_trans;    /* x-component of translatoric wind velocity          */
  float    v_trans;    /* y-component of translatoric wind velocity          */
  float    w_trans;    /* z-component of translatoric wind velocity          */
  float      p_rot;    /* rotatatoric wind velocity component around x-axis  */
  float      q_rot;    /* rotatatoric wind velocity component around y-axis  */
  float      r_rot;    /* rotatatoric wind velocity component around z-axis  */
} Wind_T;




/* ------------------------------------------------------------------------- */

typedef struct {

/* structure of fog data                                                     */
/* Prefix of following variables: ACR1-2.SUR.WEA.FOG                         */

  float  cent_density; /* Fog density directly at aircraft center      [0-1] */

  float  onset;        /* The onset is the range at which fog blending first */
                       /* occurs in world coordinates                   [m]  */

  float  range;        /* range is the distance at which scene elements are  */
                       /* completely opaque in world coordinates        [m]  */

  float  dist[6];      /* normalized distance of fog control point     [0-1] */
                       /* 0 = onset                                          */
                       /* 1 = onset + range                                  */

  float  transp[6];    /* transparency value                           [0-1] */
                       /* 0 = opaque fog                                     */
                       /* 1 = no fog                                         */

} Fog_T;

typedef struct {

/* Prefix of following variables: ACR#.SUR.WEA.ATMOS                         */

  float SAP;           /* static air pressure                          [hPa] */
  float TAP;           /* total air pressure                           [hPa] */
  float TAT;           /* total air temperature                          [K] */
  float rho;           /* air density                             [kg/m/m/m] */ 
  float vel_of_sound;  /* velocity of sound                            [m/s] */
  
  float T_null;        /* temperature at MSL                             [K] 
			* normally 288.15 K                                  */
} Atmosphere_T;




/* ------------------------------------------------------------------------- */
/* here are the variables to describe the true state of flight of the        */
/* airplane; they are input to sensor modells which are part of a sensor     */
/* process. This sensor process writes the variables which are read by most  */
/* application processes, e.g. the NAV structure                             */
/* in the beginning only the position and bank, pitch and heading angle      */
/* are subject of change; for all other variables it is assumed, that true   */
/* and sensor values are identical                                           */
/* ------------------------------------------------------------------------- */

typedef struct {

/* Prefix of following variables: ACR#.REAL.GEN.CON                          */

  float weight;            /* gross weight of airplane                  [kg] */
  float fuel_on_board;     /* actual amount of fuel on board            [kg] */
} Real_Konfiguration_T;

typedef struct {

/* Prefix of following variables: ACR#.REAL.ATT.AIR                          */

  float u_A;               /* x-component of aerodynamic velocity,
			    * body axis system                         [m/s] */
  float v_A;               /* y-component of aerodynamic velocity,
			    * body axis system                         [m/s] */
  float w_A;               /* z-component of aerodynamic velocity,
			    * body axis system                         [m/s] */

  float u_A_dot;           /* x-component of aerodynamic acceleration,
			    * body axis system                       [m/s/s] */
  float v_A_dot;           /* y-component of aerodynamic acceleration,
			    * body axis system                       [m/s/s] */
  float w_A_dot;           /* z-component of aerodynamic acceleration,
			    * body axis system                       [m/s/s] */
} Real_Luftdaten_T;

typedef struct {

/* Prefix of following variables: ACR#.REAL.ATT.STATE                        */

  float  u;                /* translatoric velocity of cg of aircraft in body
                            * fixed x-axis                             [m/s] */
  float  v;                /* translatoric velocity of cg of aircraft in body
                            * fixed y-axis                             [m/s] */
  float  w;                /* translatoric velocity of cg of aircraft in body
                            * fixed z-axis                             [m/s] */

  float  u_dot;            /* translatoric acceler. of cg of aircraft in body
                            * fixed x-axis                           [m/s/s] */
  float  v_dot;            /* translatoric acceler. of cg of aircraft in body
                            * fixed y-axis                           [m/s/s] */
  float  w_dot;            /* translatoric acceler. of cg of aircraft in body
                            * fixed z-axis                           [m/s/s] */

  float  p;                /* rotatoric velocity of cg of aircraft around body
                            * fixed x-axis                             [1/s] */
  float  q;                /* rotatoric velocity of cg of aircraft around body
                            * fixed y-axis                             [1/s] */
  float  r;                /* rotatoric velocity of cg of aircraft around body
                            * fixed z-axis                             [1/s] */

  float  p_dot;            /* rotatoric acceler. of cg of aircraft around body
                            * fixed x-axis                           [1/s/s] */
  float  q_dot;            /* rotatoric acceler. of cg of aircraft around body
                            * fixed y-axis                           [1/s/s] */
  float  r_dot;            /* rotatoric acceler. of cg of aircraft around body
                            * fixed z-axis                           [1/s/s] */

  float  Q0;                /* quaternion                                 [-]
                            *   COS(phi/2)*COS(theta/2)*COS(psi/2) + 
                            *   SIN(phi/2)*SIN(theta/2)*SIN(psi/2)           */
  float  Q1;               /* quaternion                                 [-]
                            *   COS(phi/2)*SIN(theta/2)*SIN(psi/2) - 
                            *   SIN(phi/2)*COS(theta/2)*COS(psi/2)           */
  float  Q2;               /* quaternion                                 [-]
                            * - COS(phi/2)*SIN(theta/2)*COS(psi/2) - 
                            *   SIN(phi/2)*COS(theta/2)*SIN(psi/2)           */
  float  Q3;               /* quaternion                                 [-]
                            * - COS(phi/2)*COS(theta/2)*SIN(psi/2) + 
                            *   SIN(phi/2)*SIN(theta/2)*COS(psi/2)           */
} Real_State_Space_T;

typedef struct {

/* Prefix of following variables: ACR#.REAL.ATT.NAV                          */

  long   lat;              /* latitude  (north)        WGS 84    [1/1000sec] */
  long   lon;              /* longitude (east)         WGS 84    [1/1000sec] */
  float  elev;             /* elevation (down)         WGS 84 geoid [1/100m] */

  float  geo_velo[3];      /* geodetic velocity X,Y,Z (z down)         [m/s] */
  float  geo_accel[3];     /* geodetic acceleration X,Y,Z (z down)   [m/s/s] */

  float  bank;             /* bank angle                               [deg] */
  float  pitch;            /* pitch angle                              [deg] */
  float  head;             /* heading                                  [deg] */
} Real_Navigation_T;


typedef struct {

/* Prefix of following variables: ACR#.REAL.ATT.ENG1-4                       */

  /* these variables describe the state of the engines, they are no input    */
  /* variables, they are output from the engine module                       */

  float lev_cmd;           /* n1 according to thrust lever position      [%] */
  float athr_cmd;          /* n1 according to autothrust command         [%] */
  float thrust;            /* thrust                                     [%] */
  float n1;                /* shaft speed of high pressure circuit       [%} */
  float n2;                /* shaft speed of low pressure circuit        [%} */
  float epr;               /* exhaust pressure ratio                     [-] */
  float egt;               /* exhaust gas temperature                [deg C] */
  float fuel_flow;         /* fuel flow                               [kg/h] */
} Real_Engine_T;

typedef struct {

/* Prefix of following variables: ACR#.REAL.ATT.CSUR                         */

  float elevator_l;        /* position of control surface              [deg] */
  float elevator_r;        /* position of control surface              [deg] */
  float hori_stab;         /* position of control surface              [deg] */
  float airbrake_l_i;      /* position of control surface              [deg] */
  float airbrake_l_o;      /* position of control surface              [deg] */
  float airbrake_r_i;      /* position of control surface              [deg] */
  float airbrake_r_o;      /* position of control surface              [deg] */
  float spoiler_i_l;       /* position of control surface              [deg] */
  float spoiler_i_r;       /* position of control surface              [deg] */
  float spoiler_o_l;       /* position of control surface              [deg] */
  float spoiler_o_r;       /* position of control surface              [deg] */
  float aileron_i_l;       /* position of control surface              [deg] */
  float aileron_i_r;       /* position of control surface              [deg] */
  float aileron_o_l;       /* position of control surface              [deg] */
  float aileron_o_r;       /* position of control surface              [deg] */
  float rudder_u;          /* position of control surface              [deg] */
  float rudder_l;          /* position of control surface              [deg] */
  float rudder_trim;       /* neutral point of rudder                  [deg] */
  float slat_l;            /* position of control surface              [deg] */
  float slat_r;            /* position of control surface              [deg] */
  float flap_l;            /* position of control surface              [deg] */
  float flap_r;            /* position of control surface              [deg] */
} Real_Control_Surfaces_T;

typedef struct {

/* Prefix of following variables: ACR#.REAL.ATT.GEAR                         */

  short contact_NG;        /* ground contact nose gear (TRUE,FALSE)      [-] */
  short contact_LMG;       /* ground contact left main gear (TRUE,FALSE) [-] */
  short contact_RMG;       /* ground contact right main gear (TRUE,FALSE)[-] */
  short contact_TB;        /* ground contact tail bumper (TRUE,FALSE)    [-] */

  float nose_wheel_angle;  /* angle of nosewheel (-75.0 - 75.0)        [deg] */
  float position;          /* position of landing gear (0.0 - 1.0)       [-]
			    * 0.0 = full retracted
			    * 1.0 = full extended                            */
} Real_Landing_Gear_T;


/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */

typedef struct {

/* Prefix of following variables: SYS.TIME                                   */

  int   msec;              /* milliseconds of day (0-1000)               [-] */
  int   sec;               /* seconds of day (0-60)                      [-] */
  int   min;               /* minutes of day (0-60)                      [-] */
  int   hour;              /* hours of day (0-24)                        [-] */
} Time_T;

typedef struct {

/* Prefix of following variables: SYS.DATE                                   */

  int   day;               /*                                            [-] */
  int   month;             /*                                            [-] */
  int   year;              /*                                            [-] */
} Date_T;

typedef struct {

/* Prefix of following variables: SYS.INS                                    */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset simulation (0,1)                     [-] */
  short exit;              /* exit simulation (0,1)                      [-] */
} Control_T;


typedef struct {

  /* Prefix of following variables: SYS.VIS_ACR1-2                           */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset process (0,1)                        [-] */
  short exit;              /* exit process (0,1)                         [-] */
  short showStatistics;    /* 0=no, 1=minimal, 2=full                        */
  float frameRate;    
  short visual_flag;       /* 0=off, 1=on                                    */
  short terrain_flag;      /* 0=off, 1=on                                    */
  short clouds_flag;       /* 0=off, 1=on                                    */
  short aircraft_flag;     /* 0=off, 1=on                                    */
  short moon_sun_flag;     /* 0=off, 1=on                                    */
  short horizon_flag;      /* 0=off, 1=on                                    */
  char  NameVariant[16][64]; /* identification of different variations of 
			      * airport geometries; only meaningful for Visual,
			      * therefore no possible values                 */
  short DisplayVariant[16]; /* show NameVariant[index] ON/OFF                */
} Control_Visual_T;

typedef struct {

  /* Prefix of following variables: SYS.COLL_ACR1-2                          */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset process (0,1)                        [-] */
  short exit;              /* exit process (0,1)                         [-] */
} Control_Collision_T;

typedef struct {

  /* Prefix of following variables: SYS.DMP_ACR1-2                           */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset process (0,1)                        [-] */
  short exit;              /* exit process (0,1)                         [-] */
  char  attach_file[20];   /* correlation between input device and display
			      control data */
  char  automatic_file[20];/* setting of display control data according to
			      phase of flight */
} Control_DMP_T;

typedef struct {

  /* Prefix of following variables: SYS.SENS_ACR#                            */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset process (0,1)                        [-] */
  short exit;              /* exit process (0,1)                         [-] */
  long  delta_lat;         /* latitude deviation (north)         [1/1000sec] */
  long  delta_lon;         /* longitude deviation (east)         [1/1000sec] */
  float delta_elev;        /* elevation deviation (down pos)        [1/100m] */
  float delta_bank;        /* bank angle deviation                     [deg] */
  float delta_pitch;       /* pitch angle deviation                    [deg] */
  float delta_head;        /* heading angle deviation                  [deg] */
} Control_Sensor_T;

typedef struct {

  /* Prefix of following variables: SYS.BUCK_ACR1-2                          */

  short braketrim;         /* use potentionmeter: 0=trim, 1=brake left   [-] */
  short run;               /* 0=pause, 1=go                              [-] */
  short exit;              /* exit process (0,1)                         [-] */
} Control_Seating_Buck_T;


typedef struct{
  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset process (0,1)                        [-] */
  short exit;              /* exit process (0,1)                         [-] */
  /* ----------------------------------------------------------------------- */
  short gcas_flag;         /* 0=off, 1=on                                    */
  short tcas_flag;         /* 0=off, 1=on                                    */
  short windshear_flag;    /* 0=off, 1=on                                    */
  short stallhorn_flag;    /* 0=off, 1=on                                    */
  /* ----------------------------------------------------------------------- */
  short altitude_flag;     /* 0=off, 1=on                                    */
  /* ----------------------------------------------------------------------- */
  short flaps_flag;        /* 0=off, 1=on                                    */
  short engine_flag;       /* 0=off, 1=on                                    */
  short gear_flag;         /* 0=off, 1=on                                    */
  short interaction_flag;  /* 0=off, 1=on                                    */
  short touchdown_flag;    /* 0=off, 1=on                                    */
}Control_Sound_T;

typedef struct {

/* Prefix of following variables: SYS.FCC_ACR1-2                             */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset flight controller (0,1)              [-] */
  short exit;              /* exit (0,1)                                 [-] */
  short configuration;     /* configuration of Flight Controller             */
                           /* range to be defined !!!                        */
} Control_Flight_Controller_T;

typedef struct {

/* Prefix of following variables: SYS.FM_ACR#                               */
  short run;               /* run process (0,1)                   [-]       */
  short reset;             /* reset process (0,1)                 [-]       */
  short exit;              /* exit process (0,1)                  [-]       */
  short action;            /* 0 = normal program mode
			    * 1 = take over mode
			    * 2 = trim and start from this position         */

  long  wanted_lat;        /* wanted latitude (north)           [1/1000sec] */
  long  wanted_lon;        /* wanted longitude (east)           [1/1000sec] */
  float wanted_elev;       /* wanted elevation (down pos)       [1/100m]    */
  float wanted_gamma;      /* wanted gamma angle                [deg]       */
  float wanted_head;       /* wanted heading angle              [deg]       */
  float wanted_speed;      /* true airspeed value in            [m/s]       */

  short trim_mode;         /* 0=ground, 1=flight                  [-]       */
  short gear_pos;          /* 0=gear up, 1=gear down              [-]       */
  short config;            /* configuration setting: 1,2,3,6,7,10 [-]       */
  float mass;              /* mass value:85690-137500             [kg]      */
  float cog;               /* center of gravity: 11 - 31          [%l_mu]   */
} Control_Flightmechanics_T;


typedef struct {

/* Prefix of following variables: SYS.OVHD_ACR1-2                            */

  short run;               /* 0=pause, 1=go                              [-] */
  short reset;             /* reset overhead panel (0,1)                 [-] */
  short exit;              /* exit  (0,1)                                [-] */
  short configuration;     /* configuration of Overhead Panel                */
                           /* 0 = gate                                       */
                           /* 1 = ready for take off                         */
                           /* 2 = in flight                                  */
} Control_Overhead_T;

typedef struct {
/* Prefix of following variables: MON.WORLD?.PROCINF?                      */

  char  name[50];          /* name of process                                */
  short local_number;      /* process has got this number from WorldServer   */
  int   pid;               /* id of process                              [-] */
  int   ip;                /* ip of host that helds process 
			      (host byteorder (!))                           */
} Monitor_ProcInf_T;

typedef struct {
/* Prefix of following variables: MON.WORLD?                                 */

  char  name[50];        /* name of the world the processes work in        */
  short anz_alias;       /* expected number of aliases in datapool         */
  short anz_procs;       /* expected number of processes in datapool       */
} Monitor_Expected_T;

typedef struct {
/* Prefix of following variables: MON.WORLD?.ALINF?                          */

  char  name[50];          /* aliasname by ds_new_alias                  [-] */
} Monitor_AlInf_T;

typedef struct {
/* Prefix of following variables: MON.WORLD?.ALINF?.RD?
                                  MON.WORLD?.ALINF?.WR?                      */
  short local_number;      /* process has got this number from WorldServer   */
  short type;              /* alias can have different types
			      CHAR   1
			      SHORT  2
			      USHORT 3
			      INT    4
			      UINT   5
			      LONG   6
			      ULONG  7
			      FLOAT  8
			      DOUBLE 9
			    */
  short  size;              /* Size of alias, can be a multiplier of type, 
			      because arrays can be aliases too              */

} Monitor_Proc_T;


typedef struct {
/* Prefix of following variables: TOW1-10.GEN.IDE                            */
  char apic[5];           /* ICAO airport identification code  eg. "EDDF"    */
} Identifikation_Tower_T;


typedef struct {
/* Prefix of following variables: TOW1-10.COM.ACR1-30.MSG                    */
  int id;                /* 
			  * identifier for this message. This identifier tells
			  * the user if he got a new message (different 
			  * identifier) or an old one (same identifier as 
			  * before)
			  */ 
  int type_of_message;   /* what does the aircraft want from tower?
			  * can be:
			  * 1 for START
			  * 2 for LAND
			  * 3 for PARK
			  */  
} ComFromAcr_T;

typedef struct{

/* Prefix of following variables: TOW1.RWY1.LIGHT                          */

  char  rwyic[15];        /* ICAO runway identification code eg. "07L.25R" */
  short rail_flag;        /* 0=off,1=on                                    */
  short rabbit_flag;      /* 0=off,1=on                                    */
  short tdz_flag;         /* 0=off,1=on                                    */
  short edge_flag;        /* 0=off,1=on                                    */
  short end_flag;         /* 0=off,1=on                                    */
  short papi_flag;        /* 0=off,1=on                                    */
  short center_flag;      /* 0=off,1=on                                    */
}Runway_Lights_T;

typedef struct{

/* Prefix of following variables: TOW1.RWY1.HD_LIG                         */

  char  rwyic[15];        /* ICAO runway identification code eg. "07L.25R" */
  short rabbit_flag;      /* 0=off,1=on                                    */
  short tdz_flag;         /* 0=off,1=on                                    */
  short edge_flag;        /* 0=off,1=on                                    */
  short end_flag;         /* 0=off,1=on                                    */
  short papi_flag;        /* 0=off,1=on                                    */
}HALSDTOP_Lights_T;





/* THESE STRUCTURS ARE NOT OFFICIALLY SUPPORTED, DON'T ASK US FOR ANY
   EXPLANATION. */

typedef struct {

/* just different names for ACR#.AST.FD.LLF                                  */

  float fd_x;              /* commanded lateral position                 [-] */
  float fd_y;              /* commanded vertical position                [-] */
  float fd_bank;           /* commanded bank                             [-] */
  int   fd_time_diff;      /* time difference                            [s] */
} FFS_FlightDirector_T;

typedef struct {

/* just different names for ACR#.ATT.LLF                                     */

  short tf_mode;           /* mode (0 .. 5)                              [-] */
  short tf_track;          /* track number                               [-] */
  float tf_sch;            /* set clearance height                      [ft] */
  short tf_status;         /* status / error                             [-] */
  short tf_fom;            /* figure of merit (0 .. 5)                   [-] */
  short tf_sens_state;     /* sensor state                               [-] */
} FFS_LowLevelFlight_T;


typedef struct {

/* parts of Configuration box ACR#.GEN.CON and Actuators box ACR#.ATT.AKT    */

  float aoa_limit;         /* angle of attack limit                    [deg] */
  float	v2;                /* speed v2 - critical engine speed         [kts] */
  float	ac_mass;           /* aircraft mass 			        [kg] */
  short flph_on_ground;    /* wheels on ground (TRUE/FALSE)              [-] */
  float	airbrake_1;        /* airbrake 1                                 [-] */
  float	airbrake_2;        /* airbrake 2                                 [-] */
} FFS_Configuration_T;

typedef struct {

/* parts of Airdata box ACR#.ATT.AIR                                         */

  float	wind_dir;	   /* indicated wind direction (0 .. 360.0)    [deg] */
  float	wind_speed;	   /* indicated wind speed	               [kts] */
} FFS_WindIndication_T;


typedef struct {

/* just different names for ACR#.COP.PNL.GLA.FCU                             */

  short speed_mach_push_button; /* Speed/Mach Push Button (0=OFF, 1=ON)  [-] */
  short speed_mach_knob;      /* Speed/Mach Knob
				 (0=NEUTRAL, 1=PULLED, 2=PUSHED)         [-] */
  int   speed_mach_dial;      /* Speed/Mach Dial                         [-] */
  short hdg_trk_knob;	      /* HDG/TRK Knob
				 (0=NEUTRAL, 1=PULLED, 2=PUSHED)         [-] */
  int   hdg_trk_dial;         /* HDG/TRK Dial                            [-] */
  short hdgvs_trkfpa_push_button; /* HDG V/S TRK FPA Push Button
				     (0=HDG V/S, 1=TRK FPA               [-] */
  short altitude_knob;	      /* Altitude Knob
				 (0=NEUTRAL, 1=PULLED, 2=PUSHED)         [-] */
  int   altitude_dial;        /* Altitude Dial                           [-] */
  short fd_meter_push_button; /* FD Meter  Push Button	(0=FD, 1=Meter)  [-] */
  short vs_fpa_knob;	      /* V/S FPA Knob
				 (0=NEUTRAL, 1=PULLED, 2=PUSHED)         [-] */
  int   vs_fpa_dial;          /* V/S FPA Dial                            [-] */
  short ap1_push_button;      /* AP1 Push Button (0=OFF, 1=ON)           [-] */
  short ap2_push_button;      /* AP2 Push Button (0=OFF, 1=ON)           [-] */
  short loc_push_button;      /* LOC Push Button (0=OFF, 1=ON)           [-] */
  short athr_push_button;     /* A/THR Push Button (0=OFF, 1=ON)         [-] */
  short exped_push_button;    /* EXPED Push Button (0=OFF, 1=ON)         [-] */
  short appr_push_button;     /* APPR Push Button (0=OFF, 1=ON)          [-] */
} FFS_Efcu_T;

typedef struct {

/* just different names for ACR#.COP.PNL.GLA.EFIS1-2                         */
/* EFIS1=CPT, EFIS2=FO                                                       */

  short baro_setting_knob;    /* Baro Setting Knob
				 (0=NEUTRAL, 1=PULLED, 2=PUSHED)         [-] */
  int   baro_setting_dial;    /* Baro Setting Dial	                 [-] */
  short fd_push_button;	      /* FD Push Button	(0=OFF, 1=ON)            [-] */
  short ils_push_button1;     /* ILS Push Button (0=OFF, 1=ON)           [-] */
  short cstr_push_button;     /* CSTR Push Button (0=OFF, 1=ON)          [-] */
  short wpt_push_button;      /* WPT Push Button (0=OFF, 1=ON)           [-] */
  short vord_push_button;     /* VOR.D Push Button (0=OFF, 1=ON)         [-] */
  short ndb_push_button;      /* NDB Push Button (0=OFF, 1=ON)           [-] */
  short apt_push_button;      /* APT Push Button (0=OFF, 1=ON)           [-] */
  short hsd_mode_switch;      /* HSD Mode Switch (0=ILS, 1=VOR,
				 2=NAV='look around', 3=ARC='look forward',
				 4=PLAN                                  [-] */
  short hsd_range_switch;     /* HSD Range Switch
				 (10, 20, 40, 80, 160, 320)              [-] */
  short navaid1_switch;       /* NAVAID1 Switch (0=OFF, 1=ADF1, 2=VOR1)  [-] */
  short navaid2_switch;       /* NAVAID2 Switch (0=OFF, 1=ADF2, 2=VOR2)  [-] */
} FFS_EfisControlPanel_T;


typedef struct {

/* just different names for ACR#.AST.FMA box                                 */

  float followme_ptime;       /* time offset (ptime> 0)                [sec] */
  float followme_geolat;      /* latitude                 [WGS 84 1/1000sec] */
  float followme_geolon;      /* longitude                [WGS 84 1/1000sec] */
  float followme_geoalt;      /* altitude             [WGS 84  geoid 1/100m] */
  float followme_psi;         /* azimuth psi                           [deg] */
  float folowme_phi;          /* bank angle phi                        [deg] */
  float followme_theta;       /* inclination angle theta               [deg] */
} FFS_FollowMeACR_T;


typedef struct {

/* Prefix of following variables: ACR1.FFS.SPI                               */

  int spare_int_1;            /* 1. spare integer                        [-] */
  int spare_int_2;            /* 2. spare integer                        [-] */
  int spare_int_3;            /* 3. spare integer                        [-] */
  int spare_int_4;            /* 4. spare integer                        [-] */
  int spare_int_5;            /* 5. spare integer                        [-] */
  int spare_int_6;            /* 6. spare integer                        [-] */
  int spare_int_7;            /* 7. spare integer                        [-] */
  int spare_int_8;            /* 8. spare integer                        [-] */
  int spare_int_9;            /* 9. spare integer                        [-] */
  int spare_int_10;           /* 10. spare integer                       [-] */
} FFS_SpareInt_T;


typedef struct {

/* Prefix of following variables: ACR1.FFS.SPF                               */

  float spare_float_1;            /* 1. spare float                      [-] */
  float spare_float_2;            /* 2. spare float                      [-] */
  float spare_float_3;            /* 3. spare float                      [-] */
  float spare_float_4;            /* 4. spare float                      [-] */
  float spare_float_5;            /* 5. spare float                      [-] */
  float spare_float_6;            /* 6. spare float                      [-] */
  float spare_float_7;            /* 7. spare float                      [-] */
  float spare_float_8;            /* 8. spare float                      [-] */
  float spare_float_9;            /* 9. spare float                      [-] */
  float spare_float_10;           /* 10. spare float                     [-] */
} FFS_SpareFloat_T;


typedef struct {

/* Prefix of following variables: ACR1.FFS.SPC                               */

  char spare_character_1;            /* 1. spare character               [-] */
  char spare_character_2;            /* 2. spare character               [-] */
  char spare_character_3;            /* 3. spare character               [-] */
  char spare_character_4;            /* 4. spare character               [-] */
  char spare_character_5;            /* 5. spare character               [-] */
} FFS_SpareChar_T;


typedef struct {

/* just different name for SYS.TIME.wall_clock                               */

  int time_stamp;                    /* time stamp (0 .. 86.399.999)
					= GPS time (0 = 0:00:00:000)  [msec] */
} FFS_TimeStamp_T;

typedef struct {

  /* Prefix of following variables: SYS.OGL_DISP_ACR#                        */

  int   cmd_type;
  int   cmd_arg;
  int   cmd_receiver;
  float cmd_val;
  char  cmd_string[100];
} MP_Displays_T;

typedef struct {

  /* Prefix of following variables: SYS.OGL_DISP_ACR#                      */

  short run;
  short reset;
  short exit;
} Control_MP_Displays_T;

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
   THESE STRUCTURS ARE NOT OFFICIALLY SUPPORTED, DON'T ASK US FOR ANY
   EXPLANATION. */


/******************************************************************************

                                   PROTOTYPEN
				   
******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
 * Alle Prototypen, die spaeter einmal bei jedem lokal definiert werden. Die
 * Header haben folgende Bedeutung
 * 
 * ZUWEISUNG:
 *                    "box"   <->   Konfiguration_T
 * Mapping des Boxnamens auf den Strukturnamen. Wenn bei den anderen 
 * ds_Funktionen dieser Name uebergeben wird, muss der zu fuellende (ds_read)
 * bzw. der zu lesende (ds_write) Speicherbreich vom Typ dieser Struktur sein.
 * Beispiel:
 *                       ds_read("box", (char *)&Konfiguration_T);
 *
 *
 * FUNKTIONSAUFRUF:
 *               ds_initialize_GEN(char *box, char *s1);
 * Prototyp der Funktion. Der Funktionaufruf besteht aus einem vordefinierten
 * Anteil (ds_initialize_) und einem vom Nutzer definierten Anteil (GEN etc.).
 * Der nutzerdefinerte Anteil stellt den Typ der Box dar, den er grafisch 
 * definiert hat.Es kann also derselbe Boxtyp mit unterschiedlichen Namen und
 * Parametern belegt werden (siehe auch UBERGABEPARAMETER)
 *
 *
 * DATENSTRUKTUR:
 *                 |-----"s1".GEN.CON.phase_of_flight
 *                 |-----"s1".GEN.CON.conf_no
 *    	           |-----"s1".GEN.CON.underspeed
 *                 |-----"s1".GEN.CON.overspeed
 *                 |-----"s1".GEN.CON.v_flap
 *         "box"---|-----"s1".GEN.CON.v1
 *                 |-----"s1".GEN.CON.v_rot
 *                 |-----"s1".GEN.CON.high_bank
 *       	   |-----"s1".GEN.CON.decision_height
 * Die Aliase des Datenpools, die sich hinter dem Boxtyp (hier GEN) verbergen. 
 * Hierbei sind die zu uebergebenden Paramter offengelassen. Dieser Punkt dient
 * dazu, dem User einen Ueberblick ueber die gruppierten Aliase zu geben. 
 * Die Namensgleichheit zwischen Strukturvariablen und Aliasnamen ist NICHT 
 * gezwungenermassen gleich (auch wenn von uns empfohlen wird, dies spaeter 
 * beizubehalten). Dies resultiert vielmehr aus der Einfallslosigkeit der 
 * Namensgeber :-) 
 *
 *
 * UEBERGABEPARAMETER
                 box : beliebig
 *               s1  : ACR1, ACR2
 * Die Paramter, die an die Funktion uebergeben werden koennen muessen begrenzt
 * werden, bis die grafische Oberflaeche zur Verfuegung steht. Der Boxname 
 * (box) kann frei definiert und bei den Aufrufen von ds_x_announce() und 
 * ds_read() bzw. ds_write() verwendet werden. Die weiteren erlaubten 
 * Uebergabeparamter koennen in beliebigen Kombinationen verwendet werden 
 * (sofern mehr als ein Parameter ausser der Box uebergeben wird)
 ****************************************************************************/

/*****************************************************************************
 * ZUWEISUNG:
 *
 *            "boxname"      <->     example_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_EXMPL(char *boxname, char *s1);
 *
 * DATENSTRUKTUR im DATENPOOL:
 *
 * 		    |-----"s1".EXAMPLE1.character
 * 		    |
 *       "boxname"--|-----"s1".EXAMPLE2.fliesskomma
 *                  |
 *      	    |-----"s1".EXMPL.ganzzahl
 *
 ****************************************************************************/
short ds_initialize_EXMPL(char *boxname, char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Konfiguration_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_GEN(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".GEN.CON.phase_of_flight
 *    	           |-----"s1".GEN.CON.underspeed
 *                 |-----"s1".GEN.CON.overspeed
 *                 |-----"s1".GEN.CON.v_flap
 *         "box"---|-----"s1".GEN.CON.v1
 *                 |-----"s1".GEN.CON.v_rot
 *                 |-----"s1".GEN.CON.high_bank
 *       	   |-----"s1".GEN.CON.decision_height
 *       	   |-----"s1".GEN.CON.weight
 *       	   |-----"s1".GEN.CON.max_thrust
 *       	   |-----"s1".GEN.CON.v_cruise
 *       	   |-----"s1".GEN.CON.v_touch
 *       	   |-----"s1".GEN.CON.v_to
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_GEN(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Konfiguration_II_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_GEN_II(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".GEN.CON.v2
 *    	           |-----"s1".GEN.CON.v_ls
 *                 |-----"s1".GEN.CON.v_sw
 *                 |-----"s1".GEN.CON.aoa_limit
 *         "box"---|-----"s1".GEN.CON.prot_speed
 *                 |-----"s1".GEN.CON.aoa_prot_speed
 *                 |-----"s1".GEN.CON.aoa_max_speed
 *       	   |-----"s1".GEN.CON.vmin_flap_retract
 *       	   |-----"s1".GEN.CON.vmin_slat_retract
 *       	   |-----"s1".GEN.CON.weight_on_wheels
 *       	   |-----"s1".GEN.CON.fuel_on_board
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_GEN_II(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_Konfiguration_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALGEN(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *         "box"---|-----"s1".REAL.GEN.CON.weight 
 *       	   |-----"s1".REAL.GEN.CON.fuel_on_board
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 *
 ****************************************************************************/
short ds_initialize_REALGEN(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Identifikation_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_IDE(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".GEN.IDE.aircraft_id
 *    	   "box"---|-----"s1".GEN.IDE.typ
 *                 |-----"s1".GEN.IDE.company
 *         
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ACR3, ACR4, ACR5, ACR6, ACR7, ACR8, ACR9, ACR10  
 *
 ****************************************************************************/
short ds_initialize_IDE(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Geometry_Aircraft_Body_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_GEOM_BODY(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.GEOM.BODY.nose[3]
 *                 |-----"s1".COP.GEOM.BODY.tail[3]
 *                 |-----"s1".COP.GEOM.BODY.l_wingtip[3]
 *                 |-----"s1".COP.GEOM.BODY.r_wingtip[3]
 *                 |-----"s1".COP.GEOM.BODY.l_elev_tip[3]
 *         "box"---|-----"s1".COP.GEOM.BODY.r_elev_tip[3]
 *                 |-----"s1".COP.GEOM.BODY.rudder_top[3]
 *                 |-----"s1".COP.GEOM.BODY.nose_gear[3]
 *                 |-----"s1".COP.GEOM.BODY.l_main_gear[3]
 *                 |-----"s1".COP.GEOM.BODY.r_main_gear[3]
 *                 |-----"s1".COP.GEOM.BODY.cockpit_orig[3]
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ACR3, ACR4, ACR5, ACR6, ACR7, ACR8 ,ACR9, ACR10
 ****************************************************************************/
short ds_initialize_GEOM_BODY(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   General_Display_Warnings_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_DISP_WARN(char *box, char *s1);
 *
 *                 |-----"s1".COP.PNL.MIP.DISP.WARN.alarmType
 *         "box"---|-----"s1".COP.PNL.MIP.DISP.WARN.alarmTotalNum
 *                 |-----"s1".COP.PNL.MIP.DISP.WARN.alarmIdent
 *                 |-----"s1".COP.PNL.MIP.DISP.WARN.alarmPrio
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_DISP_WARN(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   PF_Display_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_PF_DISP(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".feat_number
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".feat_flag
 *         "box"---|-----"s1".COP.PNL.MIP.DISP."s2".feat_ident[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".x_pos_off[15]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".y_pos_off[15]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".x_scale[15]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".y_scale[15]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".ILS_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".altitude_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".speed_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".heading_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".attitude_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".text_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".wind_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".nav_recv1_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".nav_recv2_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".predictor_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".fp_vector_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".f_director_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".art_horizon_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".pitch_sky_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".energyheight_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".aplha_blending
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".perf_stat_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".intruder_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".baro_set_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".baro_set_value
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".terrain_model
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".terrain_color_exponent
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".terrain_height_steps
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sun_pos[3]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sun_rgb[3]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sun_gain
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".alt_offset
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".specific_dh
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".track_load_flag
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : PFD1, PFD2
 ****************************************************************************/
short ds_initialize_PF_DISP(char *box,char *s1, char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Predictor_PF_Display_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_PF_PRED(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.ac_ground_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.no_element
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.angle_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.scaleX
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.scaleY
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.scaleZ
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.offset
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.ptime[20]
 *         "box"---|-----"s1".COP.PNL.MIP.DISP."s2".PRED.lat[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.lon[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.elev[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.heading[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.bank[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.pitch[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.climb[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.azimut[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.warning[20]
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : PFD1, PFD2
 ****************************************************************************/
short ds_initialize_PF_PRED(char *box,char *s1, char *s2);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   NAV_Display_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_NAV_DISP(char *box, char *s1, char *s2);
 *
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".feat_number
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".feat_flag
 *         "box"---|-----"s1".COP.PNL.MIP.DISP."s2".feat_ident
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".around_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".taxi_pred_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".left_up_box_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".right_up_box_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".AC_symb_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".nav_recv1_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".nav_recv2_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".track_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PFD_view_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".airport_map_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".rose_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".range_circ_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".heading_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sel_heading_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".intruder_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".zoom
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".alpha_blending
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".perf_stat_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".terrain_model
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".terrain_color_exponent
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".terrain_height_steps
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sun_pos
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sun_rgb
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".sun_gain
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".track_load_flag
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".northUp
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : NAV1, NAV2
 ****************************************************************************/
short ds_initialize_NAV_DISP(char *box,char *s1, char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Predictor_NAV_Display_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_NAV_PRED(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.no_element
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.scaleX
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.scaleY
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.scaleZ
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.offset
 *         "box"---|-----"s1".COP.PNL.MIP.DISP."s2".PRED.ptime[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.lat[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.lon[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.heading[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.azimut[20]
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".PRED.warning[20]
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : NAV1, NAV2
 ****************************************************************************/
short ds_initialize_NAV_PRED(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Touch_Display_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_TCH_DISP(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".counter0
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".counter1
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button0
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button1
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button2
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button3
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button4
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button5
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button6
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button7
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button8
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button9
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button10
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button11
 *         "box"---|-----"s1".COP.PNL.MIP.DISP."s2".push_button12
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button13
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button14
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button15
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button16
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".push_button17
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".toggle_switch0
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".toggle_switch1
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".rot_switch0
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".rot_switch1
 *                 |-----"s1".COP.PNL.MIP.DISP."s2".send_to_other_flag
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : TOUCH1, TOUCH2
 ****************************************************************************/
short ds_initialize_TCH_DISP(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   LG_Control_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_LG(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *         "box"---|-----"s1".COP.PNL.MIP.CEN.LG.gear_lever
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_LG(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Autobrake_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_AB(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.MIP.CEN.LDG.autobrake_low
 *         "box"---|-----"s1".COP.PNL.MIP.CEN.LDG.autobrake_med
 *                 |-----"s1".COP.PNL.MIP.CEN.LDG.autobrake_max
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_AB(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   FCU_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FCU(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_light0
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_light1
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_light2
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_counter0
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_counter1
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_counter2
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_counter3
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_textlight0
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_textlight1
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_textlight2
 *                 |-----"s1".COP.PNL.GLA.FCU.lcd_textlight3
 *         "box"---|-----"s1".COP.PNL.GLA.FCU.lcd_textlight4
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button0
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button1
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button2
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button3
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button4
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button5
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button6
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button7
 *                 |-----"s1".COP.PNL.GLA.FCU.push_button8
 *                 |-----"s1".COP.PNL.GLA.FCU.control_knob0
 *                 |-----"s1".COP.PNL.GLA.FCU.control_knob1
 *                 |-----"s1".COP.PNL.GLA.FCU.control_knob2
 *                 |-----"s1".COP.PNL.GLA.FCU.control_knob3
 *                 |-----"s1".COP.PNL.GLA.FCU.inc_dial0
 *                 |-----"s1".COP.PNL.GLA.FCU.inc_dial1
 *                 |-----"s1".COP.PNL.GLA.FCU.inc_dial2
 *                 |-----"s1".COP.PNL.GLA.FCU.inc_dial3
 *                 |-----"s1".COP.PNL.GLA.FCU.rot_switch0
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_FCU(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   EFIS_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_EFIS(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.GLA."s2".lcd_counter0
 *                 |-----"s1".COP.PNL.GLA."s2".lcd_textlight0
 *                 |-----"s1".COP.PNL.GLA."s2".push_button0
 *                 |-----"s1".COP.PNL.GLA."s2".push_button1
 *                 |-----"s1".COP.PNL.GLA."s2".radio_button0
 *                 |-----"s1".COP.PNL.GLA."s2".radio_button1
 *                 |-----"s1".COP.PNL.GLA."s2".radio_button2
 *         "box"---|-----"s1".COP.PNL.GLA."s2".radio_button3
 *                 |-----"s1".COP.PNL.GLA."s2".radio_button4
 *                 |-----"s1".COP.PNL.GLA."s2".control_knob0
 *                 |-----"s1".COP.PNL.GLA."s2".inc_dial0
 *                 |-----"s1".COP.PNL.GLA."s2".rot_switch0
 *                 |-----"s1".COP.PNL.GLA."s2".rot_switch1
 *                 |-----"s1".COP.PNL.GLA."s2".rot_switch2
 *                 |-----"s1".COP.PNL.GLA."s2".toggle_switch0
 *                 |-----"s1".COP.PNL.GLA."s2".toggle_switch1
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : EFIS1, EFIS2
 ****************************************************************************/
short ds_initialize_EFIS(char *box,char *s1, char *s2);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   ECAM_CTL_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ECAM_CTL(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button0
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button1
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button2
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button3
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button4
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button5
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.touch_button6
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button7
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button1
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button2
 *         "box"---|-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button3
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button4
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button5
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button6
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button7
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button8
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button9
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button10
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button11
 *                 |-----"s1".COP.PNL.PDS.ECAM_CTL.radio_button12
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_ECAM_CTL(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Engine_Master_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ENG_MAS(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".COP.PNL.PDS.ENG_MAS.toggle_switch0
 *                 |-----"s1".COP.PNL.PDS.ENG_MAS.toggle_switch1
 *         "box"---|-----"s1".COP.PNL.PDS.ENG_MAS.toggle_switch2
 *                 |-----"s1".COP.PNL.PDS.ENG_MAS.toggle_switch3

 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_ENG_MAS(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Engine_Start_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ENG_ST(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *         "box"---|-----"s1".COP.PNL.PDS.ENG_ST.rot_switch0
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_ENG_ST(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Pedestal_Basics_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_PDS(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.PDS.thrust_lev1
 *                 |-----"s1".COP.PNL.PDS.thrust_lev2
 *                 |-----"s1".COP.PNL.PDS.thrust_lev3
 *                 |-----"s1".COP.PNL.PDS.thrust_lev4
 *                 |-----"s1".COP.PNL.PDS.rev_thrust
 *         "box"---|-----"s1".COP.PNL.PDS.trim
 *                 |-----"s1".COP.PNL.PDS.flaps
 *                 |-----"s1".COP.PNL.PDS.speed_brakes
 *                 |-----"s1".COP.PNL.PDS.park_brakes
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_PDS(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Pedestal_Basics_II_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_PDS_II(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.PDS.athr_disconnect1
 *         "box"---|-----"s1".COP.PNL.PDS.athr_disconnect2
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_PDS_II(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   APU_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_APU(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *

 *                 |-----"s1".COP.PNL.OVH.APU.push_button0 
 *         "box"---|
 *                 |-----"s1".COP.PNL.OVH.APU.push_button1 
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_APU(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   External_Lighting_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_EXTLT(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.OVH.EXTLT.toggle_switch0
 *                 |-----"s1".COP.PNL.OVH.EXTLT.toggle_switch1
 *         "box"---|-----"s1".COP.PNL.OVH.EXTLT.toggle_switch2
 *                 |-----"s1".COP.PNL.OVH.EXTLT.toggle_switch3
 *                 |-----"s1".COP.PNL.OVH.EXTLT.toggle_switch4
 *                 |-----"s1".COP.PNL.OVH.EXTLT.toggle_switch5
 *                 |-----"s1".COP.PNL.OVH.EXTLT.toggle_switch6
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_EXTLT(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   APU_Bleed_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_AIR(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *         "box"---|-----"s1".COP.PNL.OVH.AIR.push_button0
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_AIR(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   External_Power_Panel_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ELEC(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP.PNL.OVH.ELEC.push_button0
           "box"---|
 *                 |-----"s1".COP.PNL.OVH.ELEC.push_button1

 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_ELEC(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Stick_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_STI(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP."s2".pitch_a
 *         "box"---|-----"s1".COP."s2".roll_a
 *                 |-----"s1".COP."s2".pitch_f
 *                 |-----"s1".COP."s2".roll_f
 *                 |-----"s1".COP."s2".steering_wheel
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : STI1, STI2
 ****************************************************************************/
short ds_initialize_STI(char *box,char *s1,char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Pedal_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_PED(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".COP."s2".rudder
 *         "box"---|-----"s1".COP."s2".brake_l
 *                 |-----"s1".COP."s2".brake_r
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : PED1, PED2
 ****************************************************************************/
short ds_initialize_PED(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   State_Space_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_STATE(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".ATT.STATE.u
 *                 |-----"s1".ATT.STATE.v
 *                 |-----"s1".ATT.STATE.w
 *                 |-----"s1".ATT.STATE.u_dot
 *                 |-----"s1".ATT.STATE.v_dot
 *                 |-----"s1".ATT.STATE.w_dot
 *                 |-----"s1".ATT.STATE.p
 *                 |-----"s1".ATT.STATE.q
 *         "box"---|-----"s1".ATT.STATE.r
 *                 |-----"s1".ATT.STATE.p_dot
 *                 |-----"s1".ATT.STATE.q_dot
 *                 |-----"s1".ATT.STATE.r_dot
 *                 |-----"s1".ATT.STATE.Q0
 *                 |-----"s1".ATT.STATE.Q1
 *                 |-----"s1".ATT.STATE.Q2
 *                 |-----"s1".ATT.STATE.Q3
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1,ACR2,ACR3,ACR4,ACR5,ACR6,ACR7,ACR8,ACR9,ACR10 
 ****************************************************************************/
short ds_initialize_STATE(char *box,char *s1);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_State_Space_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALSTATE(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".REAL.ATT.STATE.u
 *                 |-----"s1".REAL.ATT.STATE.v
 *                 |-----"s1".REAL.ATT.STATE.w
 *                 |-----"s1".REAL.ATT.STATE.u_dot
 *                 |-----"s1".REAL.ATT.STATE.v_dot
 *                 |-----"s1".REAL.ATT.STATE.w_dot
 *                 |-----"s1".REAL.ATT.STATE.p
 *                 |-----"s1".REAL.ATT.STATE.q
 *         "box"---|-----"s1".REAL.ATT.STATE.r
 *                 |-----"s1".REAL.ATT.STATE.p_dot
 *                 |-----"s1".REAL.ATT.STATE.q_dot
 *                 |-----"s1".REAL.ATT.STATE.r_dot
 *                 |-----"s1".REAL.ATT.STATE.Q0
 *                 |-----"s1".REAL.ATT.STATE.Q1
 *                 |-----"s1".REAL.ATT.STATE.Q2
 *                 |-----"s1".REAL.ATT.STATE.Q3
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_REALSTATE(char *box,char *s1);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Navigation_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_NAV(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".ATT.NAV.lat
 *                 |-----"s1".ATT.NAV.lon
 *                 |-----"s1".ATT.NAV.elev
 *                 |-----"s1".ATT.NAV.geo_velo0
 *                 |-----"s1".ATT.NAV.geo_velo1
 *                 |-----"s1".ATT.NAV.geo_velo2
 *                 |-----"s1".ATT.NAV.geo_accel0
 *                 |-----"s1".ATT.NAV.geo_accel1
 *         "box"---|-----"s1".ATT.NAV.geo_accel2
 *                 |-----"s1".ATT.NAV.bank
 *                 |-----"s1".ATT.NAV.bank_d
 *                 |-----"s1".ATT.NAV.bank_dd
 *                 |-----"s1".ATT.NAV.pitch
 *                 |-----"s1".ATT.NAV.pitch_d
 *                 |-----"s1".ATT.NAV.pitch_dd
 *                 |-----"s1".ATT.NAV.head
 *                 |-----"s1".ATT.NAV.head_d
 *                 |-----"s1".ATT.NAV.head_dd
 *                 |-----"s1".ATT.NAV.track
 *                 |-----"s1".ATT.NAV.v_tot
 *                 |-----"s1".ATT.NAV.fpa
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1,ACR2,ACR3,ACR4,ACR5,ACR6,ACR7,ACR8,ACR9,ACR10 
 ****************************************************************************/
short ds_initialize_NAV(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_Navigation_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALNAV(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".REAL.ATT.NAV.lat
 *                 |-----"s1".REAL.ATT.NAV.lon
 *                 |-----"s1".REAL.ATT.NAV.elev
 *         "box"---|-----"s1".REAL.ATT.NAV.geo_velo[3]
 *                 |-----"s1".REAL.ATT.NAV.geo_accel[3]
 *                 |-----"s1".REAL.ATT.NAV.bank
 *                 |-----"s1".REAL.ATT.NAV.pitch
 *                 |-----"s1".REAL.ATT.NAV.head
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1,ACR2, ...
 ****************************************************************************/
short ds_initialize_REALNAV(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Luftdaten_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ATTAIR(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".ATT.AIR.ias
 *                 |-----"s1".ATT.AIR.speed_trend
 *                 |-----"s1".ATT.AIR.tas
 *                 |-----"s1".ATT.AIR.mach
 *                 |-----"s1".ATT.AIR.radio_alt
 *                 |-----"s1".ATT.AIR.baro_alt
 *         "box"---|-----"s1".ATT.AIR.baro_mode
 *                 |-----"s1".ATT.AIR.baro_setting
 *                 |-----"s1".ATT.AIR.vario
 *                 |-----"s1".ATT.AIR.aoa
 *                 |-----"s1".ATT.AIR.slip
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_ATTAIR(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Luftdaten_II_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ATTAIR_II(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".ATT.AIR.SAP
 *                 |-----"s1".ATT.AIR.TAP
 *                 |-----"s1".ATT.AIR.SAT
 *                 |-----"s1".ATT.AIR.TAT
 *                 |-----"s1".ATT.AIR.rho
 *                 |-----"s1".ATT.AIR.vel_of_sound
 *         "box"---|-----"s1".ATT.AIR.baro_alt2
 *                 |-----"s1".ATT.AIR.baro_mode2
 *                 |-----"s1".ATT.AIR.baro_setting2
 *                 |-----"s1".ATT.AIR.wind_dir
 *                 |-----"s1".ATT.AIR.wind_speed
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_ATTAIR_II(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_Luftdaten_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALATTAIR(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".REAL.ATT.AIR.u_A
 *                 |-----"s1".REAL.ATT.AIR.v_A
 *         "box"---|-----"s1".REAL.ATT.AIR.w_A
 *                 |-----"s1".REAL.ATT.AIR.u_A_dot
 *                 |-----"s1".REAL.ATT.AIR.v_A_dot
 *                 |-----"s1".REAL.ATT.AIR.w_A_dot
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_REALATTAIR(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   LowLevelFlight_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ATTLLF(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".ATT.LLF.mode
 *                 |-----"s1".ATT.LLF.track
 *                 |-----"s1".ATT.LLF.clearance_height
 *         "box"---|-----"s1".ATT.LLF.status
 *                 |-----"s1".ATT.LLF.figure_of_merit
 *                 |-----"s1".ATT.LLF.sensor_state
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_ATTLLF(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Radio_NAVAID_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_NAVAID(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".ATT.RAD."s2".status
 *         "box"---|-----"s1".ATT.RAD."s2".type
 *                 |-----"s1".ATT.RAD."s2".radial
 *                 |-----"s1".ATT.RAD."s2".loc_dev
 *                 |-----"s1".ATT.RAD."s2".gls_dev
 *                 |-----"s1".ATT.RAD."s2".dme
 *                 |-----"s1".ATT.RAD."s2".direction
 *                 |-----"s1".ATT.RAD."s2".id[4]
 *                 |-----"s1".ATT.RAD."s2".freq[7]
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : NAVAID1, NAVAID2
 ****************************************************************************/
short ds_initialize_NAVAID(char *box,char *s1, char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Engine_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ENG(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".ATT."s2".throttle
 *                 |-----"s1".ATT."s2".thrust
 *                 |-----"s1".ATT."s2".n1
 *                 |-----"s1".ATT."s2".n2
 *         "box"---|-----"s1".ATT."s2".epr
 *                 |-----"s1".ATT."s2".egt
 *                 |-----"s1".ATT."s2".fuel_flow
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : ENG1, ENG, ENG3, ENG4
 ****************************************************************************/
short ds_initialize_ENG(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Engine_II_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ENG_II(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *         "box"---|-----"s1".ATT."s2".athr_cmd
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : ENG1, ENG, ENG3, ENG4
 ****************************************************************************/
short ds_initialize_ENG_II(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_Engine_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALENG(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".REAL.ATT."s2".lev_cmd
 *                 |-----"s1".REAL.ATT."s2".athr_cmd
 *                 |-----"s1".REAL.ATT."s2".thrust
 *                 |-----"s1".REAL.ATT."s2".n1
 *                 |-----"s1".REAL.ATT."s2".n2
 *         "box"---|-----"s1".REAL.ATT."s2".epr
 *                 |-----"s1".REAL.ATT."s2".egt
 *                 |-----"s1".REAL.ATT."s2".fuel_flow
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 *               s2  : ENG1, ENG, ENG3, ENG4
 ****************************************************************************/
short ds_initialize_REALENG(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Aktuatoren_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_AKT(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".ATT.AKT.elevator_l
 *                 |-----"s1".ATT.AKT.elevator_r
 *                 |-----"s1".ATT.AKT.hori_stab
 *                 |-----"s1".ATT.AKT.airbrake_l_i
 *                 |-----"s1".ATT.AKT.airbrake_l_o
 *                 |-----"s1".ATT.AKT.airbrake_r_i
 *         "box"---|-----"s1".ATT.AKT.airbrake_r_o
 *                 |-----"s1".ATT.AKT.spoiler_i_l
 *                 |-----"s1".ATT.AKT.spoiler_i_r
 *                 |-----"s1".ATT.AKT.spoiler_o_l
 *                 |-----"s1".ATT.AKT.spoiler_o_r
 *                 |-----"s1".ATT.AKT.aileron_i_l
 *                 |-----"s1".ATT.AKT.aileron_i_r
 *                 |-----"s1".ATT.AKT.aileron_o_l
 *                 |-----"s1".ATT.AKT.aileron_o_r
 *                 |-----"s1".ATT.AKT.rudder_u
 *                 |-----"s1".ATT.AKT.rudder_l
 *                 |-----"s1".ATT.AKT.slat_l
 *                 |-----"s1".ATT.AKT.slat_r
 *                 |-----"s1".ATT.AKT.flap_l
 *                 |-----"s1".ATT.AKT.flap_r
 *                 |-----"s1".ATT.AKT.gear
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_AKT(char *box,char *s1);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_Control_Surfaces_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALCSUR(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".REAL.ATT.CSUR.elevator_l
 *                 |-----"s1".REAL.ATT.CSUR.elevator_r
 *                 |-----"s1".REAL.ATT.CSUR.hori_stab
 *                 |-----"s1".REAL.ATT.CSUR.airbrake_l_i
 *                 |-----"s1".REAL.ATT.CSUR.airbrake_l_o
 *                 |-----"s1".REAL.ATT.CSUR.airbrake_r_i
 *         "box"---|-----"s1".REAL.ATT.CSUR.airbrake_r_o
 *                 |-----"s1".REAL.ATT.CSUR.spoiler_i_l
 *                 |-----"s1".REAL.ATT.CSUR.spoiler_i_r
 *                 |-----"s1".REAL.ATT.CSUR.spoiler_o_l
 *                 |-----"s1".REAL.ATT.CSUR.spoiler_o_r
 *                 |-----"s1".REAL.ATT.CSUR.aileron_i_l
 *                 |-----"s1".REAL.ATT.CSUR.aileron_i_r
 *                 |-----"s1".REAL.ATT.CSUR.aileron_o_l
 *                 |-----"s1".REAL.ATT.CSUR.aileron_o_r
 *                 |-----"s1".REAL.ATT.CSUR.rudder_u
 *                 |-----"s1".REAL.ATT.CSUR.rudder_l
 *                 |-----"s1".REAL.ATT.CSUR.slat_l
 *                 |-----"s1".REAL.ATT.CSUR.slat_r
 *                 |-----"s1".REAL.ATT.CSUR.flap_l
 *                 |-----"s1".REAL.ATT.CSUR.flap_r
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_REALCSUR(char *box,char *s1);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Real_Landing_Gear_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_REALGEAR(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".REAL.ATT.GEAR.contact_NG
 *                 |-----"s1".REAL.ATT.GEAR.contact_LMG
 *         "box"---|-----"s1".REAL.ATT.GEAR.contact_RMG
 *                 |-----"s1".REAL.ATT.GEAR.contact_TB
 *                 |-----"s1".REAL.ATT.GEAR.nose_wheel_angle
 *                 |-----"s1".REAL.ATT.GEAR.position
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_REALGEAR(char *box,char *s1);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Flight_Controller_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FCC(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".AST.FCC.fc_elevator_cmd
 *                 |-----"s1".AST.FCC.fc_trim_sw_cmd
 *                 |-----"s1".AST.FCC.fc_hori_stab_cmd
 *         "box"---|-----"s1".AST.FCC.fc_aileron_cmd
 *                 |-----"s1".AST.FCC.fc_rudder_cmd
 *                 |-----"s1".AST.FCC.fc_rud_trim_cmd
 *                 |-----"s1".AST.FCC.fc_rudtr_res_cmd
 *                 |-----"s1".AST.FCC.fc_thrust_lev1_cmd
 *                 |-----"s1".AST.FCC.fc_thrust_lev2_cmd
 *                 |-----"s1".AST.FCC.fc_thrust_lev3_cmd
 *                 |-----"s1".AST.FCC.fc_thrust_lev4_cmd
 *                 |-----"s1".AST.FCC.fc_rev_thrust_cmd
 *                 |-----"s1".AST.FCC.fc_flap_slat_cmd
 *                 |-----"s1".AST.FCC.fc_speed_brakes_cmd
 *                 |-----"s1".AST.FCC.fc_groundspoiler_cmd
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_FCC(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Autopilot_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_API(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.API.sel_speed
 *                 |-----"s1".AST.API.sel_altitude
 *                 |-----"s1".AST.API.sel_heading
 *         "box"---|-----"s1".AST.API.sel_track
 *                 |-----"s1".AST.API.sel_vert_speed
 *                 |-----"s1".AST.API.sel_fpa
 *                 |-----"s1".AST.API.sel_nav_mode
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_API(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Autopilot_II_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_API_II(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.API.speed_mode
 *                 |-----"s1".AST.API.altitude_mode
 *                 |-----"s1".AST.API.heading_mode
 *         "box"---|-----"s1".AST.API.track_mode
 *                 |-----"s1".AST.API.vert_speed_mode
 *                 |-----"s1".AST.API.fpa_mode
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_API_II(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Flight_Director_Attitude_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FD_ATT(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.FD.ATT.bank
 *         "box"---|-----"s1".AST.FD.ATT.pitch
 *                 |-----"s1".AST.FD.ATT.head
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_FD_ATT(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Flight_Director_Flightpath_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FD_FP(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.FD.FP.gamma
 *         "box"---|-----"s1".AST.FD.FP.track
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_FD_FP(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Flight_Director_LowLevelFlight_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FD_LLF(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.FD.LLF.x
 *         "box"---|-----"s1".AST.FD.LLF.y
 *                 |-----"s1".AST.FD.LLF.bank
 *                 |-----"s1".AST.FD.LLF.time_diff
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_FD_LLF(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   FollowMeACR_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FMA(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.FMA.ptime
 *         "box"---|-----"s1".AST.FMA.lat
 *                 |-----"s1".AST.FMA.lon
 *                 |-----"s1".AST.FMA.elev
 *                 |-----"s1".AST.FMA.head
 *                 |-----"s1".AST.FMA.bank
 *                 |-----"s1".AST.FMA.pitch
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/
short ds_initialize_FMA(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   TCAS_Resolution_Advisory_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_TCAS_RA(char *box, char *s1);
 *
 *                 |-----"s1".AST.TCAS.RA.raUp
 *         "box"---|-----"s1".AST.TCAS.RA.raDown
 *                 |-----"s1".AST.TCAS.RA.raCombined
 *                 |-----"s1".AST.TCAS.RA.raVerticalControl
 *                 |-----"s1".AST.TCAS.RA.raRate
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_TCAS_RA(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   GCAS_Resolution_Advisory_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_GCAS_RA(char *box, char *s1);
 *
 *         "box"---|-----"s1".AST.GCAS.RA.flightPathAdvisoryAngle
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_GCAS_RA(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Taxilines_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_TXL(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.FLP.TAXI."s2".airport
 *         "box"---|-----"s1".AST.FLP.TAXI."s2".name
 *                 |-----"s1".AST.FLP.TAXI."s2".taxi_seg
 *                 |-----"s1".AST.FLP.TAXI."s2".line_seg
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : PRES, TXL1, TXL2, TXL3, TXL4, TXL5, TXL6, 
 *                     TXL7, TXL8, TXL9, TXL10 
 ****************************************************************************/ 
short ds_initialize_TXL(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Intruder_Present_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_INTR_PRES(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".SUR."s2".PRES.lon
 *                 |-----"s1".SUR."s2".PRES.lat
 *                 |-----"s1".SUR."s2".PRES.elev
 *         "box"---|-----"s1".SUR."s2".PRES.pitch
 *                 |-----"s1".SUR."s2".PRES.bank
 *                 |-----"s1".SUR."s2".PRES.head
 *                 |-----"s1".SUR."s2".PRES.geo_velo[3]
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 *               s2  : INTR1, INTR2, INTR3, INTR4, INTR5,INTR6, INTR7, 
 *                     INTR8, INTR9, INTR10
 ****************************************************************************/ 
short ds_initialize_INTR_PRES(char *box,char *s1,char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   DBcollision_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_COLL(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".SUR.COLL.collision_flag
 *                 |-----"s1".SUR.COLL.collision_ID
 *                 |-----"s1".SUR.COLL.object_ID
 *         "box"---|-----"s1".SUR.COLL.object_alt
 *                 |-----"s1".SUR.COLL.calc_rate
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/ 
short ds_initialize_COLL(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Wind_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_WIND(char *box, char *s1,char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".SUR.WEA"s2".dx
 *    	           |-----"s1".SUR.WEA"s2".dy
 *                 |-----"s1".SUR.WEA"s2".dz
 *                 |-----"s1".SUR.WEA"s2".u_trans
 *         "box"---|-----"s1".SUR.WEA"s2".v_trans
 *                 |-----"s1".SUR.WEA"s2".w_trans
 *                 |-----"s1".SUR.WEA"s2".p_rot
 *                 |-----"s1".SUR.WEA"s2".q_rot
 *                 |-----"s1".SUR.WEA"s2".r_rot
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : WIND1
 *
 ****************************************************************************/
short ds_initialize_WIND(char *box,char *s1,char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Fog_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FOG(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".SUR.WEA.FOG.cent_density
 *                 |-----"s1".SUR.WEA.FOG.onset
 *    	           |-----"s1".SUR.WEA.FOG.range
 *                 |-----"s1".SUR.WEA.FOG.dist1
 *                 |-----"s1".SUR.WEA.FOG.dist2
 *         "box"---|-----"s1".SUR.WEA.FOG.dist3
 *                 |-----"s1".SUR.WEA.FOG.dist4
 *                 |-----"s1".SUR.WEA.FOG.dist5
 *                 |-----"s1".SUR.WEA.FOG.dist6
 *                 |-----"s1".SUR.WEA.FOG.transp1
 *                 |-----"s1".SUR.WEA.FOG.transp2
 *                 |-----"s1".SUR.WEA.FOG.transp3
 *                 |-----"s1".SUR.WEA.FOG.transp4
 *                 |-----"s1".SUR.WEA.FOG.transp5
 *                 |-----"s1".SUR.WEA.FOG.transp6
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_FOG(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Cloud_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_CLOUD(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".SUR.WEA."s2".ID
 *    	           |-----"s1".SUR.WEA."s2".center_lat
 *                 |-----"s1".SUR.WEA."s2".center_lon
 *                 |-----"s1".SUR.WEA."s2".center_elev
 *                 |-----"s1".SUR.WEA."s2".dx
 *                 |-----"s1".SUR.WEA."s2".dy
 *         "box"---|-----"s1".SUR.WEA."s2".dz
 *                 |-----"s1".SUR.WEA."s2".z_rot
 *                 |-----"s1".SUR.WEA."s2".subtyp
 *                 |-----"s1".SUR.WEA."s2".density
 *                 |-----"s1".SUR.WEA."s2".rain
 *                 |-----"s1".SUR.WEA."s2".bolt_fr
 *                 |-----"s1".SUR.WEA."s2".is_a_cloud

 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : CLD1, CLD2, CLD3, CLD4, CLD5, CLD6, CLD7, CLD8, CLD9,
 *                     CLD10
 *
 ****************************************************************************/
short ds_initialize_CLD(char *box,char *s1, char *s2);



/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Atmosphere_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ATMOS(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1".SUR.WEA.ATMOS.SAP
 *                 |-----"s1".SUR.WEA.ATMOS.TAP
 *    	   "box"---|-----"s1".SUR.WEA.ATMOS.TAT
 *                 |-----"s1".SUR.WEA.ATMOS.rho
 *                 |-----"s1".SUR.WEA.ATMOS.vel_of_sound
 *                 |-----"s1".SUR.WEA.ATMOS.T_null
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 *
 ****************************************************************************/
short ds_initialize_ATMOS(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Seating_Buck_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_BUCK(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.BUCK_"s1".run
 *         "box"---|
 *                 |-----SYS.BUCK_"s1".exit
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_BUCK(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Sensor_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_SYSSENS(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.NAVIG_"s1".run
 *                 |-----SYS.NAVIG_"s1".reset
 *                 |-----SYS.NAVIG_"s1".exit
 *                 |-----SYS.NAVIG_"s1".delta_lat
 *         "box"---|-----SYS.NAVIG_"s1".delta_lon
 *                 |-----SYS.NAVIG_"s1".delta_elev
 *                 |-----SYS.NAVIG_"s1".delta_bank
 *                 |-----SYS.NAVIG_"s1".delta_pitch
 *                 |-----SYS.NAVIG_"s1".delta_head
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_SYSSENS(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_DMP_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_DMP(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.DMP_"s1".run
 *         "box"---|-----SYS.DMP_"s1".reset
 *                 |-----SYS.DMP_"s1".exit
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_DMP(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Collision_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_SYSCOLL(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.COLL_"s1".run
 *         "box"---|-----SYS.COLL_"s1".reset
 *                 |-----SYS.COLL_"s1".exit
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_SYSCOLL(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Visual_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_VIS(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.VIS_"s1".run
 *                 |-----SYS.VIS_"s1".reset
 *                 |-----SYS.VIS_"s1".exit
 *                 |-----SYS.VIS_"s1".showStatistics
 *                 |-----SYS.VIS_"s1".frameRate
 *         "box"---|-----SYS.VIS_"s1".visual_flag
 *                 |-----SYS.VIS_"s1".terrain_flag
 *                 |-----SYS.VIS_"s1".clouds_flag
 *                 |-----SYS.VIS_"s1".aircraft_flag
 *                 |-----SYS.VIS_"s1".moon_sun_flag
 *                 |-----SYS.VIS_"s1".horizon_flag
 *                 |-----SYS.VIS_"s1".NameVariant
 *                 |-----SYS.VIS_"s1".DisplayVariant
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *
 ****************************************************************************/
short ds_initialize_VIS(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_INS(char *box);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.INS.run
 *         "box"---|-----SYS.INS.reset
 *                 |-----SYS.INS.exit
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *
 ****************************************************************************/
short ds_initialize_INS(char *box);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Date_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_DATE(char *box);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.DATE.day
 *         "box"---|-----SYS.DATE.month
 *                 |-----SYS.DATE.year
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *
 ****************************************************************************/
short ds_initialize_DATE(char *box);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Time_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_TIME(char *box);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.TIME.msec
 *         "box"---|-----SYS.TIME.sec
 *                 |-----SYS.TIME.min
 *                 |-----SYS.TIME.hour
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *
 ****************************************************************************/
short ds_initialize_TIME(char *box);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Flightmechanics_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_SYSFM(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----SYS.FM_"s1".run
 *                 |-----SYS.FM_"s1".reset
 *                 |-----SYS.FM_"s1".exit
 *                 |-----SYS.FM_"s1".action
 *                 |-----SYS.FM_"s1".wanted_lat
 *         "box"---|-----SYS.FM_"s1".wanted_lon
 *                 |-----SYS.FM_"s1".wanted_elev
 *                 |-----SYS.FM_"s1".wanted_gamma
 *                 |-----SYS.FM_"s1".wanted_head
 *                 |-----SYS.FM_"s1".wanted_speed
 *                 |-----SYS.FM_"s1".trim_mode
 *                 |-----SYS.FM_"s1".gear_pos
 *                 |-----SYS.FM_"s1".config
 *                 |-----SYS.FM_"s1".mass
 *                 |-----SYS.FM_"s1".cog
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/ 
short ds_initialize_SYSFM(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Sound_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_SND(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS."s2"_"s1".run
 *                 |-----SYS."s2"_"s1".reset
 *                 |-----SYS."s2"_"s1".exit
 *                 |-----SYS."s2"_"s1".gcas_flag
 *                 |-----SYS."s2"_"s1".tcas_flag
 *                 |-----SYS."s2"_"s1".windshear_flag
 *         "box"---|-----SYS."s2"_"s1".stallhorn_flag
 *                 |-----SYS."s2"_"s1".altitude_flag
 *                 |-----SYS."s2"_"s1".flaps_flag
 *                 |-----SYS."s2"_"s1".engine_flag
 *                 |-----SYS."s2"_"s1".gear_flag
 *                 |-----SYS."s2"_"s1".interaction_flag
 *                 |-----SYS."s2"_"s1".touchdown_flag
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 *               s2  : SND1, SND2
 ****************************************************************************/
short ds_initialize_SND(char *box,char *s1, char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Flight_Controller_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_SYS_FCC(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.FCC_"s1".run
 *         "box"---|-----SYS.FCC_"s1".reset
 *                 |-----SYS.FCC_"s1".exit
 *                 |-----SYS.FCC_"s1".configuration
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_SYS_FCC(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_Overhead_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_SYS_OVHD(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.OVHD_"s1".run
 *         "box"---|-----SYS.OVHD_"s1".reset
 *                 |-----SYS.OVHD_"s1".exit
 *                 |-----SYS.OVHD_"s1".configuration
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2
 ****************************************************************************/
short ds_initialize_SYS_OVHD(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Runway_Lights_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_RWL(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1"."s2".LIGHT.rwyic
 *                 |-----"s1"."s2".LIGHT.rail_flag
 *         "box"---|-----"s1"."s2".LIGHT.rabbit_flag
 *                 |-----"s1"."s2".LIGHT.tdz_flag
 *                 |-----"s1"."s2".LIGHT.edge_flag
 *                 |-----"s1"."s2".LIGHT.end_flag
 *                 |-----"s1"."s2".LIGHT.papi_flag
 *                 |-----"s1"."s2".LIGHT.center_flag

 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : TOW1
 *               s2  : RWY1
 ****************************************************************************/
short ds_initialize_RWL(char *box,char *s1,char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   HALSDTOP_Lights_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_RWL(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----"s1"."s2".HD_LIG.rwyic
 *                 |-----"s1"."s2".HD_LIG.rabbit_flag
 *         "box"---|-----"s1"."s2".HD_LIG.tdz_flag
 *                 |-----"s1"."s2".HD_LIG.edge_flag
 *                 |-----"s1"."s2".HD_LIG.end_flag
 *                 |-----"s1"."s2".HD_LIG.papi_flag

 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : TOW1
 *               s2  : RWY1
 ****************************************************************************/
short ds_initialize_HDRWL(char *box,char *s1,char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Monitor_Proc_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_MONPROC(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----MON."s1"."s2"."s3".local_number
 *         "box"---|-----MON."s1"."s2"."s3".type
 *                 |-----MON."s1"."s2"."s3".size
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : WORLD?
 *               s2  : ALINF?
 *               s3  : RD? oder WR?
 ****************************************************************************/
short ds_initialize_MONPROC(char *box,char *s1,char *s2,char *s3);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Monitor_ProcInf_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_PROCINF(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----MON."s1"."s2".name
 *                 |-----MON."s1"."s2".local_number
 *         "box"---|-----MON."s1"."s2".pid
 *                 |-----MON."s1"."s2".ip
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : WORLD?
 *               s1  : PROCINF?
 ****************************************************************************/
short ds_initialize_PROCINF(char *box,char *s1,char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Monitor_Expected_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_MONEXP(char *box);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----MON."s1".anz_alias
 *         "box"---|-----MON."s1".anz_proc
 *                 |-----MON."s1".name
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 ****************************************************************************/
short ds_initialize_MONEXP(char *box,char *s1);
/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Monitor_AlInf_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_ALINF(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *         "box"---|-----MON."s1"."s2".name
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
                 s1 :  WORLD?
                 s2 :  ALINF?
 ****************************************************************************/
short ds_initialize_ALINF(char *box,char *s1,char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_FDR(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.FDR
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_FDR(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_LLF(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.LLF
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_LLF(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_CON(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.CON
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_CON(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_WIND(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.WIND
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_WIND(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_EFCU(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.EFCU
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_EFCU(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_ECP(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS."s2"
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 *               s2  : ECP1, ECP2
 ****************************************************************************/ 
short ds_initialize_FFS_ECP(char *box,char *s1, char *s2);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_FMA(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.FMA
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_FMA(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_SPI(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.SPI
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_SPI(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_SPF(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.SPF
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_SPF(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_SPC(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               "s1".FFS.SPC
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1
 ****************************************************************************/ 
short ds_initialize_FFS_SPC(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                unsupported
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FFS_TIME(char *box);
 *
 * DATENSTRUKTUR:
 *               unsupported
 *               FFS.TIME
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 ****************************************************************************/ 
short ds_initialize_FFS_TIME(char *box);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   MP_Displays_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_MP_DISP(char *box,char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.OGL_DISP_"s1".cmd_type
 *         "box"---|-----SYS.OGL_DISP_"s1".cmd_arg
 *                 |-----SYS.OGL_DISP_"s1".cmd_receiver
 *                 |-----SYS.OGL_DISP_"s1".cmd_val
 *                 |-----SYS.OGL_DISP_"s1".cmd_string[100]
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/ 
short ds_initialize_MP_DISP(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Control_MP_Displays_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_CONTR_MP_DISP(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *                 |-----SYS.OGL_DISP_"s1".run
 *         "box"---|-----SYS.OGL_DISP_"s1".reset
 *                 |-----SYS.OGL_DISP_"s1".exit
 *
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1, ACR2, ...
 ****************************************************************************/ 
short ds_initialize_CONTR_MP_DISP(char *box,char *s1);

/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Flightplan_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_FLP(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".AST.FLP."s2".name
 *         "box"---|-----"s1".AST.FLP."s2".alt_fp
 *                 |-----"s1".AST.FLP."s2".lat_fp
 *                 |-----"s1".AST.FLP."s2".lon_fp
 *                 |-----"s1".AST.FLP."s2".v_ground_fp
 *                 |-----"s1".AST.FLP."s2".apic
 *                 |-----"s1".AST.FLP."s2".tasktype
 *                 |-----"s1".AST.FLP."s2".time_to_wait
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : ACR1 - ACR30
 *               s2  : TSK1 - TSK10
 ****************************************************************************/ 
short ds_initialize_FLP(char *box,char *s1, char *s2);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   Identifikation_Tower_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_TOWIDE(char *box, char *s1);
 *
 * DATENSTRUKTUR:
 *
 *    	   "box"---|-----"s1".GEN.IDE.apic
 *         
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : TOW1 - TOW10
 *
 ****************************************************************************/
short ds_initialize_TOWIDE(char *box,char *s1);


/*****************************************************************************
 * ZUWEISUNG:
 *
 *                "box"   <->   ComFromAcr_T
 *
 * FUNKTIONSAUFRUF:
 *
 *     ds_initialize_CFA(char *box, char *s1, char *s2);
 *
 * DATENSTRUKTUR:
 *
 *
 *                 |-----"s1".COM."s2".MSG.id
 *         "box"---|-----"s1".COM."s2".MSG.type_of_message
 *
 *
 * UEBERGABEPARAMETER
 *               box : beliebig
 *               s1  : TOW1 - TOW10
 *               s2  : ACR1 - ACR30
 ****************************************************************************/ 
short ds_initialize_CFA(char *box,char *s1, char *s2);


#ifdef __cplusplus
}
#endif

#endif /* _ds_init_ */










