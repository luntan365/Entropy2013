#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Subsystems/Drive.h"

/**
 *
 *
 * @author DLM
 */
class MyRobotBaseCommand : public Command {
	bool m_running;
	bool m_finished;
public:
	MyRobotBaseCommand() : m_running(false), m_finished(false) {}
	bool IsFinished() { return m_finished;}
	bool isRunning() { return m_running;}
	void setFinished(bool x) {m_finished = x;}
	void setRunning(bool x) {m_running = x;}
};
class DriveCommand: public MyRobotBaseCommand {
        float m_speed;
        float m_distance;

public:
	DriveCommand();
    void setDistance(float dist) { m_distance = dist;}
    void setSpeed(float speed) {m_speed = speed;}
	virtual void Initialize();
	virtual void Execute();

	virtual void End();
	virtual void Interrupted();
private:
};

class TurnCommand: public MyRobotBaseCommand {
        float m_speed;
        float m_angle;
        float m_radius;

public:
        TurnCommand();
        void setAngle(float angle) {m_angle = angle;}
        void setSpeed(float speed) {m_speed = speed;}
        void setRadius(float radius) {m_radius = radius;}
        virtual void Initialize();
        virtual void Execute();
        virtual void End();
        virtual void Interrupted();
private:
};


#endif
