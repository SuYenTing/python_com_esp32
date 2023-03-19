import serial

# 建立串口對象
ser = serial.Serial('COM3', 115200, timeout=1)

# 說明
print('==========可用指令字串==========')
print('red: 亮紅燈')
print('yellow: 亮黃燈')
print('green: 亮綠燈')
print('off: 熄滅所有燈光')
print('================================')

while True:

    # 讓使用者輸入要發送的字串
    user_input = input('請輸入要發送的字串 (輸入 q 離開): ')

    if user_input == 'q':
        break

    # 將使用者輸入的字串發送到ESP32
    ser.write(user_input.encode())

    # 從ESP32接收數據
    while True:
        data = ser.readline().decode('utf-8').rstrip()
        if data:
            print(data)
            break

# 關閉串口
ser.close()
