/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// BackLeft             motor         1               
// FrontLeft            motor         2               
// BackRight            motor         3               
// FrontRight           motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

    BackLeft.spinFor(fwd,1.27,rev,false);  //Motor forwards
    BackRight.spinFor(fwd,1.27,rev,false); //Motor forwards
    FrontLeft.spinFor(fwd,1.27,rev,false); //Motor forwards
    FrontRight.spinFor(fwd,1.27,rev,true);  //Motor forwards

    BackLeft.stop(); //Motor stops
    BackRight.stop(); //Motor stops
    FrontLeft.stop(); //Motor stops
    FrontRight.stop(); //Motor stops

    BackLeft.spinFor(fwd,5.08,rev,false);  //Motor forwards
    BackRight.spinFor(fwd,5.08,rev,false);  //Motor forwards
    FrontLeft.spinFor(reverse,5.08,rev,false);//Motor backwards
    FrontRight.spinFor(reverse,5.08,rev,true);//Motor backwards

    BackLeft.stop(); //Motor stops
    BackRight.stop(); //Motor stops
    FrontLeft.stop(); //Motor stops
    FrontRight.stop(); //Motor stops

    BackLeft.spinFor(fwd,33.02,rev,false);  //Motor forwards
    BackRight.spinFor(fwd,33.02,rev,false);  //Motor forwards
    FrontLeft.spinFor(fwd,33.02,rev,false);  //Motor forwards
    FrontRight.spinFor(fwd,33.02,rev,true);  //Motor forwards

    BackLeft.stop(); //Motor stops
    BackRight.stop(); //Motor stops
    FrontLeft.stop(); //Motor stops
    FrontRight.stop(); //Motor stops

    BackLeft.spinFor(fwd,8.89,rev,false);  //Motor forwards
    BackRight.spinFor(fwd,8.89,rev,false);  //Motor forwards
    FrontLeft.spinFor(reverse,8.89,rev,false);  //Motor backwards
    FrontRight.spinFor(reverse,8.89,rev,true);//Motor backwards

    BackLeft.stop(); //Motor stops
    BackRight.stop(); //Motor stops
    FrontLeft.stop(); //Motor stops
    FrontRight.stop(); //Motor stops

     BackLeft.spinFor(fwd,3.81,rev,false);  //Motor forwards
    BackRight.spinFor(fwd,3.81,rev,false);  //Motor forwards
    FrontLeft.spinFor(fwd,3.81,rev,false);  //Motor forwards
    FrontRight.spinFor(fwd,3.81,rev,true);  //Motor forwards

    BackLeft.stop();  //Motor stops
    BackRight.stop();  //Motor stops
    FrontLeft.stop();  //Motor stops
    FrontRight.stop(); //Motor stops
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
BackLeft.setStopping(brake);
BackRight.setStopping(brake);
FrontLeft.setStopping(brake);
FrontRight.setStopping(brake);

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
