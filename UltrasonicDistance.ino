#define trigPin 13
#define echoPin 12

int LedB = 4, LedG= 5, LedR = 6, Motor = 7;

void setup() {
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LedB, OUTPUT);
pinMode(LedG, OUTPUT);
pinMode(LedR, OUTPUT);
pinMode(Motor, OUTPUT);
}
bool stat=0;
void loop() {

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;

  if (distance <= 10)
  {
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, HIGH);
    digitalWrite(LedR, HIGH);
    digitalWrite(Motor, LOW);
    stat=0;
  }
  
  else if (distance > 10 && distance <=20 )
  {
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, HIGH);
    digitalWrite(LedR, LOW);
    if(stat)
      digitalWrite(Motor, HIGH);
    else
      digitalWrite(Motor, LOW);
  }  

else if (distance > 20 && distance <=40 )
  {
    digitalWrite(LedB, HIGH);
    digitalWrite(LedG, LOW);
    digitalWrite(LedR, LOW);

    if(stat)
      digitalWrite(Motor, HIGH);
    else
      digitalWrite(Motor, LOW);
  }

  else
  {
    digitalWrite(LedB, LOW);
    digitalWrite(LedG, LOW);
    digitalWrite(LedR, LOW);
    if(stat)
      digitalWrite(Motor, HIGH);
    else
      digitalWrite(Motor, LOW);
    
  }

 if (distance >= 200 || distance <=0 )
 {
  Serial.println("Out of Range");
 }
 else {
  Serial.print(distance);
  Serial.println(" cm");
       }
 delay(300);
 }
