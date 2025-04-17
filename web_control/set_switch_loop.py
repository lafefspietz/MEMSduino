
import numpy as np
import json
import time
import serial
SP9T_serial = serial.Serial('COM7', 9600)  # open serial port
time.sleep(0.01)
while True:
    time.sleep(0.01)
    try:
        file = open('control_data.txt', "r")
        control_data_raw = file.read()
        file.close()  
        control_data = json.loads(control_data_raw)
        switch_state = control_data['switch_state']
        SP9T_serial.write(bytes(str(switch_state), encoding='utf-8'))
    except:
        pass