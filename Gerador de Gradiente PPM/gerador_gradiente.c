#include <stdio.h>

//Desta vez vou tentar criar um gradiente que varia na horizontal. 

int main(){

    //Variáveis
    int largura = 256, altura = 256;
    
    //Ponteiro que criará um file para ser escrito.
    FILE *gradiente = fopen("gradiente.ppm", "w");

    //Escrita dentro do file.
    fprintf(gradiente,"P3\n%d %d\n255\n", largura, altura);

        //Loop for para preencher os pixeis:
        for(int y = 0; y < altura; y++){
            for(int x = 0; x < largura; x++){
                int r = (1 - ((float)x / largura)) * 255;   //Gradiente do Vermelho para o azul na horizontal.
                int g = 0;
                int b = ((float)x / largura) * 255;
                
                fprintf(gradiente, "%d %d %d ", r, g, b); //Escrevendo os pixeis no file
            }
            fprintf(gradiente, "\n"); //começando nova linha de pixeis a cada iteração do loop
        }
    
        fclose(gradiente); //Fechando o file escrito.
        printf("Imagem gerada: gradiente.ppm\n");
        printf("Aperte 'Enter' para sair.");
        getchar();
    
    return 0;
}