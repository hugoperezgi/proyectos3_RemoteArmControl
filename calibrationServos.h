#include <stdint.h>

/*
 * 
 *  USMAX//SERVOMAX- maximum extension possible for the servo AKA open hand
 *  USMIN//SERVOMIN- minimum extension possible for the servo AKA closed hand
 *  
 *  _A- outer servo of the given finger
 *  _B- inner servo of the given finger 
 * 
 */

/*
 * 
 * Inner servos:
 * thumb_B == servoid=0; index_B == servoid=1; middle_B == servoid=2; ring_B == servoid=3; pinky_B == servoid=4
 * 
 * Outer servos:
 * thumb_A == servoid=5; index_A == servoid=6; middle_A == servoid=7; ring_A == servoid=8; pinky_A == servoid=9
 * 
 * STEP_SERVOID_X -> step of each servo for the mapped range of motion (0-180)
 * 
 */


#define SERVOMIN_thumb_A  337 // thumb outer servo min         RED1      id5
#define SERVOMAX_thumb_A  490 // thumb outer servo max         RED1      id5
#define SERVOMIN_thumb_B  122 // thumb inner servo min         RED2      id0  122
#define SERVOMAX_thumb_B  378 // thumb inner servo max         RED2      id0

#define STEP_SERVOID_5 0.850000
#define STEP_SERVOID_0 1.422222

//Index finger servos
// #define USMIN_index_A  600 // index outer servo min         YELLOW1   id6
// #define USMAX_index_A  2000 // index outer servo max        YELLOW1   id6
// #define USMIN_index_B  1350 // index inner servo min        YELLOW2   id1
// #define USMAX_index_B  2460 // index inner servo max        YELLOW2   id1

#define SERVOMIN_index_A  122 // index outer servo min         YELLOW1   id6  122
#define SERVOMAX_index_A  409 // index outer servo max         YELLOW1   id6
#define SERVOMIN_index_B  276 // index inner servo min         YELLOW2   id1
#define SERVOMAX_index_B  503 // index inner servo max         YELLOW2   id1

#define STEP_SERVOID_6 1.594444
#define STEP_SERVOID_1 1.261111

//Middle finger servos
// #define USMIN_middle_A  600 // middle outer servo min       BLUE1     id7
// #define USMAX_middle_A  2400 // middle outer servo max      BLUE1     id7
// #define USMIN_middle_B  800 // middle inner servo min       BLUE2     id2
// #define USMAX_middle_B  1700 // middle inner servo max      BLUE2     id2

#define SERVOMIN_middle_A  122 // middle outer servo min       BLUE1     id7  122
#define SERVOMAX_middle_A  490 // middle outer servo max       BLUE1     id7
#define SERVOMIN_middle_B  163 // middle inner servo min       BLUE2     id2
#define SERVOMAX_middle_B  347 // middle inner servo max       BLUE2     id2

#define STEP_SERVOID_7 2.044445
#define STEP_SERVOID_2 1.022222

//Ring finger servos
// #define USMIN_ring_A  600 // ring outer servo min           GREEN1    id8
// #define USMAX_ring_A  2050 // ring outer servo max          GREEN1    id8
// #define USMIN_ring_B  1200 // ring inner servo min          GREEN2    id3
// #define USMAX_ring_B  2050  // ring inner servo max         GREEN2    id3

#define SERVOMIN_ring_A  122 // ring outer servo min           GREEN1    id8  122
#define SERVOMAX_ring_A  419 // ring outer servo max           GREEN1    id8
#define SERVOMIN_ring_B  245 // ring inner servo min           GREEN2    id3
#define SERVOMAX_ring_B  419  // ring inner servo max          GREEN2    id3

#define STEP_SERVOID_8 1.650000
#define STEP_SERVOID_3 0.966667

//Pinky finger servos
// #define USMIN_pinky_A  600 // pinky outer servo min         GRAY1     id9
// #define USMAX_pinky_A  1950 // pinky outer servo max        GRAY1     id9
// #define USMIN_pinky_B  600 // pinky inner servo min         GRAY2     id4
// #define USMAX_pinky_B  1500 // pinky inner servo max        GRAY2     id4

#define SERVOMIN_pinky_A  122 // pinky outer servo min         GRAY1     id9  122
#define SERVOMAX_pinky_A  398 // pinky outer servo max         GRAY1     id9
#define SERVOMIN_pinky_B  122 // pinky inner servo min         GRAY2     id4  122
#define SERVOMAX_pinky_B  306 // pinky inner servo max         GRAY2     id4

#define STEP_SERVOID_9 1.533333
#define STEP_SERVOID_4 1.022222

