#define FIRE    0

AncsNotification notifications[8];

void setup() {
  // Serial port is initialized automatically; we don't have to do anything
  BeanAncs.enable();
  pinMode(FIRE, OUTPUT);
  digitalWrite(FIRE, HIGH);
}

void loop() {
  int msgAvail = BeanAncs.notificationsAvailable();

  if (msgAvail) {
    Bean.setLedRed(30);

    BeanAncs.getNotificationHeaders(notifications, 8);

    for (int i = 0; i < msgAvail; i++) {
      if (notifications[i].catID == 4) {
        Bean.setLedGreen(155);
        delay(500);
        digitalWrite(FIRE, LOW);
        delay(500);
      }
      Bean.setLedGreen(0);
      digitalWrite(FIRE, HIGH);
      delay(3000);
    }
    Bean.setLedRed(0);
  }
}
