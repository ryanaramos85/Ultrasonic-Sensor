int TriggerPIN1 = 9;                  //Assigns TriggerPIN1 as pin 9
int EchoPIN1 = 8;                     //Assigns EchoPIN1 as pin 8
int TriggerPIN2 = 6;                  //Assigns TriggerPIN2 as pin 6
int EchoPIN2 = 12;                    //Assigns EchoPIN2 as pin 12
int TriggerPIN3 = 5;                  //Assigns TriggerPIN3 as pin 5
int EchoPIN3 = 13;                    //Assigns EchoPIN3 as pin 13
int distance1=0;                      //Initializes distance1 as 0
int distance2=0;                      //Initializes distance2 as 0
int distance3=0;                      //Initializes distance3 as 0
void setup(){
  pinMode(TriggerPIN1,OUTPUT);        //Sets pin 9 as OUTPUT
  pinMode(EchoPIN1,INPUT);            //Sets pin 8 as INPUT
  pinMode(TriggerPIN2,OUTPUT);        //Sets pin 6 as OUTPUT
  pinMode(EchoPIN2,INPUT);            //Sets pin 12 as INPUT
  pinMode(EchoPIN3,INPUT);            //Sets pin 13 as INPUT
  pinMode(TriggerPIN3,OUTPUT);        //Sets pin 5 as OUTPUT
  

  Serial.begin(9600);                 //Starts serial communication
  }

void loop(){  
  digitalWrite(TriggerPIN1,LOW);      //Sets TriggerPIN1 LOW for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,HIGH);     //Sets TriggerPIN1 HIGH for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,LOW);      //Sets TriggerPIN1 LOW

  long timedelay = pulseIn(EchoPIN1,HIGH);      //Reads EchoPIN1 and returns sound wave travel time in microseconds
  int newdistance1 = 0.0343 * (timedelay/2);    //Calculates the reading to give the distance in cm under newdistance1

  delayMicroseconds(2);               //Waits for 2 microseconds

  digitalWrite(TriggerPIN2,LOW);      //Sets TriggerPIN2 LOW for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,HIGH);     //Sets TriggerPIN2 HIGH for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,LOW);      //Sets TriggerPIN1 LOW

  long td = pulseIn(EchoPIN2,HIGH);           //Reads EchoPIN1 and returns sound wave travel time in microseconds
  int newdistance2 = 0.0343 * (td/2);         //Calculates the reading to give the distance in cm under newdistance2

  delayMicroseconds(2);              //Waits for 2 microseconds

  digitalWrite(TriggerPIN3,LOW);     //Sets TriggerPIN2 LOW for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(TriggerPIN3,HIGH);    //Sets TriggerPIN2 HIGH for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(TriggerPIN3,LOW);     //Sets TriggerPIN1 LOW

  long delay = pulseIn(EchoPIN3,HIGH);      //Reads EchoPIN1 and returns sound wave travel time in microseconds
  int newdistance3 = 0.0343 * (delay/2);    //Calculates the reading to give the distance in cm under newdistance2

  if (newdistance1 >= distance1+2 || newdistance1 <= distance1-2 || newdistance2 >= distance2+2 || newdistance2 <= distance2-2 ||newdistance3 >= distance3+2 || newdistance3 <= distance3-2)
  { // If any of the readings from the sensors +2/-2 range of the previous reading then execute step
  distance1 = newdistance1;                     //Change distance1 value to newdistance1's value
  distance2 = newdistance2;                     //Change distance2 value to newdistance2's value
  distance3 = newdistance3;                     //Change distance3 value to newdistance3's value
  Serial.println("New Measurment Detected");    //Print "New Measurement Detected" to serial monitor and start new line
  Serial.print("||Sensor 1 (cm): ");            //Print "||Sensor 1 (cm): " to serial monitor
  Serial.print(distance1);                      //Print distance1 value to serial monitor
  Serial.print(" || Sensor 2 (cm) : ");         //Print " || Sensor 2 (cm) : " to serial monitor
  Serial.print(distance2);                      //Print distance2 value to serial monitor
  Serial.print(" || Sensor 3 (cm) : ");         //Print " || Sensor 3 (cm) : " to serial monitor
  Serial.print(distance3);                      //Print distance3 value to serial monitor
  Serial.println("||");                         //Print "||" to serial monitor and start new line
  }

  }