#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR -1

int termo(char* string_line, int linepos);
int fator(char* string_line, int linepos);
int soma(char* string_line, int linepos);

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
int Exp(char* string_line, int linepos){
    //string_line[n] will works like the tapehead
    int term = termo(string_line, linepos);//function termo
    if(term == 1){
        printf("%c ", string_line[linepos]);
        return 1;
    }
    int sum = soma(string_line, linepos);
    if(sum == 1){
        printf("%c ", string_line[linepos]);
        return 1;
    }
}

/**
 * @brief 
 * 
 * @param string_line 
 * @param linepos 
 * @return int 
 */
int soma(char* string_line, int linepos){
    if(string_line[linepos] == '+' || string_line[linepos] == '-'){
        return 1;
    }else{
        return 0;
    };
}
/**
 * @brief this function will check if the token held by linepos is a term
 * @param linepos 
 * @return true 
 * @return false 
 */
int termo(char* string_line, int linepos){
    int result = fator(string_line, linepos);//function fator
    if(result == 1){
        return 1;
    }else{
        return 0;
    }
}
/**
 * @brief 
 * 
 * @param linepos 
 * @return true 
 * @return false 
 */
int fator(char* string_line, int linepos){
    if(string_line[linepos] == '('){
        while(string_line[linepos] != ')'){
            Exp(string_line, linepos);
            linepos++;
        }
    }else{
        if(string_line[linepos] >= 48 && string_line[linepos] <= 57){
            //match occurs with a number and get the next token
            return 1;
        }
    }
    return ERROR;
}



int main(){
    char* string_line = "2+3+5+7+9";//string_line will works like the tape
    int linepos = 0;
    while(string_line[linepos] != '\0'){
       Exp(string_line, linepos);
       linepos++;
    }   
    return 0;
}