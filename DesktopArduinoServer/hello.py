import serial
import subprocess
import feedparser, time, os.path


ser = serial.Serial('COM4', 9600)
data_to_send = ""

USERNAME = ""   
PASSWORD = ""     

def check_mail():

        cur_mails = int(feedparser.parse("https://" + USERNAME + ":" + PASSWORD +"@mail.google.com/gmail/feed/atom")["feed"]["fullcount"])


        print("You have " + str(cur_mails) + " unread emails.")


        if os.path.isfile("emails.txt") == False: #create the file if it doesnt exist
                f = open('emails.txt', 'w')
                f.write('1'); #The interpreter doesn't like reading from an empty file
                f.close

        f = open('emails.txt', 'r')
        last_mails = int(f.read())
        f.close()

        print("Last known number of emails: "+ str(last_mails))

        

        if  cur_mails < last_mails:
            last_mails = cur_mails
            f = open('emails.txt', 'w')
            f.write(str(last_mails))

        if  cur_mails > last_mails:
            last_mails = cur_mails
            f = open('emails.txt', 'w')
            f.write(str(last_mails))

        f.close()
        return(cur_mails)


print("This program takes your login information with plaintext. Use at your own discretion.\n")
USERNAME = raw_input("Enter your gmail username: ")
PASSWORD = raw_input("Enter your gmail password: ")



while True:

        
        if check_mail() != 0:
                data_to_send = "1"
                ser.write(data_to_send.encode())

        if check_mail() == 0:
                data_to_send = "2"
                ser.write(data_to_send.encode())
        

        
