import serial
import csv
from datetime import datetime
import matplotlib.pyplot as plt

ser = serial.Serial('COM6', 9600)  

timestamps = []
celsius_values = []
fahrenheit_values = []
print("sfsdf")

try:
    while True:
        line = ser.readline().decode().strip()

        celsius, fahrenheit = map(float, line.split(','))

        timestamp = datetime.now().strftime('%H:%M:%S')

        timestamps.append(timestamp)
        celsius_values.append(celsius)
        fahrenheit_values.append(fahrenheit)

        print(f'Time: {timestamp}, Celsius: {celsius}, Fahrenheit: {fahrenheit}')

except KeyboardInterrupt:
    ser.close()
    print("Serial connection closed.")

    with open('temperature_data.csv', mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Time', 'Celsius', 'Fahrenheit'])
        for i in range(len(timestamps)):
            writer.writerow([timestamps[i], celsius_values[i], fahrenheit_values[i]])
            
plt.figure(figsize=(10, 6))
plt.plot(timestamps, celsius_values, marker='o', linestyle='-', color='b', label='Celsius')
# plt.plot(timestamps, fahrenheit_values, marker='o', linestyle='-', color='r', label='Fahrenheit')
plt.xlabel('Time')
plt.ylabel('Temperature')
plt.title('Temperature vs. Time')
plt.xticks(rotation='vertical')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()