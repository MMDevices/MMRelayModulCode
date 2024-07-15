#include <Arduino.h>
#include "WiFi.h"

// #include "freertos/task.h"
// #include "freertos/FreeRTOS.h"

#include "EEPROM.h"

#include "0_VarAndDec.h"

// SemaphoreHandle_t buffSemaphore;
// SemaphoreHandle_t xSerialSemaphore;

#define bluetuteOnOff 0 // BT fonksiyonu derlenmesi için 1 BT fonksiyonsuz derlemek için 0

void setup();
String getChipId();
void BuzzerBip(int highPeriod, int lowPeriod, byte repiedCount, bool lastState);
void OneSecTick();
void SysLedIndicator();
void CmdRespons(String respons);
void TestHW();
void MessageExecuter(byte msjCount, String msges[25]);
void sendDebugData(byte CodeStateID, String DbgMsj);
void serialEventSB();
void TestHW();
void parsRxMesaj(String strRx);
void TestFonc();
#if bluetuteOnOff
void bluetoothReadWrite()
#endif

#include "1_Setup.h"

#include "F_ TestHW.h"

#include "3_MessageParse.h"
#include "4_Buzzer.h"
#include "5_GetChipID.h"
#include "6_EEpromReadWrite.h"
#include "7_SystemTick.h"
#include "8_MessageExecuter.h"
#include "2_SerialReadEvent.h"

#include "Z_DebugLog.h"
#include "W_TestFonction.h"

#if bluetuteOnOff
#include "H_BlueToothConnect.h"
#endif

    // TaskHandle_t TaskHandle_TaskBlink;

    void setup()
{
  // put your setup code here, to run once:
  setupSb();

  BuzzerBip(100, 100, 1, LOW);

  //  xTaskCreatePinnedToCore(
  //      TaskBlink, "TaskBlink" // A name just for humans
  //     ,
  //     2048 // This stack size can be checked & adjusted by reading the Stack Highwater
  //    ,
  ///    NULL, 15 // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
  //    ,
  //    &TaskHandle_TaskBlink, 1);

  delay(500);
}

void loop()
{

  SysLedIndicator();

  serialEventSB();   // RS485 de mesaj varsa alıp komutları işler
 
#if bluetuteOnOff
  bluetoothReadWrite();  // BT ta mesaj varsa alıp komutları işler
#endif

  delay(10);
}