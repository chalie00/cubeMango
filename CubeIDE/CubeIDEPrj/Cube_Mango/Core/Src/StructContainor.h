#ifndef STRUCTCONTAINOR_H_
#define STRUCTCONTAINOR_H_

#include "stm32f1xx_hal.h"
#include <string.h>
#include "stdbool.h"
#include "EEPROMDef.h"
#include "Define.h"



// USART Struct 
//------------------------------------
#if 1
typedef struct
{
	uint8_t CNT;
	uint8_t MAX;
	uint8_t TIMEOUT;
	uint8_t HEAD;
	uint8_t TAIL;
	uint8_t BUF[UART_BUFFER_SIZE];
//	uint8_t BUF[30][50];
} stUSARTRX;
#endif

typedef struct
{
	uint8_t READY;
	uint8_t CNT;
	uint8_t FLAG;
	uint8_t TempBUF;
	uint16_t TIMEOUT;
	uint8_t BUF[UART_BUFFER_SIZE];
//	uint8_t BUF[30][50];
} stUSART_RX;

typedef struct
{
	uint8_t READY;
	uint8_t CNT;
	uint8_t MAX;
	uint8_t HEAD;
	uint8_t TAIL;
	uint8_t TempBUF;
	uint16_t TIMEOUT;
	uint8_t BUF[UART_BUFFER_SIZE];
//	uint8_t BUF[30][50];
} stUSART_TX;

//-----------------------------------------------------

//EEPROM Struct 
//---------------------------------------------------
typedef union {
	struct {
		// EEPROM New
		uint8_t HEADER;
		uint8_t A0;
		uint8_t A1;
		uint8_t A2;
		uint8_t A3;
		uint8_t A4;
		uint8_t A5;
		uint8_t A6;
		uint8_t A7;
		uint8_t A8;
		uint8_t A9;
		uint8_t A10;
		uint8_t A11;
		uint8_t A12;
		uint8_t A13;
		uint8_t A14;
		uint8_t A15;
		uint8_t COMM_BAUD_RATE;
	} st;
	uint8_t Data[EEPROM_SIZE];
} usEEPROM;
//-------------------------------------------------


//System Struct 
//------------------------------------------------
typedef struct {
	uint8_t RUN_FLAG;
	uint8_t READY;
	uint8_t FLAG_CNT;
	uint8_t ERROR_CNT;
//	uint16_t READY_TIMEOUT;
//	uint16_t LOOP_TIMEOUT;
	uint32_t RUN_CNT;
} stSystemState;

typedef enum
{
  OFF = 0 ,
  ON = 1 ,
  FAIL = 2 ,
} enRUNstatus;
//-----------------------------------------------

typedef enum
{
  TurnOFF = 0xFF ,
  TurnON = 0x00 ,
  TurnFAIL = 2 ,
} enGPSstatus;


// Diaplay Struct Includ 
typedef struct {
	int8_t OLD_Digit_Value[10];
	int8_t OLD_Digit_Cnt;
	int8_t OLD_S_col; // -1 Set
	int8_t OLD_Dot_P;
	int8_t OLD_col_Text;
	int8_t UpDown_Flag;
	int8_t OLD_UpDown_Flag;
	int8_t BG_TEXT;
	int8_t OLD_MODE;
	uint8_t col;
	uint8_t OLD_col;
	uint8_t row;
	uint8_t OLD_row;
	uint8_t OLD_compare_FLAG[10];
	uint8_t OLD_ValueRange_FLAG;
	uint8_t OLD_Dot_FLAG;
//	uint8_t	OLD_Comparevalue[10] ;
	uint16_t OLD_Icon;
	uint32_t OLD_Dot_Dec_Value;
} stOLDLCDValue;

typedef enum {
	ROTATION_0 = 0, ROTATION_90, ROTATION_180, ROTATION_270,
} etROTATION;

typedef enum {
	COLOR_WHITE = 0xFFFF, // ���
	COLOR_BLACK = 0x0000, // ���
	COLOR_RED = 0xF800, // ����
	COLOR_YELLOW = 0xFFE0, // Ȳ��
	COLOR_GREEN = 0x07E0, // ���
	COLOR_BLUE = 0x001F, // û��
	COLOR_PURPLE = 0xf81f, // ����� 
	COLOR_INDIGO = 0x07FF, // 
	COLOR_SKY = 0x1E79, // �ϴû�
	COLOR_ORANGE = 0xFC60, // ��Ȳ��
} etCOLOR;

