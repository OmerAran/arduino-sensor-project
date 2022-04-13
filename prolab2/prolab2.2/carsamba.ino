#include "LiquidCrystal.h" 
#include "Keypad.h" 

//global değişkenler

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
byte satir_pinleri[satir] = {24,25,26,27} ;
byte sutun_pinleri[sutun] = {28,29,30} ;
char* password = "4141";
char password_dene;
int sayac=0 ;
Keypad keypad = Keypad( makeKeymap(keys), satir_pinleri, sutun_pinleri, satir, sutun );

//lcd and pir
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);     

float temp;    
 int pirled = 13;
 int pirsensor = 53 ;
 int pir_sensorval = 0 ;

//flame 
int fire_Buzzer = 11; 
int fire_FlamePin = 52 ;
int fire_Flame = LOW; 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600) ;
  analogReference(INTERNAL1V1);
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("   Made by UMUT and OMER ");      
  lcd.setCursor(0, 1);
  lcd.print("       ");
  delay (100);
  lcd.clear();

      pinMode(fire_Buzzer, OUTPUT);
 pinMode(fire_FlamePin, INPUT);
 Serial.begin(9600);

 pinMode(pirled, OUTPUT);
  pinMode(pirsensor, INPUT);
  Serial.begin(9600);

   pinMode(keypadLedGreen, OUTPUT);
   pinMode(keypadLedRed, OUTPUT);
   Serial.begin(9600);

   
}

void loop() {
  // put your main code here, to run repeatedly:

     temp = analogRead(A1);                                                    //temp = temp * 0.48828125;  //etmp=temp*(5.0/1023.0)*100;
     temp  =temp*9,31; 
  lcd.print("Sıcaklık: ");
  lcd.print(temp);
  lcd.println("*C");
delay(300);
lcd.clear();


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
  
char key = keypad.getKey();
  if(password_dene==password[sayac]){
    ++sayac ;
    if(sayac==4){
      digitalWrite(keypadLedGreen,HIGH);
      delay(1000);
      digitalWrite(keypadLedGreen,LOW);
      sayac = 0 ;
      }
      else{
        digitalWrite(keypadLedRed,HIGH);
      delay(1000);
       digitalWrite(keypadLedRed,LOW);
        }
      
    }
    
  
}




