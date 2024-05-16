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
