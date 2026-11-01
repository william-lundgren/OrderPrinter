void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);

  delay(1000);

  // put your setup code here, to run once:
  resetPrinter();

  delay(2000);

  printTestPaper();

    for (byte n = 1; n <= 4; n++) {
        Serial.print("Status ");
        Serial.print(n);
        Serial.print(": ");

        Serial1.write(0x10); // DLE
        Serial1.write(0x04); // EOT
        Serial1.write(n);

        // Wait for printer response
        unsigned long start = millis();

   while (millis() - start < 500) {
              byte response = printer.read();

              Serial.print("0x");
              if (response < 16) Serial.print("0");
              Serial.println(response, HEX);

              break;
        }

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