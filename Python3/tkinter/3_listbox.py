import tkinter as tk

window=tk.Tk()
window.geometry('200x200')
window.title('my title')

var1 = tk.StringVar()
l = tk.Label(window,textvariable=var1,bg='yellow',width=4)
l.pack()

def print_selection():
    value = lb.get(lb.curselection())
    var1.set(value)

b = tk.Button(window,text='print selection',command=print_selection,width=15,height=2)
b.pack()


var2=tk.StringVar()
var2.set((11,22,33,44))
lb = tk.Listbox(window,listvariable=var2)

#iteration
list_items = [1,2,3,4]
for item in list_items:
    lb.insert('end',item)
lb.insert(1,'first')
lb.insert(2,'second')
lb.delete(2)
lb.pack()

window.mainloop()