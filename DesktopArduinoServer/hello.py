import serial
import subprocess


ser = serial.Serial('COM4', 9600)
data_to_send = ""

while True:
    
    data_to_send = input("Send: ")
    ser.write(data_to_send.encode())
