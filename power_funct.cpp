if(n == 0){
        return 1;
    }
    if(x == 0){
        return 0;
    }
    long long int reminder = 1;
    int neg_check = 0;
    
    if(x < 0){
        x = abs(x);
        if(n%2 != 0){
            neg_check = 1;
        }
    }
    
    long long int temporary_reminder = x%d;
    
    while(n != 0){
        if(n%2 != 0){
            reminder = (reminder*temporary_reminder)%d;
        }
        
        temporary_reminder = temporary_reminder*temporary_reminder;
        temporary_reminder = temporary_reminder%d;
        
        n = n/2;
        if(reminder > d){
            reminder = reminder%d;
        }
    }
    
    if(neg_check == 1){
        return d-(int)reminder;
    }
    
    return (int)reminder;