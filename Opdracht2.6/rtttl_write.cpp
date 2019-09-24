//Author is Erik de Zeeuw
#include "rtttl_write.hpp"
#include <fstream>
    
void rtttl_write(const char *s ){
    std::ofstream file;
    file.open("meldody.hpp");
    file << "//Author is Erik de Zeeuw\n\n#ifndef MELDODY_HPP\n#define MELDODY_HPP\n\nclass meldody : public melody {\npublic:\n\tvoid play( note_player & p ){";

    int found = 0; 
    bool note = 0;
    int default_note = 0;
    
    while(*s != '\0'){      //while there are notes to be found
        if(*s == ':'){      //filter the first part
            found ++;
        }else if(*s >= 'a' && *s <= 'g' && found == 2){     //if *s is a note
            char temp = *s ^ 32;                            //lowercase to uppercase
            file << "\n\t\tp.play( note{ note::" << temp;   //put a p.play() in the file 
            note = true;                                    //and remember to put the next number as well
            
        }else if(note){                                     //if this is the char after a note
            if( *s != ',' && *s != '.'){                    //if it is not a , or .
                file << *s;                                 //throw it in the file
            }else{
                file << default_note;                       //if it is a , or . , insert default note
            }
            file << ",  note::dQ } );";
            note = false;                                   //and start over
        }
        if(found == 1 && *s == 'o'){                        //if you a 'o' at near the beginning, define a default note
            s += 2;
            default_note = *s - 48;
        }
        s++;    //and continue
    }
    if(note){
        file << default_note << ",  note::dQ } );";
    }
    file << "\n\t}\n};\n\n#endif";
    file.close();
    
}