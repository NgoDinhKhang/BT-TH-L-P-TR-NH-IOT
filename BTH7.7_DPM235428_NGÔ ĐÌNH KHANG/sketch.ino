#include <ESP32Servo.h> // Sử dụng thư viện Servo chuyên dụng cho ESP32

Servo myservo;  // Tạo đối tượng servo để điều khiển
int servoPin = 18; // Chân kết nối tín hiệu servo

void setup() {
  Serial.begin(115200); // Khởi động Serial để xem thông báo
  myservo.attach(servoPin); // Gắn servo vào chân GPIO 18
  Serial.println("He thong dieu khien Servo da san sang!");
}

void loop() {
  // Quay từ 0 độ lên 180 độ
  for (int angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    Serial.print("Dang quay len - Goc hien tai: ");
    Serial.print(angle);
    Serial.println(" do");
    delay(20); // Chờ 20ms để servo kịp quay đến vị trí
  }

  // Quay ngược lại từ 180 độ về 0 độ
  for (int angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    Serial.print("Dang quay ve - Goc hien tai: ");
    Serial.print(angle);
    Serial.println(" do");
    delay(20);
  }
}