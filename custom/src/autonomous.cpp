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
  //redleft
  lift.setVelocity(100,pct);
lift.spinToPosition(800,deg);
driveProfiled(10,320,false,0);
curveCircle(90, 10, 500, true, 9);

driveProfiled(10,1000,true,0);
lift.setVelocity(20,pct);
lift.spinToPosition(0,deg);
claw1.spin(reverse, 9, volt);
wait(550,msec);
claw1.stop(hold);
driveProfiled(-10,1000,false,70);
turnProfiled(45, 800, true, 0.0);
driveProfiled(5, 1000, false, 0.0);
claw1.spin(fwd, 12, volt);
driveProfiled(15,1000,true, 0);
driveProfiled(15,1000,false,6);
claw1.stop();
swing(200,1,500, false, 12);
runAsync([]{driveTo(10,1000,true,12);});
waitUntilTraveled(5);
lift.setVelocity(100, pct);
lift.spinToPosition(1000, deg);
wait(100,msec);

lift.spinToPosition(0, deg);

claw1.spin(reverse, 12, volt);
wait(50,msec); //1.scor
claw1.spin(reverse, 12, volt);
wait(50,msec);
claw1.stop(coast);
driveTo(-10, 1000, false, 12);
turnProfiled(-130, 1000, false, 0);
driveTo(30, 1000, false, 12);

driveProfiled(30, 1700, true, 0.0);
driveTo(5,1000,false,5);
swing(180, 1, 1000, true, 6);
claw1.spin(fwd,100,pct);
wait(50,msec);
claw1.stop(hold);

swing(-65,-1,1000,false,12);
runAsync([]{driveTo(9,500,true,12);});
waitUntilTraveled(1);
lift.setVelocity(100,pct);
lift.spinToPosition(1000,deg);
claw1.spin(reverse,12,volt);



/*








claw1.spin(fwd,100,pct);
runAsync([]{swing(180, 1, 1000, true, 6);});

wait(100,msec);
claw1.stop();

driveTo(9,500,true,12);

*/




}

void exampleAuton2() {
//right red
lift.spinToPosition(800, degrees); //placeholder
wait(50, msec);
lift.spinToPosition(0, degrees);
curveCircle(-90, -15, 800, false, 12);
lift.spinToPosition(0, degrees);
claw1.spin(fwd, 12, volt);
wait(90,msec);
claw1.stop(hold);

driveProfiled(-6, 400,false, 0);
turnProfiled(220, 500, false,0);
driveProfiled(4, 400,false, 0);
runAsync([]{driveProfiled(8, 2500, true, 8);});
waitUntilTraveled(5);
claw1.spin(fwd, 12, volt);
wait(100,msec);
claw1.stop(hold);
driveTo(-3.1, 500, false, 12);
turnProfiled(90, 500, false, 0);
driveProfiled(19, 2000, true, 0);
driveTo(-3, 500, false, 12);
turnProfiled(-45, 500, false, 0);


driveProfiled(20, 1000, false, 0);

runAsync([]{driveProfiled(9, 1000, true, 8);});
 
waitUntilTraveled(5);
claw1.spin(fwd, 12, volt);
wait(100,msec);
claw1.stop(hold);
driveTo(5, 500, false, 12);

turnProfiled(-90, 500, false, 0);

runAsync([]{driveProfiled(8, 1000, true, 0);});
waitUntilTraveled(3);
lift.setVelocity(100, percent);
claw1.spin(reverse, 12, volt);
wait(50,msec);
claw1.stop(hold);
driveTo(-3.1, 500, false, 12);

turnProfiled(220, 500, false, 0);

driveProfiled(4, 400,false, 0);
driveProfiled(9, 2500, true, 9);
 


}
/*
 * asyncExample
 * Shows background motions: start a move, run mechanisms while it drives, and stop it early with a sensor.
 */
void asyncExample() {
  //red right
 lift.spinToPosition(800, degrees); //placeholder
wait(50, msec);
lift.spinToPosition(0, degrees);
curveCircle(-90, -15, 800, false, 12);
lift.spinToPosition(0, degrees);
claw1.spin(fwd, 12, volt);
wait(90,msec);
claw1.stop(hold);

driveProfiled(-15, 700,false, 0);
turnProfiled(-45, 500, false, 0);


driveProfiled(20, 1000, false, 0);
runAsync([]{driveProfiled(10, 1000, true, 8);});
 
waitUntilTraveled(5);
claw1.spin(fwd, 12, volt);
wait(100,msec);
claw1.stop(hold);
turnToAngle(190, 500, true, 12);
driveTo(10, 500, true, 12);

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
  lift.setVelocity(100, percent);
  lift.spinToPosition(800, degrees);
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