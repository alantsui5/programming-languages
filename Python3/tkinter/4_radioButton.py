import tkinter as tk

window=tk.Tk()
window.geometry('200x200')
window.title('my title')

var = tk.StringVar()
l = tk.Label(window,textvariable=var,bg='yellow',width=4)
l.pack()

def print_selection():
    l.config(text='youhave selected'+var.get())

r1=tk.Radiobutton(window,text='Option A',variable=var,value='A',command=print_selection)
r1.pack()
r2=tk.Radiobutton(window,text='Option B',variable=var,value='B',command=print_selection)
r2.pack()
r3 = tk.Radiobutton(window, text='Option C', variable=var, value='C', command=print_selection)
r3.pack()

window.mainloop()