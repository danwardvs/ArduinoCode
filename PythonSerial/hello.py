import serial
import subprocess

ser = serial.Serial('COM9', 9600)
while True:
    subprocess.call(["shutdown.exe", "-f", "-s", "-t", "0"])
    data = str(ser.readline())
    print(data)
    print(type(data))
    if data == "bLight is off\r\n":
        subprocess.call(["shutdown.exe", "-f", "-s", "-t", "0"])
        print("Shutdown")
