import tkinter as tk

window=tk.Tk()
window.title('my title')
window.geometry('200x200')

e=tk.Entry(window,show=None)
#show='*' passwd
e.pack()

#insert_point
def insert_pointer():
    var=e.get()
    t.insert('insert',var)
    #'1.1' for array[1][1],'1.2' for array[1][2], and vice versa

b = tk.Button(window,text='insert point',width=15,height=2,command=insert_pointer)
b.pack()

def insert_end():
    var=e.get()
    t.insert('end',var)

b2=tk.Button(window,text='insert end',width=15,height=2,command=insert_end)
b2.pack()

t = tk.Text(window,height=2)
t.pack()

window.mainloop()