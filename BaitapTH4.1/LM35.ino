const int sensor = A1; // Gắn chân analog A1 làm chân đọc cảm biến
float tempc;           // Biến lưu giá trị nhiệt độ độ C
float tempf;           // Biến lưu giá trị nhiệt độ độ F
float vout;            // Biến tạm chứa kết quả phép đọc analog

void setup() {
  pinMode(sensor, INPUT); // Cấu hình chân A1 làm ngõ vào
  Serial.begin(9600);     // Khởi động Serial Monitor với tốc độ baud 9600
}

void loop() {
  // 1. Đọc giá trị Analog từ chân A1 (giá trị từ 0 - 1023)
  vout = analogRead(sensor);
  
  // 2. Chuyển đổi giá trị Analog sang điện áp và tính ra độ C
  // Công thức trong sách: (vout * 500) / 1023
  tempc = (vout * 500.0) / 1023.0; 
  
  // 3. Chuyển đổi từ độ C sang độ F
  tempf = (tempc * 1.8) + 32.0;

  // 4. In kết quả ra Serial Monitor
  Serial.print("in DegreeC= ");
  Serial.print("\t"); // In dấu tab để lùi vào
  Serial.print(tempc);
  Serial.println();   // Xuống dòng

  Serial.print("in Fahrenheit= ");
  Serial.print("\t");
  Serial.print(tempf);
  Serial.println();

  delay(1000); // Trì hoãn 1 giây để dễ đọc kết quả
}