/*
 * File:   mystring.cpp
 * Author: wingning
 *
 * mystring class implementation:
 * methods whose implementations are provided:
 * default constructor
 * a constructor taking c-style string
 * the destructor
 * size, length, capacity, max_size
 * << operator for cout
 * c_str
 *
 * methods to be implemented:
 * a copy constructor
 * ...
 */

#include "mystring.h"

// default constructor
Mystring::Mystring() 
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s) 
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

//copy constructor to be implemented
Mystring::Mystring(const Mystring& orig) 
{
    //deep copy[new memory location in the heap--copy actual contents]
    len = orig.length();
    buf_size = len + 1;
    ptr_buffer =  new char(buf_size);
    strcpy(ptr_buffer, orig.ptr_buffer);
}

// one of the over loaded assignment operator if you have time
Mystring& Mystring::operator=(const Mystring& orig)
{
     if (this!= &orig)
    {
        delete[] this->ptr_buffer;
        len = orig.length();
        buf_size = len + 1;
        ptr_buffer = new char(buf_size);
        strcpy(this->ptr_buffer,orig.ptr_buffer);
    }
    return *this;
}

Mystring& Mystring::operator=(const char *s)
{
  
    //delete[] this->ptr_buffer;

   
    delete [] this-> ptr_buffer;
    len = strlen(s);
    buf_size = len + 1;
    ptr_buffer = new char [len];
    strcpy (this->ptr_buffer, s);
     

    
    
    return *this;

}
Mystring operator+(const Mystring&s1, const Mystring&s2)
{


    char array [100];
    strcpy(array,s1.c_str());

    strcat(array,s2.c_str());

    return array;

    

}


bool operator==(const Mystring&s1, const Mystring&s2)
{
   //converting strings into c-strings using using two different bufers


    char * bufer;
    char * bufer_2;
    int bufer_size;
    int size;
  

    size = s1.length();
    bufer_size = size + 1;
    bufer = new char[bufer_size];
    strcpy(bufer, s1.c_str());


   

    size = s2.length();
    bufer_size = size + 1;
    bufer_2 = new char[bufer_size];
    strcpy (bufer_2, s2.c_str());

   
    //strcmp is used to see if two c-strings are equivalent --> returns 0 if equal
    if (strcmp(bufer, bufer_2) == 0)
    {
        delete[] bufer;
        delete[] bufer_2;
        return true;
    }
    else
    {
        delete [] bufer;
        return false;
    }
    


}

bool operator==(const char *c, const Mystring&s1)
{
   

    char * bufer;
    int bufer_size;
    int size;
 

    size = s1.length();
    bufer_size = size + 1;
    bufer = new char[bufer_size];
    strcpy(bufer, s1.c_str());

 
    
   
    //strcmp is used to see if two c-strings are equivalent --> returns 0 if equal
    if (strcmp(c, bufer) == 0)
    {
        delete[] bufer;
        return true;
    }
    else
    {
      
        delete [] bufer;
        return false;;
    }



}


bool operator==(const Mystring&s, const char *c)
{
 

    char * bufer;
    int bufer_size;
    int size;
  

    size = s.length();
    bufer_size = size + 1;
    bufer = new char[bufer_size];
    strcpy(bufer, s.c_str());

    if (strcmp(bufer, c) == 0)
    {
        delete[] bufer;
        return true;
    }
    else
    {
        delete [] bufer;
        return false;
    }


}

bool operator!=(const Mystring&s1, const char *s2)
{
    
    char * bufer;
    int bufer_size;
    int size;



    size = s1.length();
    bufer_size = size + 1;
    bufer = new char[bufer_size];
    strcpy(bufer, s1.c_str());

 
    
   
    //strcmp is used to see if two c-strings are equivalent --> returns 0 if equal
    if (strcmp(bufer, s2) == 0)
    {
        delete[] bufer;
        return false;
    }
    else
    {
      
        delete [] bufer;
        return true;
    }

    
}

