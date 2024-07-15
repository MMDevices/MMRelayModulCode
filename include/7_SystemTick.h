
void OneSecTick()
{

    // readFrqTemp(); //Soğutma su sıcaklığını okur

    KontrolSayac = KontrolSayac + 1;

    if (KontrolSayac > 60)
    {

        KontrolSayac = 0;
        // ZamaniOku();
        // GecerlilikKontrol();
    }
    /*
    if (GecerlilikSuresi == 1) {

    //BuzzerBip();
                            if ((Aktif_SayfaNo == 0) || (Aktif_SayfaNo == 1)){
                              SendTextFont("Kiralama Suresi Doldu",300,200,Red);
                               }
                            if ((StartStopStatus == 1) && ((Aktif_SayfaNo == 2) || (Aktif_SayfaNo == 3))){
                            SendBaytes(LazerOFF_Picture_Cut,19);
                              StartStopStatus = 0;
                               }
                              }
            */

    // if (ERROR_GENEL==1) {

    //BuzzerBip();
    //                       if ((Aktif_SayfaNo == 2) || (Aktif_SayfaNo == 3)){
    //                          if (BlinkStatus==0) {BlinkStatus = 1; SendBaytes(ErrorON_Picture_Cut,19);} else {BlinkStatus = 0; SendBaytes(ErrorOFF_Picture_Cut,19);}
    //                           SendTextFont("Er=" + String(ERROR_CODE),145,348,Yellow);
    // SendTextFont(String(ERROR_CODE),160,345,Yellow);
    //                          }
    //
    //                       if ((StartStopStatus == 1) && ((Aktif_SayfaNo == 2) || (Aktif_SayfaNo == 3))){
    //                           SendBaytes(LazerOFF_Picture_Cut,19);
    //                          StartStopStatus = 0;
    ///                          }

    //                       }else {//digitalWrite(BUZZER_PIN, HIGH);
    //                             digitalWrite(BUZZER_PIN, LOW);  // Yeni kırmızı bord için
    //                               }

    // atım sayısı kayıt süre sayacını işletir
    // if (AtimYapildimi == 1) {sayacKayitSuresi = sayacKayitSuresi + 1;}
    // 1 saniyede bir sıcaklık bilgisini ekranda göster
    // if ((Aktif_SayfaNo == 2) || (Aktif_SayfaNo == 3)) {
    //                                                   if (ERROR_OSC_TEMP == 0) {
    //                                                                             SendTextFont(String(SSuyu_Mevcut_Sicakligi),165,415,DefaultColour);
    //                                                                            }
    //                                                                             else {
    //                                                                           SendTextFont(String(SSuyu_Mevcut_Sicakligi),165,415,Red);
    //                                                                            }

    //                                                   if (ERROR_WATER_FLOW == 1) {
    // SendTextFont("X",75,315,Red);
    //                                                                            SendBaytes(SusistemiOFF_Picture_Cut,19);
    //                                                                            } // Soğutma musluk üzerine çarpı işaret durumu eklenecek
    //  else {
    // SendTextFont("X",435,405,Red);
    //  }
}


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void SysLedIndicator()
{

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        // save the last time you blinked the LED

        // toggle state of LED
        // ledState = !ledState;
       
        if (ledState == true)
        {
            ledState = false;
            digitalWrite(SysLedPin, LOW);
            delay(5);
        }
        else
        {
            ledState = true;
            digitalWrite(SysLedPin, HIGH);
            delay(5);
        }
        // control LED arccoding to the toggled state
        digitalWrite(SysLedPin, ledState);
        // delay(1000);                       // wait for a second
       
       

       previousMillis = currentMillis;

        // Saniyede bir periyodik işler bölümünü çağırır.
        OneSecTick();
        /*
           digitalWrite(BUZZER_PIN, HIGH);
         digitalWrite(SYS_LED_PIN, HIGH);
         delay(100);
         digitalWrite(BUZZER_PIN, LOW);
         digitalWrite(SYS_LED_PIN, LOW);
         */
    }
}
