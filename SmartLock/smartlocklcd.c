#include<Keypad.h>
#include <EEPROM.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32,16,2); 
const byte rows = 4; //số hàng
const byte columns = 4; //số cột
 
char key = 0;

int in[6] = {};
int pass[6] = {2,7,0,9,5,6}; //Pass mặc định là 270956;
int i=0;
int passwordMode;
//Định nghĩa các giá trị trả về
char keys[rows][columns] =
{
  {'1', '2', '3','A'},
  {'4', '5', '6','B'},
  {'7', '8', '9','C'},
  {'*', '0', '#','D'},
};
 
byte rowPins[rows] = {5, 6, 7, 8}; //Cách nối chân với Arduino
byte columnPins[columns] = {9, 10, 11,12};
int changePassButton = 12;
 
//cài đặt thư viện keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);
void setup() {
  lcd.init();                    
  lcd.backlight();
  lcd.setCursor(2,0);
  passwordMode = 0;
  pinMode(13, OUTPUT);
  pinMode(changePassButton, INPUT_PULLUP);
  //for(i = 0; i < 6; i++) pass[i] = EEPROM.read(i); 	
  lcd.print("Enter password");
  lcd.setCursor(0,1);
}

void loop() {  
  char temp = keypad.getKey();
 
  if ((int)keypad.getState() ==  PRESSED) {
    if (temp != 0) {
      key = temp;
    }
  }
  if ((int)keypad.getState() ==  RELEASED) {
    //Xuất lên Máy tính để xem kết quả
  if(key>=48 && key<=57){
    lcd.print('*');
    in[i] = (int)key - 48;
    i++;
    }
  if(key == '*') clear(); // Bấm * để xóa màn hình
  if(key == '#')
    {
    //lcd.print(check);
    if(passwordMode == 0)        
       {
      if(check() == 1) 
          {lcd.print("Unlocked");
           digitalWrite(13, HIGH);
           delay(5000);
           digitalWrite(13, LOW);
           clear();
          }
      else {
          lcd.print("Wrong password");
          delay(1000);
          clear();}
       }
    if(passwordMode == 1) changePassword();   
    }
    if(key == 'A') 
      if(check() == 1)
        if(passwordMode == 0){
	   delay(500);
           lcd.clear();
           lcd.print(" Password mode");
           delay(1000);
           lcd.clear();
           lcd.print("Enter new password");
           lcd.setCursor(0,1);
           passwordMode = 1;
           i=0;
           }
        else{
          delay(500);
          lcd.clear();
          lcd.print("Exit");
          clear();
          passwordMode = 0;
          i=0;
        }
      else {lcd.print("Wrong password"); 
            i=0;
           }
  }
  
  delay(100);
}

void clear(){
  for(i=0; i<6;i++)
    in[i]=0;
  lcd.clear();
  lcd.print("Enter password");
  lcd.setCursor(0,1);
  i=0;
}

int check(){
  int kt = 1;
  for(i=0; i<6;i++)
    if(in[i] != pass[i]) kt=0;
  i=0;
  lcd.clear();
  return kt;
}

void changePassword(){
  for(int i = 0; i < 6; i++){
    EEPROM.write(i, in[i]);
    pass[i] = EEPROM.read(i);
    }
  lcd.clear();
  lcd.print("Password changed");
  delay(1000);
  clear();
  passwordMode = 0;
}  
