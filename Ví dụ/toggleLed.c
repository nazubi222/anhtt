int LED = 13;
int button = 7;
int ledon = 0 ;
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  int stbutton = digitalRead(button);
  int stled = digitalRead(LED);
  if (stbutton == 1 && stled == ledon ){
  digitalWrite(LED, !stled);
  delay(500);
  ledon = !ledon;
  }
}
