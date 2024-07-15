String SfVersion = "RLV1.0.0 ESP32221223";
String BtPassword = "1234";

#define Relay1Pin 21
#define Relay2Pin 22
#define Relay3Pin 25
#define Relay4Pin 23

#define BuzzerPin 5
#define SysLedPin 13

#define IOintPin 19

//RS485 Pins
#define Rs485RxPin 17
#define Rs485TxPin 16
#define Rs485DePin 18

// Serial Port definations
#define Debug_Serial Serial
#define Rs485_Serial Serial1

byte SellectBuzStatus = 1;
byte KontrolSayac = 0;

unsigned long previousMillis = 0;
const long interval = 1000;
bool ledState = false;

#define ON 1
#define OFF 0

#define CmdDeviceID "RLM01" // Bu parametrede RLM= Role modülü olduğunu, 01= Modülün versiyon bilgisini gösterir

#define CmdModuleNumber "01" // Kaç numaralı modül olduğunu gösterir

#define CmdHWTest "HWTest"  // Test fonksiyonunu çalıştırı
#define CmdRLStatus "GETRLSSTATES" // Tüm rolelerin durum bilgilerini gönderir
#define CmdRLStatus "SETRLSSTATES" // Tüm rolelerin durum bilgilerini sıra ile Set eder
#define CmdRLINFO "RLINFO"
#define CmdEko  "EKO"   // Gönderielen mesaja cevap istendiğini gösterir

#define CmdBTON "BTON"
#define CmdBTON "BTOFF"
byte bluetuteState = OFF;

#define CmdWifiON "WIFION"
#define CmdWifiON "WIFIOFF"
#define wifiOnOff 0   // Wifi fonksiyonu derlenmesi için 1 BT fonksiyonsuz derlemek için 0
byte wifiState = OFF;

#define CmdRL1ON "RL1ON" // Role 1 i ON yapar
#define RL1ON digitalWrite(Relay1Pin, LOW);
#define CmdRL1OFF "RL1OFF"
#define RL1OFF digitalWrite(Relay1Pin, HIGH);
#define CmdRL1State "RL1STATE"
#define CmdRL1BlinkON "RL1BLKON"
#define CmdRL1BlinkOFF "RL1BLKOFF"
#define CmdRL1BlinkInterval "RL1BLKINTVAL"
unsigned long RL1BlinkInterval = 1000;
byte realy1State = OFF;

#define CmdRL2ON "RL2ON"
#define RL2ON digitalWrite(Relay2Pin, LOW);
#define CmdRL2OFF "RL2OFF"
#define RL2OFF digitalWrite(Relay2Pin, HIGH);
#define CmdRL2State "RL2STATE"
#define CmdRL2BlinkON "RL1BLKON"
#define CmdRL2BlinkOFF "RL1BLKOFF"
#define CmdRL2BlinkInterval "RL1BLKINTVAL"
unsigned long RL2BlinkInterval = 1000;
byte realy2State = OFF;

#define CmdRL3ON "RL3ON"
#define RL3ON digitalWrite(Relay3Pin, LOW);
#define CmdRL3OFF "RL3OFF"
#define RL3OFF digitalWrite(Relay3Pin, HIGH);
#define CmdRL3State "RL3STATE"
#define CmdRL3BlinkON "RL1BLKON"
#define CmdRL3BlinkOFF "RL1BLKOFF"
#define CmdRL3BlinkInterval "RL1BLKINTVAL"
unsigned long RL3BlinkInterval = 1000;
byte realy3State = OFF;

#define CmdRL4ON "RL4ON"
#define RL4ON digitalWrite(Relay4Pin, LOW);
#define CmdRL4OFF "RL4OFF"
#define RL4OFF digitalWrite(Relay4Pin, HIGH);
#define CmdRL4State "RL4STATE"
#define CmdRL4BlinkON "RL1BLKON"
#define CmdRL4BlinkOFF "RL1BLKOFF"
#define CmdRL4BlinkInterval "RL1BLKINTVAL"
unsigned long RL4BlinkInterval = 1000;
byte realy4State = OFF;

#define CmdBuzON "BUZON"
#define BuzON digitalWrite(BuzzerPin, HIGH);
#define CmdBuzOFF "BUZOFF"
#define BuzOFF digitalWrite(BuzzerPin, LOW);
#define CmdBuzState "BUZSTATE"
#define CmdBuzBlinkON "BUZBLKON"
#define CmdBuzBlinkOFF "BUZBLKOFF"
#define CmdBuzBlinkInterval "BUZBLKINTVAL"
unsigned long BUZBlinkInterval = 1000;
byte buzzerState = OFF;

#define CmdSysLedON "SYSLEDON"
#define SysLedON digitalWrite(SysLedPin, LOW);
#define CmdSysLedOFF "SYSLEDOFF"
#define SysLedOFF digitalWrite(SysLedPin, HIGH);
#define CmdSysLedState "SYSLEDSTATE"
#define CmdSysLedBlinkON "SYSLEDBLKON"
#define CmdSysLedBlinkOFF "SYSLEDBLKOFF"
#define CmdSysLedBlinkInterval "SYSLEDBLKINTVAL"
unsigned long SysLedBlinkInterval = 1000;
byte SysLedState = OFF;

#define CmdDebugON "DEBUGON"
#define CmdDebugOFF "DEBUGOFF"
byte debugStatus = ON;

#define Rs485TxModeAktif digitalWrite(SysLedPin, HIGH);
#define Rs485RxModeAktif digitalWrite(SysLedPin, LOW);


byte count = 0;
String commandFeedbackMsj = "";
String data[25] = {"", "", "", "", "", ""};
char c;
byte msjParsOK = 0;
String RxData = "";

bool stringComplete = false;  // whether the string is complete