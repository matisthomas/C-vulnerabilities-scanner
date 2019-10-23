#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
  int i=0;
  int malloc=0;
  int free=0;
  int lettre = 0;
  char buffer[256];
  int longueurBuffer;
  int cpt=0;
  FILE* code = NULL;
  code = fopen(argv[1], "r+");

  //fichier s'ouvre
  if(code != NULL){
    printf("fichier ouvert!\n");

    //traitement du fichier
    while(1){

      if(feof(code)){
        break;
      }
      else{
        lettre = fgetc(code);
        }
        //if(lettre!=' ' && lettre!='\n' && lettre!='(' && lettre!=')'){
          if((lettre>=48 && lettre <=57) || (lettre>=65 && lettre<=90) || (lettre>=97 && lettre<=122) || lettre==95){
          buffer[cpt]=lettre;
          cpt++;
          printf("%c", lettre);
        }
        else{
          //gestion des mots
          buffer[cpt]='\0';
          longueurBuffer = strlen(buffer);
          printf("%d\n", longueurBuffer);
          if(!strcmp(buffer,"malloc")){
            malloc++;
          }
          if(!strcmp(buffer,"free")){
            free++;
          }
          if(!strcmp(buffer,"strcpy")){
            printf("votre code n'est pas sécurisé : utilisation de strcpy!");
            return 1;
          }
          cpt=0;
          if(malloc!=free){
            printf("malloc sans free! Attention");
            return 1;
          }
        }
      }
    }







  //fichier s'ouvre pas
  else{

    printf("impossible d'ouvrir le fichier!\n");
    return 1;
  }



 if(!fclose(code)){
   printf("fichier fermé\n");
 }
 else{
   printf("erreur de fermeture!\n");
   return 1;
 }
 return 0;
}
