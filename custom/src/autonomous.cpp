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
double liftt = 0;

int liftTask() {
  
  lift.setVelocity(100, pct);
  lift.spinToPosition(liftt, deg);
  return 0;
}

void exampleAuton()
{

  //skills
const double heights[] = {250, 390, 490, 590, 600};

  lift.setVelocity(100,pct);
  lift.spinToPosition(130,deg);
driveProfiled(5,1000,false,0.0);
turnToAngle(90,1000,true,12);
driveProfiled(8,1000,true,0.0);
lift.setVelocity(40,pct);
lift.spinToPosition(60,deg);
claw1.spin(reverse, 5, volt);//pin1





//goal
turnToAngle(90,500,true, 12);

for(int i = 0; i<4; i++){
  turnToAngle(90,1000,true,12);
//runAsync([]{driveProfiled(-23,1050,true,0);});
//waitUntilTraveled(4);
//lift.spinToPosition(10,deg);
//turnToPoint(-17.4,2.255,1,1000);

liftt = 0;
task thread2(liftTask);

driveProfiled(-24.75,1300,true,0.0);
claw1.spin(fwd,50,volt);
turnProfiled(180,1300,true,0.0);

lift.setVelocity(90,pct);
 lift.spinToPosition(0,deg);
  wholetthisnerdcodedistancesensors(11.5,2000,front_sensor, true, 4);

  wait(250,msec);

//matchloader





driveProfiled(-9.5,1000, true, 0.0);
turnToAngle(90,1500,true,12);

lift.setVelocity(100,pct);

liftt = heights[i];
task thread(liftTask);

 


driveProfiled(44,2500,true,20);




 lift.setVelocity(55,pct);


wait(150,msec);

 lift.spinToPosition(heights[i] - 120,deg);
  claw1.spin(reverse,5,pct);




}
turnToAngle(90,1000,true,12);
//runAsync([]{driveProfiled(-23,1050,true,0);});
//waitUntilTraveled(4);
//lift.spinToPosition(10,deg);
//turnToPoint(-17.4,2.255,1,1000);

liftt = 0;
task thread2(liftTask);

driveProfiled(-24.75,1300,true,0.0);
claw1.spin(fwd,50,volt);
turnProfiled(180,1300,true,0.0);

lift.setVelocity(90,pct);
 lift.spinToPosition(0,deg);
  wholetthisnerdcodedistancesensors(11.5,2000,front_sensor, true, 4);
wait(250,msec);

//matchloader





driveProfiled(-9.5,1000, true, 0.0);
turnToAngle(90,1500,true,12);

lift.setVelocity(100,pct);

liftt = 700;
task thread3(liftTask);

 


driveProfiled(39,2500,true,15);




 lift.setVelocity(55,pct);


wait(150,msec);

 lift.spinToPosition(200,deg);
  claw1.spin(reverse,5,pct);





lift.spinToPosition(0,deg);
driveProfiled(-7,800,false,0.0);
turnProfiled(45,100,false,0.0);
driveProfiled(22,1000,false,0.0);
swing(182,1,1000,true,12);
claw1.spin(reverse,100,pct);
driveProfiled(50,1200,false,0.0);
wait(10,msec);
driveProfiled(-4,1000,false,20);
driveProfiled(4,1000,false,0.0);

driveProfiled(-60,1300,true,0.0);


}
void asyncExample()
//skills 2
{
// const double heights1[] = {480, 590, 600};
//   task z(liftTask);
//   liftt = 150;
//   claw1.spin(fwd,10,volt);
// turnToAngle(58,100,false,12);
// driveProfiled(10,1000,false,0.0);
// driveProfiled(13,1000,true,20);

 

// lift.spinToPosition(0,deg);
//   claw1.spin(reverse,10,volt);
//   wait(20,msec);

//   // turnToAngle(90,100,false,12);

//   driveProfiled(-3.5,1000,false,0.0);
//   turnToAngle(15,100,false,12);
//   driveProfiled(7.5,1000,false,0.0);
// turnToAngle(45,100,false,10);
// claw1.spin(fwd,10,volt);
  
   
//   driveProfiled(18,1300,false,18);
//   lift.spinToPosition(50,deg);
//    task w = task(liftTask);
//   liftt = 250;
//   driveProfiled(3,200,true,0.0);
//   wait(200,msec);
  
// turnToAngle(180,1000,3);
// driveProfiled(26,1000,true,20);
// lift.setVelocity(40,pct);
// lift.spinToPosition(0,deg);
// lift.setVelocity(100,pct);
// claw1.spin(reverse,10,volt);
// driveProfiled(-8.3,1000,false,0.0);
// turnToAngle(135,100,false,10);
// claw1.spin(fwd,10, volt);
// driveProfiled(28,1300,false,20);
// lift.spinToPosition(50,deg);
// task g = task(liftTask);
// liftt = 400;
// driveProfiled(10,100,true,0.0);

// wait(40,msec);

// turnProfiled(-90,1000,true, 0.0);

// wait(10,msec);
// driveProfiled(28,1000,true, 0.0);
// wait(150,msec);
// lift.spinToPosition(0,deg);
// for(int i = 0; i<2; i++){
//   task zero(liftTask);
//   liftt = 0;
//   driveProfiled(-21,1000,false, 0.0);

// turnProfiled(180,1000,true,0.0);
// claw1.spin(fwd,10,volt);

// wholetthisnerdcodedistancesensors(9.5,1000,front_sensor, true, 4);
// wait(100,msec);
// driveProfiled(-1,1000,false,0.0);
// task chudtask(liftTask);
// lift.setVelocity(100,pct);
// liftt = heights1[i];

// driveProfiled(-5,1100,true,40);
// turnProfiled(-90,2000,true,0.0);

// driveProfiled(28, 2000, true, 35);
// wait(100,msec);
// lift.setVelocity(50,pct);

// lift.spinToPosition(heights1[i]-120, deg);
// claw1.spin(reverse, 5, volt);

// }
setPose(0,0,-90);
task o = task(liftTask);
liftt = 0;
driveProfiled(-23,1000,true, 0.0);
turnProfiled(180,1000,true,0.0);
claw1.spin(fwd,1000,volt);

driveProfiled(7,1000,false,0.0);
for(int j = 0; j<2; j++){
  task up = task(liftTask);
  liftt = 150;
  driveProfiled(-10,1000,false,0.0);
turnProfiled(-40,100,false,0.0);
driveProfiled(1,200,false,0.0);
swing(0,1,1000,true,12);
  driveProfiled(13,1000,true,0.0);
  lift.spinToPosition(0,deg);
  claw1.spin(reverse,10,volt);
  driveProfiled(-10,1000,false,0.0);
  turnProfiled(100,1000,false,0.0);
  driveProfiled(4,1000,false,0.0);
  swing(180,1,1000,true,12);
   driveProfiled(10,1000,false,0.0);
}

  
}
void exampleAuton2()
{
//sawp

setPose(0,0,0);
task a = task(liftTask);
liftt = 150;
turnProfiled(60,1000,false,0.0);
driveProfiled(22,1000,true,0.0);
  lift.spinToPosition(0,deg);
  claw1.spin(reverse, 10, volt);
  
driveProfiled(-7.5,1100,true,0.0);
turnProfiled(90,1000,false,0.0);
driveProfiled(18.4,1100,false,0.0);
claw1.spin(fwd,10,volt);

turnProfiled(45,1000,false,0.0);
driveProfiled(12, 1000, false, 10);
driveProfiled(6.2,1000,true,50);
task r = task(liftTask);
liftt = 200;
turnProfiled(-90,1000,true,0.0);
driveProfiled(16,1000,true,0.0);
lift.spinToPosition(0,deg);
driveProfiled(-13,1000,true,0.0);
//29,31
//45,76
claw1.spin(fwd,10,volt);
turnProfiled(-45,1000,false,0.0);
driveProfiled(46,1400,true, 20);
turnProfiled(25,1000,true,0.0);
task v = task(liftTask);
liftt = 250;
driveProfiled(55,1300,true,0.0);
lift.spinToPosition(0,deg);
driveProfiled(-10,1000,false,0.0);
turnProfiled(-90,400,false,0.0);
driveProfiled(-20,1000,false,0.0);
driveProfiled(5,1000,false,0.0);
driveProfiled(-5,1000,false,0.0);



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
  //red left
  lift.setVelocity(100,pct);

wait(10,msec);
lift.setVelocity(50,pct);
lift.spinToPosition(100,deg);
claw1.spin(fwd, 50, volt);
curveCircle(90, 10, 500, true, 6);

driveProfiled(15,1000,true,0);
lift.setVelocity(30,pct);
lift.spinToPosition(0,deg);
claw1.spin(reverse, 4, volt);
wait(550,msec);
claw1.stop(hold);
driveProfiled(-8,1000,false,0.0);
turnProfiled(45, 800, true, 0.0);
driveProfiled(11, 1100, false, 0.0);
claw1.spin(fwd, 12, volt);
driveProfiled(19,1200,true,8);
claw1.stop();
driveTo(2,1000,true,5);
turnProfiled(170,1000,true,0.0);

lift.setVelocity(100, pct);
lift.spinToPosition(200, deg);
driveTo(20,1000,true,4);
wait(50,msec);
lift.setVelocity(30,pct);
lift.spinToPosition(0, deg);

claw1.spin(reverse, 12, volt);
wait(50,msec); 
claw1.spin(reverse, 12, volt);
wait(50,msec);
claw1.stop(coast);
turnToAngle(180,500,true, 12);
driveProfiled(-9, 1400, false, 0.0);
turnToAngle(-135,1000,true,12);
driveTo(25, 1600, false, 10);
claw1.spin(reverse,5,volt);
turnProfiled(180,1000,false,0.0);
driveProfiled(41,1300,false,0.0);
driveProfiled(-4,1000,false,0.0);
driveProfiled(4,1000,false,0.0);
driveProfiled(-4,1000,true,0.0);
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
{//blue
  lift.setVelocity(100,pct);

wait(10,msec);
lift.setVelocity(50,pct);
lift.spinToPosition(100,deg);
claw1.spin(fwd, 50, volt);
curveCircle(-90, 10, 500, true, 6);

driveProfiled(15,1000,true,0);
lift.setVelocity(30,pct);
lift.spinToPosition(0,deg);
claw1.spin(reverse, 4, volt);
wait(550,msec);
claw1.stop(hold);
driveProfiled(-8,1000,false,0.0);
turnProfiled(-45, 800, true, 0.0);
driveProfiled(11, 1100, false, 0.0);
claw1.spin(fwd, 12, volt);
driveProfiled(19,1200,true,8);
claw1.stop();
driveTo(2,1000,true,5);
turnProfiled(-170,1000,true,0.0);

lift.setVelocity(100, pct);
lift.spinToPosition(200, deg);
driveTo(20,1000,true,4);
wait(50,msec);
lift.setVelocity(30,pct);
lift.spinToPosition(0, deg);

claw1.spin(reverse, 12, volt);
wait(50,msec); 
claw1.spin(reverse, 12, volt);
wait(50,msec);
claw1.stop(coast);
turnToAngle(-180,500,true, 12);
driveProfiled(-9, 1400, false, 0.0);
turnToAngle(135,1000,true,12);
driveTo(25, 1600, false, 10);
claw1.spin(reverse,5,volt);
turnProfiled(-180,1000,false,0.0);
driveProfiled(41,1300,false,0.0);
driveProfiled(-4,1000,false,0.0);
driveProfiled(4,1000,false,0.0);
driveProfiled(-4,1000,true,0.0);
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
 lift.setVelocity(100,pct);

wait(10,msec);
lift.setVelocity(50,pct);
lift.spinToPosition(100,deg);
claw1.spin(fwd, 50, volt);
driveProfiled(8.5,500,false,0.0);
turnProfiled(-90,1000,true,0.0);
driveProfiled(8,500,true,0.0);

driveProfiled(15,1000,true,0);
lift.setVelocity(30,pct);
lift.spinToPosition(0,deg);
claw1.spin(reverse, 4, volt);
wait(550,msec);
claw1.stop(hold);
driveProfiled(-8,1000,false,0.0);
turnProfiled(-45, 800, true, 0.0);
driveProfiled(11, 1100, false, 0.0);
claw1.spin(fwd, 12, volt);
driveProfiled(19,1200,true,8);
claw1.stop();
driveTo(2,1000,true,5);
turnProfiled(-170,1000,true,0.0);

lift.setVelocity(100, pct);
lift.spinToPosition(200, deg);
driveTo(20,1000,true,4);
wait(50,msec);
lift.setVelocity(30,pct);
lift.spinToPosition(0, deg);

claw1.spin(reverse, 12, volt);
wait(50,msec); 
claw1.spin(reverse, 12, volt);
wait(50,msec);
claw1.stop(coast);
turnToAngle(-180,500,true, 12);
driveProfiled(-9, 1400, false, 0.0);
turnToAngle(135,1000,true,12);
driveTo(25, 1600, false, 10);
claw1.spin(reverse,5,volt);
turnProfiled(-180,1000,false,0.0);
driveProfiled(41,1300,false,0.0);
driveProfiled(-4,1000,false,0.0);
driveProfiled(6,1000,false,0.0);
driveProfiled(-4,1000,true,0.0);
}