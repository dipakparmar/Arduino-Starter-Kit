void setup() {
 pinMode(3, OUTPUT); 
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
delay(10);

}
