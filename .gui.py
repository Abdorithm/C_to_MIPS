# from tkinter import *
# import subprocess
# win=Tk()
# win.geometry('1300x900')
# win.title("C_toMips")
# win.configure(bg="#0f1a2b")
# with open("output.txt", 'r') as file:

#     file_contents = file.read()
# v= Label(text=file_contents,font=25,foreground="black",width=50,height=30,bg="pink")
# v.place(x=20,y=150)
# def delete():
#     v.destroy()
#     dele.destroy()
# def delete2():
#     m.destroy()
#     dele1.destroy()
# dele=Button(win,command=delete,text="x")
# dele1=Button(win,command=delete2,text="x")
# m= Label(text="Mips",font=10,foreground="black",width=50,height=30,bg="pink")
# m.place(x=820,y=150)
# dele.place(x=470,y=140)

# dele1.place(x=1275,y=140)

# convert = Button(win,text="Convert",width=12,height=4,font=18,bg="cadetblue",foreground="white")
# convert.place(x=580,y=450)
# win.mainloop()
from tkinter import *
import subprocess
import os
root = Tk()
root.geometry("700x900")
root.title(" Q&A ")

def compile_and_run_c_code():
    # Compile the C code using gcc
    subprocess.run(['rm -rf input output'], ['./mipsify', 'output.txt', '>','input.txt'])
    #./mips text.txt > "output.txt"

    

# if __name__ == "__main__":
  
#     compile_and_run_c_code()

def Take_input():
    INPUT = inputtxt.get("1.0", "end-1c")
    with open("output.txt", 'w') as file:
        file_contents = file.write(INPUT)
    compile_and_run_c_code()
    with open("input.txt","r") as file:
        inputfile = file.read()
        Output.insert(END, inputfile)


l = Label(text = "What is 24 * 5 ? ")

inputtxt = Text(root, height = 20,
                width = 50,
                bg = "light yellow")


Output = Text(root, height = 20,
              width = 50,
              bg = "light cyan")

Display = Button(root, height = 2,
                 width = 20,
                 text ="Show",
                 command = lambda:Take_input())



l.pack()
inputtxt.pack()
Display.pack()
Output.pack()
os.system('cls' if os.name == 'nt' else 'clear')

root.mainloop()
