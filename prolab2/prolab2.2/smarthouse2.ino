#include "LiquidCrystal.h" 
#include "Keypad.h" 

//keypad
int keypadLedGreen = 31;
int keypadLedRed  =32 ;

const byte satir = 4; //four rows
const byte sutun = 3; //three columns
char keys[satir][sutun] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
byte satir_pinleri[satir] = {27,28,29,30} ;
byte sutun_pinleri[sutun] = {24,25,26} ;
char password[4]={'4','1','4','1'};
char input_password[4];
Keypad keypad = Keypad( makeKeymap(keys), satir_pinleri, sutun_pinleri, satir, sutun );

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);     
//global değişkenleri tanımla
float temp;    
//hareket global
 int pirled = 13;
// #define pirsensor A1
 int pirsensor = 53 ;
int pir_sensorval = 0 ;

//fire global
int fire_Buzzer = 11; // Use buzzer for alert 
// #define fire_FlamePin A0// This is for input pin
int fire_FlamePin = 52 ;
int fire_Flame = LOW; // HIGH when FLAME Exposed
 
//fonksiyonların setup kısmını burada bir fonksiyon ile yaz, karışmasın ve clean code olsun.
//gerekliyse de parametre ekle fonksiyonlara.


void lcd_setup(){
  Serial.begin(9600) ;
  analogReference(INTERNAL1V1);
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("   Made by UMUT and ÖMER ");      
  lcd.setCursor(0, 1);
  lcd.print("       ");
  delay (100);
  lcd.clear();   
  }
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



void keypad_setup(){
  //input_password.reserve(32);
   pinMode(keypadLedGreen, OUTPUT);
   pinMode(keypadLedRed, OUTPUT);
   Serial.begin(9600);
  
  }




void setup() {
  // put your setup code here, to run once:
  fire_alarm_setup();
  pir_sensor_setup();
  keypad_setup();
  lcd_setup();

}


void lcd_loop(){
  lcd.clear();
   temp = analogRead(A1);                                                    //temp = temp * 0.48828125;  //etmp=temp*(5.0/1023.0)*100;
 float  onetemp =temp*(5000.0/1023.0);;
 float  lasttemp = onetemp / 10.0 ;
  lcd.print("Sıcaklık: ");
  lcd.print(lasttemp);
  lcd.println("*C");
delay(300);
 
  }
void fire_alarm_loop(){
  //pin,led tanımla
   fire_Flame = digitalRead(fire_FlamePin);
 if (fire_Flame == HIGH)
 {
  Serial.println("Yangın tespit edildi.");
  digitalWrite(fire_Buzzer, HIGH);
  delay(2000);
  digitalWrite(fire_Buzzer, LOW);
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
   delay(1500);
   digitalWrite(pirled, LOW);
  }
  else {
    digitalWrite(pirled, LOW);
  // delay(500);
  }
  }


int x=0;
void keypad_loop(){
  char key = keypad.getKey();
  if(key){
    input_password[x]=key;
    x++;
    if(x==4){
      Check();
    }
    if(x>4){
      x=0;
    }
    delay(10);
  }
 }
int Check(){
  if(input_password[0] == password[0] && input_password[1] == password[1] && input_password[2] == password[2] && input_password[3] == password[3]){
    digitalWrite(keypadLedGreen,HIGH);
    delay(1000);
  }
  else{
      digitalWrite(keypadLedRed,HIGH);
      delay(1000);
  }
}
  

void loop() {
  // put your main code here, to run repeatedly:
  keypad_loop();
  fire_alarm_loop();
  pir_sensor_loop();
  lcd_loop();

}
