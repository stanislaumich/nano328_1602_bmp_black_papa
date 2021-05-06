#pip install pyserial
import serial
import time


print("Start")
#try:
realport = serial.Serial("COM9",115200)
print('Подключено')
#	except Exception as e:
time.sleep(3)
realport.write(b'HELLO')	
realport.close()
