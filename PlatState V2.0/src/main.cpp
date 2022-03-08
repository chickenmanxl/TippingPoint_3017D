/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// back_left_motor      motor         2
// back_right_motor     motor         6
// front_left_motor     motor         5
// front_right_motor    motor         4
// front_expansion      motor         8
// back_expansion       motor         19
// arm                  motor         12
// claw                 motor         10
// side_claw            digital_out   A
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*@@@@@@@@      @@@@    @@@    @@@@@@@@@@   @@@@@@
        @@    @@    @@   @@           @@    @@@@@@@@
        @@    @@    @@   @@          @@     @@    @@
  @@@@@@@@    @@    @@   @@        @@       @@    @@
        @@    @@    @@   @@       @@        @@    @@
        @@    @@    @@   @@       @@        @@@@@@@@
  @@@@@@@@      @@@@    @@@@      @@        @@@@@@
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  int rev_to_center = 4; // Amount of rotations before reaching the center ofthe field from one side
                         
  int motor_speed = 90; // Wheel speed in autonomous

  back_left_motor.setStopping(brake); // Configuration for autonomous driving (setting brake and speed)
  back_right_motor.setStopping(brake);
  front_left_motor.setStopping(brake);
  front_right_motor.setStopping(brake);

  back_left_motor.setVelocity(motor_speed, pct);
  back_right_motor.setVelocity(motor_speed, pct);
  front_left_motor.setVelocity(motor_speed, pct);
  front_right_motor.setVelocity(motor_speed, pct);

  claw.setStopping(hold); // configuration for autonomous arm and claw (setting hold and speed)
  arm.setStopping(hold);

  claw.setVelocity(40, pct);
  arm.setVelocity(100, pct);

  back_left_motor.spinFor(fwd, rev_to_center - 1, rev, false);  // moves bot to center of field
  back_right_motor.spinFor(fwd, rev_to_center - 1, rev, false);
  front_left_motor.spinFor(fwd, rev_to_center - 1, rev, false);
  front_right_motor.spinFor(fwd, rev_to_center - 1, rev, false);
  
  arm.spinFor(fwd, 4, rev, true); // readies the arm so the claw can unfold

  back_left_motor.stop(); // keeps arm and wheels at their current position
  back_right_motor.stop();
  front_left_motor.stop();
  front_right_motor.stop();
  arm.stop();

  claw.spinFor(reverse, 3, rev, false); // unfolds claw, lowers the arm, and expands robot
  arm.spinFor(reverse, 4, rev, false);

  back_expansion.spinFor(reverse, .9, rev, false);  // expands robot
  front_expansion.spinFor(reverse, .9, rev, true);

  back_expansion.stop();  // prevents further expansion
  front_expansion.stop();

  back_left_motor.spinFor(fwd, 1, rev, false);  // moves bot to center of field
  back_right_motor.spinFor(fwd, 1, rev, false);
  front_left_motor.spinFor(fwd, 1, rev, false);
  front_right_motor.spinFor(fwd, 1, rev, false);

  back_left_motor.stop(); // keeps wheels at their current position
  back_right_motor.stop();
  front_left_motor.stop();
  front_right_motor.stop();

  claw.spinFor(fwd, 2, rev, true);  // grabs the tower

  claw.stop();  // prevents the claw from shifting

  arm.spinFor(fwd, 4, rev, false);  // lifts up tower and keeps pressure on the claw to prevent the tower slipping out
  claw.spin(reverse);

  wait(1, seconds);

  arm.stop();
  claw.stop();

  front_right_motor.spinFor(fwd, 1, rev, false);  // rotates bot
  back_right_motor.spinFor(fwd, 1, rev, true);

  front_left_motor.spinFor(reverse, 4, rev, false);  // strafes bot to the other tower
  front_right_motor.spinFor(fwd, 4, rev, false);
  back_left_motor.spinFor(reverse, 4, rev, false);
  back_right_motor.spinFor(fwd, 4, rev, true);

  back_left_motor.stop(); // keeps wheels at their current position
  back_right_motor.stop();
  front_left_motor.stop();
  front_right_motor.stop();

  side_claw.set(true);


  back_left_motor.spinFor(reverse, rev_to_center, rev, false);  // moves bot back to alliance side
  back_right_motor.spinFor(reverse, rev_to_center, rev, false);
  front_left_motor.spinFor(reverse, rev_to_center , rev, false);
  front_right_motor.spinFor(reverse, rev_to_center, rev, true);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int claw_user() {
  claw.setStopping(hold);
  claw.stop(); // prevents loops
 
  wait(20, msec);
  return (1);
}

