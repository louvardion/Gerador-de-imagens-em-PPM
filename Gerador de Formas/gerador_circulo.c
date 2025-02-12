#include <stdio.h>
#include <math.h>

int main(){

    int largura = 256, altura = 256;

    FILE *gerador_circulo = fopen("gerador_circulo.ppm", "w");

        if(gerador_circulo == NULL){
            printf("Erro ao criar arquivo.");
            return 1;
        }
        printf("Arquivo criado com sucesso!\n");

        fprintf(gerador_circulo,"P3\n%d %d\n255\n", largura, altura);

        //Aqui defino o centro do circulo
        int centX = largura / 2;
        int centY = altura / 2;
        int raio = 100; // raio do circulo

        for(int y = 0; y < altura; y++){
            for(int x = 0; x < largura; x++){

                int r = 0, g = 0, b = 0;

                //agora usar um pitágoras para calcular a distancia do ponto x, y ate o centro.
                double distancia = sqrt((x - centX)*(x - centX)+(y - centY)*(y - centY));

                if(distancia <= raio){
                    r = 0;
                    g = 0;
                    b = 255;
                } else {
                    r = 0;
                    g = 0;
                    b = 0;
                }
                fprintf(gerador_circulo, "%d %d %d ", r, g, b);
            }
            fprintf(gerador_circulo,"\n");
        }
        fclose(gerador_circulo);
        printf("Imagem gerada: gerador_circulo.ppm\n");

        printf("Aperte 'Enter' para sair");
        getchar();
    
    return 0;
}