
void sendDebugData( byte CodeStateID,String DbgMsj)
{
    if (debugStatus == ON)
    {
        Debug_Serial.print("[" + String(millis()) + "] CSID=" + String(CodeStateID) + "/" + DbgMsj);

        delay(5);
    }
}