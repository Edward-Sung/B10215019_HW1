#include <stdio.h>
#include <stdlib.h>

char* Caesar(char* Plaintext)
{
    int i;
    char* Caesar = Plaintext;
    for(i=0; i<16; i++)
    {
        Caesar[i] += 3 ;
        if(Caesar[i] > 122)
            Caesar[i] -= 26;
        Caesar[i] -= 32 ;
    }
    return Caesar;
}
char* D_Caesar(char* Plaintext)
{
    int i;
    char* Caesar = Plaintext;
    for(i=0; i<16; i++)
    {
        Caesar[i] -= 3 ;
        if(Caesar[i] < 65)
            Caesar[i] += 26;
        Caesar[i]+=32;
    }

    return Caesar;
}

char* Monoalphabetic(char* Plaintext)
{
    int i = 0;
    char* Mono = Plaintext;
    while(Mono[i] != '\0')
    {
        switch(Mono[i])
        {
        case 'a':
            Mono[i] = 'Q';
            break;
        case 'b':
            Mono[i] = 'W';
            break;
        case 'c':
            Mono[i] = 'E';
            break;
        case 'd':
            Mono[i] = 'R';
            break;
        case 'e':
            Mono[i] = 'T';
            break;
        case 'f':
            Mono[i] = 'Y';
            break;
        case 'g':
            Mono[i] = 'U';
            break;
        case 'h':
            Mono[i] = 'I';
            break;
        case 'i':
            Mono[i] = 'O';
            break;
        case 'j':
            Mono[i] = 'P';
            break;
        case 'k':
            Mono[i] = 'A';
            break;
        case 'l':
            Mono[i] = 'S';
            break;
        case 'm':
            Mono[i] = 'D';
            break;
        case 'n':
            Mono[i] = 'F';
            break;
        case 'o':
            Mono[i] = 'G';
            break;
        case 'p':
            Mono[i] = 'H';
            break;
        case 'q':
            Mono[i] = 'J';
            break;
        case 'r':
            Mono[i] = 'K';
            break;
        case 's':
            Mono[i] = 'L';
            break;
        case 't':
            Mono[i] = 'Z';
            break;
        case 'u':
            Mono[i] = 'X';
            break;
        case 'v':
            Mono[i] = 'C';
            break;
        case 'w':
            Mono[i] = 'V';
            break;
        case 'x':
            Mono[i] = 'B';
            break;
        case 'y':
            Mono[i] = 'N';
            break;
        case 'z':
            Mono[i] = 'M';
            break;
        }
        i++;
    }
    return Mono;
}
char* D_Monoalphabetic(char* Plaintext)
{
    int i = 0;
    char* Mono = Plaintext;
    while(Mono[i] != '\0')
    {
        switch(Mono[i])
        {
        case 'Q':
            Mono[i] = 'a';
            break;
        case 'W':
            Mono[i] = 'b';
            break;
        case 'E':
            Mono[i] = 'c';
            break;
        case 'R':
            Mono[i] = 'd';
            break;
        case 'T':
            Mono[i] = 'e';
            break;
        case 'Y':
            Mono[i] = 'f';
            break;
        case 'U':
            Mono[i] = 'g';
            break;
        case 'I':
            Mono[i] = 'h';
            break;
        case 'O':
            Mono[i] = 'i';
            break;
        case 'P':
            Mono[i] = 'j';
            break;
        case 'A':
            Mono[i] = 'k';
            break;
        case 'S':
            Mono[i] = 'l';
            break;
        case 'D':
            Mono[i] = 'm';
            break;
        case 'F':
            Mono[i] = 'n';
            break;
        case 'G':
            Mono[i] = 'o';
            break;
        case 'H':
            Mono[i] = 'p';
            break;
        case 'J':
            Mono[i] = 'q';
            break;
        case 'K':
            Mono[i] = 'r';
            break;
        case 'L':
            Mono[i] = 's';
            break;
        case 'Z':
            Mono[i] = 't';
            break;
        case 'X':
            Mono[i] = 'u';
            break;
        case 'C':
            Mono[i] = 'v';
            break;
        case 'V':
            Mono[i] = 'w';
            break;
        case 'B':
            Mono[i] = 'x';
            break;
        case 'N':
            Mono[i] = 'y';
            break;
        case 'M':
            Mono[i] = 'z';
            break;
        }
        i++;
    }
    return Mono;
}

