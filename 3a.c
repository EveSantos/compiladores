#include <stdio.h>
#include <string.h>
#define STACKSIZE 1000

char stack[STACKSIZE];
int top = -1;

void push(char c)
{
    if (top < STACKSIZE)
    {
        stack[++top] = c;
    }
}

void pop()
{
    if (top >= 0)
    {
        top--;
    }
}

int main(int argc, char *argv[])
{
    int posit = 0;
    char token;

    char *word = NULL;
    char line[100];
    FILE *arquivo;
    size_t len = 100;
    ssize_t read;

    arquivo = fopen(argv[1], "r");
    if (arquivo == NULL)
        return 1;

    while (!feof(arquivo))
    {

        word = fgets(line, len, arquivo);
    }

q0:
    push('S');
    goto q1;
q1:
    token = word[posit];

// ! p1: S → M
    if ((token == 'm') && (stack[top] == 'S'))
    {
        pop();
        push('M');
        goto q1;
    }
    // p2: S -> G M
    else if ((token == 'G') && (stack[top] == 'S'))
    {
        pop();
        push('M');
        push('G');
        goto q1;
    }
   //p3: S -> N G M
    else if ((token == 'N') && (stack[top] == 'S'))
    {
        pop();
        push('M');
        push('G');
        push('N');
        goto q1;
    }
    //p4: N → n(){ A; r(E); }
    else if ((token == 'n') && (stack[top] == 'N'))
    {
        pop();
        push(';');
        push(')');
        push('E');
        push('(');
        push('r');
        push(';');
        push('A');
        push('{');
        push(')');
        push('(');
        push('n');
        goto q1;
    }
    // p5: G → g(){ C; r(E); }
    else if ((token == 'g') && (stack[top] == 'G'))
    {
        pop();
        push(';');
        push(')');
        push('E');
        push(')');
        push('r');
        push(';');
        push('A');
        push('{');
        push(')');
        push('(');
        push('g');
        goto q1;
    }
    // p6: M → m(){ C; r(E); }
    else if ((token == 'm') && (stack[top] == 'M'))
    {
        pop();
        push('}');
        push(';');
        push(')');
        push('E');
        push('(');
        push('r');
        push(';');
        push('C');
        push('{');
        push(')');
        push('(');
        push('m');
        goto q1;
    }    
    //p7 : A → CB
    else if ((token == 'C') && (stack[top] == 'A'))
    {
        pop();
        push('B');
        push('C');
        goto q1;
    }   
    //p8 : B → .
    else if ((token == '.') && (stack[top] == 'B'))
    {
        pop();
        goto q1;
    }
    //p9 : B → ;CB
    else if ((token == ';') && (stack[top] == 'B'))
    {
        pop();
        push('B');
        push(';');
        push('C');
        goto q1;
    }
    //p10 : E → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | x | y | (EXE)
    else if ((token == '0') && (stack[top] == 'E'))
    {
        pop();
        push('0');
        goto q1;
    }
    else if ((token == '1') && (stack[top] == 'E'))
    {
        pop();
        push('1');
        goto q1;
    }
    else if ((token == '2') && (stack[top] == 'E'))
    {
        pop();
        push('2');
        goto q1;
    }
    else if ((token == '3') && (stack[top] == 'E'))
    {
        pop();
        push('3');
        goto q1;
    }
    else if ((token == '4') && (stack[top] == 'E'))
    {
        pop();
        push('4');
        goto q1;
    }
    else if ((token == '5') && (stack[top] == 'E'))
    {
        pop();
        push('5');
        goto q1;
    }
    else if ((token == '6') && (stack[top] == 'E'))
    {
        pop();
        push('6');
        goto q1;
    }
    else if ((token == '7') && (stack[top] == 'E'))
    {
        pop();
        push('7');
        goto q1;
    }
    else if ((token == '8') && (stack[top] == 'E'))
    {
        pop();
        push('8');
        goto q1;
    }
    else if ((token == '9') && (stack[top] == 'E'))
    {
        pop();
        push('9');
        goto q1;
    }
    else if ((token == 'x') && (stack[top] == 'E'))
    {
        pop();
        push('x');
        goto q1;
    }
    else if ((token == 'y') && (stack[top] == 'E'))
    {
        pop();
        push('y');
        goto q1;
    }
    else if ((token == '(') && (stack[top] == 'E'))
    {
        pop();
        push(')');
        push('E');
        push('X');
        push('E');
        push('(');
        goto q1;
    }

    //p7 : E → 0 | 1 | x | y | (EXE)
    else if ((token == '0') && (stack[top] == 'E'))
    {
        pop();
        push('0');
        goto q1;
    }
    else if ((token == '1') && (stack[top] == 'E'))
    {
        pop();
        push('1');
        goto q1;
    }
    else if ((token == 'x') && (stack[top] == 'E'))
    {
        pop();
        push('x');
        goto q1;
    }
    else if ((token == 'y') && (stack[top] == 'E'))
    {
        pop();
        push('y');
        goto q1;
    }
    //p11: E -> (EXE)
    else if ((token == '(') && (stack[top] == 'E'))
    {
        pop();
        push(')');
        push('E');
        push('X');
         push('E');
        push('(');
        goto q1;
    }
    //p:24 X → + | - | * | /
    else if ((token == '+') && (stack[top] == 'X'))
    {
        pop();
        push('+');
        goto q1;
    }
    else if ((token == '-') && (stack[top] == 'X'))
    {
        pop();
        push('-');
        goto q1;
    }
    else if ((token == '*') && (stack[top] == 'X'))
    {
        pop();
        push('*');
        goto q1;
    }
    else if ((token == '/') && (stack[top] == 'X'))
    {
        pop();
        push('/');
        goto q1;
    }

    //p24: C -> h=g() | i=n() | j=E | k=E | z=E | (EXE) | w(E){CD | f(E){CD | o(E;E;E) {CD
    else if ((token == 'h') && (stack[top] == 'C'))
    {
        pop();
        push(')');
        push(')');
        push('E');
        push('(');
        push('g');
        push('(');
        push('h');
        goto q1;
    }
    else if ((token == 'i') && (stack[top] == 'C'))
    {
        pop();
        push(')');
        push(')');
        push('E');
        push('(');
        push('n');
        push('(');
        push('i');
        goto q1;
    }
    else if ((token == 'j') && (stack[top] == 'C'))
    {
        pop();
        push('j');
        goto q1;
    }
    else if ((token == 'k') && (stack[top] == 'C'))
    {
        pop();
        push('k');
        goto q1;
    }
    else if ((token == 'z') && (stack[top] == 'C'))
    {
        pop();
        push('z');
        goto q1;
    }
    else if ((token == '(') && (stack[top] == 'C'))
    {
        pop();
        push(')');
        push('E');
        push('X');
        push('E');
        push('(');
        goto q1;
    }
    else if ((token == 'w') && (stack[top] == 'C'))
    {
        pop();
        push('D');
        push('C');
        push('{');
        push('E');
        push('(');
        push('w');
        goto q1;
    }
    else if ((token == 'f') && (stack[top] == 'C'))
    {
        pop();
        push('D');
        push('C');
        push('{');
        push('E');
        push('(');
        push('f');
        goto q1;
    }
    else if ((token == 'o') && (stack[top] == 'C'))
    {
        pop();
        push('D');
        push('C');
        push('{');
        push('E');
        push(';');
        push('E');
        push(';');
        push('E');
        push('(');
        push('o');
        goto q1;
    }

    //p37: D -> } | ;CD
    else if ((token == '}') && (stack[top] == 'D'))
    {
        pop();
        push('}');
        goto q1;
    }
    else if ((token == ';') && (stack[top] == 'D'))
    {
        pop();
        push('D');
        push('C');
        push(';');
        goto q1;
    }

    //fazer produções que consumam (identifiquem) os terminais m,r,0,1,x,y,(,),+,-,*,/,h,i,j,k,z,w,{,},;,f,=,o
    else if ((token == 'm') && (stack[top] == 'm'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'r') && (stack[top] == 'r'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '0') && (stack[top] == '0'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '1') && (stack[top] == '1'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'x') && (stack[top] == 'x'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'y') && (stack[top] == 'y'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '(') && (stack[top] == '('))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == ')') && (stack[top] == ')'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '+') && (stack[top] == '+'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '-') && (stack[top] == '-'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '*') && (stack[top] == '*'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == '/') && (stack[top] == '/'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'h') && (stack[top] == 'h'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'i') && (stack[top] == 'i'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'j') && (stack[top] == 'j'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'k') && (stack[top] == 'k'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if ((token == 'z') && (stack[top] == 'z'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == 'w') && (stack[top] == 'w'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == '{') && (stack[top] == '{'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == '}') && (stack[top] == '}'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == ';') && (stack[top] == ';'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == 'f') && (stack[top] == 'f'))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == '=') && (stack[top] == '='))
    {
        pop();
        posit++;
        goto q1;
    }
    else if((token == 'o') && (stack[top] == 'o'))
    {
        pop();
        posit++;
        goto q1;
    }
    



    else if (stack[top] == '\0' && token == '\0')
    {
        printf("palavra consumida");
    }
    else
    {
        printf("\nerro Sintático\n\n");
        return 1;
    }
}