/**
 * Wrist Servo
 * id=15
*/

// #define USMAX_WRIST 2200 //Muñeca min extension/hacia antebrazo (MANO HACIA ABAJO, PLEGADA, WHATEVER)
// #define USMIN_WRIST 1000 //Muñeca max extension/hacia fuera (MANO HACIA EL EXTERIOR)

#define SERVOMAX_wrist 449 
#define SERVOMIN_wrist 204

#define STEP_SERVOID_15 1.361111

/**
 * Forearm Servo
 * id=13
*/

// #define USMAX_FOREARM 2350 //antebrazo SENTIDO HORARIO MAX
// #define USMIN_FOREARM 1400 // SENTIDO ANTI-HORARIO MAX

#define SERVOMAX_forearm 479
#define SERVOMIN_forearm 285

#define STEP_SERVOID_13 1.077778

/**
 * Biceps Servo
 * id=14
*/

// #define USMAX_BICEPS 1650 //BRAZO CONTRAIDO - Puede subir un poco más, pero al igual q min, no puede bajar :)
// #define USMIN_BICEPS 1100  //bRAZO EXTENDIDO - No puede subir si baja mas q esto, por rango si q podría

#define SERVOMAX_biceps 337
#define SERVOMIN_biceps 224

#define STEP_SERVOID_14 0.627778

/**
 * Shoulder Servo
 * id=12
*/

// #define USMAX_SHOULDER 2000 //HOMBRO HACIA "DENTRO"
// #define USMIN_SHOULDER 1200  //hOMBRO HACIA "FUERA"

#define SERVOMAX_shoulder 408 //lo mas levantado posible
#define SERVOMIN_shoulder 245 //pegado a la mesa

#define STEP_SERVOID_12 0.905556

/**
 * Palm Servo
 * id=11
*/

// #define USMAX_PALM 800 //thumb hacia fuera
// #define USMIN_PALM 300  //thumb hacia dentro

#define SERVOMAX_palm 163   //thumb hacia fuera
#define SERVOMIN_palm 61  //thumb hacia dentro

#define STEP_SERVOID_11 0.566667




// Deprecated Code:

// /**
//  * SERVOMIN_ values corresponding to the servoid given:
//  * 
//  * SERVOMINS_Fingers[servoid] = SERVOMIN_finger_X
//  * 
//  * Inner servos:
//  * thumb_B == servoid=0; index_B == servoid=1; middle_B == servoid=2; ring_B == servoid=3; pinky_B == servoid=4
//  * 
//  * Outer servos:
//  * thumb_A == servoid=5; index_A == servoid=6; middle_A == servoid=7; ring_A == servoid=8; pinky_A == servoid=9
//  * 
// */
// uint16_t SERVOMINS_Fingers[10] = {SERVOMIN_thumb_B, SERVOMIN_index_B, SERVOMIN_middle_B, SERVOMIN_ring_B, SERVOMIN_pinky_B, SERVOMIN_thumb_A, SERVOMIN_index_A, SERVOMIN_middle_A, SERVOMIN_ring_A, SERVOMIN_pinky_A};

// /**
//  * SERVOMAX_ values corresponding to the servoid given:
//  * 
//  * SERVOMAXS_Fingers[servoid] = SERVOMAX_finger_X
//  * 
//  * Inner servos:
//  * thumb_B == servoid=0; index_B == servoid=1; middle_B == servoid=2; ring_B == servoid=3; pinky_B == servoid=4
//  * 
//  * Outer servos:
//  * thumb_A == servoid=5; index_A == servoid=6; middle_A == servoid=7; ring_A == servoid=8; pinky_A == servoid=9
//  * 
// */
// uint16_t SERVOMAXS_Fingers[10] = {SERVOMAX_thumb_B, SERVOMAX_index_B, SERVOMAX_middle_B, SERVOMAX_ring_B, SERVOMAX_pinky_B, SERVOMAX_thumb_A, SERVOMAX_index_A, SERVOMAX_middle_A, SERVOMAX_ring_A, SERVOMAX_pinky_A};
// /**
//  * Returns the pulselen needed to turn a servo into X degree position
//  * 
//  *  pulselen_from_degrees[servoid][degrees]
//  * 
// */
// uint16_t pulselen_from_degrees[10][181];

//   for (i = 0; i < 181; i++){
//     for(servoid=0; servoid<10; servoid++){
//       pulselen_from_degrees[servoid][i] = map(i,0,180,SERVOMINS_Fingers[servoid],SERVOMAXS_Fingers[servoid]);
//     }
//   }
