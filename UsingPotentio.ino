void setup() {
 pinMode(3, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 Serial.begin(9600);
 
}

int i=0,val=0,newval=0;

void loop() {
val = analogRead(A0);
Serial.println("Control Value=");
Serial.println(val);
newval = map(val,0,1024,0,255);                                                                                                                                                                                   ;
analogWrite(3, newval);
Serial.println("Red New Control Value=");
Serial.println(newval);
analogWrite(5, newval);
Serial.println("Green New Control Value=");
Serial.println(newval);
delay(1000);
analogWrite(6, newval);
Serial.println("White New Control Value=");
Serial.println(newval);

}
