script anatomy:

FunctionType, ReturnType, FunctionName, Argument1, Argument2

example: native void: Timer_SetETimer(event, float: time);

FunctionType: always native
Return Type: most of these will be void which means returns nothing. 
	     I'm not sure if a return type is required



script format:
#include: the includes are just which libraries 
          to reference(you can't overinclude, so just include em all)

new: 	  things in the level itself that are being declared to be used
	  in the script. Example if you have a door, you'd put "new Door:secretDoor0;"


