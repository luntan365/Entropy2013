#include "RobotMap.h"
#include "EntropyRobotDrive.h"

#define ELEVATIONCHANNEL     7
#define AZIMUTHCHANNEL       6


// define and initialize static members
Jaguar*             RobotMap::Shooter_Motor1 = 0;
Jaguar*             RobotMap::Shooter_Motor2 = 0;
Compressor*         RobotMap::Shooter_Compressor = 0;
Solenoid*           RobotMap::Shooter_Solenoid = 0;
Solenoid*           RobotMap::Shooter_LED = 0;
CANJaguar*          RobotMap::El_Jaguar = 0; 
CANJaguar*          RobotMap::Az_Jaguar = 0;
CANJaguar*          RobotMap::DRIVE_CAN_JAGUAR_FRONT_LEFT = 0;
CANJaguar*          RobotMap::DRIVE_CAN_JAGUAR_REAR_LEFT = 0;
CANJaguar*          RobotMap::DRIVE_CAN_JAGUAR_FRONT_RIGHT = 0;
CANJaguar*          RobotMap::DRIVE_CAN_JAGUAR_REAR_RIGHT = 0;
EntropyRobotDrive*  RobotMap::DRIVE_ROBOT_DRIVE_4 = 0;
Encoder*            RobotMap::DRIVE_QUADRATURE_ENCODER_LEFT = 0;
Encoder*            RobotMap::DRIVE_QUADRATURE_ENCODER_RIGHT = 0;
DriverStationLCD*   RobotMap::DRIVERSTATIONLCD = 0;
Gyro*               RobotMap::DRIVE_GYRO = 0;
AnalogChannel*      RobotMap::m_pAzimuthPosition = 0;
AnalogChannel*      RobotMap::m_pAccelerometerElPos = 0;
AnalogChannel*      RobotMap::Auto_Switch = 0;
Victor*             RobotMap::m_pDiscFloorVac = 0;
Victor*             RobotMap::m_pDiscElevate = 0;
Victor*             RobotMap::m_pDiscFeed = 0;
Servo*              RobotMap::m_pCamTiltControl = 0;

void RobotMap::init() {
	
	Shooter_Motor1 = new Jaguar(1, 4);
	Shooter_Motor2 = new Jaguar(1, 5);
	Shooter_Compressor = new Compressor(1, 8, 1, 1);
	Shooter_Solenoid = new Solenoid(1, 1);
	Shooter_LED = new Solenoid(1, 7);
	El_Jaguar = new CANJaguar(ELEVATIONCHANNEL);
	Az_Jaguar = new CANJaguar(AZIMUTHCHANNEL);
	DRIVE_CAN_JAGUAR_FRONT_LEFT = new CANJaguar(2);
	DRIVE_CAN_JAGUAR_REAR_LEFT = new CANJaguar(3);
	DRIVE_CAN_JAGUAR_FRONT_RIGHT = new CANJaguar(4);
	DRIVE_CAN_JAGUAR_REAR_RIGHT = new CANJaguar(5);
    DRIVE_ROBOT_DRIVE_4 = new EntropyRobotDrive
    		(DRIVE_CAN_JAGUAR_FRONT_LEFT, DRIVE_CAN_JAGUAR_REAR_LEFT, 
    		 DRIVE_CAN_JAGUAR_FRONT_RIGHT, DRIVE_CAN_JAGUAR_REAR_RIGHT);
    DRIVE_QUADRATURE_ENCODER_RIGHT = new Encoder(1, 3, 1, 4, true, Encoder::k4X);
    DRIVE_QUADRATURE_ENCODER_LEFT = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
    DRIVE_GYRO = new Gyro(1, 1);
    m_pAzimuthPosition = new AnalogChannel(1, 5);
    m_pAccelerometerElPos = new AnalogChannel(1, 4);
    Auto_Switch = new AnalogChannel(1, 6);
	m_pDiscFloorVac = new Victor(1, 1);
	m_pDiscElevate = new Victor(1, 2);
	m_pDiscFeed = new Victor(1, 3);	
	m_pCamTiltControl = new Servo(1, 7);
	
	Shooter_Compressor->Start();
	Shooter_Motor1->SetSafetyEnabled(false);
	Shooter_Motor2->SetSafetyEnabled(false);
	Shooter_LED->Set(true);
	
	El_Jaguar->SetSafetyEnabled(false);
	Az_Jaguar->SetSafetyEnabled(false);
	
    DRIVE_ROBOT_DRIVE_4->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
    DRIVE_ROBOT_DRIVE_4->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
    DRIVE_ROBOT_DRIVE_4->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
    DRIVE_ROBOT_DRIVE_4->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
    DRIVE_ROBOT_DRIVE_4->SetSafetyEnabled(false);
    DRIVE_ROBOT_DRIVE_4->SetExpiration(0.1);
    DRIVE_ROBOT_DRIVE_4->SetSensitivity(0.5);
    DRIVE_ROBOT_DRIVE_4->SetMaxOutput(1.0);
       
    DRIVE_QUADRATURE_ENCODER_LEFT->SetDistancePerPulse((double) ((double)0.111 /(double) 12.0));
    DRIVE_QUADRATURE_ENCODER_LEFT->SetPIDSourceParameter(Encoder::kRate);
    DRIVE_QUADRATURE_ENCODER_RIGHT->SetDistancePerPulse((double) ((double)0.111 /(double) 12.0));
    DRIVE_QUADRATURE_ENCODER_RIGHT->SetPIDSourceParameter(Encoder::kRate);
    DRIVE_QUADRATURE_ENCODER_LEFT->Start();
    DRIVE_QUADRATURE_ENCODER_LEFT->Reset();
    DRIVE_QUADRATURE_ENCODER_RIGHT->Start();
    DRIVE_QUADRATURE_ENCODER_RIGHT->Reset();

    DRIVE_GYRO->SetSensitivity(-0.00502 * 2.3);
    DRIVE_GYRO->Reset();
    
    DRIVERSTATIONLCD = DriverStationLCD::GetInstance();

	// todo list of remaining devices

#ifdef TODO
	
	// Hopper Load Indicator (IR)

	m_pHopperLoadIndicator = new AnalogChannel(1, 3);
	
	// Robot Battery Voltage

	m_pRobotBatteryVoltage = new AnalogChannel(1, 8);
	
	m_pPressureSwitch = new DigitalInput(1, 8);

#endif
	
}