char* Playfair(char* Plaintext)
{
    char key[5][5] = {{"DPABC"},{"EFGHI"},{"KLMNO"},{"QRSTU"},{"VWXYZ"}};
    char* Playfair = Plaintext;
    int i,j,k1=0,k2=1,i1,j1,i2,j2;
    while(k1<16)
    {
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if(Plaintext[k1]-32 == key[i][j])
                {
                    i1=i;
                    j1=j;
                }
                if(Plaintext[k2]-32 == key[i][j])
                {
                    i2=i;
                    j2=j;
                }
            }
        }
        if(i1==i2)
        {
            Playfair[k1] = key[i1][(j1+1)%5];
            Playfair[k2] = key[i2][(j2+1)%5];
        }
        else if(j1==j2)
        {
            Playfair[k1] = key[(i1+1)%5][j1];
            Playfair[k2] = key[(i2+1)%5][j2];
        }
        else
        {
            Playfair[k1] = key[i1][j2];
            Playfair[k2] = key[i2][j1];
        }
        k1+=2;
        k2+=2;
    }
    return Playfair;
}

char* D_Playfair(char* Plaintext)
{
    char key[5][5] = {{"DPABC"},{"EFGHI"},{"KLMNO"},{"QRSTU"},{"VWXYZ"}};
    char* Playfair = Plaintext;
    int i,j,k1=0,k2=1,i1,j1,i2,j2;
    while(k1<16)
    {
        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if(Plaintext[k1] == key[i][j])
                {
                    i1=i;
                    j1=j;
                }
                if(Plaintext[k2] == key[i][j])
                {
                    i2=i;
                    j2=j;
                }
            }
        }
        if(i1==i2)
        {
            if(j1-1<0)
                j1+=5;
            if(j2-1<0)
                j2+=5;
            Playfair[k1] = key[i1][(j1-1)]+32;
            Playfair[k2] = key[i2][(j2-1)]+32;
        }
        else if(j1==j2)
        {
            if(i1-1<0)
                i1+=5;
            if(i2-1<0)
                i2+=5;
            Playfair[k1] = key[(i1-1)%5][j1]+32;
            Playfair[k2] = key[(i2-1)%5][j2]+32;
        }
        else
        {
            Playfair[k1] = key[i1][j2]+32;
            Playfair[k2] = key[i2][j1]+32;
        }
        k1+=2;
        k2+=2;
    }
    return Playfair;
}

char* autokey(char* Plaintext)
{
    char* key = "kmt";
    int i,j;
    for(i=3; i<16; i++)
        key[i] = Plaintext[i-3];
    key[16] = '\0';
    for(j=0; j<16; j++)
        key[j] = (key[j]-97+Plaintext[j]-97)%26+65;
    return key;

}


char* D_autokey(char* Plaintext)
{
    char* key = {"KMTSENTFROMMYIPH"};
    char* a ={""};
    int j;
    for(j=0; j<16; j++)
    {
        if(key[j]>Plaintext[j])
            Plaintext[j]+=26;
        key[j] = (Plaintext[j]-key[j])+97;

    }
    return key;

}

char* transposition(char* Plaintext)
{
    char key = "52834671";
    char* text = {""};
    int i=0,f=0;
    while(i<16)
    {
        switch(i%8)
        {
        case 4:
            if(f==1)
                text[1] = Plaintext[i]-32;
            else
                text[0] = Plaintext[i]-32;
            break;
        case 1:
            if(f==1)
                text[3] = Plaintext[i]-32;
            else
                text[2] = Plaintext[i]-32;
            break;
        case 7:
            if(f==1)
                text[5] = Plaintext[i]-32;
            else
                text[4] = Plaintext[i]-32;
            f++;
            break;
        case 2:
            if(f==1)
                text[7] = Plaintext[i]-32;
            else
                text[6] = Plaintext[i]-32;
            break;
        case 3:
            if(f==1)
                text[9] = Plaintext[i]-32;
            else
                text[8] = Plaintext[i]-32;
            break;
        case 5:
            if(f==1)
                text[11] = Plaintext[i]-32;
            else
                text[10] = Plaintext[i]-32;
            break;
        case 6:
            if(f==1)
                text[13] = Plaintext[i]-32;
            else
                text[12] = Plaintext[i]-32;
            break;
        case 0:
            if(f==1)
                text[15] = Plaintext[i]-32;
            else
                text[14] = Plaintext[i]-32;
            break;
        }
        i++;
    }
    return text;


}

