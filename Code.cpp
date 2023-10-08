
#include <LiquidCrystal.h>   
#include <Keypad.h>


int a=0, b=0, c=0, d=0;
int var=0; 
int C1=1,C2=4,C3=7,C4=0;
char f='*';  
int times=0,incorrect=0; 
int notice=3; 
const byte rows = 4; 
const byte column = 4; 
char key[rows][column] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinRows[rows] = {7, 6, 5, 4}; 
byte pinColumn[column] = {3, 2, A1, A0}; 
Keypad keypad = Keypad( makeKeymap(key), pinRows, pinColumn, rows, column);
LiquidCrystal lcd(8,9,10,11,12,13); 
void setup(){
  lcd.begin(16,2); 
  pinMode(A2,OUTPUT); 
  pinMode(A3,OUTPUT); 
  lcd.setCursor(4,1),lcd.print("GROUP 1");
  delay(5000);
  lcd.clear();
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
}
  
void loop(){
  
  char key = keypad.getKey();
  if (key){
   lcd.setCursor(6+var,1);
   lcd.print(key),lcd.setCursor(6+var,1),lcd.print(f);
   key=key-48; 
   var++; 
   switch(var){
    case 1:
    a=key; 
    break;
    case 2:
    b=key; 
    break;
    case 3:
    c=key; 
    break;
    case 4:
    d=key; 
   delay(100);
  if(a==C1 && b==C2 && c==C3 && d==C4)
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Password");
    lcd.setCursor(5,1);
    lcd.print("Valid");
    digitalWrite(A2,HIGH);
    delay(1000); 
    lcd.clear();
    lcd.print("Welcome Group 1");
    digitalWrite(A3,LOW);
    delay(5000);
    digitalWrite(A3,HIGH);
    }
  else
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Password");
    lcd.setCursor(4,1);
    lcd.print("Invalid");
    digitalWrite(A2,LOW); 
    delay(1000); 
    lcd.clear();
    digitalWrite(A3,HIGH); 
    }




  if(a==C1 && b==C2 && c==C3 && d==C4){
      times=0;
      notice=3;
    }
  else{
      times ++; 
      notice --;
      lcd.setCursor(2,0);
      lcd.print("REST: "); 
      lcd.setCursor(13,0);
      lcd.print(notice); 
      lcd.setCursor(2,1);
      lcd.print("OPPORTUNITY");
      delay(1000);
       if(notice==0){
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("ALARM");
          lcd.setCursor(4,1);
          lcd.print("ACTIVATED");
        }
      delay(300);lcd.clear();
      }
  unsigned long start = millis();
   while(times>=3 && millis() - start < 10000){ 
        lcd.setCursor(1,0),lcd.print("POLICE ALERT");
        lcd.setCursor(4,1),lcd.print("INTRUDERS");
        digitalWrite(A2,HIGH); 
        delay(500);
        lcd.clear();
        digitalWrite(A2,LOW);
        delay(500);
     }
    

   var=0;
   lcd.clear();

  break;
  }
  
 }
 if(!key){
  
  lcd.setCursor(0,0);
  lcd.print("Insert Password");}


  delay(2);
}
