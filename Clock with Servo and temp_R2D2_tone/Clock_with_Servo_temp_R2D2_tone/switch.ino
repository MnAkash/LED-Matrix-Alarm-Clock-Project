byte menu_press(byte a) {
  int p = 0;
  while (!digitalRead(menu_button)) {
    p++; delay(1);
    if ((p >= 500 && a != 2) || a == 1) {
      if (a == 1) delay(100);
      return 1;
    }
  }
  if (p > 15) return 2;
  return 0;
}

byte set_press(byte a) {
  int p = 0;
  while (!digitalRead(set_button)) {
    p++; delay(1);
    if ((p >= 500 && a != 2) || a == 1) {
      if (a == 1) delay(100);
      return 1;
    }
  }
  if (p > 15) return 2;
  return 0;
}

byte long_press() {
  int p = 0;
  while (!digitalRead(set_button)) {
    p++; delay(1);
    if (p > long_press_timer * 1000) return 1;
  }
  if (p > 15) return 2;
  return 0;
}

byte tap_press() {
  int count = 0;
d: int p = 0;
  while (!digitalRead(menu_button)) {
    p++; delay(1);
  }
  if (p > 15) {
    count++; p = 0;
    while (digitalRead(menu_button)) {
      p++; delay(1);
      if (p > 500) return count;
    }
    goto d;
  }
  return count;
}

byte special_press() {
  int p = 0;
  while (!digitalRead(special_button)) {
    p++; delay(1);
    if (p >= press_time * 1000) {
      if (!start) {
        lc.shutdown(1, 0); lc.shutdown(0, 0);
        for (byte i = 0; i < 8; i++) lc.setRow(1, i, he[i]);
        for (byte i = 0; i < 8; i++) lc.setRow(0, i, ey[i]);
        start = 1; delay(2000);
      }
      else {
        for (byte i = 0; i < 8; i++) lc.setRow(1, i, by[i]);
        for (byte i = 0; i < 8; i++) lc.setRow(0, i, ye[i]);
        delay(2000); lc.shutdown(1, 1); lc.shutdown(0, 1);
        start = 0;
      }
      return 2;
    }
  }
  if (p > 15) return 1;
  return 0;
}

byte temp_press() {
  int p = 0;
  while (!digitalRead(temp_button)) {
    p++; delay(1);
  }
  if (p > 15) return 1;
  return 0;
}

byte servo_press() {
  int p = 0;
  while (!digitalRead(servo_button)) {
    p++; delay(1);
  }
  if (p > 15) return 1;
  return 0;
}
