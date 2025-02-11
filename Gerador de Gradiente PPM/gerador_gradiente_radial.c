#include <stdio.h>
#include <math.h> //para poder fazer cálculo usando função de raíz quadrada preciso desta biblioteca

int main(){

    int largura = 256, altura = 256;
    
    FILE *gradiente_radial = fopen("gradiente_radial.ppm", "w");

        if(gradiente_radial == NULL){
            printf("Erro ao criar arquivo.");
            return 1;
        }
        printf("Arquivo criado com sucesso!\n");

        fprintf(gradiente_radial, "P3\n%d %d\n255\n", largura, altura);

        /*para poder criar um circulo radial a partir do centro, tenho que encontrar a distância de x e y 
        do centro, a distância máxima possível da imagem, e normalizar usando os resultados.*/

        int centroX = largura / 2;   //no plano carteziano traçando uma linha entre os dois pontos marcados na metade encontro o centro
        int centroY = altura / 2;
        double distanciaMAX = sqrt((centroX*centroY)+(centroX*centroY)); //no carteziano isto seria uma diagonal que divide o plano ao meio

        for(int y = 0; y < altura; y++){
            for(int x = 0; x < largura; x++){

                double distancia = sqrt((x - centroX) * (x - centroX) + (y - centroY) * (y - centroY)); //Basicamente é o teorema de pitágoras calculando a distância do centro a cada iteração.
                
                double normalizar = distancia / distanciaMAX; //Para manter a gradação constante e não dar problemas se for feito com outros valores para largura e altura que não 256. 

                int r = 0;
                int g = (1 - normalizar) * 255; //O centro será verde.
                int b = normalizar * 255;  //notando que é o mesmo cálculo de G mas em inversão (o cálculo de g vai gerar valores menores que os de b) a normalização é para o centro. gerando valores maiores de g ali.

                fprintf(gradiente_radial, "%d %d %d ", r, g, b);
            }
            fprintf(gradiente_radial, "\n");
        }
        fclose(gradiente_radial);
        printf("Arquivo gerado: gradiente_radial.ppm\n\n");

        printf("Aperte enter para sair.");
        getchar();

    return 0;
}

/*Conclusão: Esse foi o cão de fazer. O mais difícil. Em parte porque levou um tempo para entender a matemática por trás no começo. 
Mas depois de entender que é basicamente o cálculo de um triângulo facilitou. Santa seja a pesquisa! Um agradecimente especial ao professor gpt 
por passar meia hora tentando me explicar como a normalização funciona aqui.*/