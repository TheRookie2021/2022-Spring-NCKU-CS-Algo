# passing pointer/ address of pointer in a function 
!!FORGET ABOUT PASSING BY REFERENCE OR PASSING BY VALUE!!  

When using a function, it does not verify what kind of passing method it is using, it is all the same to a function.  

What seperates these two passing concepts is whether the function is manipulating an address or not.  
In general, a function always passing a copy of the variable, and the manipulation in a function can only base on the copy it recieves.  
  
Thus, what makes function a "pass by value" or "pass by ref" depends on the kind of data it recieves:  
- if a function recieves a copy of (int), it manipulates the data of that copy.  
- if a function recieves a copy of (int*), which means it recieves an copy of an address, it manipulates the data based on the address. 
    
futher Q: how "delete" works in a function? 

