void setup() {
  // Thiết lập các chân từ 2 đến 9 làm ngõ ra (OUTPUT)
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}

// Hàm tắt toàn bộ 8 LED
void allLEDsOff(void) {
  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
}

void loop() {
  // Quét từ trái sang phải (từ chân 2 đến chân 9)
  for (int i = 2; i <= 9; i++) {
    allLEDsOff();
    digitalWrite(i, HIGH);
    delay(200);
  }

  // Quét ngược lại từ phải sang trái (từ chân 8 về chân 2)
  for (int i = 8; i >= 2; i--) {
    allLEDsOff();
    digitalWrite(i, HIGH);
    delay(200);
  }
}