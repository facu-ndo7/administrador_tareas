#include <stdio.h>
#include <sys/statvfs.h>
#include "colors.h"

void consultar_almacenamiento() {
    struct statvfs info;

    if (statvfs("/", &info) != 0) {
        perror("Error al obtener información del sistema de archivos");
        return;
    }

    unsigned long total = info.f_blocks * info.f_frsize;
    unsigned long libre = info.f_bfree * info.f_frsize;
    printf("total: %lu\n", total);
    printf("libre: %lu\n", libre);

    double total_gib = (double)total / 1073741824.0;
    double libre_gib = (double)libre / 1073741824.0;
    printf("total_gib: %f\n", total_gib);
    printf("libre_gib: %f\n", libre_gib);
    int barra_total = (int)(total_gib);
    int barra_libre = (int)(libre_gib);
    printf("barra_total: %i\n", barra_total);
    printf("barra_libre: %i\n", barra_libre);

   printf(BG_LGREEN "   " RESET);
   printf(LGREEN " Espacio libre\n");
   printf(BG_RED "   " RESET);
   printf(RED " Espacio ocupado\n");
   printf("\n");

   for (int i = 0; i < (barra_total + barra_libre); i++){
    if(i <= barra_libre){
     printf(BG_LGREEN " " RESET);
    }else{
     printf(BG_RED " " RESET);
    }
   }
   printf("\n");
};

