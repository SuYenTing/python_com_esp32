void setup() {
  // 初始化串口通信
  Serial.begin(115200);

  // 等待 USB 串口連接
  while (!Serial);
  Serial.println("USB Serial connected.");

  // 腳位設定
  pinMode(17, OUTPUT); // 17號腳位:紅燈
  pinMode(16, OUTPUT); // 16號腳位:黃燈
  pinMode(4, OUTPUT); // 4號腳位:綠燈

  // 亮燈測試功能是否正常
  light_test();
}


// 亮燈測試功能是否正常
void light_test() {

  // 測試紅燈開關
  digitalWrite(17, HIGH);
  delay(1000);
  digitalWrite(17, LOW);

  // 測試紅燈開關
  digitalWrite(16, HIGH);
  delay(1000);
  digitalWrite(16, LOW);

  // 測試紅燈開關
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
}


void loop() {

  String data = "";
  
  // 從 PC 獲取數據
  if (Serial.available()) {
    data = Serial.readString();
    Serial.println("Received command: " + data);
  } else {
    String data = "";
  }

  // 判斷指令
  if (data == "red") {
    digitalWrite(17, HIGH); // 亮紅燈
    
  } else if (data == "yellow") {
    digitalWrite(16, HIGH); // 亮黃燈
    
  } else if (data == "green") {
    digitalWrite(4, HIGH); // 亮綠燈
    
  } else if (data == "off") {
    digitalWrite(17, LOW); // 燈號關閉
    digitalWrite(16, LOW);
    digitalWrite(4, LOW);
    
  } else if (data == "") {
    
  } else {
    Serial.println("Unknown command: " + data);
  }
  
  delay(1000);
}
