#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

const char operators[] = "+-*/=<>&|;,(){}[]";

bool isOperator(char ch) {
    for(int i = 0; i < strlen(operators); i++) {
        if(ch == operators[i]) {
            return true;
        }
    }
    return false;
}

void lexems(const char* filename) {
	FILE* file = fopen(filename, "r");
	FILE* output = fopen("output.txt", "a");

	//debug
	if(!file) {
		printf("Unable to open file!");
	}

	char str[256];
	char token[100] = "";
	int tokenId = 0;

	while(fgets(str, sizeof(str), file)) {
		int n = strlen(str);

		for(int i = 0; i < n; i++) {
			char ch = str[i];

			if(isalpha(ch)) {
				token[tokenId++] =ch;
			}
			else if(isdigit(ch)) {
				if(tokenId > 0 and isalpha(token[0])) {
					token[tokenId] = '\0';
					fprintf(output, "%s\n", token);
					tokenId = 0;
				}
				token[tokenId++] = ch;
			}
			else if(isOperator(ch)) {
				if(tokenId > 0) {
					token[tokenId] = '\0';
					fprintf(output, "%s\n", token);
					tokenId = 0;
				}
				fprintf(output, "%c\n", ch);
			}

			//handling space
			else if(isspace(ch)) {
				if(tokenId > 0) {
					token[tokenId] = '\0';
					fprintf(output, "%s\n", token);
					tokenId = 0;
				}
			}
			
		}

		if(tokenId > 0) {
			token[tokenId] = '\0';
			fprintf(output, "%s\n", token);
			tokenId = 0;
		}
	}
	fclose(file);
	fclose(output);
}

int main() {
    const char* filename = "file.txt";
    int c = 0;

    while(true) {
        FILE* file = fopen(filename, "a");  //append mode
    
        char str[256];

        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "999") == 0) {
            break;
        }

       // printf("%s\n", str);
        fprintf(file, "%s\n", str);
        fclose(file);
    }
    lexems("file.txt");

    return 0;
}