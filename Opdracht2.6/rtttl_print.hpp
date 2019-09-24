#ifndef RTTTL_PRINT_HPP
#define RTTTL_PRINT_HPP
    
void rtttl_print(const char *s ){
    int found = 0; 
    bool note = 0;
    
    while(*s != '\0'){      //while there are notes to be found
        if(*s == ':'){      //filter the first part
            found ++;
        }else if(*s >= 'a' && *s <= 'g' && found == 2){     //if *s is a note
            char temp = *s ^ 32;                            //lowercase to uppercase
            hwlib::cout << temp;                            //print it
            note = true;                                    //remember to print the next char aswell
        }else if( note ){
            if( *s != ',' && *s != '.'){                    //unless it is a , or .
                hwlib::cout << *s;                          //print it
            }
            hwlib::cout << " ";
            note = false;                                   //and start over again
        }
        s++;    //and continue
    }
}

#endif