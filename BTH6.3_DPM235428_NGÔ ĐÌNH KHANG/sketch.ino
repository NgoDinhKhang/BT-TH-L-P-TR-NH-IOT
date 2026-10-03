#include <WiFi.h> // Sử dụng thư viện WiFi cho ESP32 thay vì ESP8266WiFi

// Thông số mạng WiFi ảo trên Wokwi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Tên máy chủ đám mây
const char* host = "dweet.io";

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // Quá trình kết nối WiFi 
  Serial.println();
  Serial.print("Dang ket noi den ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nDa ket noi WiFi");
  Serial.print("Dia chi IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Trì hoãn 5 giây giữa các lần gửi dữ liệu lên server
  delay(5000); 

  Serial.print("\nDang ket noi den host: ");
  Serial.println(host);

  // Sử dụng lớp WiFiClient để tạo kết nối TCP
  WiFiClient client;
  const int httpPort = 80;
  
  // Hàm client.connect() kiểm tra xem có kết nối được tới server không
  if (!client.connect(host, httpPort)) {
    Serial.println("Ket noi that bai");
    return;
  }

  // Xây dựng URI (đường dẫn) cho yêu cầu GET để gửi lên máy chủ
  // Bạn có thể đổi chữ "esp32-wokwi-test" thành tên bất kỳ để không đụng hàng
  String url = "/dweet/for/esp32-wokwi-test?value=hello_server";
  
  Serial.print("Dang yeu cau URL: ");
  Serial.println(url);

  // Hàm client.print() dùng để gửi yêu cầu HTTP GET đến máy chủ
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Thiết lập thời gian chờ phản hồi (timeout)
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Het thoi gian client!");
      client.stop();
      return;
    }
  }

  // Hàm client.available() kiểm tra dữ liệu gửi về và in ra Serial Monitor
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("Dang dong ket noi");
}