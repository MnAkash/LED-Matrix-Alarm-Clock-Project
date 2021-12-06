void phrase1() {

  int k = random(1000, 2000);
  for (int i = 0; i <=  random(100, 2000); i++) {
    startTimeStamp = millis();
    tone(buzzer, k + (-i * 2));
    rands = random(.9, 2);
    while (millis() - startTimeStamp < rands ) {}

  }
  for (int i = 0; i <= random(100, 1000); i++) {
    startTimeStamp = millis();
    tone(buzzer, k + (i * 10));
    rands = random(.9, 2);
    while (millis() - startTimeStamp < rands ) {}
  }
}
void phrase2() {

  int k = random(1000, 2000);
  for (int i = 0; i <= random(100, 2000); i++) {
    startTimeStamp = millis();
    tone(buzzer, k + (i * 2));
    rands = random(.9, 2);
    while (millis() - startTimeStamp < rands ) {}
  }
  for (int i = 0; i <= random(100, 1000); i++) {
    startTimeStamp = millis();
    tone(buzzer, k + (-i * 10));
    rands = random(.9, 2);
    while (millis() - startTimeStamp < rands ) {}
  }
}

void r2d2() {
  //Serial.println("Working");
  int K = 2000;
  switch (random(1, 7)) {

    case 1: phrase1(); break;
    case 2: phrase2(); break;
    case 3: phrase1(); phrase2(); break;
    case 4: phrase1(); phrase2(); phrase1(); break;
    case 5: phrase1(); phrase2(); phrase1(); phrase2(); phrase1(); break;
    case 6: phrase2(); phrase1(); phrase2(); break;
  }
  for (int i = 0; i <= random(3, 9); i++) {

    tone(buzzer, K + random(-1700, 2000));
    startTimeStamp = millis();
    rands = random(70, 170);
    while (millis() - startTimeStamp < rands ) {}

    noTone(buzzer);
    startTimeStamp = millis();
    rands = random(0, 30);
    while (millis() - startTimeStamp < rands ) {}
  }
  noTone(buzzer);
  startTimeStamp = millis();
  rands = random(1000, 3000);
  //while(millis() - startTimeStamp < rands ){} //wait a moment before ending starting new task
}
