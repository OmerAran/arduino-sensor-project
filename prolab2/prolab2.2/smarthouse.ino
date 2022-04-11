

//global değişkenleri tanımla

//hareket global
 int pirled = 13;
int pirsensor = 2;
int pir_sensorval = 0 ;

//fire global
int fire_Buzzer = 11; // Use buzzer for alert 
int fire_FlamePin = 1; // This is for input pin
int fire_Flame = HIGH; // HIGH when FLAME Exposed
 
//fonksiyonların setup kısmını burada bir fonksiyon ile yaz, karışmasın ve clean code olsun.
//gerekliyse de parametre ekle fonksiyonlara.

void fire_alarm_setup(){
  
  //pin,led tanımla
  pinMode(fire_Buzzer, OUTPUT);
 pinMode(fire_FlamePin, INPUT);
 Serial.begin(9600);
  }

void pir_sensor_setup(){
  //sensor,pin,inp,out tanımla
  pinMode(pirled, OUTPUT);
  pinMode(pirsensor, INPUT);
  Serial.begin(9600);
  }

void temperature_and_lcd_setup(){
  }

void keypad_setup(){
  }




void setup() {
  // put your setup code here, to run once:
  fire_alarm_setup();
  pir_sensor_setup();
  temperature_and_lcd_setup();
  keypad_setup();

}


void fire_alarm_loop(){
  //pin,led tanımla
   fire_Flame = digitalRead(fire_FlamePin);
 if (fire_Flame== HIGH)
 {
 Serial.println("Yangın tespit edildi.");
 digitalWrite(fire_Buzzer, HIGH);
 }
 else
 {
 Serial.println("Yangın yok.");
 digitalWrite(fire_Buzzer, LOW);
 }
  }

void pir_sensor_loop(){
  //sensor,pin,inp,out tanımla
    pir_sensorval = digitalRead(pirsensor);
  Serial.println(pir_sensorval);
  
  if (pir_sensorval == HIGH) {
    digitalWrite(pirled, HIGH);
   // delay(500);
  }
  else {
    digitalWrite(pirled, LOW);
  // delay(500);
  }
  }

void temperature_and_lcd_loop(){
  
  }

void keypad_loop(){
  }


void loop() {
  // put your main code here, to run repeatedly:

  fire_alarm_loop();
  pir_sensor_loop();
  temperature_and_lcd_loop();
  keypad_loop();

}
