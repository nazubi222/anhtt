#include<Keypad.h>
 
const byte rows = 4; //số hàng
const byte columns = 3; //số cột
 
char key = 0;

int in[6] = {};
int pass[6] = {2,7,0,9,5,6}; //Pass mặc định là 270956;
int i=0;

//Định nghĩa các giá trị trả về
char keys[rows][columns] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'},
};
 
byte rowPins[rows] = {5, 6, 7, 8}; //Cách nối chân với Arduino
byte columnPins[columns] = {9, 10, 11};
 
//cài đặt thư viện keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);
void setup() {
  Serial.begin(9600);//bật serial, baudrate 9600
   Serial.println("Enter password");
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
      Serial.println('*');
      in[i] = (int)key - 48;
      i++;
      }
    if(i == 6) check();
    if(key == '*') clear(); // Bấm * để xóa màn hình
    if(key == '#') check(); // Bấm # để mở khóa
  }
  delay(100);
}

void clear(){
  for(i=0; i<6;i++)
    in[i]=0;
  Serial.println("Deleted");
  i=0;
}

void check(){
  int kt = 1;
  for(i=0; i<6;i++)
    if(in[i] != pass[i]) kt=0;
  if (kt == 1) Serial.println("Unlocked");
  if (kt == 0) Serial.println("Wrong password");
  i=0;
}
