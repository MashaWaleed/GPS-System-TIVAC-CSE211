











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
