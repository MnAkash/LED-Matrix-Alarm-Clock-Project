void alarm_function() {
  if (millis() - al > beeping_interval) {
    al = millis();
    digitalWrite(buzzer, !digitalRead(buzzer));
  }
  if (mute_timer != 0)
    if (millis() - m2 > mute_timer * 1000) {
      alarm = 0; digitalWrite(buzzer, 0);
      if (snooze_count > 0) {
        snooze = 1; snooze_count--;
        sz = millis();
      }
    }
}
