
   //ForLoop sketch

void setup() {
  Serial.begin(9600);
}

void loop(){
  for(int i=1; i > 0; i++)
  {
    Serial.println(i);
    delay(1000);
  }
}
