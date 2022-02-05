using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor BLMotor;
extern motor BRMotor;
extern motor FLMotor;
extern motor FRMotor;
extern motor ExpansionF;
extern motor ExpansionB;
extern motor TowerFLift;
extern motor TowerBLift;
extern digital_out ClawF;
extern digital_out ClawB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );