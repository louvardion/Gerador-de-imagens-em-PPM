#include <stdio.h>

/* Projeto de teste para aprendizado
Por:    Diego Amaral (louvardion)
        Estudante de Análise e Desenvolvimento de Sistemas  
Passos:
    1 - Criar um programa em C que crie um arquivo ".ppm".
    2 - Preencher esse arquivo com píxels coloridos como um gradiente, ou formas simples. 
    3 - Abrir imagem em um visualizador compatível.

 Sobre formato .ppm:
    Um arquivo .ppm começa com:

    P3
    LARGURA ALTURA
    255
    R G B R G B R G B...

    Cada trio de "R G B" define a cor de um píxel. O valor varia de 0 a 255.
*/

int main () {
    
    //Declaro as variáveis de altura e largura da imagem
    int largura = 256, altura = 256;

    FILE *imagem = fopen("imagem.ppm", "w");

    fprintf(imagem, "P3\n%d %d\n255\n", largura, altura);

        //Verificação de arquivo: Caso o programa falhe e tente escrever num ponteiro NULL
        if(imagem == NULL){
            printf("Erro ao criar arquivo.\n\n");
            return 1;
        }
        
        printf("Arquivo aberto com sucesso!");

        for (int y = 0; y < altura; y++){
            for (int x = 0; x < largura; x++){
                int r = (x * 255) / (largura - 1);    //Vermelho variando na horizontal - Normalizando largura 
                int g = (y * 255) / (altura - 1);    //Verde variando na vertical - Normalizando altura
                int b = 128;  //O Azul fica fixo
                fprintf(imagem, "%d %d %d ", r, g, b);
            }
            fprintf(imagem, "\n");
        }

    fclose(imagem);
    printf("Imagem gerada: imagem.ppm\n");
    
    printf("Pressione 'Enter' para sair:");
    getchar();
            
    return 0;
}