int side_claw_user() {
  while(Controller1.ButtonA.pressing()) { // lowers pneumatic claw
    side_claw.set(true);
  }

  while(Controller1.ButtonX.pressing()) { // raises pneumatic claw
    side_claw.set(false);
  }
  wait(20, msec);
  return (1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int expansion_user() {
   front_expansion.stop(); // prevents loops
   back_expansion.stop();

  while(Controller1.ButtonLeft.pressing()){  //Expands bot
      front_expansion.spin(fwd, 50, pct);  //Expansion motors
      back_expansion.spin(fwd, 50, pct);

      front_right_motor.spin(fwd, 70, pct);
      front_left_motor.spin(fwd, 70, pct);
      back_left_motor.spin(reverse, 70, pct);
      back_right_motor.spin(reverse, 70, pct);
    }
   
    while(Controller1.ButtonRight.pressing()){  //Shrinks bot
      front_expansion.spin(fwd, 50, pct);  //Expansion motors
      back_expansion.spin(fwd, 50, pct);

      front_right_motor.spin(reverse, 70, pct);
      front_left_motor.spin(reverse, 70, pct);
      back_left_motor.spin(fwd, 70, pct);
      back_right_motor.spin(fwd, 70, pct);
    }
  wait(20, msec);
  return (1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

  int forward = Controller1.Axis3.position(percent);  // reads the position of the joysticks to determine the speed the motors go
  int sideways = Controller1.Axis4.position(percent);
  int rot = Controller1.Axis1.position(percent);

  back_left_motor.spin(vex::forward, forward/1.1 - sideways/1.1 + rot/1.1, vex::percent); // mecanum wheel control
  back_right_motor.spin(vex::forward,  forward/1.1 + sideways/1.1 - rot/1.1, vex::percent);
  front_left_motor.spin(vex::forward,  forward/1.1 + sideways/1.1 + rot/1.1, vex::percent);
  front_right_motor.spin(vex::forward,   forward/1.1 - sideways/1.1 - rot/1.1, vex::percent);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
back_left_motor.stop();
back_right_motor.stop();
front_left_motor.stop();
front_right_motor.stop();


  while(Controller1.ButtonR2.pressing()) { // lifts up the arm and keeps claw stationary
    arm.spin(fwd, 100, pct);
  }

  while(Controller1.ButtonR1.pressing()) { // lowers the arm and keeps claw stationary
    arm.spin(reverse, 100, pct);
  }

  while(Controller1.ButtonL2.pressing()) { // opens claw
    claw.spin(fwd, 40, pct);
  }

  while(Controller1.ButtonL1.pressing()) { // closes claw
    claw.spin(reverse, 40, pct);
  }
  
  while(Controller1.ButtonLeft.pressing()) {  //Expands bot
    front_expansion.spin(fwd, 50, pct);  //Expansion motors
    back_expansion.spin(fwd, 50, pct);

    front_right_motor.spin(fwd, 70, pct);
    front_left_motor.spin(fwd, 70, pct);
    back_left_motor.spin(reverse, 70, pct);
    back_right_motor.spin(reverse, 70, pct);
  }
   
  while(Controller1.ButtonRight.pressing()) {  //Shrinks bot
    front_expansion.spin(fwd, 50, pct);  //Expansion motors
    back_expansion.spin(fwd, 50, pct);

    front_right_motor.spin(reverse, 70, pct);
    front_left_motor.spin(reverse, 70, pct);
    back_left_motor.spin(fwd, 70, pct);
    back_right_motor.spin(fwd, 70, pct);
  }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
