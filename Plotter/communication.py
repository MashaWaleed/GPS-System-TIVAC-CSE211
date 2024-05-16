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
