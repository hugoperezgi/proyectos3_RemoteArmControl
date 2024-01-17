/**
 * This is meant as a place in which functions can be stored/worked on when they're not being used on the
 * Arduino code, this is not meant to be an importable module for the main Arduino script. To use any of
 * these functions, just copy the function over to the working Arduino script.
 * 
*/

#include "calibrationServos.h" 

/**
 * Finger Servos:
 *  Inner servos:
 *      thumb_B == servoid=0; 
 *      index_B == servoid=1; 
 *      middle_B == servoid=2; 
 *      ring_B == servoid=3; 
 *      pinky_B == servoid=4
 * 
 *  Outer servos:
 *      thumb_A == servoid=5; 
 *      index_A == servoid=6; 
 *      middle_A == servoid=7; 
 *      ring_A == servoid=8; 
 *      pinky_A == servoid=9
 * 
 * STEP_SERVOID_X -> step of each servo for the mapped range of motion (0-180)
 * 
 * Palm servo: 
 *      servoid==11
 * 
 * Arm servos: 
 *      Shoulder -> id=12
 *      Forearm -> id=13
 *      Biceps -> id=14
 *      Wrist -> id=15
 * 
*/

/**
 * 0º == Fully extended
 * 180º == Fully contracted
*/
uint8_t currentPosition[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void openCloseHand(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
    i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] > 0){currentPosition[3]--;pwm.setPWM(3, 0, currentPosition[3]*STEP_SERVOID_3 + SERVOMIN_ring_B);}
        if(currentPosition[4] > 0){currentPosition[4]--;pwm.setPWM(4, 0, currentPosition[4]*STEP_SERVOID_4 + SERVOMIN_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] > 0){currentPosition[8]--;pwm.setPWM(8, 0, currentPosition[8]*STEP_SERVOID_8 + SERVOMIN_ring_A);}
        if(currentPosition[9] > 0){currentPosition[9]--;pwm.setPWM(9, 0, currentPosition[9]*STEP_SERVOID_9 + SERVOMIN_pinky_A);}      
        if(currentPosition[10] > 0){currentPosition[10]--;pwm.setPWM(11, 0, -currentPosition[10]*STEP_SERVOID_11+ SERVOMAX_palm);}
        i++;
    }
}
/**
 * Everything closed but thumb, palm servo extended
*/
void signLangA(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] > 0){currentPosition[10]--;pwm.setPWM(11, 0, -currentPosition[10]*STEP_SERVOID_11+ SERVOMAX_palm);}
        i++;
    }
}


/**
 * Everything extended, palm servo closed
*/
void signLangB(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}

        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Everything extended, palm servo included
*/
void signLangC(){
    i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] > 0){currentPosition[3]--;pwm.setPWM(3, 0, currentPosition[3]*STEP_SERVOID_3 + SERVOMIN_ring_B);}
        if(currentPosition[4] > 0){currentPosition[4]--;pwm.setPWM(4, 0, currentPosition[4]*STEP_SERVOID_4 + SERVOMIN_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] > 0){currentPosition[8]--;pwm.setPWM(8, 0, currentPosition[8]*STEP_SERVOID_8 + SERVOMIN_ring_A);}
        if(currentPosition[9] > 0){currentPosition[9]--;pwm.setPWM(9, 0, currentPosition[9]*STEP_SERVOID_9 + SERVOMIN_pinky_A);}      
        if(currentPosition[10] > 0){currentPosition[10]--;pwm.setPWM(11, 0, -currentPosition[10]*STEP_SERVOID_11+ SERVOMAX_palm);}
        i++;
    }
}


