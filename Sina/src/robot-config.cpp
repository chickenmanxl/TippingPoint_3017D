#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor BLMotor = motor(PORT1, ratio18_1, false);
motor BRMotor = motor(PORT2, ratio18_1, false);
motor FLMotor = motor(PORT3, ratio18_1, false);
motor FRMotor = motor(PORT4, ratio18_1, false);
motor ExpansionF = motor(PORT5, ratio18_1, false);
motor ExpansionB = motor(PORT6, ratio18_1, false);
motor TowerFLift = motor(PORT8, ratio18_1, false);
motor TowerBLift = motor(PORT10, ratio18_1, false);
digital_out ClawF = digital_out(Brain.ThreeWirePort.A);
digital_out ClawB = digital_out(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}