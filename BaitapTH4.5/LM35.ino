#include <IRremote.h>

const int receiverPin = 8;

// Mảng chứa 10 chân kết nối với 10 đèn LED (y hệt trong sách)
const int ledPin[] = {3, 4, 5, 6, 7, 9, 10, 11, 12, 13};

// Mảng lưu trạng thái Bật/Tắt của 10 đèn (false = đang tắt, true = đang bật)
boolean stateLed[10] = {false, false, false, false, false, false, false, false, false, false};

void setup() {
  Serial.begin(9600);
  
  // Khởi động bộ thu hồng ngoại (Lệnh mới thay cho irrecv.enableIRIn)
  IrReceiver.begin(receiverPin); 

  // Dùng vòng lặp khai báo ngõ ra cho 10 đèn LED
  for (int i = 0; i < 10; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  // Kiểm tra xem có nhận được tín hiệu từ Remote không (Lệnh mới thay cho irrecv.decode)
  if (IrReceiver.decode()) {
    translateIR(); // Gọi hàm xử lý tín hiệu
    delay(200);    // Trì hoãn một chút để tránh hiện tượng dội phím (bấm 1 lần ăn 2 lần)
    
    // Tiếp tục lắng nghe tín hiệu tiếp theo
    IrReceiver.resume(); 
  }
}

void translateIR() {
  // Thay vì dùng mã HEX dài dòng (0xFF6897), phiên bản mới cho phép lấy mã lệnh gốc (command)
  int command = IrReceiver.decodedIRData.command;
  
  switch (command) {
    case 104: // Nút số 0 (Sách ghi là 0xFF6897)
      stateLed[0] = !stateLed[0];             // Đảo trạng thái (Đang tắt thành bật, đang bật thành tắt)
      digitalWrite(ledPin[0], stateLed[0]);   // Xuất trạng thái ra đèn tương ứng
      break;
      
    case 48:  // Nút số 1 (Sách ghi là 0xFF30CF)
      stateLed[1] = !stateLed[1];
      digitalWrite(ledPin[1], stateLed[1]);
      break;
      
    case 24:  // Nút số 2 (Sách ghi là 0xFF18E7)
      stateLed[2] = !stateLed[2];
      digitalWrite(ledPin[2], stateLed[2]);
      break;
      
    case 122: // Nút số 3 (Sách ghi là 0xFF7A85)
      stateLed[3] = !stateLed[3];
      digitalWrite(ledPin[3], stateLed[3]);
      break;
      
    case 16:  // Nút số 4 (Sách ghi là 0xFF10EF)
      stateLed[4] = !stateLed[4];
      digitalWrite(ledPin[4], stateLed[4]);
      break;
      
    case 56:  // Nút số 5 (Sách ghi là 0xFF38C7)
      stateLed[5] = !stateLed[5];
      digitalWrite(ledPin[5], stateLed[5]);
      break;
      
    case 90:  // Nút số 6 (Sách ghi là 0xFF5AA5)
      stateLed[6] = !stateLed[6];
      digitalWrite(ledPin[6], stateLed[6]);
      break;
      
    case 66:  // Nút số 7 (Sách ghi là 0xFF42BD)
      stateLed[7] = !stateLed[7];
      digitalWrite(ledPin[7], stateLed[7]);
      break;
      
    case 74:  // Nút số 8 (Sách ghi là 0xFF4AB5)
      stateLed[8] = !stateLed[8];
      digitalWrite(ledPin[8], stateLed[8]);
      break;
      
    case 82:  // Nút số 9 (Sách ghi là 0xFF52AD)
      stateLed[9] = !stateLed[9];
      digitalWrite(ledPin[9], stateLed[9]);
      break;
  }
}