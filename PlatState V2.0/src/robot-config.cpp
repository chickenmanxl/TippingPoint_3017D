#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor back_left_motor = motor(PORT2, ratio18_1, true);
motor back_right_motor = motor(PORT6, ratio18_1, false);
motor front_left_motor = motor(PORT5, ratio18_1, true);
motor front_right_motor = motor(PORT4, ratio18_1, false);
motor front_expansion = motor(PORT8, ratio36_1, false);
motor back_expansion = motor(PORT19, ratio36_1, false);
motor arm = motor(PORT12, ratio36_1, true);
motor claw = motor(PORT10, ratio18_1, false);
digital_out side_claw = digital_out(Brain.ThreeWirePort.A);

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