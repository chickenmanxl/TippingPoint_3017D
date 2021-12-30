#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor BackLeft = motor(PORT12, ratio18_1, false);
motor BackRight = motor(PORT1, ratio18_1, false);
motor FrontLeft = motor(PORT16, ratio18_1, false);
motor FrontRight = motor(PORT11, ratio18_1, false);
digital_out claw = digital_out(Brain.ThreeWirePort.H);
/*vex-vision-config:begin*/
vision VisionR = vision (PORT6, 50);
/*vex-vision-config:end*/
/*vex-vision-config:begin*/
vision VisionL = vision (PORT10, 50);
/*vex-vision-config:end*/
motor TowerR = motor(PORT14, ratio18_1, false);
motor ExpandL = motor(PORT4, ratio36_1, false);

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