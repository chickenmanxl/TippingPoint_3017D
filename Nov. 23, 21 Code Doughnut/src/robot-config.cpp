#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature VisionR__PCUBE = signature (1, 523, 2329, 1426, 3449, 6649, 5049, 1, 0);
vision VisionR = vision (PORT6, 50, VisionR__PCUBE);
/*vex-vision-config:end*/
/*vex-vision-config:begin*/
signature VisionL__PCUBE = signature (1, 979, 2095, 1537, 6185, 8651, 7418, 1.7, 0);
vision VisionL = vision (PORT10, 50, VisionL__PCUBE);
/*vex-vision-config:end*/
motor BackLeft = motor(PORT12, ratio18_1, false);
motor BackRight = motor(PORT1, ratio18_1, true);
motor FrontLeft = motor(PORT16, ratio18_1, false);
motor FrontRight = motor(PORT11, ratio18_1, true);
controller Controller1 = controller(primary);
motor liftR = motor(PORT3, ratio18_1, true);
motor expandL = motor(PORT4, ratio36_1, true);
motor liftL = motor(PORT5, ratio18_1, false);

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