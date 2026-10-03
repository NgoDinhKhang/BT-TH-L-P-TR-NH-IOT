#include "DHT.h"

#define DHTPIN 4     // Chân kết nối dữ liệu từ cảm biến
#define DHTTYPE DHT22 // Định nghĩa loại cảm biến (DHT22 trên Wokwi)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // Chờ 2 giây giữa các lần đọc
  delay(2000);

  // Đọc độ ẩm
  float h = dht.readHumidity();
  // Đọc nhiệt độ tính theo độ C
  float t = dht.readTemperature();

  // Kiểm tra xem việc đọc có bị lỗi không
  if (isnan(h) || isnan(t)) {
    Serial.println("Loi doc du lieu tu cam biến DHT!");
    return;
  }

  // Hiển thị kết quả lên Serial Monitor
  Serial.print("Do am: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.println(" *C");
}