[Esp32 Arduino Dev]

Reference:
1. Arduino core for the ESP32, ESP32-S2, ESP32-S3 and ESP32-C3 -> https://github.com/espressif/arduino-esp32
2. Arduino-ESP32 Online Documentation -> https://docs.espressif.com/projects/arduino-esp32/en/latest/

Driver:
1. Download CH340 driver: CH341SER
http://www.wch.cn/download/ch341ser_exe.html
2. Install CH340 driver
3. PC connect to board
4. Check the windows device manager: CH340

Dev (ARDUINO IDE):
1. Download nad install: ARDUINO IDE 1.8.19 [Windows-win7-and-newer] https://www.arduino.cc/en/software
2. Run ARDUINO IDE
3. [File] -> [Preferences] -> Additional Boards Manager URLs: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
4. [Tools] -> [Board] -> [Boards meneger...] -> search "esp32" and install the "esp32" verdion 2.0.3
5. [Tools] -> [Board] -> [ESP32 Arduino] -> [ESP32 DEV Module]
6. [Tools] -> [Port] -> [YOUR_BOARD_PORT]
7. Compile by button:[V] Verify
8. Upload by button: [->] Upload

Dev (VSCode) :
1. Download and install: VSCode https://code.visualstudio.com/
2. Run VSCode
3. Select sheet [Extensions] in left side: searsh and install "Arduino"
4. Enter [Extensions]:"Arduino" settings -> Path -> YOUR_ARDUINO_INSTALLED_FOLDER
5. Load the code folder
6. Select <Show_Board_Config> = [ESP32 DEV Module] (at right-down side)
7. Run first compile (the button "Arduino: Verify" (at right-up side)
8. Select <Select_Board_Serial> = [YOUR_BOARD_PORT] (at right-down side)
9. Compile by button:[V] Arduino: Verify (at right-up side)
10. Upload by button: [|] Arduino: Upload (at right-up side)
