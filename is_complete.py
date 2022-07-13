from pyautogui import *
import time
import pyautogui
import serial

arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
# while True:
#     num = input("Enter a number: ") # Taking input from user
#     value = write_read(num)
#     print(value) # printing the value


times_completed = 0
total = 100
is_running = False

while True:
                                                        #x    y    width height
    if pyautogui.locateOnScreen('complete.jpeg', region=(200, 903, 1389, 27) ,  confidence=0.6) != None:
        times_completed += 1
        time.sleep(20)
        print('achei o completo')
    print('ok')

    if times_completed == 2:
        write_read(2)
        times_completed = 0
        total -= 1
        time.sleep(120)   
        is_running = False
        print('completed')

    if times_completed == 0 and is_running == False and total>4:
        pyautogui.click(1389, 534) #the pixels of play button
        is_running = True
        print('começando a printar')
    
    time.sleep(10)


# while True:
#     pyautogui.click(10, 50)
#     time.sleep(10)