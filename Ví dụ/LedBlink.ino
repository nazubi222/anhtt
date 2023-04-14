
void setup() {
  pinMode(13, OUTPUT); //Khai báo chân 13 xuất tín hiệu
  digitalWrite(13, LOW);// Cài đặt điện thế cho chân 13 ban đầu là 0   
}


void loop() {
  digitalWrite(13, HIGH); // Bật đèn led 
  delay(1000); // Đợi 1 giây                     
  digitalWrite(13, LOW); // Tắt đèn led  
  delay(1000); //đợi 1 giây                     
}