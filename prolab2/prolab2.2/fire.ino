int relay = 4 ;// define relay pin
int flamedigital = 9; // define the flame sensor digital pin
int flameanalog = A3; // define the flame sensor analog pin
int buzzer = 11; //define buzzer pin
int val ; // define numeric variable val
float sensor; //define floating variable sensor

void setup ()
{
  pinMode (flamedigital, INPUT) ;// input interface defines the flame sensor
  pinMode (flameanalog, INPUT) ;// input interface defines the flame sensor
  pinMode (relay, OUTPUT); //output interface defines the relay
  pinMode (buzzer, OUTPUT); //output interface defines the buzzer
}

void loop ()
{
  sensor = analogRead(flameanalog); //read flameanalog value and assigne it to sensor variable


  val = digitalRead (flamedigital) ;// read flamedigital value and assigne it to val variable
  if (val == HIGH) // When the flame sensor detects a signal relay is on and buzzer sound (void alarm)
  {
    alarm();
    digitalWrite (relay, HIGH); //close the relay circuit

  }
  else
  {
    digitalWrite (relay, LOW); //open the relay circuit
  }
  delay(1000);
}

void alarm()  {
  tone(buzzer, 400, 500); //the buzzer emit sound at 400 MHz for 500 millis
  delay(500); //wait 500 millis
  tone(buzzer, 650, 500); //the buzzer emit sound at 650 MHz for 500 millis
  delay(500); //wait 500 millis
}
