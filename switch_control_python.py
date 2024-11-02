import serial
ser = serial.Serial('COM12', 9600)  # open serial port, replace with correct COM port, found from IDE
ser.write(bytes(str(1), encoding='utf-8')) # replace the number 1 with port number