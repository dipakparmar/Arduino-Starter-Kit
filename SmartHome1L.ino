/*
 * Basic Smart Home Logic for Arduino
 */

#include <IRremote.h>

int RECV_PIN = 11;
int RELAY_PIN = 4;
int Led1 = 5;
int Led2 = 6;
int Led3 = 16;

IRrecv irrecv(RECV_PIN);
decode_results results;

// Dumps out the decode_results structure.
// Call this after IRrecv::decode()
// void * to work around compiler issue
//void dump(void *v) {
//  decode_results *results = (decode_results *)v


void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led3, OUTPUT);
    Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

int on1 = 0, on2 = 0, on3 = 0;
String s1;
unsigned long last = millis();

void loop() {
  if (irrecv.decode(&results)) {
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    if (millis() - last > 250) {
      s1 = String(results.value, HEX);
      Serial.println(s1);
      if(s1.equals("1fe50af"))
        {
        on1 = !on1;
        digitalWrite(RELAY_PIN, on1 ? HIGH : LOW);
        }
      else if(s1.equals("1fed827") )
        {
         on2 = !on2;
         digitalWrite(Led1, on2 ? HIGH : LOW);
        }

       else if(s1.equals("1fef807") )
        {
         on3 = !on3;
         digitalWrite(Led2, on3 ? HIGH : LOW);
        }
       else if(s1.equals("1fe48b7"))
       {
         on1 = !on1;
         digitalWrite(RELAY_PIN, on1 ? HIGH : LOW);
         on2 = !on2;
         digitalWrite(Led1, on2 ? HIGH : LOW);
         on3 = !on3;
         digitalWrite(Led2, on3 ? HIGH : LOW);
       }

       else if(s1.equals("1fe58a7"))
       {
          Serial.println("Welcome to the Smart Home");
          Serial.println(" \n Enter the 3 Digit Pin to unlock the Door\n ");
         
       }
          
          
            
       
      
    }
    last = millis();      
    irrecv.resume(); // Receive the next value
  }
}
