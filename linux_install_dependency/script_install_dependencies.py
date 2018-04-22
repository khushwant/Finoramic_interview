#!/usr/bin/python                                                                                                                                                                     
import os                                                                                                                                                                             
import json                                                                                                                                                                           
                                                                                                                                                                                      
json_abspath = os.path.abspath('dependency.json')                                                                                                                                     
failed_cases = []                                                                                                                                                                     
fd = open(json_abspath)                                                                                                                                                               
json_data = json.load(fd)                                                                                                                                                             
                                                                                                                                                                                      
'''                                                                                                                                                                                   
print("\t\tTest\t")                                                                                                                                                                   
t1 = "idna"                                                                                                                                                                           
file1 = open("tmp.txt",'r').read()                                                                                                                                                    
output = "Successfully installed %s"%t1                                                                                                                                               
if "Successfully installed %s"%t1 in file1:                                                                                                                                           
    print("Successfull")                                                                                                                                                              
else:                                                                                                                                                                                 
    print("failed")                                                                                                                                                                   
'''                                                                                                                                                                                   
                                                                                                                                                                                      
for key,val in json_data['dependencies'].items():                                                                                                                                     
    #print("%s == %s"%(key,val))                                                                                                                                                      
    cmd = "pip install %s==%s"%(key,val)                                                                                                                                              
    #print("cmd: %s"%cmd)                                                                                                                                                             
    os.system('%s > tmp_%s.txt'%(cmd,key))                                                                                                                                            
    with open('tmp_%s.txt'%key,'r') as fd:                                                                                                                                            
        install_logs = fd.read()                                                                                                                                                      
        #print("start:\n %s \n\n End"%install_logs)                                                                                                                                   
        if not "Successfully installed %s"%key in install_logs:                                                                                                                       
            #print("failed")                                                                                                                                                           
            failed_cases.append("%s == %s"%(key,val))                                                                                                                                 
                                                                                                                                                                                      
    os.remove('tmp_%s.txt'%key)                                                                                                                                                       
                                                                                                                                                                                      
if not failed_cases:                                                                                                                                                                  
    print("success")                                                                                                                                                                  
else:                                                                                                                                                                                 
    for failed_case in failed_cases:                                                                                                                                                  
        print("%s\n"%failed_case)                                                                                                                                                          
