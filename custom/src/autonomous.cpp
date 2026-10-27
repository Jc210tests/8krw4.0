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

void exampleAuton()
{
  // redleft
  claw1.spin(fwd,50,pct);
  lift.setVelocity(100,pct);
  lift.spinToPosition(200,deg);
moveToPoint(0,5.96,2,500,false,12);
swing(90,1,400,false, 10);
driveProfiled(5,1000,true,0);
lift.setVelocity(40,pct);
lift.spinToPosition(60,deg);
wait(10,msec);
claw1.spin(reverse, 5, volt);
wait(150,msec);
runAsync([]{driveProfiled(-21,1000,true,0);});
waitUntilTraveled(4);
lift.spinToPosition(0,deg);
turnToPoint(-15.97,2.255,1,1000);
claw1.spin(fwd,12,volt);
moveToPoint(-16.7,2.955,1,1000,false,4);
driveProfiled(-5,1000,false,5);
moveToPoint(-16.785,15.162,-1,1000, true,12);
turnToPoint(17.68,15.384,1,1000);









  /*








  claw1.spin(fwd,100,pct);
  runAsync([]{swing(180, 1, 1000, true, 6);});

  wait(100,msec);
  claw1.stop();

  driveTo(9,500,true,12);

  */
}
void asyncExample()

{

  lift.setVelocity(220,pct);

  lift.spinToPosition(450, deg);
 

  wait(10, msec);
  lift.setVelocity(50, pct);
  lift.spinToPosition(100, deg);
  claw1.spin(fwd, 50, volt);
  driveTo(5,1000,true, 9);
  swing(-90,1,1000,true,10);

  driveProfiled(15, 1000, true, 0);
  lift.setVelocity(60, pct);
  lift.spinToPosition(-25, deg);
  claw1.spin(reverse, 4, volt);
  wait(550, msec);
  claw1.stop(hold);
  driveProfiled(-6, 1100, false, 0.0);
  turnProfiled(-45, 800, true, 0.0);
  driveProfiled(11, 1100, false, 0.0);
  claw1.spin(fwd, 12, volt);
  driveProfiled(18, 1000, true, 8);
  claw1.stop();
  driveTo(2, 1000, true, 5);
  turnProfiled(-170, 1000, true, 0.0);

  lift.setVelocity(100, pct);
  lift.spinToPosition(300, deg);
  driveTo(20, 1000, true, 4);
  wait(50, msec);
  lift.setVelocity(50, pct);
  lift.spinToPosition(-20, deg);

  claw1.spin(reverse, 12, volt);
  wait(50, msec);
  claw1.spin(reverse, 12, volt);
  wait(50, msec);
  claw1.stop(coast);
  turnToAngle(-180, 500, true, 12);
  
}
void exampleAuton2()
{
  // right red
  
  lift.setVelocity(100, pct);
  runAsync([]{driveTo(-10,1000,true, 12);});
  waitUntilTraveled(.1);
  lift.spinToPosition(1200, deg);
}
/*
 * pathExample
 * Drives a smooth S-curve with pure pursuit, then backs along it with RAMSETE.
 * Paths use field coordinates, so the auton starts with setPose().
 */
void pathExample()
{
 
  lift.setVelocity(200,pct);

  lift.spinToPosition(450, deg);
  

  wait(10, msec);
  lift.setVelocity(50, pct);
  lift.spinToPosition(100, deg);
  claw1.spin(fwd, 50, volt);
  curveCircle(90, 10, 500, true, 6);

  driveProfiled(15, 1000, true, 0);
  lift.setVelocity(60, pct);
  lift.spinToPosition(-25, deg);
  claw1.spin(reverse, 4, volt);
  wait(550, msec);
  claw1.stop(hold);
  driveProfiled(-6, 1100, false, 0.0);
  turnProfiled(45, 800, true, 0.0);
  driveProfiled(11, 1100, false, 0.0);
  claw1.spin(fwd, 12, volt);
  driveProfiled(18, 1000, true, 8);
  claw1.stop();
  driveTo(2, 1000, true, 5);
  turnProfiled(170, 1000, true, 0.0);

  lift.setVelocity(100, pct);
  lift.spinToPosition(300, deg);
  driveTo(20, 1000, true, 4);
  wait(50, msec);
  lift.setVelocity(50, pct);
  lift.spinToPosition(-20, deg);

  claw1.spin(reverse, 12, volt);
  wait(50, msec);
  claw1.spin(reverse, 12, volt);
  wait(50, msec);
  claw1.stop(coast);
  turnToAngle(180, 500, true, 12);
  driveTo(-4, 1000, false, 12);
  turnToAngle(-135, 1000, true, 12);
  driveTo(25, 1400, false, 10);

  claw1.spin(fwd, 100, pct);
  driveProfiled(10, 1000, false, 8);
  driveProfiled(10, 1000, true, 8);
  lift.setVelocity(100, pct);
  lift.spinToPosition(200, deg);

  wait(50, msec);
  claw1.stop(hold);

  swing(-65, -1, 1000, false, 12);
  runAsync([]
           { driveTo(9, 500, true, 12); });
  waitUntilTraveled(1);
  lift.setVelocity(100, pct);
  lift.spinToPosition(300, deg);
  claw1.spin(reverse, 12, volt);

}

/*
 * profiledExample
 * Straight drives and turns with motion profiles: they speed up and slow down smoothly.
 */
void profiledExample()
{
  lift.setVelocity(100, pct);
  lift.spinToPosition(1200, deg);
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
void rushClamp()
{
// skills 1 28 point
  lift.setVelocity(100, pct);
  lift.spinToPosition(1200, deg);
  wait(10, msec);
  lift.setVelocity(50, pct);
  lift.spinToPosition(500, deg);
  claw1.spin(fwd, 50, volt);
  curveCircle(-90, 10, 500, true, 6);

  driveProfiled(15, 1000, true, 0);
  lift.setVelocity(30, pct);
  lift.spinToPosition(0, deg);
  claw1.spin(reverse, 4, volt);
  wait(550, msec);
  claw1.stop(hold);
  driveProfiled(-8, 1000, false, 0.0);
  turnProfiled(-45, 800, true, 0.0);
  driveProfiled(11, 1100, false, 0.0);
  claw1.spin(fwd, 12, volt);
  driveProfiled(18, 1000, true, 8);
  claw1.stop();
  driveTo(2, 1000, true, 5);
  turnProfiled(-170, 1000, true, 0.0);

  lift.setVelocity(100, pct);
  lift.spinToPosition(500, deg);
  driveTo(20, 1000, true, 4);
  wait(50, msec);
  lift.setVelocity(30, pct);
  lift.spinToPosition(0, deg);

  claw1.spin(reverse, 12, volt);
  wait(50, msec);
  claw1.spin(reverse, 12, volt);
  wait(50, msec);
  claw1.stop(coast);
  turnToAngle(-180, 500, true, 12);
  driveTo(-4, 1000, false, 12);
  wait(40, msec);
  turnToAngle(-230, 1000, true, 12);
  driveTo(-10, 100, true, 12);
}

/*
 * intakeThread
 * Runs the intake until an object is detected by the optical or distance sensor, then stops the intake.
 * Used for picking up rings or other objects during autonomous.
 */
void intakeThread()
{
}

/*
 * redGoalRush
 * 2024-2025 World Championship runner-up(1698V) autonomous routine.
 * This routine executes a complex sequence to rush, grab, and score mobile goals and rings.
 * It uses multiple threads for simultaneous arm, clamp, and intake control.
 */
void redGoalRush()
{
  // Slow drive forward
}