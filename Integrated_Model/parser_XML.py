#Library for creating an GUI
from tkinter import *
from tkinter import messagebox
from tkinter.filedialog import askopenfilename

import xml.etree.ElementTree as ET

import pandas as pd

import os

inputID=[]
inputName=[]
inputHead=[]

convertMenu=['Excel File (.xlsx)', 'Text File (.txt)', 'C source file (.c)']

def openFile():
    entryFile=askopenfilename(initialdir=".",filetypes =(("Xml File", "*.xml"),("All Files","*.*")),
                           title = "Choose a file:")
    checkFlag=checkFileType(entryFile)
    if checkFlag == True:
        ifileEntry.delete(0,'end')
        ifileEntry.insert(0,entryFile)
    else:
        messagebox.showerror("Error","Not an XML file")

def checkFileType(fileinput):
    checkFlag = fileinput.endswith(".xml")
    return checkFlag

def parseXML():
    global inputID
    global inputName
    global inputHead
    fileName=ifileEntry.get()
    
    fileOpen=open(fileName)
    try:
        filetree=ET.parse(fileName)
        fileRoot=filetree.getroot()
        for data in fileRoot:
            subID=[]
            subName=[]
            inputHead.append(data.tag)
            for childData in data.findall(".//input"):
                subID.append(childData.get("id"))
                subName.append(childData.get("inputname"))
            inputID.append(subID)
            inputName.append(subName)
        
        if parseVar.get() == convertMenu[0]:
            convertToExcel()
        elif parseVar.get() == convertMenu[1]:
            convertToText()
        elif parseVar.get() == convertMenu[2]:
            convertToC()

    except Exception as error:
        messagebox.showerror("Error","XML Format is Erroneous");

def convertToExcel():
    outXclFile = pd.ExcelWriter('Output_Data.xlsx')
    for num in range(len(inputHead)):
        dataDict={'ID':inputID[num],'Inputname':inputName[num]}
        dataStructure=pd.DataFrame(dataDict)
        dataStructure.index += 1
        print(dataStructure)
        dataStructure.to_excel(outXclFile, sheet_name = inputHead[num], index_label = 'Serial No.')
        dataDict.clear()
    outXclFile.save()
    outXclFile.close()
    messagebox.showinfo('Excel file Created','Converted to Excel File successfully')

def convertToText():
    textFile = open("Output_Data.txt", 'w')
    print("TEXT file is created")
    for i in range(len(inputHead)):
        headText='\n' + inputHead[i].upper()+': \n\n'
        textFile.write(headText)
        textFile.write("Serial No.\t InputId\t Input Name \n")
        for j in range(len(inputID[i])):
            subText = str(j+1) + ' \t\t' + inputID[i][j] + ' \t\t' + inputName[i][j] + '\n'
            textFile.write(subText)
    textFile.close()
    messagebox.showinfo('Text File Created','Converted to Text File Succesfully')

def convertToC():
    cFile = open("Output_Data.c", 'w')
    print("C Object file is created")
    cFile.write('#include <stdio.h>\n#include "data_table.h" \n\n')
    for i in range(len(inputHead)):
        cFile.write('/* ' + inputHead[i] + ' signal*/\n')
        for j in range(len(inputID[i])):
            cFile.write('#define ' + inputName[i][j] + '_Index ' + inputID[i][j] + '\n')
        cFile.write(' \n')
    for i in range(len(inputHead)):
        cFile.write('/* ' + inputHead[i] + ' signal variable*/\n')
        for j in range(len(inputID[i])):
            cFile.write('unsigned short ' + inputName[i][j] + ';\n')
        cFile.write(' \n')
    cFile.write('\nvoid readInputs()\n{\n')
    for i in range(len(inputHead)):
        for j in range(len(inputID[i])):
            cFile.write('\t put_data(' + inputName[i][j] + '_index, ' + inputName[i][j] + ');\n')
        cFile.write(' \n')
    cFile.write('}')
    cFile.close()
    messagebox.showinfo('C file created','Converted to C source file successfully')

#Creating the window
parseWindow = Tk()
parseWindow.title('XML PARSER')
parseWindow.geometry('500x400')
parseWindow.resizable(0,0)

#Adding the Logo
backCanvas = Canvas(height = 500, width = 500, bg = 'white')
backCanvas.place(x=0, y=0)
logoImage= PhotoImage(file='logoWhite.gif')
logo = Label(parseWindow, image = logoImage)
logo.place(x = 50, y = 10, height = 50, width = 200)

#Creating the buttons for input file
ifileButton = Button(parseWindow, text = 'File', fg = 'red', command=openFile)
ifileButton.place(x = 50, y = 110, height = 30, width = 70)
ifileEntry = Entry(parseWindow)
ifileEntry.place(x = 130, y = 110, height = 30, width = 300)

#Creating the buttons for Convertible Data type Option
convertLabel = Label(parseWindow, text = "Choose the data file: ")
convertLabel.place(x = 50, y = 190, height = 30, width = 150)
parseVar = StringVar(parseWindow)
parseVar.set(convertMenu[0])
optionMenubutton = OptionMenu(parseWindow, parseVar, *convertMenu)
optionMenubutton.place(x = 210, y = 190, height = 30, width = 150)

#Creating the buttons for Parsing The XML file
parseButton = Button(parseWindow, text = 'Parse', fg = 'red', command = parseXML)
parseButton.place(x = 75, y = 300, height = 50, width = 100)

#Creating the buttons for Closing the window
closeButton = Button(parseWindow, text = "Close", fg = "red")
closeButton.place(x = 325, y = 300, height = 50, width = 100)

#To Keep the main window open
parseWindow.mainloop()

