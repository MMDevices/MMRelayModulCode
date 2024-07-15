

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

void bluetoothReadWrite()
{

  int n = 0;
  RxData = "";
  if (bluetuteOnOff)
  {
    n = 0;
    while (SerialBT.available())
    {
      // Serial.println("y");
      //  get the new byte:

      char inbyte1 = SerialBT.read();

      Serial.write(inbyte1);
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
}