To run my program you need to compile all the Class files(.cpp and .h) and the
driver file Projec1.cpp. Then run the executable created from this.  
The command to do this is: 
g++ Project1.cpp Time.cpp Date.cpp Appointment.cpp User.cpp
AppointmentDiary.cpp -o p1

Then to run the executable use:
./p1 

There is a problem with the implemantation where if the user inputs more
than one char during the welcome screen it will input use the rest of the 
input beside the first letter to answer the promts that come after the menu 
item.  For example if someone were to type Apple it would create a usser called
"pple". To fix this I would limit the system to only read the first letter
of the inputs during the welcome screen. 
