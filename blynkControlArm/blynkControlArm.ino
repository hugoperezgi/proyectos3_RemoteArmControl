
#define BLYNK_TEMPLATE_ID "TMPL4GIdzmfuk"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "GSbPUeA72UzF_-Eky6Nz4_90dt50Hx2u"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// #define BLYNK_PRINT Serial // Blynk debugger

#define SERVO_FREQ 50 

char ssid[] = "Hugoo";
char pass[] = "12345678";

Adafruit_PWMServoDriveAXpwm = Adafruit_PWMServoDriver(); 

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


uint8_t servoid = 0;
uint8_t i = 0;
uint8_t j = 0;


/**
 * 0º == Fully extended
 * 180º == Fully contracted
*/
uint8_t currentPosition[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
  pwm.setPWM(11, 0, SERVOMAX_palm);
  currentPosition[10]=0;
}


void pointIndex(){
  i=0;
  while (i<180){
    if(currentPosition[0] < 180){currentPosition[0]++;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}

      if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}

    if(currentPosition[2] < 180){currentPosition[2]++;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
    if(currentPosition[3] < 180){currentPosition[3]++;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
    if(currentPosition[4] < 180){currentPosition[4]++;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
    if(currentPosition[5] < 180){currentPosition[5]++;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
    if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
    if(currentPosition[7] < 180){currentPosition[7]++;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
    if(currentPosition[8] < 180){currentPosition[8]++;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
    if(currentPosition[9] < 180){currentPosition[9]++;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}
    if(currentPosition[10] < 180){currentPosition[10]++;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+SERVOMIN_palm);}
    
    i++;
  }
  delay(25);
}

void openHand(){
    i=0;
    while (i<180){
      if(currentPosition[0] > 0){currentPosition[0]--;pwm.setPWM(0, 0, -currentPosition[0]*STEP_SERVOID_0 + SERVOMAX_thumb_B);}
      if(currentPosition[1] > 0){currentPosition[1]--;pwm.setPWM(1, 0, -currentPosition[1]*STEP_SERVOID_1 + SERVOMAX_index_B);}
      if(currentPosition[2] > 0){currentPosition[2]--;pwm.setPWM(2, 0, -currentPosition[2]*STEP_SERVOID_2 + SERVOMAX_middle_B);}
      if(currentPosition[3] > 0){currentPosition[3]--;pwm.setPWM(3, 0, -currentPosition[3]*STEP_SERVOID_3 + SERVOMAX_ring_B);}
      if(currentPosition[4] > 0){currentPosition[4]--;pwm.setPWM(4, 0, -currentPosition[4]*STEP_SERVOID_4 + SERVOMAX_pinky_B);}
      if(currentPosition[5] > 0){currentPosition[5]--;pwm.setPWM(5, 0, -currentPosition[5]*STEP_SERVOID_5 + SERVOMAX_thumb_A);}
      if(currentPosition[6] > 0){currentPosition[6]--;pwm.setPWM(6, 0, -currentPosition[6]*STEP_SERVOID_6 + SERVOMAX_index_A);}
      if(currentPosition[7] > 0){currentPosition[7]--;pwm.setPWM(7, 0, -currentPosition[7]*STEP_SERVOID_7 + SERVOMAX_middle_A);}
      if(currentPosition[8] > 0){currentPosition[8]--;pwm.setPWM(8, 0, -currentPosition[8]*STEP_SERVOID_8 + SERVOMAX_ring_A);}
      if(currentPosition[9] > 0){currentPosition[9]--;pwm.setPWM(9, 0, -currentPosition[9]*STEP_SERVOID_9 + SERVOMAX_pinky_A);}      
      if(currentPosition[10] > 0){currentPosition[10]--;pwm.setPWM(11, 0, currentPosition[10]*STEP_SERVOID_11+ SERVOMIN_palm);}
      i++;
    }
}
BLYNK_WRITE(V2){
  if(param.asInt()==1){
    pointIndex();
  }else{
    openHand();
  }
}

BLYNK_WRITE(V9){
  setUpServoPositions();
}

void setup(){
  // Debug console
  Serial.begin(9600);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop(){
  Blynk.run();
}