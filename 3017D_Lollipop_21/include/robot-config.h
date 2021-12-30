using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor BackLeft;
extern motor BackRight;
extern motor FrontLeft;
extern motor FrontRight;
extern digital_out claw;
extern signature VisionR__SIG_1;
extern signature VisionR__SIG_2;
extern signature VisionR__SIG_3;
extern signature VisionR__SIG_4;
extern signature VisionR__SIG_5;
extern signature VisionR__SIG_6;
extern signature VisionR__SIG_7;
extern vision VisionR;
extern signature VisionL__SIG_1;
extern signature VisionL__SIG_2;
extern signature VisionL__SIG_3;
extern signature VisionL__SIG_4;
extern signature VisionL__SIG_5;
extern signature VisionL__SIG_6;
extern signature VisionL__SIG_7;
extern vision VisionL;
extern motor TowerR;
extern motor ExpandL;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );