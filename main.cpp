/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "mystring.h"


#define string Mystring
using namespace std;



/*
 * Check function from the previous lab
 */
void check (const string s, const string name)
{

 

    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main() 
{
 
    string s1("Hello, World!");
    string s1name("s1");
    string s4;



    //check(s1, s1name);    
    
    cout << "---Testing assignment operator and == operator---\n";    
    string s2;
    s2=s1 ;
    string s2name("s2");
    check(s2,s2name);


    //Testing C- string operator
    cout << "Testing c-string assignment operator" << endl;
    s4 = "quick_brown_fox";
    
    cout << "s4_size:" << s4.size() << endl;
    check(s4, "s4");

    cout << "--------------------------------------\n\n" ;
    
    char array[] = "quick_brown_fox";
    cout<< "testing first relational equal operator" << endl;
    if(s1== s2)
        cout << "s1 and s2 are same string" << endl;

    
    //Testing second relational equal operator
    cout << "testing second relational equal operator" << endl;
    if (s1 == "Hello, World!")
        cout << "correct" << endl;

    cout << "testing thrid relati0onal equal operator" << endl;

    if( array == s4)
        cout << "correct" << endl;
    cout << "--------------------------------------\n\n" ;


    
    cout << "---relational != operators----\n";
    string s3("Hi");
    check(s3,"s3");
    check(s3,"s3");
    char array_2[] = "hello";
    cout << s3 << endl; 
    cout << "first relational opreator" << endl;
    if(s3 != "Hey")
        cout << "your assignment operator is wrong" << endl;
    else
        cout << "assignment operator is correct" << endl;
    check (s3,"s3");
    

    cout << " -------second relational operator--------" << endl;
        if (array_2!= s4)
            cout << "assignment operator is correct" << endl;
        else
        {
            cout << "assigment operator is wrong" << endl;
        }



   

    cout << "s3 before assignment operator:" << s3 << endl;
     if (s3!= s4)
           cout << "assignment operator is correct" << endl;
        else
        {
            cout << "assigment operator is wrong" << endl;
        }

     cout << "--------------------------------------\n\n" ;

    cout << "s3 after assignment operator:" << s3 << endl;
    check (s3, "s3");
    





    
    
    check(s1, s1name); 
    cout << "---Testing array notation---\n";
    cout << "second char of s1: "<< s1[1] << endl;
    cout << "--------------------------------------\n\n" ; 

    check (s3, "s3");

   //second array notation


    /*
    cout << "----Testing clear----\n";
    s3.clear();
    check (s3,"s3");
    s3= "hello";
    check(s3, "s3");

    checking pushback
    char c = '!';
    s3.push_back(c);
    check(s3, "s3");
    */





    //Testing += operator
    check (s3, "s3");
    cout << "---Testing += operator ---\n";
    s2 += s1;
    cout << "s2 after += s1: "<< s2 << endl;
   

    check (s3, "s3");
    
    //Testing second += operator
    cout << "---Testing 2nd += operator ---\n";
    check(s3,"s3");
    s3 += "you";
    cout << "s3 after +=" << s3 << endl;        
    cout << "--------------------------------------\n\n" ;
    
    
    
    cout << "---Testing append ---\n";
    s2.append("??");
    cout << "s2 after append s1: "<< s2 << endl;
    check(s2,"s2");
    


    
    //Testing second append function
    cout << "---Testing second append----\n";
    string s5 = "goodbye";

    cout << "original s5:" << s5 << endl;
    cout << "original s4:" << s4 << endl;
    s4.append(s5); 
    check(s4,"s4");
    cout << "original s5:" << s5 << endl;
    cout << "original s4:" << s4 << endl;










    cout << "--------------------------------------\n\n" ;
    
    
    cout << "---Testing insert ---\n";
    check(s2,"s2");

   
    s2.insert(6, "c++");
    check(s2,"s");
    
    /*cout << "--Testing second input" << endl;

    //Checking second insert function
    cout << "testing second insert function ---\n";
    cout << "original s5:" << s5 << endl;
    cout << "original s4:" << s4 << endl;
    s5.insert(3, s4); 
    check (s5, "s5");*/





    cout << "--------------------------------------\n\n" ;  



     
    
    /*cout << "---Testing replace ---\n";
    cout << "s2 before replace" << s2 << endl;
    s2.replace(6, 7, "code");
    cout << "s2 after replace: "<< s2 << endl;*/

    //Checking second replace function
    /*
    cout << "testing replace 2----\n";

    s4.replace(3,4, s5);

    check (s4,"s4");



    cout << "--------------------------------------\n\n" ;*/


    
    
    check(s2,"s2");
    cout << "---Testing find_first_of ---\n";
    cout << "s2 find first of aeiou after index 2: " << s2.find_first_of("aeiou", 2, 7);
    cout << "--------------------------------------\n\n" ; 
    
    
    cout << "---Testing find_last_not_of ---\n";
    cout << "s1: " << s1.length() << endl;
    cout << "s1 find find_last_not_of !? after index 2: " << s1.find_last_not_of("!?");
    cout << "--------------------------------------\n\n" ;
   
   
    /**cout << "---Testing + ---\n";
    s3 = s1 + s2;
    cout << s3 << endl;
    cout << "--------------------------------------\n\n" ;*/
    
  
          
    return 0;
}