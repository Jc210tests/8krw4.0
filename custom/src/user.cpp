#include "vex.h"
#include "motor-control.h"
#include "driver-control.h"
#include "auton-selector.h"
#include "drive-log.h"
#include "../custom/include/autonomous.h"
#include "../custom/include/robot-config.h"

// Modify autonomous, driver, or pre-auton code below

void runAutonomous() {
  // Runs the routine picked on the Brain screen (or with the controller arrows while disabled).
  // Add routines to the list in runPreAutonomous() below.
  exampleAuton();
}

// controller_1 input variables (snake_case)
int ch1, ch2, ch3, ch4;
bool l1, l2, r1, r2;
bool button_a, button_b, button_x, button_y;
bool button_up_arrow, button_down_arrow, button_left_arrow, button_right_arrow;
int chassis_flag = 0;

void runDriver() {
  stopChassis(coast);
  heading_correction = false;
    const double liftMaxDeg = 2000; 

  while (true) {
    // [-100, 100] for controller stick axis values
    ch1 = controller_1.Axis1.value();
    ch2 = controller_1.Axis2.value();
    ch3 = controller_1.Axis3.value();
    ch4 = controller_1.Axis4.value();

    // true/false for controller button presses
    l1 = controller_1.ButtonL1.pressing();
    l2 = controller_1.ButtonL2.pressing();
    r1 = controller_1.ButtonR1.pressing();
    r2 = controller_1.ButtonR2.pressing();
    button_a = controller_1.ButtonA.pressing();
    button_b = controller_1.ButtonB.pressing();
    button_x = controller_1.ButtonX.pressing();
    button_y = controller_1.ButtonY.pressing();
    button_up_arrow = controller_1.ButtonUp.pressing();
    button_down_arrow = controller_1.ButtonDown.pressing();
    button_left_arrow = controller_1.ButtonLeft.pressing();
    button_right_arrow = controller_1.ButtonRight.pressing();

    // default tank drive or replace it with your preferred driver code here:
    driverArcade(ch3, ch1);
    // Arcade on the left stick:           driverArcade(ch3, ch4);
    // Split arcade (left fwd, right turn): driverArcade(ch3, ch1);
    // Tune feel with driver_curve and driver_deadband in custom/src/robot-config.cpp
 
    double leftPos = left_lift.position(deg);
    double rightPos = right_lift.position(deg);

    if (controller_1.ButtonR1.pressing()) {
      if (leftPos < liftMaxDeg) left_lift.spin(fwd, 12, volt);
      else left_lift.stop(hold);

      if (rightPos < liftMaxDeg) right_lift.spin(fwd, 12, volt);
      else right_lift.stop(hold);

    } else if (controller_1.ButtonR2.pressing()) {
      left_lift.spin(reverse, 4, volt);
      right_lift.spin(reverse, 4, volt);
    } else {
      left_lift.stop(hold);
      right_lift.stop(hold);
    }

    if(controller_1.ButtonL1.pressing()) {
      claw1.spin(fwd, 40, volt);
    } else if (controller_1.ButtonL2.pressing()) {
      claw1.spin(reverse, 3, volt);
    }else {
      claw1.stop(hold);
    }
    wait(10, msec); 
  }
}

void runPreAutonomous() {
    // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // Calibrate inertial sensor
  inertial_sensor.calibrate();

  // Wait for the Inertial Sensor to calibrate
  while (inertial_sensor.isCalibrating()) {
    wait(10, msec);
  }

  // odom tracking (picks the setup from using_horizontal_tracker / using_vertical_tracker)
  startOdometry();

  // Optional: MCL uses the distance sensors to keep odometry from drifting while driving.
  // Needs field-centered coordinates, so start each auton with setPose() at the real field position.
  // startMcl();

  // Autonomous routines for the selector, in the order they appear on the Brain screen
  addAuton("LeftRed", exampleAuton);
  addAuton("RightRed", exampleAuton2);
  addAuton("Skills ", redGoalRush);
  addAuton("Async Example", asyncExample);
  addAuton("Path Example", pathExample);
  addAuton("ProfiledExample", profiledExample);
  addAuton("Drive Calibration", calibrateDrive);  // For the simulator (see README)
  startAutonSelector();
 

}
