const int LM = 2, LK = 3, LH = 4,
RM = 5, RK = 6, RH = 7,
EM = 8, EK = 9, EH =  10;

const int timeTemp = 6000, timeChange = 1000;

void trafficLight(int i, int RED, int YEL, int GRE){
  if (i == 1){
    digitalWrite(RED, 0); digitalWrite(YEL, 0); digitalWrite(GRE, 1);
  }

  else if(i == 2){
    digitalWrite(RED, 1); digitalWrite(YEL, 0); digitalWrite(GRE, 0);
  }
}

void trafficReset(int RED1, int GRE1, int RED2, int GRE2, int RED3, int GRE3){
  digitalWrite(RED1, 0); digitalWrite(GRE1, 0); digitalWrite(RED2, 0); digitalWrite(GRE2, 0); digitalWrite(RED3, 0); digitalWrite(GRE3, 0);
}

void trafficChange(int YEL1, int YEL2, int YEL3){
  digitalWrite(YEL1, 1); digitalWrite(YEL2, 1); digitalWrite(YEL3, 1);
}

void trafficInterval(){
  trafficReset(LM, LH, RM, RH, EM, EH); trafficChange(LK, RK, EK); delay(timeChange);
}

void setup() {
  for(int i = 1; i <= 10; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  trafficLight(1 ,LM, LK, LH);
  trafficLight(2, RM, RK, RH);
  trafficLight(2, EM, EK, EH);
  delay(timeTemp);

  trafficInterval();

  trafficLight(2 ,LM, LK, LH);
  trafficLight(1, RM, RK, RH);
  trafficLight(2, EM, EK, EH);
  delay(timeTemp);

  trafficInterval();

  trafficLight(2 ,LM, LK, LH);
  trafficLight(2, RM, RK, RH);
  trafficLight(1, EM, EK, EH);
  delay(timeTemp);
  
  trafficInterval();
}