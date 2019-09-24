//author is Erik de Zeeuw
#ifndef RTTTL_PRINT_HPP
#define RTTTL_PRINT_HPP
    
void rtttl_print(const char *s ){

    int found = 0; 
    bool note = 0;
    int default_note = 0;
    
    while(*s != '\0'){      //while there are notes to be found
        if(*s == ':'){      //filter the first part
            found ++;
        }else if(*s >= 'a' && *s <= 'g' && found == 2){     //if *s is a note
            char temp = *s ^ 32;                            //lowercase to uppercase
            hwlib::cout << temp;                            //cout the note 
            note = true;                                    //and remember to put the next number as well
            
        }else if(note){                                     //if this is the char after a note
            if( *s != ',' && *s != '.'){                    //if it is not a , or .
                hwlib::cout << *s;                          //cout it
            }else{
                hwlib::cout << default_note;                //if it is a , or . , cout default note
            }
            hwlib::cout << " ";
            note = false;                                   //and start over
        }
        if(found == 1 && *s == 'o'){                        //if you a 'o' at near the beginning, define a default note
            s += 2;
            default_note = *s - 48;
        }
        s++;    //and continue
    }
    if(note){
        hwlib::cout << default_note;
    }
    
}
#endif