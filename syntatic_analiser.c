#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR -1

/*  This is the grammar of the language
    exp -> termo {soma termo}
    soma -> + | - 
    termo -> fator {mult fator}
    mult -> *
    fator -> (exp) | número 
 */

/**
 * @brief this function will start by the first token of the grammar
 * @param string_line 
 * @return true 
 * @return false 
 */
bool exp(char* string_line, int linepos){
    //string_line[n] will works like the tapehead
    bool term = termo(string_line[linepos], linepos);//function termo
    if(term == true){
        printf("%c", string_line[linepos]);
    }
    int sum = soma(string_line, linepos+1);
    if(sum == true){
        term = termo(string_line[linepos], linepos+2);
    }
}
/**
 * @brief this function will check if the token held by linepos is a term
 * @param linepos 
 * @return true 
 * @return false 
 */
bool termo(char* string_line, int linepos){
    bool result = fator(string_line[linepos]);//function fator
    if(result == true) return true;
    else return ERROR;
}
/**
 * @brief 
 * 
 * @param linepos 
 * @return true 
 * @return false 
 */
bool fator(char* string_line, int linepos){
    if(string_line[linepos] == '('){
        while(string_line[linepos] != ')'){
            exp(string_line, linepos);
            linepos++;
        }
    }else{
        if(string_line[linepos] > '48' && string_line[linepos] < '57'){
            //match occurs with a number and get the next token
            return true;
        }
    }
    return ERROR;
}

bool soma(char* string_line, int linepos){
    if(string_line[linepos] == '+' || string_line[linepos] == '-'){
        printf("%c", string_line[linepos]);
        return true;
    }else return false;
}


int main(){
    char string_line = "2+3+5";//string_line will works like the tape
    int linepos = 0;
    exp(string_line, linepos);
    return 0;
}