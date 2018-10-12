int trigPin = 9;
int echoPin = 10;
int led = 7;
const int buzzer = 11;
const int motorPin = 5; 

void setup() {
  Serial.begin(9600); 
   pinMode(led, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(motorPin, OUTPUT);
   
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;  
  Serial.print(distance);
  Serial.println("CM");
  delay(100);
  if((distance<=40))
  {
 
    digitalWrite(motorPin, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
}
   else if(distance>40)
 {    
      digitalWrite(motorPin, LOW);
      digitalWrite(buzzer, LOW);
       digitalWrite(led, LOW);
   }
}
