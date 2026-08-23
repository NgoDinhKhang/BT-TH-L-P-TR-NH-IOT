int sensorPin = A0;   // Chân đọc tín hiệu biến trở
int ledPin = 13;      // Chân điều khiển đèn LED
int sensorValue = 0;  // Biến lưu giá trị biến trở (0 - 1023)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Mở cổng Serial monitor để theo dõi giá trị
}

void loop() {
  sensorValue = analogRead(sensorPin); // Đọc giá trị biến trở

  Serial.print("Gia tri bien tro: ");
  Serial.println(sensorValue);

  digitalWrite(ledPin, HIGH); // Bật LED
  delay(sensorValue);         // Chờ thời gian tương ứng với giá trị biến trở

  digitalWrite(ledPin, LOW);  // Tắt LED
  delay(sensorValue);         // Chờ thời gian tương ứng với giá trị biến trở
}