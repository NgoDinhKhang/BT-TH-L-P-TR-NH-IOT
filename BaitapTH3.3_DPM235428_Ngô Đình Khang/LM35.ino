const int kPinButton1 = 2; // Chân nhận tín hiệu từ nút nhấn
const int kPinLed = 9;     // Chân xuất tín hiệu điều khiển LED

void setup() {
  pinMode(kPinButton1, INPUT);
  digitalWrite(kPinButton1, HIGH); // Bật điện trở kéo lên nội (Internal Pull-up)

  pinMode(kPinLed, OUTPUT);        // Khai báo chân LED là ngõ ra
}

void loop() {
  // Khi nhấn nút: Tín hiệu chân 2 bị nối xuống GND (mức LOW) -> Bật LED
  if (digitalRead(kPinButton1) == LOW) {
    digitalWrite(kPinLed, HIGH);
  } 
  // Khi không nhấn: Điện trở kéo lên giữ chân 2 ở mức HIGH -> Tắt LED
  else {
    digitalWrite(kPinLed, LOW);
  }
}