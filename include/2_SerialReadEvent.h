
void serialEventSB()
{
    // Serial.println("x");
    int n = 0;
    RxData = "";
    Rs485RxModeAktif;
    while (Rs485_Serial.available())
    {

        char inbyte1 = Rs485_Serial.read();

#if bluetuteOnOff
        SerialBT.write(inbyte1);
#endif
        if (inbyte1 == '$')
        {
            n = 0;
            RxData = "";
        }

        RxData = RxData + inbyte1;
        n = n + 1;

        if (n > 20)
        {
            n = 0;
        }

        // if the incoming character is a newline, set a flag so the main loop can
        // do something about it:
        if ((inbyte1 == '#') && (RxData[0] == '$'))
        {
            inbyte1 = ' ';
            RxData = RxData + inbyte1;
            parsRxMesaj(RxData);
            RxData = "";
            delay(25);
            // n=0;
            stringComplete = true;
        }
    }

}