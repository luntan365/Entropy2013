#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "EntropyRobotDrive.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

class RobotMap {
public:
	static CANJaguar* DRIVE_CAN_JAGUAR_FRONT_LEFT;
	static CANJaguar* DRIVE_CAN_JAGUAR_REAR_LEFT;
	static CANJaguar* DRIVE_CAN_JAGUAR_FRONT_RIGHT;
	static CANJaguar* DRIVE_CAN_JAGUAR_REAR_RIGHT;
	static EntropyRobotDrive* DRIVE_ROBOT_DRIVE_4;
	static Encoder* DRIVE_QUADRATURE_ENCODER_LEFT;
	static Encoder* DRIVE_QUADRATURE_ENCODER_RIGHT;
	static DriverStationLCD *DRIVERSTATIONLCD;
	static Gyro * DRIVE_GYRO;
	static AnalogChannel* m_pAzimuthPosition;
	static AnalogChannel* m_pAccelerometerElPos;
	static AnalogChannel* Auto_Switch;
	static CANJaguar* El_Jaguar;
	static CANJaguar* Az_Jaguar;
	static Compressor* Shooter_Compressor;
	static Solenoid* Shooter_Solenoid;
	static Solenoid* Shooter_LED;
	static Jaguar* Shooter_Motor1;
	static Jaguar* Shooter_Motor2;
	static Victor* m_pDiscFloorVac;
	static Victor* m_pDiscElevate;
	static Victor* m_pDiscFeed;
	static Servo* m_pCamTiltControl;

	static void init();

};
#endif
