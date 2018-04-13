int ledRed=5, ledGreen=6, ledWhite=7;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledWhite, OUTPUT);
  Serial.println("Welcome to the Arduino Workshop");
  Serial.println("\n Enter Choice \n 1-Red \n 2-Green \n 3-White \n 4-Turn On All Lights \n 5-Turn Off All Lights");
}

int choice;
bool on1=0,on2=0,on3=0;

void loop() 

  {

    if(Serial.available())
      {

       choice=Serial.parseInt();
       Serial.println("\n You had Selected \t");
       if(choice==1)
       {
        Serial.print("Red");
       }
       if(choice==2)
       {
        Serial.print("Green");
       }
       if(choice==3)
       {
        Serial.print("White");
       }

       if(choice==4)
       {
        Serial.print("Turn On all the lights");
       }

       if(choice==5)
       {
        Serial.print("Turn Off All the Lights");
       }

      switch(choice){
      case 1:
          on1=!on1;
          if(on1)
           {
            digitalWrite(ledRed, HIGH);
           }
          else
           {
          digitalWrite(ledRed, LOW);
            }
          break;

       case 2:
          on2=!on2;
          if(on2)
          {
          digitalWrite(ledGreen, HIGH);
          }
          else
          {
          digitalWrite(ledGreen, LOW);
          }
          break;

      case 3:
          on3=!on3;
          if(on3)
          {
          digitalWrite(ledWhite, HIGH);
          }
          else
          {
          digitalWrite(ledWhite, LOW);
          }
          break;
        
        case 4:
          on1=!on1;
          on2=!on2;
          on3=!on3;
          if(on1,on2,on3)
          {
          digitalWrite(ledRed, HIGH);
          digitalWrite(ledGreen, HIGH);
          digitalWrite(ledWhite, HIGH);
          }
                
          break;
          
          case 5:
          digitalWrite(ledRed, LOW);
          digitalWrite(ledGreen, LOW);
          digitalWrite(ledWhite, LOW);
          break;
       }
     } 
  
}
