import tkinter as tk
import random

window=tk.Tk()
window.title('love index predictor')
window.geometry('220x200')

label_1 = tk.Label(window,text='Enter Your Name',width=15,height=2,font=('Arial',12))
e=tk.Entry(window,show=None)
label_2 = tk.Label(window,text="Enter Your favourite girl/ boy's name",width=20,height=2,font=('Arial',12))
e1=tk.Entry(window,show=None)
#show='*' passwd
e.pack()
e1.pack()


def insert_text():
    var = 'The probability of marrying the person you love is ' + str(round(random.uniform(0,100),2))+"%."
    t.configure(state='normal')
    t.delete('0.0', 'end')
    t.insert('0.0',var)
    t.configure(state='disabled')

b2=tk.Button(window,text='Predict',width=15,height=2,command=insert_text)
b2.pack()

t = tk.Text(window,height=2)
t.pack()

window.mainloop()