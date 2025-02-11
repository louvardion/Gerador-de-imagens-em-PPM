#include <stdio.h>

int main(){

    int largura = 256, altura = 256;

    FILE *gradiente_diagonal = fopen("gradiente_diagonal.ppm", "w");

         if(gradiente_diagonal == NULL){
            printf("Erro ao criar arquivo.");
            return 1;
         }
        printf("Arquivo aberto com sucesso!\n");

        fprintf(gradiente_diagonal,"P3\n%d %d\n255\n", largura, altura);

        for(int y = 0; y < altura; y++){
            for(int x = 0; x < largura; x++){

                int r = ((y + x) * 255) / ((altura + largura) - 2); //Fórmula para escrever a cor de forma diagonal normalizada.
                int g = 0;
                int b = 255 - r; //Assim o azul fará o inverso do vermelho

                fprintf(gradiente_diagonal, "%d %d %d ", r, g, b);
            }
            fprintf(gradiente_diagonal, "\n");
        }

        fclose(gradiente_diagonal);
        printf("Imagem gerada: gradiente_diagonal.ppm\n\n");

        printf("Aperte 'Enter' para terminar.");
        getchar();
    
    return 0;
}