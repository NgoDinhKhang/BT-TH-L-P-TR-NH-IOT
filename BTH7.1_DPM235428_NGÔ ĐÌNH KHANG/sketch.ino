int inputPin = 5; // Chân GPIO 5 đọc tín hiệu
int val = 0;      // Biến lưu trữ giá trị đọc được

void setup() {
  Serial.begin(9600);           // Khởi động Serial Monitor
  pinMode(inputPin, INPUT);     // Cài đặt chân D5 là ngõ vào (INPUT)
}

void loop() {
  // Đọc trạng thái chân D5 (sẽ trả về 0 hoặc 1)
  val = digitalRead(inputPin);  
  
  // In giá trị ra màn hình
  Serial.print("Gia tri Digital dang la: ");
  Serial.println(val);
  
  delay(1000); // Chờ 1 giây trước khi đọc lại
}