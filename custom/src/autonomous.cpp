#include "vex.h"
#include "utils.h"
#include "pid.h"
#include <ctime>
#include <cmath>
#include <thread>

#include "../include/autonomous.h"
#include "motor-control.h"
#include "path-following.h"

// IMPORTANT: Remember to add respective function declarations to custom/include/autonomous.h
// Then add each routine to the auton selector with addAuton() in runPreAutonomous() (custom/src/user.cpp)
// Format: returnType functionName() { code }

void exampleAuton() {
  // Use this for tuning linear and turn pid
  setPose(-164.245, -15.515, 0);
}

void exampleAuton2() {
 driveProfiled(15,2000,false,0);
 turnProfiled(-90,2000,false,0);
 driveProfiled(15,2000,true,0);


 


}
/*
 * asyncExample
 * Shows background motions: start a move, run mechanisms while it drives, and stop it early with a sensor.
 */
void asyncExample() {
 
}

/*
 * pathExample
 * Drives a smooth S-curve with pure pursuit, then backs along it with RAMSETE.
 * Paths use field coordinates, so the auton starts with setPose().
 */
void pathExample() {
  setPose(-36, -60, 0);
  Path out = pathFromPoints({{-36, -60}, {-36, -32}, {-12, -22}, {12, -30}, {34, -24}});
  followPath(out, 5000);
  Path back = pathFromPoints({{34, -24}, {12, -30}, {-12, -22}, {-36, -32}, {-36, -52}});
  followPathRamsete(back, 5000, true);
}

/*
 * profiledExample
 * Straight drives and turns with motion profiles: they speed up and slow down smoothly.
 */
void profiledExample() {
  driveProfiled(36, 3000);
  turnProfiled(90, 2000);
  driveProfiled(24, 3000);
  turnProfiled(0, 2000);
  driveProfiled(-36, 3000);
}

double arm_pid_target = 0, arm_load_target = 60, arm_store_target = 250, arm_score_target = 470;

/*
 * armPID
 * Runs a single PID update for the arm motor to reach the specified target position.
 * - arm_target: Desired arm position (degrees).
 */

/*
 * armPIDLoop
 * Continuously runs the arm PID control in a separate thread, keeping the arm at the target position.
 */


/*
 * rushClamp
 * Waits until the clamp distance sensor detects an object within 85mm, then closes the claw and lowers the rush arm.
 * Used for quickly grabbing a mobile goal at the start of autonomous.
 */
void rushClamp() {
 
}

/*
 * intakeThread
 * Runs the intake until an object is detected by the optical or distance sensor, then stops the intake.
 * Used for picking up rings or other objects during autonomous.
 */
void intakeThread(){

}

/*
 * redGoalRush
 * 2024-2025 World Championship runner-up(1698V) autonomous routine.
 * This routine executes a complex sequence to rush, grab, and score mobile goals and rings.
 * It uses multiple threads for simultaneous arm, clamp, and intake control.
 */
void redGoalRush() {
                                 // Slow drive forward
}