#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//list of keywords
const char* keywords[] = {"int", "float", "if", "else", "while", "return", "for", "break", "continue", "main"};

const int keywordCount = 10;
//list of operators
const char operators[] = "+-*/=<>&|;,(){}[]";

bool isKeyword(const char* tok) {
    for(int i = 0; i < keywordCount; i++) {
        if(strcmp(tok, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
bool isOperator(char ch) {
    for(int i = 0; i < strlen(operators); i++) {
        if(ch == operators[i]) {
            return true;
        }
    }
    return false;
}
void lexicalAnalyzer(const char* filename) {

    FILE* file = fopen(filename, "r");
    if(!file) {
        printf("Opps! Unable to open file %s! ", filename);
        return;
    }
    char str[256];
    char token[100] = "";
    int tokenId = 0;

    while(fgets(str, sizeof(str), file)) {
            int n = strlen(str);
            
            for(int i = 0;  i< n; i++) {
            char ch = str[i];
            if(isalpha(ch)) {
                token[tokenId++] = ch;
            }
            else if(isdigit(ch)) {
                if(tokenId > 0 && isalpha(token[0])) {
                    token[tokenId] = '\0';

                    if(isKeyword(token)) {
                        //keyword:
                        printf("%s\n", token);
                    }
                    else {
                        //Identifier: 
                        printf("%s\n", token);
                    }
                    tokenId = 0;
                }
                token[tokenId++] = ch;
            }

            //check if it is an operator
            else if(isOperator(ch)) {
                if(tokenId > 0) {
                    token[tokenId] = '\0';
                    if(isKeyword(token)) {
                        //keyword: 
                        printf("%s\n", token);
                    }
                    else if(isdigit(token[0])) {
                        //Number: 
                        printf("%s\n", token);
                    }
                    else {
                        //Identifier: 
                         printf("%s\n", token);
                    }
                    tokenId = 0;
                }
                //Operator :
                printf("%c\n", ch);
            }

            //handle whitespace
            else if(isspace(ch)) {
                if(tokenId > 0) {
                    token[tokenId] = '\0';
                    if(isKeyword(token)) {
                        //keyword: 
                        printf("%s\n", token);
                    }
                    else if(isdigit(token[0])) {
                        //Number:
                        printf("%s\n", token);
                    }
                    else {
                        //Identifier: 
                         printf("%s\n", token);
                    }
                    tokenId = 0;
                }
            }
        }

        //handling last token
        if(tokenId > 0) {
            token[tokenId] = '\0';
            if(isKeyword(token)) {
                //keyword: 
                printf("%s\n", token);
            }
            else if(isdigit(token[0])) {
                //Number: 
                printf("%s\n", token);
            }
            else {
                //Identifier: 
                printf("%s\n", token);
            }
        }
    }
}
int main() {
    // char str[256];

    // fgets(str, sizeof(str), stdin);

    // str[strcspn(str, "\n")] = '\0'; // Remove the newline character

    // lexicalAnalyzer(str);

    lexicalAnalyzer("input.txt");

    return 0;
}
