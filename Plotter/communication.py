import tkinter as tk
import serial
import threading
import folium
import tkinter.messagebox as messagebox


def center_window(window):
    window.update_idletasks()

    width = window.winfo_width()
    height = window.winfo_height()
    x = (window.winfo_screenwidth() // 2) - (width // 2)
    y = (window.winfo_screenheight() // 2) - (height // 2)

    window.geometry('{}x{}+{}+{}'.format(width, height, x, y))


class BluetoothController(tk.Tk):
    def reset_text_field(self):
        self.text_field.delete(0, tk.END)    # Clear the text field
        self.text_field.insert(0, "Example: 1,2,3,4, etc.") # Add placeholder text
    
    def get_text_field_value(self):
            self.COM_num = self.text_field.get() # Get the value from the text field
            
    def clear_placeholder(self, event):
        if self.text_field.get() == "Example: 1,2,3,4, etc.":
            self.text_field.delete(0, "end")
            
    def validate_input(self, new_value):
        return (new_value.isdigit() and len(new_value) <= 2) or new_value == ""

    def check_com_port(self):
        while True:
                self.update()
                if self.COM_num:
                    if self.COM_num.isdigit():
                        break
        
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.title("Serial Communication with Microcontroller")
        self.COM_num = None

        # 2D array to store latitude and longitude points
        self.points = []
        
        self.geometry("500x375")  # Set the size of the window to 800x600 pixels

        self.choice_frame = tk.Frame(self)
        self.choice_frame.pack(fill=tk.BOTH, expand=True) # Make the frame fill the entire window
        self.choice_frame.place(relx=0.5, rely=0.5, anchor='center')  # Center the frame in the window

        self.com_frame = tk.Frame(self.choice_frame)
        self.com_frame.grid(row=1, column=0, columnspan=2, padx=10, pady=10)

        self.text_label = tk.Label(self.com_frame, text="Enter COM Port Number:", font=("Helvetica", 16, "bold"))
        self.text_label.grid(row=0, column=0, columnspan=2)

        self.text_frame = tk.Frame(self.com_frame, width=150, height=35)
        self.text_frame.grid(row=1, column=0, padx=10, pady=10)
        self.text_frame.pack_propagate(False)  # Don't let the button resize the frame

        vcmd = (self.register(self.validate_input), '%P')
        self.text_field = tk.Entry(self.text_frame, bg='green', fg="white", validate='key', validatecommand=vcmd, font=("Helvetica", 10, "bold"))
        self.text_field.insert(0, "Example: 1,2,3,4, etc.") # Add placeholder text
        self.text_field.bind("<FocusIn>", self.clear_placeholder)  # Bind the clear_placeholder method to the FocusIn event
        self.text_field.pack(fill=tk.BOTH, expand=1)  # Place the text field below the label
        self.reset_text_field()  # Add placeholder text



        self.submit_frame = tk.Frame(self.com_frame, width=75, height=35)
        self.submit_frame.grid(row=1, column=1, padx=10, pady=10)
        self.submit_frame.pack_propagate(False)  # Don't let the button resize the frame
        
        self.submit_button = tk.Button(self.submit_frame, text="Submit", command=self.get_text_field_value, bg='green', fg='white', font=("Helvetica", 12, "bold"))  # Set the background color to green and make the button larger
        self.submit_button.pack(fill=tk.BOTH, expand=1)  # Place the button below the text field
        
        
        self.choice_label = tk.Label(self.choice_frame, text="Send Flag?", font=("Helvetica", 16, "bold"))
        self.choice_label.grid(row=3, column=0, columnspan=2)  # Place the label below the text field and button

        # make the buttons for the user to select yes or no, make each button 200x200 pixels

        self.no_button_frame = tk.Frame(self.choice_frame, width=75, height=50)
        self.no_button_frame.grid(row=4, column=1, padx=10, pady=10)
        self.no_button_frame.pack_propagate(False)  # Don't let the button resize the frame

        self.no_button = tk.Button(self.no_button_frame, text="No", bg="red", fg="white", font=("Helvetica", 12, "bold"), command=lambda: self.send_choice('No'))
        self.no_button.pack(fill=tk.BOTH, expand=1)  # Fill the entire frame

        self.yes_button_frame = tk.Frame(self.choice_frame, width=75, height=50)
        self.yes_button_frame.grid(row=4, column=0, padx=10, pady=10)
        self.yes_button_frame.pack_propagate(False)  # Don't let the button resize the frame

        self.yes_button = tk.Button(self.yes_button_frame, text="Yes", bg="green", fg="white", font=("Helvetica", 12, "bold"), command=lambda: self.send_choice('Yes'))
        self.yes_button.pack(fill=tk.BOTH, expand=1)  # Fill the entire frame

        # Create a new frame at the bottom of the window
        self.bot_frame = tk.Frame(self.choice_frame)
        self.bot_frame.grid(row=5, column=0, columnspan=2, padx=10, pady=10)

        self.text_label2 = tk.Label(self.bot_frame, text="Send Data to MicroController:", font=("Helvetica", 16, "bold"))
        self.text_label2.grid(row=0, column=0, columnspan=2)

        self.text_frame2 = tk.Frame(self.bot_frame, width=150, height=35)
        self.text_frame2.grid(row=1, column=0, padx=10, pady=10)
        self.text_frame2.pack_propagate(False)  # Don't let the button resize the frame

        self.text_field2 = tk.Entry(self.text_frame2, bg='#FF8C00', fg='white', font=("Helvetica", 10, "bold"))
        self.text_field2.pack(fill=tk.BOTH, expand=1)  # Place the text field below the label

        self.submit_frame2 = tk.Frame(self.bot_frame, width=75, height=35)
        self.submit_frame2.grid(row=1, column=1, padx=10, pady=10)
        self.submit_frame2.pack_propagate(False)  # Don't let the button resize the frame
        
        self.submit_button2 = tk.Button(self.submit_frame2, text="Submit", command=lambda: self.send_choice(self.text_field2.get()), bg='#FF8C00', fg='white', font=("Helvetica", 12, "bold"))  # Set the background color to green and make the button larger
        self.submit_button2.pack(fill=tk.BOTH, expand=1)  # Place the button below the text field
        # Center the window on the screen
        center_window(self)


        # Make sure the user has entered a COM port number before proceeding
        self.check_com_port()
        
        # Connect to the serial port
        self.establish_connection()                    
    
    def establish_connection(self):
        while True:
            try:
                self.send_port = serial.Serial('COM' + self.COM_num, 9600)  
                messagebox.showinfo("Success", "Connected to COM" + self.COM_num)
                self.send_port.timeout = 1
                
                # Create a thread for receiving data
                self.receive_thread = threading.Thread(target=self.receive_data)
                self.receive_thread.daemon = True
                self.receive_thread.start()
                break
            except:
                messagebox.showerror("Error", "Could not connect to COM" + self.COM_num + ". Check the COM port number and try again.")
                self.COM_num = None
                self.check_com_port()
                
    def send_command(self):
        try:
            self.send_port.write(b'U\n\r')  # Sending 'U' command with newline and carriage return
        except:
            messagebox.showerror("Error", "Could not send command. Exiting program.")
            self.destroy()
    def send_choice(self, choice):
        try:
            self.send_port.write(choice.encode() + b'\n\r')  # Sending 'Y' or 'N' choice with newline and carriage return
        except:
            messagebox.showerror("Error", "Could not send choice. Please check your COM connection.")

    def receive_data(self):
# This block of code is responsible for reading data from the serial port in the `BluetoothController`
# class. Here's a breakdown of what it does:
        dataPoints = 0
        while True:
            try:
                data = self.send_port.readline().decode().strip()  # Read the data
                print(data)
                if type(data) == str and data.isdigit() and int(data) > 0:
                    dataPoints = int(data)
                    print(dataPoints)
                    break
            except serial.SerialException:
                print("Error reading data. Exiting receive thread.")
                return
        
        while dataPoints > 0:
            try:
                data = self.send_port.readline().decode().strip()  # Read the data
                if data:
                    print(data)
                    # Parse the received data and store latitude and longitude points
                    if data.startswith('$') and ',' in data:
                        lat_lon = data[1:].split(',')
                        if len(lat_lon) == 2:
                            latitude = float(lat_lon[0]) / pow(10, 2) + 0.02613
                            longitude = float(lat_lon[1]) / pow(10, 2) + 0.11135
                            self.points.append([latitude, longitude])
                            print("Latitude:", latitude, "Longitude:", longitude)
                            dataPoints -= 1
            except serial.SerialException:
                print("Error reading data. Exiting receive thread.") 
                return
        graphData(self.points)
        
def graphData(points):
    lats = []
    lons = []
    # Create a map centered at coordinates and set zoom level
    m = folium.Map(location=[points[0][0], points[0][1]], zoom_start=25)

    for point in points:
        try:
            lats.append(float(point[0]))
            lons.append(float(point[1]))
        except:
            break
    # Add a marker with a popup
    folium.PolyLine(locations=zip(lats, lons), color='red', weight=5).add_to(m)
    # Save as an HTML file
    m.save("map.html")

    print("Map created! Open 'map.html' in your browser to view it.")


def main():
    app = BluetoothController()
    app.mainloop()
    # If the tkinter window is closed, the program will exit
    while app.winfo_exists():
        pass
    print("Exiting program...")
    app.send_port.close()  # Close the serial port connection
    exit()
    
    
if __name__ == "__main__":
    main()
