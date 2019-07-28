import tkinter as tk

window = tk.Tk()
window.title('Milianare generator')
window.geometry('200x200')

#the text
var = tk.IntVar()
state = tk.StringVar()
#Label,text left
state_label = tk.Label(window,textvariable=state,bg='yellow',font=('Arial',12),width=30,height=2)
state_label.pack()
l = tk.Label(window,textvariable=var,bg='green',font=('Arial',12),width=30,height=2)
l.pack()

#hit_me
def hit_me():
    global var,state
    value=var.get()+1
    state_setter(value,state)
    show_boost_money(value,state)
    var.set(value)
# Set your social status
def state_setter(value,state):
    if value < 10:
        state.set('Work hard!')
    elif value < 100:
        state.set('You are tenaire')
    elif value < 1000:
        state.set('You are hundredaire')
    elif value < 100000:
        state.set('You are thousandaire')
    elif value < 1000000000:
        state.set('You are millionare!!!!!!!')


# Multiply your money by 10 
def boost_money():
    global var,state
    value=var.get()*2
    state_setter(value,state)
    var.set(value)

def show_boost_money(value,state):
    global b1
    if value >= 100:
        b1.pack()


#Buttons
b=tk.Button(window,text='hit me to get $1',width=15,height=2,command=hit_me)
b.pack()
b1 = tk.Button(window,text='Boost your money!!',width=15,height=2,command=boost_money)
b1.pack_forget()

window.mainloop()