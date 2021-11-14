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
// VisionR              vision        18              
// VisionL              vision        17              
// BackLeft             motor         12              
// BackRight            motor         1               
// FrontLeft            motor         16              
// FrontRight           motor         11              
// Controller1          controller                    
// liftR                motor         3               
// expandL              motor         4               
// liftL                motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
using namespace std;
int spd = 0;
// A global instance of competition
competition Competition;
//call
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
float dist()
{ //find distance to object with stero vision
    //start distance
    float f = 2.7;
    float T = 128;
    

    VisionR.takeSnapshot(VisionR__PCUBE);
    VisionL.takeSnapshot(VisionL__PCUBE);
    
    float Xr = VisionR.objects[1].centerX;
    float Xl = VisionL.objects[1].centerX;
    
   return (f * T)/(Xr-Xl);
    //end distance
  }


  float drev() //finds revoultions
  {
    return dist()/12.566;
  }  

  float dTurn() //finds ammount to turn
  {
    float Xr = VisionR.objects[1].centerX;
    float Xl = VisionL.objects[1].centerX;

    return Xr-Xl;
  }

  void drive(char dir) //used for autonomous to drive
  {
    switch(dir)
    {
      case 'f':

        BackLeft.setVelocity(spd, pct); //Motor speed
        BackRight.setVelocity(spd, pct); //Motor speed
        FrontLeft.setVelocity(spd, pct); //Motor speed
        FrontRight.setVelocity(spd, pct); //Motor speed

        BackLeft.spinFor(fwd,drev(),rev,false);  //Motor forwards
        BackRight.spinFor(fwd,drev(),rev,false); //Motor forwards
        FrontLeft.spinFor(fwd,drev(),rev,false); //Motor forwards
        FrontRight.spinFor(fwd,drev(),rev,true);  //Motor forwards

        BackLeft.stop(); //Motor stops
        BackRight.stop(); //Motor stops
        FrontLeft.stop(); //Motor stops
        FrontRight.stop(); //Motor stops
        break;

      case 'b':
        BackLeft.setVelocity(spd, pct); //Motor speed
        BackRight.setVelocity(spd, pct); //Motor speed
        FrontLeft.setVelocity(spd, pct); //Motor speed
        FrontRight.setVelocity(spd, pct); //Motor speed


        BackLeft.spinFor(reverse,drev(),rev,false);  //Motor forwards
        BackRight.spinFor(reverse,drev(),rev,false); //Motor forwards
        FrontLeft.spinFor(reverse,drev(),rev,false); //Motor forwards
        FrontRight.spinFor(reverse,drev(),rev,true);  //Motor forwards

        BackLeft.stop(); //Motor stops
        BackRight.stop(); //Motor stops
        FrontLeft.stop(); //Motor stops
        FrontRight.stop(); //Motor stops
        break;

      case 'r':
        BackLeft.setVelocity(spd, pct); //Motor speed
        BackRight.setVelocity(spd, pct); //Motor speed
        FrontLeft.setVelocity(spd, pct); //Motor speed
        FrontRight.setVelocity(spd, pct); //Motor speed

        BackLeft.spinFor(reverse,drev(),rev,false);  //Motor forwards
        BackRight.spinFor(reverse,drev(),rev,false); //Motor forwards
        FrontLeft.spinFor(fwd,drev(),rev,false); //Motor forwards
        FrontRight.spinFor(fwd,drev(),rev,true);  //Motor forwards

        BackLeft.stop(); //Motor stops
        BackRight.stop(); //Motor stops
        FrontLeft.stop(); //Motor stops
        FrontRight.stop(); //Motor stops
        break;

      case 'l':
        BackLeft.setVelocity(spd, pct); //Motor speed
        BackRight.setVelocity(spd, pct); //Motor speed
        FrontLeft.setVelocity(spd, pct); //Motor speed
        FrontRight.setVelocity(spd, pct); //Motor speed

        BackLeft.spinFor(fwd,drev(),rev,false);  //Motor forwards
        BackRight.spinFor(fwd,drev(),rev,false); //Motor forwards
        FrontLeft.spinFor(reverse,drev(),rev,false); //Motor forwards
        FrontRight.spinFor(reverse,drev(),rev,true);  //Motor forwards

        BackLeft.stop(); //Motor stops
        BackRight.stop(); //Motor stops
        FrontLeft.stop(); //Motor stops
        FrontRight.stop(); //Motor stops
        break;

        case 'R':
        while(dTurn()>1)
        {
        BackLeft.setVelocity(spd/2, pct); //Motor speed
        BackRight.setVelocity(spd/2, pct); //Motor speed
        FrontLeft.setVelocity(spd/2, pct); //Motor speed
        FrontRight.setVelocity(spd/2, pct); //Motor speed

        BackLeft.spinFor(fwd,.25,rev,false);  //Motor forwards
        BackRight.spinFor(reverse,.25,rev,false); //Motor forwards
        FrontLeft.spinFor(fwd,.25,rev,false); //Motor forwards
        FrontRight.spinFor(reverse,.25,rev,true);  //Motor forwards

        BackLeft.stop(); //Motor stops
        BackRight.stop(); //Motor stops
        FrontLeft.stop(); //Motor stops
        FrontRight.stop(); //Motor stops
        }
        break;

        case 'L':
        while(dTurn()<1)
        {
        BackLeft.setVelocity(spd/2, pct); //Motor speed
        BackRight.setVelocity(spd/2, pct); //Motor speed
        FrontLeft.setVelocity(spd/2, pct); //Motor speed
        FrontRight.setVelocity(spd/2, pct); //Motor speed

        BackLeft.spinFor(reverse,.25,rev,false);  //Motor forwards
        BackRight.spinFor(fwd,.25,rev,false); //Motor forwards
        FrontLeft.spinFor(reverse,.25,rev,false); //Motor forwards
        FrontRight.spinFor(fwd,.25,rev,true);  //Motor forwards

        BackLeft.stop(); //Motor stops
        BackRight.stop(); //Motor stops
        FrontLeft.stop(); //Motor stops
        FrontRight.stop(); //Motor stops
        }
        break;
      default:
      break;
    }
  }

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}



