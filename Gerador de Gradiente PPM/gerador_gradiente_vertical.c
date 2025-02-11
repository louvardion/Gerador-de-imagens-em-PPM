#include <stdio.h>

//Aqui vou produzir gradientes verticais

int main(){

    //Variáveis
    int largura = 256, altura = 256;

    //Ponteiro
    FILE *gradiente = fopen("gradiente.ppm", "w");

        if(gradiente == NULL){
            printf("Erro a o criar arquivo");   //checagem
            return 1;
        }

        //primeira impressão no arquivo
         fprintf(gradiente, "P3\n%d %d\n255\n", largura, altura);

        //Loop de impressão
        for(int y = 0; y < altura; y++){
            for(int x = 0; x < largura; x++){
                int r = ((float)y / (altura - 1)) * 255;  //branco
                int g = 255; //Verde vertical
                int b = ((float)y / (altura -1)) * 255; //branco

                fprintf(gradiente, "%d %d %d ", r, g ,b);
            }
            fprintf(gradiente, "\n");
        }
    
        fclose(gradiente); //fechando o file
        printf("Imagem gerada: gradiente.ppm\n");
        printf("Aperte 'Enter' para terminar.");
        getchar();

    return 0;
}