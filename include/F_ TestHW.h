
void TestHW()
{

  BuzzerBip(100, 100, 3, LOW);
  // put your main code here, to run repeatedly:
  digitalWrite(Relay1Pin, LOW);
  digitalWrite(SysLedPin, LOW);
  Debug_Serial.println("Relay1 LED ON...");
  delay(1000);
  digitalWrite(Relay1Pin, HIGH);
  digitalWrite(SysLedPin, HIGH);
  Debug_Serial.println("Relay1 LED OFF...");
  delay(1000);

  Rs485_Serial.println("Relay1 Test OK...");
  Debug_Serial.println("Relay1 Test OK...");

  digitalWrite(Relay2Pin, LOW);
  digitalWrite(SysLedPin, LOW);
  Debug_Serial.println("Relay2 LED ON...");
  delay(1000);
  digitalWrite(Relay2Pin, HIGH);
  digitalWrite(SysLedPin, HIGH);
  Debug_Serial.println("Relay2 LED OFF...");
  delay(1000);

  Rs485_Serial.println("Relay2 Test OK...");
  Debug_Serial.println("Relay2 Test OK...");

  digitalWrite(Relay3Pin, LOW);
  digitalWrite(SysLedPin, LOW);
  Debug_Serial.println("Relay3 LED ON...");
  delay(1000);
  digitalWrite(Relay3Pin, HIGH);
  digitalWrite(SysLedPin, HIGH);
  Debug_Serial.println("Relay3 LED OFF...");
  delay(1000);

  Rs485_Serial.println("Relay3 Test OK...");
  Debug_Serial.println("Relay3 Test OK...");

  digitalWrite(Relay4Pin, LOW);
  digitalWrite(SysLedPin, LOW);
  Debug_Serial.println("Relay4 LED ON...");
  delay(1000);
  digitalWrite(Relay4Pin, HIGH);
  digitalWrite(SysLedPin, HIGH);
  Debug_Serial.println("Relay4 LED OFF...");
  delay(1000);

  Rs485_Serial.println("Relay4 Test OK...");
  Debug_Serial.println("Relay4 Test OK...");

  for (byte i = 0; i < 3; i++)
  {
    digitalWrite(SysLedPin, LOW);
    digitalWrite(BuzzerPin, HIGH);
    delay(150);
    digitalWrite(SysLedPin, HIGH);
    digitalWrite(BuzzerPin, LOW);
  }
}