bool operator!=(const char *c, const Mystring&s1)
{
   

    char * bufer;
    int bufer_size;
    int size;
 

    size = s1.length();
    bufer_size = size + 1;
    bufer = new char[bufer_size];
    strcpy(bufer, s1.c_str());

 
    
   
    //strcmp is used to see if two c-strings are equivalent --> returns 0 if equal
    if (strcmp(c, bufer) == 0)
    {
        delete[] bufer;
        return false;
    }
    else
    {
      
        delete [] bufer;
        return true;
    }


}

bool operator!=(const Mystring&s1, const Mystring&s2)
{
    


     //converting strings into c-strings using using two different bufers


    char * bufer;
    char * bufer_2;
    int bufer_size;
    int size;
  

    size = s1.length();
    bufer_size = size + 1;
    bufer = new char[bufer_size];
    strcpy(bufer, s1.c_str());


   

    size = s2.length();
    bufer_size = size + 1;
    bufer_2 = new char[bufer_size];
    strcpy (bufer_2, s2.c_str());

   
    //strcmp is used to see if two c-strings are equivalent --> returns 0 if equal
    if (strcmp(bufer, bufer_2) == 0)
    {
        delete[] bufer;
        delete[] bufer_2;
        return false;
    }
    else
    {
        delete [] bufer;
        return true;
    }


}


 /*char Mystring:: operator[](size_type pos) const
 {
    
     
     

 }*/

char& Mystring:: operator[](size_type pos)
{

    //simply returns a char from ptr_buffer


    return ptr_buffer[pos];


}

Mystring& Mystring:: operator+=(const Mystring& str) 
{
  
    char string [100];

     strcpy(string, this->ptr_buffer);


     delete []this-> ptr_buffer;

     len = (strlen(string) + (strlen(str.c_str())));
     buf_size = len  + 1;
     this->ptr_buffer = new char[buf_size];

     strcat(string, str.c_str());

     strcpy(this->ptr_buffer, string);

    return *this;


   
}

Mystring& Mystring:: operator+=(const char*str)
{
     char string [100];

     strcpy(string, this->ptr_buffer);


     delete []this-> ptr_buffer;

     len = (strlen(string) + (strlen(str)));
     buf_size = len  + 1;
     this->ptr_buffer = new char[buf_size];

     strcat(string, str);

     strcpy(this->ptr_buffer, string);

    return *this;

}

/*Mystring operator+(const Mystring&s1, const Mystring&s2)
{
    cout << "operator+ called" << endl;
}*/

void Mystring :: clear()
{
   for ( int i = 0; i< strlen(this->ptr_buffer); i++)
        this->ptr_buffer[i] ='\0';
    

}

/*void Mystring:: push_back(char c)
{
    cout << "calling push_back" << endl;

    

 
   
}*/



 Mystring& Mystring:: append(const Mystring& str)
 {
    
     char string [100];

     strcpy(string, this->ptr_buffer);
     


     delete [] this-> ptr_buffer;

     len = (strlen(string) + (strlen(str.c_str())));
     buf_size = len  + 1;
     this->ptr_buffer = new char[buf_size];

     strcat(string, str.c_str());
    

     strcpy(this->ptr_buffer, string);




    return *this;
    
     
     
    
 }

 
 //size is not exactly right here for some reason but returns correctly
 Mystring& Mystring :: append(const char * str)
 {


     char string [100];

     strcpy(string, ptr_buffer);


     delete[] this-> ptr_buffer;

     len = (strlen(string) + (strlen(str)));
     buf_size = len  + 1;
     this->ptr_buffer = new char[buf_size];

     strcat(string, str);

     strcpy(this->ptr_buffer, string);

        return *this;

  




 }



