#if 0
/*************************************************************************
 * TITLE: Autonomous.cpp
 *
 *  AUTHOR:   DLM
 *
 *  COMMENTS: Entropy 2013 Autonomous code
 */
//#include "EntropyIO.h"
#include "Autonomous.h"
//#include "CommandBase.h"
#include <stdio.h>
//#define AUTO_DEBUG

#include "Timer.h"
#include "WPILib.h"

// Team 138 "Entropy" Autonomous Code 2013

// Command Processing Vars for Autonomous



#define DRIVE_COMMAND 0
#define TURN_COMMAND 1
#define SCALED 2
#define SCALET 3
#define SHOOT_COMMAND 4
#define CONTINUE_COMMAND 5
#define JUMP_COMMAND 6
#define ONSWITCH_COMMAND 7
#define AFTER_COMMAND 8
#define COUNT_COMMAND 9
#define INVERT_LAMP 10
#define FINISHED 11

class  AutoControl {
    char m_program[1024];
    int m_pc;
    int m_lamps[4];
    int m_bigendian;
    Drive * m_drive;
    bool m_finished;
public:
    AutoControl() : m_pc(0), m_bigendian(1), m_drive(NULL), m_finished(false) {
        FILE * commands = fopen("/CommandFiles/team138autocode.dat", "rb");
        int status;
        if (commands != NULL) {
            status = fread(m_program, 1, 1024, commands);
            DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "read %d bytes", status);
            DriverStationLCD::GetInstance()->UpdateLCD();
            fclose(commands);
        }
        else {
            m_program[0] = CONTINUE_COMMAND;
            m_program[1] = JUMP_COMMAND;
            m_program[2] = 0;
            m_program[3] = 0;
        }
        unsigned char *x = (unsigned char *)m_bigendian;
        (*x) = 0;
        init(NULL);
    }
    void init(Drive *drive) {
        m_lamps[0] = 0;
        m_lamps[1] = 0;
        m_lamps[2] = 0;
        m_lamps[3] = 0;
        m_pc = 0;
        if(drive != NULL) {
        	drive->robotDrive4->SetSafetyEnabled(false);
        }
        m_drive = drive;
        m_finished = false;
    }
    
    int getByte() {
        return m_program[m_pc++];
    }
    
    short getShort() {
        return (getByte() << 8) | getByte();
    }

    float getFloat() {
        float x;
        unsigned char * b = (unsigned char *)&x;
        if (m_bigendian) {
            *(b+3) = getByte();
            *(b+2) = getByte();
            *(b+1) = getByte();
            *b = getByte();
        }
        else {
            *b = getByte();
            *(b + 1) = getByte();
            *(b + 2) = getByte();
            *(b + 3) = getByte();
        }
        return x;
    }
    
    int execute() {
      while (1) {
        int command = getByte();
        float val;
        float speed;
        int ival;
        int iswitch;

        DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line2, 1, "command %d at %p", command, m_pc-1);
        DriverStationLCD::GetInstance()->UpdateLCD();
        switch (command) {
            case DRIVE_COMMAND: //drive number
                val = getFloat();
                speed = getFloat();
                DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line4, 1, 
                		 "driving distance %f speed %f", val, speed);
                DriverStationLCD::GetInstance()->UpdateLCD();
                m_drive->auto_drive_straight(val, speed);
                Wait(0.001);
                break;
            case TURN_COMMAND: // turn
                val = getFloat();
                speed = getFloat();
                if (val > 0) {
                    m_drive->auto_turn_left(val, speed);
                }
                else {
                    m_drive->auto_turn_right(val, speed);
                }
                DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line3, 1, "where baaaak");
                DriverStationLCD::GetInstance()->UpdateLCD();
                Wait(0.001);
                break;
            case SCALED: // scaled
            case SCALET: // scalet
                break;
            case SHOOT_COMMAND: // shoot
                // add shoot command here
                break;
            case CONTINUE_COMMAND: //continue
                return 0; // return control
            case JUMP_COMMAND: //jump
                m_pc = getShort();
                break;
            case ONSWITCH_COMMAND: //onswitch
                ival = getByte();
                iswitch = 0; // read the switch here
                ival = getShort();
                if (ival == iswitch) {
                    m_pc = ival;
                }
                break;
            case AFTER_COMMAND:
                val = getFloat();
                Wait(val);
            case COUNT_COMMAND:
                ival = getShort();
                break;
            case INVERT_LAMP:
                ival = getByte();
                if (ival < 0 || ival > 4) {
                    return -1;
                }
                if (m_lamps[ival]) {
                    m_lamps[ival] = 0;
                }
                else {
                    m_lamps[ival] = 1;
                }
                // Set lamp here
                break;
            case FINISHED:
            	m_finished = true;
            	break;
        }
      }
    }
    bool isFinished() {return m_finished;}
};

AutoControl * auto_control = NULL;


void EntropyAutonomousInit(Drive *drive)
{
    if (auto_control == NULL) {
        auto_control = new AutoControl;
    }
    auto_control->init(drive);
}

/*
** Autonomous Periodic Code Loop
**    Called from BuiltInDefault
*/
void EntropyAutonomousPeriodic()
{
    if (auto_control != NULL) {
        auto_control->execute();
    }
    return;
}

void EntropyAutonomousContinuous()
{
   // Nothing here yet
}

bool EntropyAnonymousFinished() 
{
    return auto_control->isFinished();
}

#endif
