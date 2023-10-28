#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR -1
/*  This is the grammar of the language
    exp -> termo {sum term}
    sum -> + | - 
    term -> fator {mult factor}
    mult -> *
    factor -> (exp) | number 
 */

int term(char* string_line, int* linepos);
int factor(char* string_line, int* linepos);
int sum(char* string_line, int* linepos);
int mult(char* string_line, int* linepos);

/**
 * @brief this function will start the grammar analysis by calling the function Exp.
 * Note that from this point we can derive all the rest of the grammar, thus it
 * means from Exp we can get 'number' or '*', for example.
 * @param string_line works like the tape and receive the source code
 * @param linepos reference to the variable linepos that exists in main()
 * @return int 
 */
int Exp(char* string_line, int* linepos){
    //string_line[n] will works like the tapehead
    int t = term(string_line, linepos);//function termo
    if(t == 1){
        printf("%c ", string_line[*linepos]);
        return 1;
    }
    int s = sum(string_line, linepos);
    if(s == 1){
        printf("%c ", string_line[*linepos]);
        return 1;
    }
}

/**
 * @brief This function checks if the current token is a + or -
 * @param string_line 
 * @param linepos 
 * @return int 
 */
int sum(char* string_line, int* linepos){
    if(string_line[*linepos] == '+' || string_line[*linepos] == '-'){
        return 1;
    }else{
        return 0;
    }
}


/**
 * @brief this function have the same principle of exp, but it just derives factor.
 *  and mult. So, from this point we can have a '*' or an (exp), for example. 
 * @param string_line 
 * @param linepos 
 * @return int 
 */
int term(char* string_line, int* linepos){
    int result = factor(string_line, linepos);//function fator
    if(result == 1){
        return 1;
    }
    int m = mult(string_line, linepos);
    if(m == 1){
        return 1;
    }
}
    
/**
 * @brief this function have the same principle of Exp as well, but it just derives 
 * (exp) and 'num'.
 * @param string_line 
 * @param linepos 
 * @return int 
 */
int factor(char* string_line, int* linepos){
    if(string_line[*linepos] == '('){
        printf("%c ", string_line[*linepos]);
        while(string_line[*linepos] != ')'){
            (*linepos)++;//increments 
            Exp(string_line, linepos);
        }
        printf("%c ", string_line[*linepos]);
    }else{
        //match occurs with a number and get the next token
        if(string_line[*linepos] >= 48 && string_line[*linepos] <= 57){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief this function test if the current token is '*'.
 * @param string_line 
 * @param linepos 
 * @return int 
 */
int mult(char* string_line, int* linepos){
     if(string_line[*linepos] == '*'){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char* string_line = "(8+9)+(7+4-5*9-1+9)+7+8+0";
    int linepos = 0;//linepos will work as the tapehead
    while(string_line[linepos] != '\0'){
       Exp(string_line, &linepos);
       linepos++;
    }   
    return 0;
}