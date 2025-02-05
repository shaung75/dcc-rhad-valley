// This is the startup sequence, 
AUTOSTART
// we need to set all relay pins to HIGH as the board is LOW trigger
SET(22)
SET(23)
SET(24)
SET(25)
SET(26)
SET(27)
SET(28)
SET(29)
SET(30)
SET(31)
SET(32)
SET(33)
SET(34)
SET(35)
SET(36)
SET(37)
DONE 

#define PULSE 50 //mSec

#define DUAL_SOLENOID_TURNOUT(id,pc,pt,desc,ali) \
VIRTUAL_TURNOUT(id,desc) \
ALIAS(ali,id) \
DONE \
ONCLOSE(id) \
RESET(pc) \
DELAY(PULSE) \
SET(pc) \
DONE \
ONTHROW(id) \
RESET(pt) \
DELAY(PULSE) \
SET(pt) \
DONE

// Define the points
DUAL_SOLENOID_TURNOUT(1,22,23,"Platforms",TURNOUT_1)
DUAL_SOLENOID_TURNOUT(2,24,25,"Yard Entry",TURNOUT_2)
DUAL_SOLENOID_TURNOUT(3,26,27,"Yard 1",TURNOUT_3)
DUAL_SOLENOID_TURNOUT(4,28,29,"Yard 2",TURNOUT_4)
DUAL_SOLENOID_TURNOUT(5,30,31,"Fiddle 1",TURNOUT_5)
DUAL_SOLENOID_TURNOUT(6,32,33,"Fiddle 2",TURNOUT_6)
DUAL_SOLENOID_TURNOUT(7,34,35,"Fiddle 3",TURNOUT_7)
DUAL_SOLENOID_TURNOUT(8,36,37,"Fiddle 4",TURNOUT_8)

// Define the locos
ROSTER(5382,"Class 27 - D5382","F0/F1/*F2/F3/F4/F5/F6/F7/F8")

// Define the routes
ROUTE(1,"Platform 1")
  THROW(1)
  DONE
  
ROUTE(2,"Platform 2")
  CLOSE(1)
  DONE
  
ROUTE(3,"Fiddle 1")
  THROW(5)
  CLOSE(7)
  CLOSE(8)
  DONE
  
ROUTE(4,"Fiddle 2")
  THROW(5)
  CLOSE(7)
  THROW(8)
  DONE

ROUTE(5,"Fiddle 3")
  THROW(5)
  THROW(7)
  DONE

ROUTE(6,"Fiddle 4")
  CLOSE(5)
  CLOSE(6)
  DONE

ROUTE(7,"Fiddle 5")
  CLOSE(5)
  THROW(6)
  DONE
