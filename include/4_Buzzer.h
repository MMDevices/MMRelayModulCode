

void BuzzerBip(int highPeriod, int lowPeriod, byte repiedCount, bool lastState)
{

  if (SellectBuzStatus == 1)
  {
    for (size_t b = 0; b < repiedCount; b++)
    {
      digitalWrite(BuzzerPin, HIGH);
      delay(highPeriod);
     // vTaskDelay(highPeriod / portTICK_PERIOD_MS);
      digitalWrite(BuzzerPin, LOW);
      delay(lowPeriod);
     // vTaskDelay(lowPeriod / portTICK_PERIOD_MS);
    }
  }
  digitalWrite(BuzzerPin, lastState);
}