/**
 * index extended, everything else clsoed
*/
void signLangD(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Everythin closed
*/
void signLangE(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Index and thumb closed, palm closed, everything else extended
*/
void signLangF(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] > 0){currentPosition[3]--;pwm.setPWM(3, 0, currentPosition[3]*STEP_SERVOID_3 + SERVOMIN_ring_B);}
        if(currentPosition[4] > 0){currentPosition[4]--;pwm.setPWM(4, 0, currentPosition[4]*STEP_SERVOID_4 + SERVOMIN_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] > 0){currentPosition[8]--;pwm.setPWM(8, 0, currentPosition[8]*STEP_SERVOID_8 + SERVOMIN_ring_A);}
        if(currentPosition[9] > 0){currentPosition[9]--;pwm.setPWM(9, 0, currentPosition[9]*STEP_SERVOID_9 + SERVOMIN_pinky_A);}      
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Everything closed, pynky fully extended, palm closed
*/
void signLangI(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] > 0){currentPosition[9]--;pwm.setPWM(9, 0, currentPosition[9]*STEP_SERVOID_9 + SERVOMIN_pinky_A);}      
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Index, Middle and Thumb extended; ring, pynky and palm closed
*/
void signLangK(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Index, thumb and palm fully extended, other 3 fingers closed
*/
void signLangL(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] > 0){currentPosition[10]--;pwm.setPWM(11, 0, -currentPosition[10]*STEP_SERVOID_11+ SERVOMAX_palm);}
        i++;
    }
}

/**
 * Outer servos fully closed; palm and thumb servos fully closed
*/
void signLangO(){
uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] > 0){currentPosition[3]--;pwm.setPWM(3, 0, currentPosition[3]*STEP_SERVOID_3 + SERVOMIN_ring_B);}
        if(currentPosition[4] > 0){currentPosition[4]--;pwm.setPWM(4, 0, currentPosition[4]*STEP_SERVOID_4 + SERVOMIN_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Outter index servo, thumb servos extended, palm servo closed; every other servo closed
*/
void signLangQ(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/** Index middle and thumb fully extended; every other servo closed*/
void signLangU(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Peace Sign
*/
void signLangV(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * tres cervezas
*/
void signLangW(){
    uint8_t i=0;
    while (i<180){
        if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
        if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);}
        if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);}
        if(currentPosition[3] > 0){currentPosition[3]--;pwm.setPWM(3, 0, currentPosition[3]*STEP_SERVOID_3 + SERVOMIN_ring_B);}
        if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
        if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
        if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);}
        if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);}
        if(currentPosition[8] > 0){currentPosition[8]--;pwm.setPWM(8, 0, currentPosition[8]*STEP_SERVOID_8 + SERVOMIN_ring_A);}
        if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
        if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
        i++;
    }
}

/**
 * Surf emote
*/
void signLangY(){
        uint8_t i=0;
    while (i<180){
        if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);}
        if(currentPosition[1] < 180){currentPosition[1]++;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
        if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
        if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
        if(currentPosition[4] > 0){currentPosition[4]--;pwm.setPWM(4, 0, currentPosition[4]*STEP_SERVOID_4 + SERVOMIN_pinky_B);}
        if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);}
        if(currentPosition[6] < 180){currentPosition[6]++;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
        if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
        if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
        if(currentPosition[9] > 0){currentPosition[9]--;pwm.setPWM(9, 0, currentPosition[9]*STEP_SERVOID_9 + SERVOMIN_pinky_A);}      
        if(currentPosition[10] > 0){currentPosition[10]--;pwm.setPWM(11, 0, -currentPosition[10]*STEP_SERVOID_11+ SERVOMAX_palm);}
        i++;
    }
}

//  Setup servos to extended position (Open Hand)
void setUpServoPositions(){
    pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    currentPosition[0]=0;
    pwm.setPWM(1, 0, SERVOMAX_index_B);
    currentPosition[1]=0;
    pwm.setPWM(2, 0, SERVOMAX_middle_B);
    currentPosition[2]=0;
    pwm.setPWM(3, 0, SERVOMAX_ring_B);
    currentPosition[3]=0;
    pwm.setPWM(4, 0, SERVOMAX_pinky_B);
    currentPosition[4]=0;
    pwm.setPWM(5, 0, SERVOMAX_thumb_A);
    currentPosition[5]=0;
    pwm.setPWM(6, 0, SERVOMAX_index_A);
    currentPosition[6]=0;
    pwm.setPWM(7, 0, SERVOMAX_middle_A);
    currentPosition[7]=0;
    pwm.setPWM(8, 0, SERVOMAX_ring_A);
    currentPosition[8]=0;
    pwm.setPWM(9, 0, SERVOMAX_pinky_A);
    currentPosition[9]=0;
    pwm.setPWM(11, 0, SERVOMIN_palm);
    currentPosition[10]=0;
}

