#include <stdio.h>
#include <stdlib.h>
static void BorrarComentarios(FILE *leer)
{
 char c;
 FILE *escribir;
 escribir = fopen("ComentariosBorrados.txt","w");
 while((c=getc(leer))!=EOF)
 {
     if(c=='/')
     {
         c=getc(leer);
          if(c=='/')
          {
              c =getc(leer);
          }
         else if(c=='*')
          {
              c=getc(leer);
          }
     }
     else if(c=='*')
     {
         c=getc(leer);
         if(c=='/')
         {
             c=getc(leer);
         }
     }
     fputc(c,escribir);
      }
 fclose(leer);
 fclose(escribir);
}

int main()
{

    FILE *leer;
    leer = fopen("CodigoOriginal.txt","r");
    BorrarComentarios(leer);
    printf("Se ha creado un .txt llamado ComentariosBorrados");
    return 0;
}

