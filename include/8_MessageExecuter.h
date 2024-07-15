

void MessageExecuter(byte msjCount, String *msges)
{

    commandFeedbackMsj = "";
    sendDebugData(0, "Komut icra ediliyor \n\r");

    for (byte s = 2; s < msjCount; s++)
    {

        // Hardware Test
        if (msges[s].indexOf(CmdHWTest) != -1)
        {
            // digitalWrite(BUZZER_PIN, HIGH);
            // BuzzerBip(1000, 1, 1, HIGH);
            TestHW();
            commandFeedbackMsj = commandFeedbackMsj + "Hardware Tested";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        // Bluetooth
        if (msges[s].indexOf("BTON") != -1)
        {
            
            bluetuteState = ON;
            commandFeedbackMsj = commandFeedbackMsj + "Bluetooth On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("BTOFF") != -1)
        {
            
            bluetuteState = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "Bluetooth Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        // Bluetooth
        if (msges[s].indexOf("WIFION") != -1)
        {
            
            wifiState = ON;
            commandFeedbackMsj = commandFeedbackMsj + "Wifi On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("WIFIOFF") != -1)
        {
            
            wifiState = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "Wifi Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        // Buzzer
        if (msges[s].indexOf("BUZON") != -1)
        {
            // digitalWrite(BUZZER_PIN, HIGH);
            // BuzzerBip(1000, 1, 1, HIGH);
            BuzON;
            buzzerState = ON;
            commandFeedbackMsj = commandFeedbackMsj + "Buzzer On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("BUZOFF") != -1)
        {
            // digitalWrite(BUZZER_PIN, LOW);
            // BuzzerBip(1, 1000, 1, LOW);
            BuzOFF;
            buzzerState = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "Buzzer Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        // Relay1
        if (msges[s].indexOf("RL1ON") != -1)
        {
            RL1ON;
            realy1State = ON;
            commandFeedbackMsj = commandFeedbackMsj + "RL1 On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("RL1OFF") != -1)
        {
            RL1OFF;
            realy1State = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "RL1 Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        if (msges[s].indexOf("RL1STATE") != -1)
        {
            CmdRespons(String(realy1State));
            commandFeedbackMsj = commandFeedbackMsj + "Relay1 States";
        }

        // Relay 2
        if (msges[s].indexOf("RL2ON") != -1)
        {
            RL2ON;
            realy2State = ON;
            commandFeedbackMsj = commandFeedbackMsj + "RL2 On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("RL2OFF") != -1)
        {
            RL2OFF;
            realy2State = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "RL1 Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        if (msges[s].indexOf("RL2STATE") != -1)
        {
            CmdRespons(String(realy2State));
            commandFeedbackMsj = commandFeedbackMsj + "Relay2 States";
        }

        // Relay 3
        if (msges[s].indexOf("RL3ON") != -1)
        {
            RL3ON;
            realy3State = ON;
            commandFeedbackMsj = commandFeedbackMsj + "RL3 On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("RL2OFF") != -1)
        {
            RL3OFF;
            realy3State = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "RL3 Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        if (msges[s].indexOf("RL3STATE") != -1)
        {
            CmdRespons(String(realy3State));
            commandFeedbackMsj = commandFeedbackMsj + "Relay3 States";
        }

        // Relay 4
        if (msges[s].indexOf("RL4ON") != -1)
        {
            RL4ON;
            realy4State = ON;
            commandFeedbackMsj = commandFeedbackMsj + "RL4 On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("RL4OFF") != -1)
        {
            RL4OFF;
            realy4State = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "RL4 Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        if (msges[s].indexOf("RL4STATE") != -1)
        {
            CmdRespons(String(realy4State));
            commandFeedbackMsj = commandFeedbackMsj + "Relay4 States";
        }
        // Relay 4
        if (msges[s].indexOf("DEBUGON") != -1)
        {
            debugStatus = ON;
            commandFeedbackMsj = commandFeedbackMsj + "Debug On";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("DEBUGOFF") != -1)
        {
            debugStatus = OFF;
            commandFeedbackMsj = commandFeedbackMsj + "Debug Off";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("GETRLSSTATES") != -1)
        {
            CmdRespons("RLSSTATES" + String(realy1State) + "," + String(realy2State) + "," + String(realy3State) + "," + String(realy4State) + "," + String(buzzerState));
            commandFeedbackMsj = commandFeedbackMsj + "Relays States";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (msges[s].indexOf("SETRLSSTATES") != -1)
        {
            digitalWrite(Relay1Pin, msges[s + 1].toInt());
            digitalWrite(Relay2Pin, msges[s + 2].toInt());
            digitalWrite(Relay3Pin, msges[s + 3].toInt());
            digitalWrite(Relay4Pin, msges[s + 4].toInt());
            delay(25);
            commandFeedbackMsj = commandFeedbackMsj + "Set Relays States";
            // vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        delay(5);
    }
     delay(25);
}

void CmdRespons(String respons)
{
    Rs485TxModeAktif;
    Rs485_Serial.print("$," + String(CmdDeviceID) + respons + ",#");
    // Rs485_Serial.print("$," + respons + ",#");
    Rs485RxModeAktif;
    delay(25);
}