char* D_transposition(char* Plaintext)
{

    char key = {"52834671"};
    char* text = malloc(sizeof(char)*17);
    int i=0;
    while(i<16)
    {
        switch(i)
        {
        case 0:
            text[4] = Plaintext[i]+32;
            text[12] = Plaintext[i+1]+32;
            break;
        case 2:
            text[1] = Plaintext[i]+32;
            text[9] = Plaintext[i+1]+32;
            break;
        case 4:
            text[7] = Plaintext[i]+32;
            text[15] = Plaintext[i+1]+32;
            break;
        case 6:
            text[2] = Plaintext[i]+32;
            text[10] = Plaintext[i+1]+32;
            break;
        case 8:
            text[3] = Plaintext[i]+32;
            text[11] = Plaintext[i+1]+32;
            break;
        case 10:
            text[5] = Plaintext[i]+32;
            text[13] = Plaintext[i+1]+32;
            break;
        case 12:
            text[6] = Plaintext[i]+32;
            text[14] = Plaintext[i+1]+32;
            break;
        case 14:
            text[0] = Plaintext[i]+32;
            text[8] = Plaintext[i+1]+32;
            break;
        }
        i+=2;
    }
    text[16] = '\0';
    return text;
    free(text);
}
char* product(char* Plaintext)
{
    char* pro = {""};
    pro[0] = Plaintext[14]-32;
    pro[1] = Plaintext[10]-32;
    pro[2] = Plaintext[1]-32;
    pro[3] = Plaintext[9]-32;
    pro[4] = Plaintext[15]-32;
    pro[5] = Plaintext[2]-32;
    pro[6] = Plaintext[6]-32;
    pro[7] = Plaintext[13]-32;
    pro[8] = Plaintext[3]-32;
    pro[9] = Plaintext[11]-32;
    pro[10] = Plaintext[8]-32;
    pro[11] = Plaintext[5]-32;
    pro[12] = Plaintext[0]-32;
    pro[13] = Plaintext[4]-32;
    pro[14] = Plaintext[7]-32;
    pro[15] = Plaintext[12]-32;
    return pro;

}

char* D_product(char* Plaintext)
{
    char* pro = malloc(sizeof(char)*17);
    pro[14] = Plaintext[0]+32;
    pro[10] = Plaintext[1]+32;
    pro[1] = Plaintext[2]+32;
    pro[9] = Plaintext[3]+32;
    pro[15] = Plaintext[4]+32;
    pro[2] = Plaintext[5]+32;
    pro[6] = Plaintext[6]+32;
    pro[13] = Plaintext[7]+32;
    pro[3] = Plaintext[8]+32;
    pro[11] = Plaintext[9]+32;
    pro[8] = Plaintext[10]+32;
    pro[5] = Plaintext[11]+32;
    pro[0] = Plaintext[12]+32;
    pro[4] = Plaintext[13]+32;
    pro[7] = Plaintext[14]+32;
    pro[12] = Plaintext[15]+32;
    pro[16] = '\0';
    return pro;
    free(pro);

}

int main()
{
    char* Plaintext = "sentfrommyiphone";
    printf("encrypt:\n");
    printf("1.  Caesar cipher: %s\n",Caesar("sentfrommyiphone"));
    printf("2.  Monoalphabetic cipher: %s\n",Monoalphabetic("sentfrommyiphone"));
    printf("3.	Playfair cipher: %s\n",Playfair("sentfrommyiphone"));
    printf("4.	Autokey system: %s\n",autokey("sentfrommyiphone"));
    printf("5.	Row transposition: %s\n",transposition("sentfrommyiphone"));
    printf("6.	Product cipher: %s\n",product("sentfrommyiphone"));

    printf("---------------------------------------------------------------\n");
    printf("decrypt:\n");

    printf("1.  Caesar cipher: %s\n",D_Caesar(Caesar("sentfrommyiphone")));
    printf("2.  Monoalphabetic cipher: %s\n",D_Monoalphabetic(Monoalphabetic("sentfrommyiphone")));
    printf("3.	Playfair cipher: %s\n",D_Playfair(Playfair("sentfrommyiphone")));
    printf("4.	Autokey system: %s\n",D_autokey("CQGLJEHRDMUBFWCL"));
    printf("5.	Row transposition: %s\n",D_transposition(transposition("sentfrommyiphone")));
    printf("6.	Product cipher: %s\n",D_product(product("sentfrommyiphone")));


    return 0;
}