typedef enum {
	ssd1306 = 0, ssd1351_0, ssd1351_1, ssd1351_2,
} etDEVSEL;

// RTC Struct 
typedef struct {
	uint8_t AMPM;
	uint8_t OLD_AMPM;
	uint8_t HOURS;
	uint8_t MINUTES;
	uint8_t SECONDS;
	uint8_t Comparevalue[4];
	uint8_t OLD_Time_Digit_Value_1351[6];
	uint8_t ADJ;
	uint8_t OLD_ADJ;
	uint8_t RUN_FLAG;
	uint8_t OLD_RUN_FLAG;
	int8_t Position;
	int8_t OLD_Position;
//	uint8_t AMPM_SELECT ;
	uint8_t COURSE_Toggle[3];
	uint8_t Set_Flag;
	uint8_t OLD_TIME_BG_TEXT;
	uint8_t ADJ_HoldCNT;
	uint16_t COURSE_TOGGLE;
	uint16_t OLD_Time_Dec_Value_1351;

} stRTC;

// KEY Struct
typedef struct {
	int8_t NowKey;
	int8_t OldKey;
	int8_t State;
	uint16_t PressCNT;
	uint16_t LongPressCNT;
	uint8_t PressCheckFlag;
	uint8_t ZeroSETCNT;
	uint8_t ZeroSETFLAG;
	uint8_t LongPressCheckFlag;
	uint8_t Uart_Data_Out;
	uint8_t Uart_State_Flag;
} stKEY;

//SPS30 Struct 
typedef struct {
	float mc_1p0;
	float mc_2p5;
	float mc_4p0;
	float mc_10p0;
	float nc_0p5;
	float nc_1p0;
	float nc_2p5;
	float nc_4p0;
	float nc_10p0;
	float typical_particle_size;
} sps30_measurement;

//GPS Struct 
//-------------------------------------------
typedef struct
{
	uint8_t SYSTEM_State ;
	uint8_t RUN_Flag ;
	uint8_t LINK_Cnt ;
	uint8_t DEVICE_RUN_Cnt ;
	uint8_t DEVICE_SHUTDOWN_FLAG ;
	uint8_t Connected ;
	uint8_t Connected_OLD ;
	uint8_t Disconnected ;
	uint8_t Disconnected_OLD ;
	uint8_t Disconnected_FAIL ;
	uint8_t Disconnected_FAIL_OLD ;
	uint8_t ON_OFF ;
	uint8_t OLD_ON_OFF ;
	uint8_t ON_OFF_Cnt ;
	uint8_t BG_TEXT ;
	uint8_t OLD_BG_TEXT ;
	uint8_t OLD_Text_Bg ;
	uint8_t compass[2] ; 
	uint8_t OLD_compass[2] ;
	uint8_t Degree[2][3][3] ;
	uint8_t OLD_Degree[2][3][3] ;
	uint8_t ERROR_CNT ;
	uint16_t LINK_REFLASH_Cnt ;
} stGPS ;

typedef enum {
	NMEA_BAD     = 0x00,
	NMEA_GLL     = 0x01,
	NMEA_RMC     = 0x02,
	NMEA_VTG     = 0x03,
	NMEA_GGA     = 0x04,
	NMEA_GSA     = 0x05,
	NMEA_GSV     = 0x06,
	NMEA_ZDA     = 0x07,
	NMEA_PMTK001 = 0x08,
	NMEA_PMTK010 = 0x09,
	NMEA_PMTK011 = 0x0a
} NMEASentenceType_TypeDef;


typedef struct {
	uint16_t start;
	uint16_t end;
	NMEASentenceType_TypeDef type;
} NMEASentence_TypeDef;

