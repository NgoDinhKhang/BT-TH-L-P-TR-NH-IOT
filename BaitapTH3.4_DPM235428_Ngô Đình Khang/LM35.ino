const int kPinButton1 = 2; // Nút 1: Giảm độ sáng
const int kPinButton2 = 3; // Nút 2: Tăng độ sáng
const int kPinLed = 9;     // Chân xuất xung PWM điều khiển LED

int ledBrightness = 128;   // Đặt độ sáng ban đầu mức trung bình (128/255)
int lastBrightness = -1;   // Lưu giá trị cũ để so sánh và chỉ in khi có thay đổi

void setup() {
  Serial.begin(9600);      // Bật cổng kết nối Serial với máy tính

  pinMode(kPinButton1, INPUT);
  pinMode(kPinButton2, INPUT);
  pinMode(kPinLed, OUTPUT);
  
  digitalWrite(kPinButton1, HIGH); // Kích hoạt điện trở kéo lên nội
  digitalWrite(kPinButton2, HIGH); // Kích hoạt điện trở kéo lên nội
}

void loop() {
  // Nhấn nút 1 -> Giảm độ sáng
  if (digitalRead(kPinButton1) == LOW) {
    ledBrightness--;
  }
  // Nhấn nút 2 -> Tăng độ sáng
  else if (digitalRead(kPinButton2) == LOW) {
    ledBrightness++;
  }

  // Giữ giá trị độ sáng luôn nằm trong khoảng 0 đến 255
  ledBrightness = constrain(ledBrightness, 0, 255);

  // Chỉ in ra Serial Monitor khi độ sáng thực sự thay đổi (tránh tràn màn hình)
  if (ledBrightness != lastBrightness) {
    Serial.print("Do sang LED hien tai: ");
    Serial.println(ledBrightness);
    lastBrightness = ledBrightness; // Cập nhật lại giá trị cũ
  }

  // Xuất tín hiệu PWM ra chân LED
  analogWrite(kPinLed, ledBrightness);
  
  delay(20); // Delay nhỏ để tạo tốc độ thay đổi mượt mà
}