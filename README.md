# GPS Tracking System 🌍

## Project Description
This project is developed for the course "Introduction to Embedded Systems" (CSE 211s, Spring24) at the (FOE-ASU) CSE Dept. <br>
The goal is to create a GPS tracking system that collects real-time positional coordinates from a microcontroller in motion and displays this trajectory on a map.

## Features
- **Data Collection:** Captures real-time GPS coordinates 📍.
- **End Point Detection:** Stops data collection based on distance (>100m), button press, or a predefined destination 🏁.
- **LED Notification:** Indicates when the destination point is reached 🔔.
- **Data Transfer:** Sends the collected data to a PC via UART when commanded ⬆️.

## Hardware Requirements
- Microcontroller development board ( ARM® Cortex®-M4F Based MCU TM4C123G "TivaC" ) 🖥️
- GPS module 🛰️
- Personal computer (PC) 💻
- Connecting cables (USB, serial, etc.) 🔌

## Software Requirements
- C development environment (e.g., Keil) 💾
- PC-based application development environment (e.g., Python with Matplotlib or a mapping API) 📊

## Setup and Operation
1. **Configure Interfaces:** Setup UART interfaces for the GPS module and PC. Prepare digital output for built-in LED.
2. **Initialization:** On power-on, the system should read GPS data and wait for a valid GPS fix 🛠️.
3. **Data Logging:** Continuously log the GPS coordinates, updating the trajectory until the end conditions are met 📝.
4. **Data Visualization:** Utilize PC-based software to draw and display the trajectory on a map 🗺️.

## Contributing
Feel free to fork this repository, make changes, and submit pull requests if you have improvements or new features to add 👍.

## License
📜 Check the [License](LICENSE) file for details.