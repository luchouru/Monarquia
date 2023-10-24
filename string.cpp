#include "string.h"

void strCrear (string &s){
    s = new char[1];
    s[0] = '\0';
}

void strDestruir (string &s){
    delete [] s;
    s = NULL;
}

int strLargo (string s){
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop (string &s1, string s2){
    int i = 0;
    int largo = strLargo(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan (string &s){
    string aux = new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
    aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
             strCop (s,aux);
             strDestruir (aux);
}

void print (string s){
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

boolean strEq (string s1,string s2){
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

boolean strMenor (string s1, string s2){
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;
}

void bajarString (string s, FILE * f){
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite (&s[i], sizeof(char), 1, f);
}

void levantarString (string &s, FILE * f){
    int i=0;
    string aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    strCop (s, aux);
    delete [] aux;
}

void convertirMayus (string &s){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'a' && s[i] <='z')
            s[i] = s[i] - 32;
        i++;
    }
}

boolean soloLetras (string s){
    int i = 0;
    boolean letras = TRUE;
    while(letras && s[i] != '\0'){
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
            letras = FALSE;
        i++;
    }
    return letras;
}

boolean soloFlecha (string s){
    int i = 0;
    boolean flecha = TRUE;
    while(flecha && s[i] != '\0'){
        if(s[0] != '-' || s[1] != '>')
            flecha = FALSE;
        i++;
    }
    if(s[2] != '\0')
        flecha = FALSE;

    return flecha;
}

boolean validarFormatoFecha (string s){
    int i = 0;
    boolean fecha = TRUE;
    while(fecha && s[i] != '\0'){
        if(s[0] < '0' || s[0] > '9')
            fecha = FALSE;
        else if(s[1] < '0' || s[1] > '9')
            fecha = FALSE;
        else if(s[2] != '/')
            fecha = FALSE;
        else if(s[3] < '0' || s[3] > '9')
            fecha = FALSE;
        else if(s[4] < '0' || s[4] > '9')
            fecha = FALSE;
        else if(s[5] != '/')
            fecha = FALSE;
        else if(s[6] < '0' || s[6] > '9')
            fecha = FALSE;
        else if(s[7] < '0' || s[7] > '9')
            fecha = FALSE;
        else if(s[8] < '0' || s[8] > '9')
            fecha = FALSE;
        else if(s[9] < '0' || s[9] > '9')
            fecha = FALSE;
        else if(s[10] != '\0')
            fecha = FALSE;
        i++;
        }

    return fecha;
}

void dividirStringFecha(string fecha, string &dia, string &mes, string &anio){
    dia = new char[3];
    mes = new char[3];
    anio = new char[5];
    int i = 0, j = 3, k = 6, l = 0, m = 0;

    while(fecha[i] != '/'){
        dia[i] = fecha[i];
        i++;
    }
    dia[i] = '\0';

    while(fecha[j] != '/'){
        mes[l] = fecha[j];
        l++;
        j++;
    }
    mes[l] = '\0';

    while(fecha[k] != '\0'){
        anio[m] = fecha [k];
        m++;
        k++;
    }
    anio[m] = '\0';
}

int convertirNumero (string s){
    int i = 0, digito, num = 0;

    while (s[i] != '\0'){
        digito = s[i] - 48;
        num = digito + 10 * num;
        i++;
    }
    return num;
}

fecha convertirFecha(string fec){
    fecha f;
    string dia, mes, anio;
    dividirStringFecha(fec,dia,mes,anio);
    f.dia = convertirNumero(dia);
    f.mes = convertirNumero(mes);
    f.anio = convertirNumero(anio);
    return f;
}

void eliminarBlancosPrincipio (string s, string &sb){
    int largo = strLargo(s) + 1;
    int blanco = 0;

    while(s[blanco] == ' '){
        blanco++;
    }

    delete [] sb;
    sb = new char [largo - blanco];

    int i = 0;
    while(s[blanco] != '\0'){
        sb[i] = s[blanco];
        i++;
        blanco++;
    }
    sb[i] = '\0';
}

void dividirString (string s, string &primero, string &resto){
    int largo = strLargo(s) + 1;
    int contar = 0;
    int i = 0;
    int t = 0;
    int j = 0;

    while(s[contar] != ' ' && s[t] != '\0'){
        contar++;
        t++;
    }

    delete [] primero;
    delete [] resto;

    primero = new char [contar + 1];
    resto = new char [largo - contar];

    while(s[i] != ' ' && s[i] != '\0'){
        primero[i] = s[i];
        i++;
    }
    primero[i] = '\0';

    while(s[contar] != '\0'){
        resto[j] = s[contar];
        j++;
        contar++;
    }
    resto[j] = '\0';
}