void pointIndex(){
  i=0;
  while (i<90){
    if(currentPosition[0] > 0 && currentPosition[0] < 180){ currentPosition[0] == 1 ? currentPosition[0]-=1 : currentPosition[0]-=2; pwm.setPWM(0, 0, currentPosition[0]*STEP_SERVOID_0 + SERVOMIN_thumb_B);} 

    if(currentPosition[1] > 0 && currentPosition[1] < 180){ currentPosition[1] == 179 ? currentPosition[1]+=1 : currentPosition[1]+=2; pwm.setPWM(1, 0, currentPosition[1]*STEP_SERVOID_1 + SERVOMIN_index_B);} 

    if(currentPosition[2] > 0 && currentPosition[2] < 180){ currentPosition[2] == 1 ? currentPosition[2]-=1 : currentPosition[2]-=2; pwm.setPWM(2, 0, currentPosition[2]*STEP_SERVOID_2 + SERVOMIN_middle_B);} 
    if(currentPosition[3] > 0 && currentPosition[3] < 180){ currentPosition[3] == 1 ? currentPosition[3]-=1 : currentPosition[3]-=2; pwm.setPWM(3, 0, currentPosition[3]*STEP_SERVOID_3 + SERVOMIN_ring_B);} 
    if(currentPosition[4] > 0 && currentPosition[4] < 180){ currentPosition[4] == 1 ? currentPosition[4]-=1 : currentPosition[4]-=2; pwm.setPWM(4, 0, currentPosition[4]*STEP_SERVOID_4 + SERVOMIN_pinky_B);} 
    if(currentPosition[5] > 0 && currentPosition[5] < 180){ currentPosition[5] == 1 ? currentPosition[5]-=1 : currentPosition[5]-=2; pwm.setPWM(5, 0, currentPosition[5]*STEP_SERVOID_5 + SERVOMIN_thumb_A);} 

    if(currentPosition[6] > 0 && currentPosition[6] < 180){ currentPosition[6] == 179 ? currentPosition[6]+=1 : currentPosition[6]+=2; pwm.setPWM(6, 0, currentPosition[6]*STEP_SERVOID_6 + SERVOMIN_index_A);} 
    
    if(currentPosition[7] > 0 && currentPosition[7] < 180){ currentPosition[7] == 1 ? currentPosition[7]-=1 : currentPosition[7]-=2; pwm.setPWM(7, 0, currentPosition[7]*STEP_SERVOID_7 + SERVOMIN_middle_A);} 
    if(currentPosition[8] > 0 && currentPosition[8] < 180){ currentPosition[8] == 1 ? currentPosition[8]-=1 : currentPosition[8]-=2; pwm.setPWM(8, 0, currentPosition[8]*STEP_SERVOID_8 + SERVOMIN_ring_A);} 
    if(currentPosition[9] > 0 && currentPosition[9] < 180){ currentPosition[9] == 1 ? currentPosition[9]-=1 : currentPosition[9]-=2; pwm.setPWM(9, 0, currentPosition[9]*STEP_SERVOID_9 + SERVOMIN_pinky_A);} 
    if(currentPosition[10] > 0 && currentPosition[10] < 180){ currentPosition[10] == 1 ? currentPosition[10]-=1 : currentPosition[10]-=2; pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11 + SERVOMAX_palm);} 

    delay(5);
    i++;
  }
  delay(25);
}


void switchGestures(int i){
    switch (i){
        case 0:
            signLangA();
            break;
        case 1:
            signLangB();
            break;
        case 2:
            signLangC();
            break;
        case 3:
            signLangD();
            break;
        case 4:
            signLangE();
            break;
        case 5:
            signLangF();
            break;
        case 6:
            signLangI();
            break;
        case 7:
            signLangK();
            break;
        case 8:
            signLangL();
            break;
        case 9:
            signLangO();
            break;
        case 10:
            signLangQ();
            break;
        case 11:
            signLangU();
            break;
        case 12:
            signLangV();
            break;
        case 13:
            signLangW();
            break;
        case 14:
            signLangY();
            break;
    }
}

void moveWristToAngle(int angle){
  if(angle>180 && angle<=255) return;
  while (currentPosition[14]!=angle){
    pwm.setPWM(15, 0, -currentPosition[14]*STEP_SERVOID_15);
    currentPosition[14] < angle ? ++currentPosition[14] : --currentPosition[14];
    delay(10);
  }
}

