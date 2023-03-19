# Python與ESP32通訊範例

## 專案說明
透過傳輸線(Micro USB - USB)連接ESP32和PC，在PC上利用Python的`serial`套件，與ESP32通訊控制LED燈。

## 檔案說明
* led_light_ctrl: ESP32程式碼，可以Arduino Software開啟
* main.py: Python程式碼，使用輸入對應指令來控制LED燈號

## 使用說明

1. 以傳輸線(Micro USB - USB)連接ESP32和PC後，先以Arduino Software開啟`led_light_ctrl`，將程式碼燒錄至ESP32內，燒錄完畢後關閉Arduino Software。
2. 開啟Python執行`main.py`，注意程式碼內的COM Port是否設定正確(可透過硬體裝置管理員查詢)，另還需要pip安裝`pyserial`套件。