Mystring& Mystring :: insert(size_type pos, const Mystring& str)
{
  //inintal c-string declared with a size large enough to accomdate strings
    char str_c[100];
 


    //strncpy and strcat are used to retrieve a portion of ptr_buffer into newly created c-string
    strncpy(str_c, this->ptr_buffer, pos);

    

    



    str_c[pos] = '\0';

    strcat(str_c, str.c_str());

    strcat (str_c, this->ptr_buffer + pos);

 
    //ptr_buffer intialized to the null character to empty the string
    delete[]this-> ptr_buffer;
    len = strlen(str_c) + strlen(str.c_str());
    buf_size = len  + 1;
    this->ptr_buffer = new char[buf_size];
    
    

    //desired string copied into ptr_buffer
    strcpy(this->ptr_buffer, str_c);

    return *this;


}
Mystring& Mystring :: insert(size_type pos, const char * str)
{

  //inintal c-string declared with a size large enough to accomdate strings
    char str_c[100];
    


    //strncpy and strcat are used to retrieve a portion of ptr_buffer into newly created c-string
    strncpy(str_c, this->ptr_buffer, pos);

    



    str_c[pos] = '\0';

    strcat(str_c, str);

    strcat (str_c, this->ptr_buffer + pos);

 
    //ptr_buffer intialized to the null character to empty the string
    delete[]this-> ptr_buffer;
    len = strlen(str_c) + strlen(str);
    buf_size = len  + 1;
    this->ptr_buffer = new char[buf_size];


    //desired string copied into ptr_buffer
    strcpy(this->ptr_buffer, str_c);

    return *this;

}

/*Mystring& Mystring :: replace(size_type start, size_type span, const Mystring& str)
{
    cout << "second replace" << endl;

}*/


Mystring& Mystring:: replace(size_type start, size_type span, const char * str)
{
    cout << "replace operator" << endl;

    //two intermeidate c-strings used here
    char str_c[100];
    char str_d[100];
   
   //pos defines the beginning of the last part of the final string
    size_t pos;
    pos = (span + start);

    //similar logic used as insert
    strncpy(str_c, this->ptr_buffer,start);

    strcat(str_c, str);


    //the goal is append the final character in ptr_bufer into str_c to finish replacement
    //second intermediate c-string intalized to these characters beginning at pos
    int j = 0;
    for ( int i = pos; i < strlen(this->ptr_buffer); i++)
    {


        str_d[j] = this->ptr_buffer[i];
        j++;
            
    }

    //final replacement involves appending the last part of the string to str_c
    //final str_c string replacment copied into ptr_buffe
    strcat(str_c, str_d);
    strcpy(this->ptr_buffer, str_c);

    return *this;
}

Mystring :: size_type Mystring :: find_first_of(const char* s, size_type pos, size_type n) const
{   

int j = 0;
char c[100];
for ( int i = pos; i< pos + n; i++)
{
   c[j] = this->ptr_buffer[i];
   j++;
}

char target;


for ( int k = 0; k < strlen(c); k++)
{
       
    for (int j = k; j <strlen(s); j++)
    {
        if ( c[k] ==s[j] )
            {
             
                target = c[k];
                break;

            }
    }           
        
}

size_type targetIndex = 0;

for (size_type f = pos; f<= pos+n; f++)
    if (this->ptr_buffer[f] == target)
    {
       
        targetIndex= f;
        break;
    }

return targetIndex;

}
Mystring :: size_type Mystring :: find_last_not_of (const char* s, size_type pos) const
{
   

    const char * delimiters;
    delimiters = s;

    

    char str [100];



    int j = 0;
    for ( int i = 0; i< strlen(this->ptr_buffer); i++)
    {
        str[j] = this->ptr_buffer[i];
        j++;
    }

    size_t sequenceNumber;

    sequenceNumber = (strcspn(str, delimiters) -1);
   

    return sequenceNumber;


}


// some simple methods implemented for you
 Mystring::size_type Mystring::size() const 
 {
     return len;
 }
 
 Mystring::size_type Mystring::length() const
 {
     return len;
 } 
 
 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }
 
// Destructor
Mystring::~Mystring() 
{
    delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) 
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const 
{
    return ptr_buffer;
}