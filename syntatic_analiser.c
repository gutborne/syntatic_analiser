#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief this function will start by the first token of the grammar
 * @param string_line 
 * @return true 
 * @return false 
 */
bool exp(char* string_line){
    //linepos will works like the tapehead
    char linepos = string_line[0];
    termo(linepos);//function termo
}
/**
 * @brief this function will check if the token held by linepos is a term
 * @param linepos 
 * @return true 
 * @return false 
 */
bool termo(char linepos){
    fator(linepos);//function fator
}
/**
 * @brief 
 * 
 * @param linepos 
 * @return true 
 * @return false 
 */
bool fator(char linepos){
    if(linepos == '('){
        exp();
    }
}
/*  This is the grammar of the language
    exp -> termo {soma termo}
    soma -> + | - 
    termo -> fator {mult fator}
    mult -> *
    fator -> (exp) | número 
 */

int main(){
    char string_line = "2+3+5+(9+0)";
    exp(string_line);
    return 0;
}