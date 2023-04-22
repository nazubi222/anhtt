int in1=7;
int in2=6;
int in3=5;
int in4=4;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
     tien();
    delay(5000);
    dung();
    delay(5000);
    lui();
    delay(5000);
    dung();
    delay(5000);
}

void tien(){
  analogWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }

 void lui(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }

 void dung(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