typedef struct {
	uint32_t latitude;            // Latitude (degrees)
	uint8_t  latitude_char;       // Latitude N/S indicator (X if no valid data)
	uint32_t longitude;           // Longitude (degrees)
	uint8_t  longitude_char;      // Longitude E/W indicator (X if no valid data)
	uint32_t speed_k;             // Speed over ground (Knots, 1 knot = 1.825km/h)
	uint32_t speed;               // Speed over ground (km/h)
	uint32_t course;              // Track angle relative to North (Degrees)
	uint32_t PDOP;                // Dilution of precision
	uint32_t HDOP;                // Horizontal dilution of precision
	uint32_t VDOP;                // Vertical dilution of precision
	uint32_t accuracy;            // Position accuracy (meters) [500 means 5.00m]
	uint8_t  sats_used;           // Satellites used for fix
	uint8_t  sats_view;           // Satellites in view
	int32_t  altitude;            // Mean-sea-level altitude (meters)
	int32_t  geoid_separation;    // Geoid-to-ellipsoid separation (meters)
	uint8_t  fix;                 // Fix indicator (1=Fix not available, 2=2D fix, 3=3D fix)
	uint32_t fix_time;            // Time of fix (seconds from midnight)
	uint32_t fix_date;            // Date of fix (DDMMYYYY)
	uint8_t  fix_quality;         // Position fix indicator:
                                  //   0 = invalid
                                  //   1 = GPS fix (SPS)
                                  //   2 = DGPS fix
                                  //   3 = PPS fix (Encrypted military signal)
                                  //   4 = Real Time Kinematic
                                  //   5 = Floating RTK
                                  //   6 = Estimated (dead reckoning) (2.3 feature)
                                  //   7 = Manual input mode
                                  //   8 = Simulation mode
	uint32_t time;                // UTC Time (seconds from midnight)
	uint32_t date;                // UTC Date (DDMMYYYY)
	uint8_t  mode;                // Mode indicator (A=Autonomous, D=Differential(DGPS), E=Estimated(DR),
	                              // R=Coarse pos., S=Simulator, N=Data not valid)
	uint32_t dgps_age;            // Time since last DGPS update (seconds)
	uint32_t dgps_id;             // DGPS station ID number
	bool     datetime_valid;      // Have valid date and time
	bool     valid;               // GPS status: TRUE if data valid
} GPS_Data_TypeDef;

typedef struct {
	uint8_t  PRN;                 // Satellite PRN number
	uint8_t  elevation;           // Elevation, degrees (max 90)
	uint16_t azimuth;             // Azimuth, degrees from true noth (0..359)
	uint8_t  SNR;                 // SNR, dB (0..99, 255 when not tracking)
	bool     used;                // TRUE if satellite used in location fix
} GPS_Satellite_TypeDef;

typedef struct {
	bool     PMTK_BOOT;           // TRUE when "$PMTK011,MTKGPS*08" sentence parsed
	uint8_t  PMTK010;             // Last parsed $PMTK010 sentence:
	                              //   0 = unknown
	                              //   1 = startup
	                              //   2 = notification for the host aiding EPO
	                              //   3 = notification for the transition to normal mode is successfully done
	uint16_t PMTK001_CMD;         // Cmd field from last parsed $PMTK001 sentence
	uint8_t  PMTK001_FLAG;        // Flag field from last parsed $PMTK001 sentence:
	                              //   0 = invalid packet
	                              //   1 = unsupported packet type
	                              //   2 = valid packet, but action failed
	                              //   3 = valid packet, action succeeded
} GPS_PMTK_TypeDef;

//------------------------------------------

//Quene Struct
//----------------------------------------
typedef struct 
{
	uint16_t iTask;
	uint8_t bP1;
	uint8_t bP2;
	uint8_t bP3;
} stTaskQueue;
//----------------------------------------

#if 1
typedef struct {
	uint8_t FontWidth_16B; /*!< Font width in pixels */
	uint8_t FontHeight_16B; /*!< Font height in pixels */
	const uint16_t *data_16B; /*!< Pointer to data font data array */
} FontDef_16t;

typedef struct {
	uint8_t FontWidth_8B; /*!< Font width in pixels */
	uint8_t FontHeight_8B; /*!< Font height in pixels */
	const uint8_t *data_8B; /*!< Pointer to data font data array */
} FontDef_8t;

#else
typedef struct {
	const uint8_t FontWidth_16B;    /*!< Font width in pixels */
	uint8_t FontHeight_16B;   /*!< Font height in pixels */
	const uint16_t *data_16B; /*!< Pointer to data font data array */
} FontDef_16t;

typedef struct {
	const uint8_t FontWidth_8B;    /*!< Font width in pixels */
	uint8_t FontHeight_8B;   /*!< Font height in pixels */
	const uint8_t *data_8B; /*!< Pointer to data font data array */
} FontDef_8t;

#endif
/** 
 * @brief  String length and height 
 */
typedef struct {
	uint16_t Length; /*!< String length in units of pixels */
	uint16_t Height; /*!< String height in units of pixels */
} FONTS_SIZE_t;

typedef enum {
	DecFont_0 = 0,
	DecFont_1,
	DecFont_2,
	DecFont_3,
	DecFont_4,
	DecFont_5,
	DecFont_6,
	DecFont_7,
	DecFont_8,
	DecFont_9,
	DecFont_dot,
} etFont_Select_Dec;

#endif
