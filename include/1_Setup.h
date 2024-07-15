
void setupSb()
{

    pinMode(Relay1Pin, OUTPUT);
    pinMode(Relay2Pin, OUTPUT);
    pinMode(Relay3Pin, OUTPUT);
    pinMode(Relay4Pin, OUTPUT);

    pinMode(BuzzerPin, OUTPUT);
    pinMode(SysLedPin, OUTPUT);

    pinMode(IOintPin, INPUT);

    pinMode(Rs485DePin, OUTPUT);

    digitalWrite(Relay1Pin, HIGH);
    digitalWrite(Relay2Pin, HIGH);
    digitalWrite(Relay3Pin, HIGH);
    digitalWrite(Relay4Pin, HIGH);
    digitalWrite(Rs485DePin, HIGH);
    digitalWrite(BuzzerPin, HIGH);
    digitalWrite(SysLedPin, HIGH);

    digitalWrite(Rs485DePin, LOW);

    Rs485_Serial.begin(9600, SERIAL_8N1, Rs485RxPin, Rs485TxPin, false, 512);
    // Rs485_Serial.begin(1200, SERIAL_6N2, Rs485RxPin, Rs485TxPin, true, 512);
    Debug_Serial.begin(115200, SERIAL_8N1);

    delay(100);
    digitalWrite(BuzzerPin, LOW);

    Serial.println(SfVersion);

#if bluetuteOnOff
    String StrID = "MRMD_RLM" + getChipId();
    SerialBT.begin(StrID); // Bluetooth device name
    SerialBT.setPin(BtPassword);
    SerialBT.enableSSP();
    // SerialBT.begin("MORMED_BT"); //Bluetooth device name
    Debug_Serial.println("The device started, now you can pair it with bluetooth!");
    Debug_Serial.println("BT Connection ID = " + StrID);
    SerialBT.println(SfVersion);
#endif
}