#!/usr/bin/python
from gi.repository import Gtk
import os
import serial_graphics
#Program to give GUI for the Project ADDER Authors: Musaddiq Faraz, Sameer Shaik, Shashi Kiran Reddy, Sujay
class GUI(Gtk.Window):
	def toggle_graphics(self,check):
		if (self.show1 == 1):
			self.show1 = 0
			self.entry_3.hide()
			self.entry_4.hide()
			self.button2.hide()
			self.label_3.hide()
			
		else:
			self.show1=1
			self.entry_3.show()
			self.entry_4.show()
			self.label_3.show()
			self.button2.show()	
			

	def __init__(self):
	        Gtk.Window.__init__(self, title="ADDER")
		self.set_position(Gtk.WindowPosition.CENTER)
		self.set_border_width(15)
		self.entry_text_1 = "null"
		self.entry_text_2 = "null"
	        table = Gtk.Table(10, 10, False)
	        self.add(table)
	
	        self.label = Gtk.Label("Answer : " + answer)
	        button = Gtk.Button("ADD")
	        button.connect("clicked", self.button_pressed)
		
		label_app = Gtk.Label("Application Adder ")
		label_1 = Gtk.Label("Enter number1: ")
		entry_1 = Gtk.Entry()
		entry_1.connect("changed", self.enter_callback_1, entry_1)
		label_2 = Gtk.Label("Enter number2: ")
		entry_2 = Gtk.Entry()
		entry_2.connect("changed", self.enter_callback_2, entry_2)
		self.label_3 = Gtk.Label("Enter 4-bit Number ")
		self.entry_3 = Gtk.Entry()
		self.entry_4 = Gtk.Entry()
		self.entry_3.set_max_length(4)
		self.entry_4.set_max_length(4)
		self.show1 = 1
		self.button2 = Gtk.Button("Simulate")
		self.button2.connect("clicked", self.button2_pressed)
		check = Gtk.CheckButton("4-bit Graphical Adder")
		check.set_active(True)
		check.connect("toggled", self.toggle_graphics)
        	check.show()
		about = Gtk.Button("About")
        	about.connect("clicked", self.aboutdig)
		
		table.attach(label_app,1,10,1,2)
		table.attach(label_1,1,2,2,3)
		table.attach(entry_1,2,10,2,3)
		table.attach(label_2,1,2,3,4)
		table.attach(entry_2,2,10,3,4)
	        table.attach(self.label, 1, 10, 5, 6)
	        table.attach(button, 2, 10, 4, 5)
		table.attach(about, 1, 2, 4, 5)
		table.attach(check,1,10,6,7)
		table.attach(self.label_3,1,3,7,8)
		table.attach(self.entry_3,3,5,7,8)
		table.attach(self.entry_4,5,7,7,8)
		table.attach(self.button2,7,10,7,8)
	def aboutdig(self, widget):
		message="Program to simulate adder...\nAuthors: Musaddiq Faraz, Sameer Shaik, Shashi Kiran Reddy, Sujay"
        	dialog = Gtk.MessageDialog(self, 0, Gtk.MessageType.INFO,Gtk.ButtonsType.OK, "About the program")
        	dialog.format_secondary_markup(message)
        	dialog.run()
        	dialog.destroy()
	def button2_pressed(self, button):
		x = self.entry_3.get_text()
		y = self.entry_4.get_text()
		c = ""
		temp1 = int(x)
		temp2 = int(y)
		s = str(temp1 + temp2)
		while temp1!=0 and temp2!=0 :
			if (temp1%10+temp2%10 > 9):
				c = c + '1'
			else:
				c = c + '0'
			temp1 = temp1/10
			temp2 = temp2/10
		x = correct(x[::-1])
		y = correct(y[::-1])
		c = correct(c[::-1])
		s = correct(s[::-1])
		c = '0' + c
		serial_graphics.main(x,y,c,s)
			
	def button_pressed(self, button):		
		os.system("gcc main.c -o add")
		if (os.name == "posix"):
			command="./add "+self.entry_text_1+" "+self.entry_text_2+" >ans"
		else:
			command="add "+self.entry_text_1+" "+self.entry_text_2+" >ans"
		os.system(command)
		fobj = open("ans","r")
		answer = fobj.readline()
		answer = answer[:len(answer)-1]
		fobj.close()
		os.system("rm add")
        	self.label.set_text("Sum = "+answer)
	def enter_callback_1(self, widget, entry_1):
        	self.entry_text_1 = entry_1.get_text()
		return
	def enter_callback_2(self, widget, entry_2):
        	self.entry_text_2 = entry_2.get_text()
        	return
def correct(str1):
	len1=len(str1)
	while len1<4:
		str1 = str1 + '0'
		len1+=1
	return str1

entry_text_1="null"	
answer="null"
win = GUI()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()