void autonomous(void) {
  BackLeft.setVelocity(90, pct); //Motor speed
  BackRight.setVelocity(90, pct); //Motor speed
  FrontLeft.setVelocity(90, pct); //Motor speed
  FrontRight.setVelocity(90, pct); //Motor speed
  liftL.setVelocity(90, pct); //Lift speed

  BackLeft.spinFor(reverse,1,rev,false);  //Motor forwards
  BackRight.spinFor(reverse,1,rev,false); //Motor forwards
  FrontLeft.spinFor(reverse,1,rev,false); //Motor forwards
  FrontRight.spinFor(reverse,1,rev,true);  //Motor forwards

  liftL.spinFor(reverse, 5, rev, false); //Lift up

  BackLeft.stop(); //Motor stops
  BackRight.stop(); //Motor stops
  FrontLeft.stop(); //Motor stops
  FrontRight.stop(); //Motor stops
  liftL.stop(); //Lift stops

}

  
void usercontrol(void) {
 while(1){
  int forward = Controller1.Axis3.position(percent); //reads controller stick input
  int sideways = -Controller1.Axis4.position(percent); //reads controller stick input
  int rot = -Controller1.Axis1.position(percent); //reads controller stick input

  FrontRight.spin(vex::forward, forward/2 - sideways/2 + rot/2, vex::percent); //front right motor drive
  FrontLeft.spin(vex::forward,  forward/2 + sideways/2 - rot/2, vex::percent); //front left motor drive
  BackRight.spin(vex::forward,  forward/2 + sideways/2 + rot/2, vex::percent); //back right motor drive
  BackLeft.spin(vex::forward,   forward/2 - sideways/2 - rot/2, vex::percent); //back left motor drive

  liftL.stop(); //stops lift
  liftR.stop(); //stops lift
  expandL.stop(); //stops expansion

    if(Controller1.ButtonL1.pressing()) //lift up
    {
      liftL.spin(reverse,60,pct); //motor reverse
    }

    while(Controller1.ButtonL2.pressing()) //lift down
    {
      liftL.spin(fwd,80,pct); //motor forward
    }

    while(Controller1.ButtonR1.pressing()) //lift up
    {
      liftR.spin(reverse,90,pct); //motor reverse
    }

    while(Controller1.ButtonR2.pressing()) //lift down
    {
      liftR.spin(fwd,70,pct); //motor forward
    }

    while(Controller1.ButtonLeft.pressing()) //expand bot
    {
      FrontRight.spin(fwd,20,pct); //motor forward
      FrontLeft.spin(fwd,20,pct); //motor forward
      BackRight.spin(reverse,20,pct); //motor reverse
      BackLeft.spin(reverse,20,pct); //motor reverse
      expandL.spin(fwd,50,pct); //expand using rack gear
    }

    while(Controller1.ButtonRight.pressing()) //contract bot
    {
      FrontRight.spin(reverse,20,pct); //motor forward
      FrontLeft.spin(reverse,20,pct); //motor forward
      BackRight.spin(fwd,20,pct); //motor reverse
      BackLeft.spin(fwd,20,pct); //motor reverse
      expandL.spin(reverse,50,pct); //contract using rack gear
    }

  // User control code here, inside the loop
 }
 /* while (dist()>=1000) {
      dist();
      drive('f');
      //Drivetrain.setTurnVelocity(25, percent);
      //Drivetrain.turnFor(left, 90, degrees);
    

  }
  while (dist()<500 && dist()>100)
  {
    dist();
      drive('f');
  }
  */

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

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
