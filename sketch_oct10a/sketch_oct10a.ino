const int TrigPin = 2;
const int EchoPin = 3;
const int led = 13;
float cm;
void setup()
{
  Serial.begin(9600); 
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT);

} 
void loop() 
{ 
  digitalWrite(TrigPin, LOW); 
  //低高低电平发一个短时间脉冲去TrigPin 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW);
  cm = pulseIn(EchoPin, HIGH)  / 58.0; 
  //将回波时间换算成cm 
  cm = (int(cm * 100.0))  / 100.0; //保留两位小数

  int mode = int(cm) % 10;
  if (0 == mode || 9 == mode) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  Serial.print(cm); 
  Serial.print("cm");
  Serial.print("    mode : ");
  Serial.print(mode); 
  Serial.println(); 
  delay(100);
}

