

void parsRxMesaj(String strRx)
{

  // if (GsmMesajReceived == true) {

  // if (state)
  //{
  // state = false;

  for (int i = 0; i < strRx.length(); i++)
  {
    char c = strRx[i];

    // delay(1500);

    switch (c)
    {
    case '$':
      count = 0;
      data[count] = data[count] + c;
      // count++;

      // Serial.println("$...");

      break;

    case ',':
      count++;
      data[count] = "";
      // Serial.println(",");
      // Serial.println(data[1]);
      break;

    case '#':
      data[count] = data[count] + c;
      msjParsOK = 1;

      break;

    default:
      data[count] = data[count] + c;
      // Serial.print(".");
      break;
    }
  }
  //}

  //}
  sendDebugData(0, "parsRxMesaj =" + strRx + "\n\r");
  sendDebugData(0, "RxMesaj count =" + String(count) + "\n\r");
  for (size_t i = 0; i < count; i++)
  {
    sendDebugData(0, "data[" + String(i) + "] =" + data[i] + "\n\r");
  }

  if ((data[0] == "$") && (data[1] == CmdDeviceID) && (msjParsOK == 1))
  {
    MessageExecuter(count, data); // Alınan komut mesajlarını icra eder
    msjParsOK = 0;
    data[0] = "";
  }

  //
  /*
        if (data[s].indexOf("TESTSMS") != -1)
        {
          sensSMSsb("05337116630", "Bu alinan bir Test Mesajina Cevap icin gonderilmistir.");
        }

        if (data[s].indexOf("UPDATE") != -1)
        {
          updatePr();
        }

        if (data[s].indexOf("BUZSTATE") != -1)
        {
          SellectBuzStatus = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Buzzer Sate Set..";
        }

        if (data[s].indexOf("BUZON") != -1)
        {
          // digitalWrite(BUZZER_PIN, HIGH);
          BuzzerBip(1000, 1, 1, HIGH);
          commandFeedbackMsj = commandFeedbackMsj + "Buzzer On";
          vTaskDelay(2000 / portTICK_PERIOD_MS);
        }

        if (data[s].indexOf("BUZOFF") != -1)
        {
          // digitalWrite(BUZZER_PIN, LOW);
          BuzzerBip(1, 1000, 1, LOW);
          commandFeedbackMsj = commandFeedbackMsj + "Buzzer Off";
          vTaskDelay(500 / portTICK_PERIOD_MS);
        }

        if (data[s].indexOf("GPSON") != -1)
        {
          SellectGPSTask = 1;
          commandFeedbackMsj = commandFeedbackMsj + "GPS On";
        }

        if (data[s].indexOf("GPSOFF") != -1)
        {
          SellectGPSTask = 0;
          commandFeedbackMsj = commandFeedbackMsj + "GPS Off";
        }

        if (data[s].indexOf("GSMON") != -1)
        {
          SellectGSMTask = 1;
          commandFeedbackMsj = commandFeedbackMsj + "GSM On";
        }

        if (data[s].indexOf("GSMOFF") != -1)
        {
          SellectGSMTask = 0;
          commandFeedbackMsj = commandFeedbackMsj + "GSM Off";
        }

        if (data[s].indexOf("CANON") != -1)
        {
          SellectCanTask = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Can On";
          // Init CAN Module
          ESP32Can.CANInit();
        }

        if (data[s].indexOf("CANOFF") != -1)
        {
          SellectCanTask = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Can Off";
          CAN_stop();
        }

        if (data[s].indexOf("SOFTCANFILTERON") != -1)
        {
          SellectSoftCanFilter = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can Filter On";
        }

        if (data[s].indexOf("SOFTCANFILTEROFF") != -1)
        {
          SellectSoftCanFilter = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can Filter Off";
        }

        if (data[s].indexOf("SOFTCANFILTERINVORTON") != -1)
        {
          SellectSoftCanFilterInvert = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can Filter Inverter On";
        }

        if (data[s].indexOf("SOFTCANFILTERINVORTOFF") != -1)
        {
          SellectSoftCanFilterInvert = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can Filter Inverter Off";
        }

        if (data[s].indexOf("SOFTCANFILTERID1") != -1)
        {
          CanFilterID1 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID1..";
        }

        if (data[s].indexOf("SOFTCANFILTERID2") != -1)
        {
          CanFilterID2 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID2..";
        }

        if (data[s].indexOf("SOFTCANFILTERID3") != -1)
        {
          CanFilterID3 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID3..";
        }

        if (data[s].indexOf("SOFTCANFILTERID4") != -1)
        {
          CanFilterID4 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID4..";
        }

        if (data[s].indexOf("SOFTCANFILTERID5") != -1)
        {
          CanFilterID5 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID5..";
        }

        if (data[s].indexOf("SOFTCANFILTERID6") != -1)
        {
          CanFilterID6 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID6..";
        }

        if (data[s].indexOf("SOFTCANFILTERID7") != -1)
        {
          CanFilterID7 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID7..";
        }

        if (data[s].indexOf("SOFTCANFILTERID8") != -1)
        {
          CanFilterID8 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID8..";
        }

        if (data[s].indexOf("SOFTCANFILTERID9") != -1)
        {
          CanFilterID9 = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterID9..";
        }

        if (data[s].indexOf("SOFTCANFILTERIDA") != -1)
        {
          CanFilterIDA = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Soft Can FilterIDA..";
        }

        if (data[s].indexOf("HWCANFILTERON") != -1)
        {
          SellectHWCanFilter = 1;
          commandFeedbackMsj = commandFeedbackMsj + "HW Can Filter On";
        }

        if (data[s].indexOf("HWCANFILTEROFF") != -1)
        {
          SellectHWCanFilter = 0;
          commandFeedbackMsj = commandFeedbackMsj + "HW Can Filter Off";
        }

        if (data[s].indexOf("HWCANCONFIGPARAM") != -1)
        {
          CAN_filter_t p_filter;
          byte pfFM = data[s + 1].toInt();
          if (pfFM == 1)
          {
            p_filter.FM = Single_Mode;
          }
          else
          {
            p_filter.FM = Dual_Mode;
          }
          // p_filter.FM = data[s+1].toInt();
          p_filter.ACR0 = data[s + 2].toInt();
          p_filter.ACR1 = data[s + 3].toInt();
          p_filter.ACR2 = data[s + 4].toInt();
          p_filter.ACR3 = data[s + 5].toInt();

          p_filter.AMR0 = data[s + 6].toInt();
          p_filter.AMR1 = data[s + 7].toInt();
          p_filter.AMR2 = data[s + 8].toInt();
          ;
          p_filter.AMR3 = data[s + 9].toInt();
          ;
          ESP32Can.CANConfigFilter(&p_filter);
          commandFeedbackMsj = commandFeedbackMsj + "HW Can Filter Conf. Param. OK";
        }

        if (data[s].indexOf("CANTXPACKAGESIZE") != -1)
        {
          CanTxPackageSize = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Can Tx Package Size..";
        }

        if (data[s].indexOf("TRACSRVON") != -1)
        {
          SellectTrackerServer = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Tracker Server On";
        }

        if (data[s].indexOf("TRACSRVOFF") != -1)
        {
          SellectTrackerServer = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Tracker Server Off";
        }

        if (data[s].indexOf("CMDSRVON") != -1)
        {
          SellectCmdServer = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Command Server On";
        }

        if (data[s].indexOf("CMDSRVOFF") != -1)
        {
          SellectCmdServer = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Commad Server Off";
        }

        if (data[s].indexOf("TACON") != -1)
        {
          SellectTakoTask = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Taco On";
          K_LineSerial.begin(K_LineBaud, SoftSerialConf, KlineRxPin, KlineTxPin, false, 512);
        }

        if (data[s].indexOf("TACOFF") != -1)
        {
          SellectTakoTask = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Taco Off";
          K_LineSerial.stopListening();
        }

        if (data[s].indexOf("TACOTYPE") != -1)
        {
          TakoType = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Taco Type changed ..." + TakoType;
        }

        if (data[s].indexOf("TACOBAUD") != -1)
        {
          K_LineBaud = data[s + 1].toInt();
          K_LineSerial.stopListening();
          vTaskDelay(500 / portTICK_PERIOD_MS);
          K_LineSerial.begin(K_LineBaud, SoftSerialConf, KlineRxPin, KlineTxPin, false, 512);
          commandFeedbackMsj = commandFeedbackMsj + "Tako baud changed.." + K_LineBaud;
        }

        if (data[s].indexOf("TACOCONFIG") != -1)
        {

          if (data[s + 1].indexOf("SWSERIAL_8N1") != -1)
          {
            SoftSerialConf = SWSERIAL_8N1;
            // TakoConfig = 1;
          }
          if (data[s + 1].indexOf("SWSERIAL_8N2") != -1)
          {
            SoftSerialConf = SWSERIAL_8N2;
            // TakoConfig = 2;
          }
          if (data[s + 1].indexOf("SWSERIAL_8E1") != -1)
          {
            SoftSerialConf = SWSERIAL_8E1;
            // TakoConfig = 3;
          }
          if (data[s + 1].indexOf("SWSERIAL_8E2") != -1)
          {
            SoftSerialConf = SWSERIAL_8E2;
            // TakoConfig = 4;
            // TakoConfig = editBaud;
          }
          if (data[s + 1].indexOf("SWSERIAL_8O1") != -1)
          {
            SoftSerialConf = SWSERIAL_8O1;
            // TakoConfig = 5;
            // TakoConfig = editBaud;
          }
          if (data[s + 1].indexOf("SWSERIAL_8O2") != -1)
          {
            SoftSerialConf = SWSERIAL_8O2;
            // TakoConfig = 6;
            // TakoConfig = editBaud;
          }
          TakoConfig = SoftSerialConf;
          K_LineSerial.stopListening();
          vTaskDelay(500 / portTICK_PERIOD_MS);
          K_LineSerial.begin(K_LineBaud, SoftSerialConf, KlineRxPin, KlineTxPin, false, SoftSerBuffSize);
          // K_LineSerial.enableRx();
          commandFeedbackMsj = commandFeedbackMsj + "Tako config changed.." + TakoConfig;
        }

        if (data[s].indexOf("ADCREADON") != -1)
        {
          SellectAdcReadTask = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Adc Read On";
        }

        if (data[s].indexOf("ADCREADOFF") != -1)
        {
          SellectAdcReadTask = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Adc Read  Off";
        }

        if (data[s].indexOf("INFSRVON") != -1)
        {
          SellectInfoServer = 1;
          commandFeedbackMsj = commandFeedbackMsj + "Info Server On";
        }

        if (data[s].indexOf("INFSRVOFF") != -1)
        {
          SellectInfoServer = 0;
          commandFeedbackMsj = commandFeedbackMsj + "Info Server Off";
        }

        if (data[s].indexOf("RESETSETIGS") != -1)
        {
          commandFeedbackMsj = commandFeedbackMsj + "Reset defalt. Restart MCU.";
          EEPROM.writeByte(EepromAdresIlkKurulum, 0); // İlk kurulum yapıldı şeklinde kayıt atıyor
          EEPROM.commit();
          vTaskDelay(20000 / portTICK_PERIOD_MS);

          // esp.reset();
          // esp_restart();
          ESP.restart();
        }

        if (data[s].indexOf("RESTARTMCU") != -1)
        {
          commandFeedbackMsj = commandFeedbackMsj + "Restart MCU.";
          vTaskDelay(20000 / portTICK_PERIOD_MS);
          // esp.reset();

          // esp_restart();
          // CAN_stop();

          BuzzerBip(150, 150, 10, LOW);
          // esp_restart();
          // system_restart();

          ESP.restart();
        }

        if (data[s].indexOf("RESTARTMODEM") != -1)
        {
          commandFeedbackMsj = commandFeedbackMsj + "Restarting Modem..";
          vTaskDelay(20000 / portTICK_PERIOD_MS);
          digitalWrite(MODEM_RST, LOW);
          vTaskDelay(1000 / portTICK_PERIOD_MS);
          digitalWrite(MODEM_RST, HIGH);
        }

        if (data[s].indexOf("CANSPEED") != -1)
        {
          if (data[s + 1].indexOf("100KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_100KBPS;
            CanSpeed = 100;
          }
          if (data[s + 1].indexOf("125KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_125KBPS;
            CanSpeed = 125;
          }
          if (data[s + 1].indexOf("200KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_200KBPS;
            CanSpeed = 200;
          }
          if (data[s + 1].indexOf("250KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_250KBPS;
            CanSpeed = 250;
          }
          if (data[s + 1].indexOf("500KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_500KBPS;
            CanSpeed = 500;
          }
          if (data[s + 1].indexOf("800KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_800KBPS;
            CanSpeed = 800;
          }
          if (data[s + 1].indexOf("1000KBPS") != -1)
          {
            CAN_cfg.speed = CAN_SPEED_1000KBPS;
            CanSpeed = 1000;
          }
          commandFeedbackMsj = commandFeedbackMsj + "Can Speed Set..";
        }

        if (data[s].indexOf("SETPCISSRVIP") != -1)
        {
          data[s + 1].toCharArray(pcisServerIP, data[s + 1].length() + 1);
          commandFeedbackMsj = commandFeedbackMsj + "PCIS Srv IP Set..";
        }

        if (data[s].indexOf("SETPCISSRVPORT") != -1)
        {
          pcisServerport = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "PCIS Srv PORT Set..";
        }

        if (data[s].indexOf("SETRCKSRVIP") != -1)
        {
          data[s + 1].toCharArray(trackerServerIP, data[s + 1].length() + 1);
          // Debug_Serial.println(trackerServerIP);
          commandFeedbackMsj = commandFeedbackMsj + "TRACK Srv IP Set..";
        }

        if (data[s].indexOf("SETRCKSRVPORT") != -1)
        {
          trackerServerport = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "TRACK Srv PORT Set..";
        }

          //  if (data[s].indexOf("SETTRACKINTERVAL") != -1)
           // {
           //   trackServerInterval = data[s + 1].toInt();
           //   commandFeedbackMsj = commandFeedbackMsj + "TRACK Interval Set..";
           // }

        if (data[s].indexOf("SETRCKSENTENCEINTERVAL") != -1)
        {
          setTrackSentenceInterval = data[s + 1].toInt();
          commandFeedbackMsj = commandFeedbackMsj + "Track Sentence Interval Set..";
        }

        if (data[s].indexOf("SETAPN") != -1)
        {
          data[s + 1].toCharArray(apn, data[s + 1].length());
          commandFeedbackMsj = commandFeedbackMsj + "APN Set..";
        }

        if (data[s].indexOf("INFOSETIGS") != -1)
        {
          commandFeedbackMsj = commandFeedbackMsj + "Seting Info..\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "Version=" + Version + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "BuzState=" + SellectBuzStatus + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanTask=" + SellectCanTask + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanSpeed=" + CanSpeed + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "SoftCanFilter=" + SellectSoftCanFilter + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "SoftCanFilterInvert=" + SellectSoftCanFilterInvert + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID1=" + CanFilterID1 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID2=" + CanFilterID2 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID3=" + CanFilterID3 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID4=" + CanFilterID4 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID5=" + CanFilterID5 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID6=" + CanFilterID6 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID7=" + CanFilterID7 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID8=" + CanFilterID8 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFID9=" + CanFilterID9 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanFIDA=" + CanFilterIDA + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "HWCanFilter=" + SellectHWCanFilter + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "HWCanFilterMode=" + pfFM + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACR0=" + pfACR0 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACR1=" + pfACR1 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACR2=" + pfACR2 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACR3=" + pfACR3 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACM0=" + pfAMR0 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACM1=" + pfAMR0 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACM2=" + pfAMR0 + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CanHWpfACM3=" + pfAMR0 + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "CanTxPackageSize=" + CanTxPackageSize + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "GSMTask=" + SellectGSMTask + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "apn=" + apn + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "TakoTask=" + SellectTakoTask + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "TakoBaud=" + K_LineBaud + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "TakoConfig=" + TakoConfig + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "TakoType=" + TakoType + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "GPSTask=" + SellectGPSTask + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "AdcReadTask=" + SellectAdcReadTask + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "BlinkTask=" + SellectBlinkTask + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "CmdTask=" + SellectCmdServer + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CmdServerIP=" + CommandServerIP + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "CmdServerport=" + CommandServerport + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "InfoServerTask=" + SellectInfoServer + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "pcisServerIP=" + pcisServerIP + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "pcisServerport=" + pcisServerport + "\n\r";

          commandFeedbackMsj = commandFeedbackMsj + "TrackerTask=" + SellectTrackerServer + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "trackerServerIP=" + trackerServerIP + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "trackerServerport=" + trackerServerport + "\n\r";
          commandFeedbackMsj = commandFeedbackMsj + "trackerSentenceInterval=" + setTrackSentenceInterval + "\n\r";
          String snx = local.toString();
          commandFeedbackMsj = commandFeedbackMsj + "LocalIP=" + snx + "\n\r";
          // commandFeedbackMsj = commandFeedbackMsj + "CommandServerIP=" + CommandServerIP + "\n";
          // commandFeedbackMsj = commandFeedbackMsj + "CommandServerport=" + CommandServerport + "\n";
        }
        if (data[s].indexOf("SAVESETINGS") != -1)
        {
          commandFeedbackMsj = commandFeedbackMsj + "Save Setings ";
          EepromWriteParam();
        }
        data[s] = "";
      }

      Debug_Serial.println(commandFeedbackMsj);
      GsmRxMesaj = "";
      GsmMesajReceived = false;
      vTaskDelay(100 / portTICK_PERIOD_MS);

      */
}
