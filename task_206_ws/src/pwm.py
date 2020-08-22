'''
Written by Maria Cuyutupa Garcia August 2020
'''
import RPi.GPIO as GPIO
from time import sleep

def setPIN (PIN, freq):
    # Set GPIO numbering mode
    GPIO.setmode(GPIO.BOARD)
    # Set PIN number
    GPIO.setup(PIN, GPIO.OUT)
    motor = GPIO.PWM(PIN, freq)	#create PWM instance with frequency
    motor.start(0)				#start PWM of required Duty Cycle 
    return motor

def getFreq (val):
    freq = abs(val) * 340
    if freq < 10:
        return 0
    return freq

def isPositive (val):
    if val > 0:
        return True
    return False 

def getDutyCycle (val, isPositive):
    period = 0.05
    if isPositive:
        return (0.002 / period) * 100
    return (0.001 / period) * 100

def sendPWM (motor, duty):
    while True:
        motor.ChangeDutyCycle(duty)
        sleep(0.5)