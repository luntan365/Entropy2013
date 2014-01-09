#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private: 
	JoystickButton* m_pNykoGPbutton6;
	JoystickButton* m_pNykoGPbutton5;
	JoystickButton* m_pNykoGPbutton9;
	JoystickButton* m_pNykoGPbutton10;
	JoystickButton* m_pNykoGPbutton11;
	JoystickButton* m_pNykoGPbutton1;
	JoystickButton* m_pNykoGPbutton4;
	JoystickButton* m_pNykoGPbutton8;
	JoystickButton* m_pNykoGPbutton7;
	JoystickButton* m_pNykoGPbutton2;
	JoystickButton* m_pNykoGPbutton3;
	float lastspeed;

	
private:
	Joystick* joystick;
	Joystick* m_pNykoGmPad;
	float m_LastAzimuthReading;
	float m_LastElevationReading;
	int count;

public:
	OI();
	void ProcessGamePadInput();
	Joystick* getJoystick();
	
private:
	void VerifyGamePadAxes();
	float m_oldButtonsState;
	float m_oldRighty;
	float m_oldGetDPadx;
	float m_oldGetDPady;
	bool m_tmpButval;
	float tmp1;
	float tmp2;
	float tmp3;
	float tmp4;
	float tmp5;
};
#endif
