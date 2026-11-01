void setup() {
  Serial.begin(9600);

  delay(1000);

  // put your setup code here, to run once:
  resetPrinter();

  delay(2000);

  printTestPaper();


}

void loop() {
  // put your main code here, to run repeatedly:

}

void resetPrinter(){
  Serial.write(0x1B);
  Serial.write(0x40); 
}

void printTestPaper(){
  Serial.write(0x12);
  Serial.write(0x54);
}