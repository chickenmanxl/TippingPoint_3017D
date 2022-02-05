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
// BLMotor              motor         1               
// BRMotor              motor         2               
// FLMotor              motor         3               
// FRMotor              motor         4               
// ExpansionF           motor         15              
// ExpansionB           motor         19              
// TowerFLift           motor         8               
// TowerBLift           motor         10              
// ClawF                digital_out   A               
// ClawB                digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

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

void pre_auton(void){
  vexcodeInit();
}
void autonomous(void) {

  int revToCenter = 4; //Amount of rotations before reaching the center of the field from one side
  int motorSpeed = 90; //Wheel speed in autonomous

  BLMotor.setStopping(brake); //Configuring motor braking for autonomous
  BRMotor.setStopping(brake);
  FLMotor.setStopping(brake);
  FRMotor.setStopping(brake);

  BLMotor.setVelocity(motorSpeed, pct);  //Configuring motor velocity for autonomous
  BRMotor.setVelocity(motorSpeed, pct);
  FLMotor.setVelocity(motorSpeed, pct);
  FRMotor.setVelocity(motorSpeed, pct);

  TowerFLift.setVelocity(90, pct);

  BLMotor.spinFor(fwd, revToCenter, rev, false); //Moves bot forward to center of field
  BRMotor.spinFor(fwd, revToCenter, rev, false);
  FLMotor.spinFor(fwd, revToCenter, rev, false);
  FRMotor.spinFor(fwd, revToCenter, rev, true );

  BLMotor.stop(); //Stops the motors at center of field
  BRMotor.stop();
  FLMotor.stop();
  FRMotor.stop();

  TowerFLift.spinFor(reverse, .5, rev);

  BLMotor.spinFor(reverse, revToCenter, rev, false); //Moves bot back to home with tower in claw
  BRMotor.spinFor(reverse, revToCenter, rev, false);
  FLMotor.spinFor(reverse, revToCenter, rev, false);
  FRMotor.spinFor(reverse, revToCenter, rev, true );

  BLMotor.stop(); //Stops the motors when it reaches home
  BRMotor.stop();
  FLMotor.stop();
  FRMotor.stop();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void usercontrol(void) {
  while (1) {

    int forward = Controller1.Axis3.position(percent);  //reads the position of the joysticks to determine the speed the motors go
    int sideways = Controller1.Axis4.position(percent);
    int rot = Controller1.Axis1.position(percent);

    BLMotor.spin(vex::forward, forward/1.1 - sideways/1.1 + rot/1.1, vex::percent); //Mecanum wheel control
    BRMotor.spin(vex::forward,  forward/1.1 + sideways/1.1 - rot/1.1, vex::percent);
    FLMotor.spin(vex::forward,  forward/1.1 + sideways/1.1 + rot/1.1, vex::percent);
    FRMotor.spin(vex::forward,   forward/1.1 - sideways/1.1 - rot/1.1, vex::percent);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ExpansionF.stop(); //Prevents loops
    ExpansionB.stop();
    TowerFLift.stop();
    TowerBLift.stop();
    
    TowerFLift.setStopping(hold);

    while(Controller1.ButtonR1.pressing()){ //Lifts up the front tower lift
      TowerFLift.spin(fwd, 50, pct);
    }

    while(Controller1.ButtonR2.pressing()){ //Lowers the front tower lift
      TowerFLift.spin(reverse, 50, pct);
    }

    while(Controller1.ButtonL2.pressing()){ //Lifts up the back tower lift
      TowerBLift.spin(fwd, 10, pct);
    }

    while(Controller1.ButtonL1.pressing()){ //Lowers the back tower lift
      TowerBLift.spin(reverse, 10, pct);
    }

    while(Controller1.ButtonUp.pressing()){  //Opens front claw
      ClawF.set(false);
    }

    while(Controller1.ButtonDown.pressing()){  //Closes back claw
      ClawF.set(true);
    }

    while(Controller1.ButtonX.pressing()){  //Opens back claw
      ClawB.set(false);
    }

    while(Controller1.ButtonB.pressing()){  //Closes back claw
      ClawB.set(true);
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(Controller1.ButtonLeft.pressing()){  //Expands bot
      ExpansionF.spin(fwd, 50, pct);  //Expansion motors
      ExpansionB.spin(fwd, 50, pct);

      FRMotor.spin(fwd, 70, pct);
      FLMotor.spin(fwd, 70, pct);
      BRMotor.spin(reverse, 70, pct);
      BLMotor.spin(reverse, 70, pct);
    }
   
    while(Controller1.ButtonRight.pressing()){  //Shrinks bot
      ExpansionF.spin(reverse, 50, pct);  //Expansion motors
      ExpansionB.spin(reverse, 50, pct);

      FRMotor.spin(reverse, 70, pct);
      FLMotor.spin(reverse, 70, pct);
      BRMotor.spin(fwd, 70, pct);
      BLMotor.spin(fwd, 70, pct);
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

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