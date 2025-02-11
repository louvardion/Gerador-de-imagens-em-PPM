#include <stdio.h>

int main (){

    int largura = 256, altura = 256;

    FILE *gerador_retangulo = fopen("gerador_retangulo.ppm", "w");

        if(gerador_retangulo == NULL){
            printf("Erro ao criar arquivo.");
            return 1;
        }
        printf("Arquivo criado com sucesso!\n");

        fprintf(gerador_retangulo, "P3\n%d %d\n255\n", largura, altura);

        //Aqui vou definir o retângulo

        int rectX = largura / 4; //ponto inicial
        int rectY = altura / 4; //do retangulo.
        int largRect = largura / 2; //As dimensões
        int altRect = altura / 2;   //do retângulo. 

        for(int y = 0; y < altura; y++){
            for(int x = 0; x < largura; x++){
                
                int r, g, b;

                //aqui a lógica será para dizer "Se estiver dentro do retangulo, pintar de vermelho"
                if(x >= rectX && x < rectX + largRect && y >= rectY && y < rectY + altRect){
                    r = 255, g = 0, b = 0;
                } else {
                    r = 0, g = 0, b = 0;
                }

                fprintf(gerador_retangulo, "%d %d %d ", r, g ,b);
            }
            fprintf(gerador_retangulo, "\n");
        }
        fclose(gerador_retangulo);
        printf("Imagem gerada: gerador_retangulo.ppm\n");

        printf("Aperte 'Enter' para sair.");
        getchar();
    
    return 0;
}