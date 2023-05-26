#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
  char timestamp[20];
  float age;
  char streaming_service[35];
  float hours_per_day;
  char while_working[5];
  char instrumentalist[5];
  char composer[5];
  char fav_genre[20];
  char exploratory[5];
  char foreign_languages[5];
  float bpm;

  char frequency_classical[20];
  char frequency_country[20];
  char frequency_edm[20];
  char frequency_folk[20];
  char frequency_gospel[20];
  char frequency_hip_hop[20];
  char frequency_jazz[20];
  char frequency_kpop[20];
  char frequency_latin[20];
  char frequency_lofi[20];
  char frequency_metal[20];
  char frequency_pop[20];
  char frequency_rb[20];
  char frequency_rap[20];
  char frequency_rock[20];
  char frequency_video_game_music[20];

  float anxiety;
  float depression;
  float insomnia;
  float ocd;
  char music_effects[25];
}tDados_csv;

void imprimirStructEspecifica(tDados_csv* dados[], int indice) {
  printf("Dados do struct no índice %d:\n", indice);
  printf("Timestamp: %s\n", dados[indice]->timestamp);
  printf("Age: %.1f\n", dados[indice]->age);
  printf("Streaming Service: %s\n", dados[indice]->streaming_service);
  printf("Hours per Day: %.1f\n", dados[indice]->hours_per_day);
  printf("While Working: %s\n", dados[indice]->while_working);
  printf("Instrumentalist: %s\n", dados[indice]->instrumentalist);
  printf("Composer: %s\n", dados[indice]->composer);
  printf("Favorite Genre: %s\n", dados[indice]->fav_genre);
  printf("Exploratory: %s\n", dados[indice]->exploratory);
  printf("Foreign Languages: %s\n", dados[indice]->foreign_languages);
  printf("BPM: %.1f\n", dados[indice]->bpm);
  printf("Frequency Classical: %s\n", dados[indice]->frequency_classical);
  printf("Frequency Country: %s\n", dados[indice]->frequency_country);
  printf("Frequency EDM: %s\n", dados[indice]->frequency_edm);
  printf("Frequency Folk: %s\n", dados[indice]->frequency_folk);
  printf("Frequency Gospel: %s\n", dados[indice]->frequency_gospel);
  printf("Frequency Hip Hop: %s\n", dados[indice]->frequency_hip_hop);
  printf("Frequency Jazz: %s\n", dados[indice]->frequency_jazz);
  printf("Frequency K-pop: %s\n", dados[indice]->frequency_kpop);
  printf("Frequency Latin: %s\n", dados[indice]->frequency_latin);
  printf("Frequency Lo-fi: %s\n", dados[indice]->frequency_lofi);
  printf("Frequency Metal: %s\n", dados[indice]->frequency_metal);
  printf("Frequency Pop: %s\n", dados[indice]->frequency_pop);
  printf("Frequency R&B: %s\n", dados[indice]->frequency_rb);
  printf("Frequency Rap: %s\n", dados[indice]->frequency_rap);
  printf("Frequency Rock: %s\n", dados[indice]->frequency_rock);
  printf("Frequency Video Game Music: %s\n", dados[indice]->frequency_video_game_music);
  printf("Anxiety: %.2f\n", dados[indice]->anxiety);
  printf("Depression: %.2f\n", dados[indice]->depression);
  printf("Insomnia: %.2f\n", dados[indice]->depression);
  printf("OCD: %.2f\n", dados[indice]->ocd);
  printf("Music Effects: %s\n", dados[indice]->music_effects);
}

void preencherDadosCSV(tDados_csv* dados[], int numLinhas) {
  FILE* arquivo = fopen("arquivo_corrigido.csv", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  char linha[10000];
  fgets(linha, sizeof(linha), arquivo); 

  for (int i = 0; i < numLinhas; i++) {
    if (fgets(linha, sizeof(linha), arquivo)) {
      sscanf(linha, "%[^,],%f,%[^,],%f,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f,%[^,]",
             dados[i]->timestamp, &dados[i]->age, dados[i]->streaming_service, &dados[i]->hours_per_day, dados[i]->while_working, dados[i]->instrumentalist, dados[i]->composer, dados[i]->fav_genre,
             dados[i]->exploratory, dados[i]->foreign_languages, &dados[i]->bpm, dados[i]->frequency_classical, dados[i]->frequency_country, dados[i]->frequency_edm, dados[i]->frequency_folk,
             dados[i]->frequency_gospel, dados[i]->frequency_hip_hop, dados[i]->frequency_jazz, dados[i]->frequency_kpop, dados[i]->frequency_latin, dados[i]->frequency_lofi, dados[i]->frequency_metal,
             dados[i]->frequency_pop, dados[i]->frequency_rb, dados[i]->frequency_rap, dados[i]->frequency_rock, dados[i]->frequency_video_game_music, &dados[i]->anxiety, &dados[i]->depression, &dados[i]->insomnia,
             &dados[i]->ocd, dados[i]->music_effects);
    }
  }
  fclose(arquivo);
}

int main() {
  int numLinhas = 735;
  int indice;
  tDados_csv* dados[numLinhas];

  for (int i = 0; i < numLinhas; i++) {
    dados[i] = (tDados_csv*)malloc(sizeof(tDados_csv));
    if (dados[i] == NULL) {
      printf("Erro ao alocar memória.\n");
      exit(1);
      }
  }

  preencherDadosCSV(dados, numLinhas);
  
  /*printf("Digite o indice a ser buscado\n");
  scanf("%d", &indice);
  imprimirStructEspecifica(dados, indice);*/


  float media_idade;
  int cont;
  for (int i = 0; i < 735; i++){
    if (dados[i]->age > 0){
      media_idade += dados[i]->age;
      cont ++;
    }
  }
  media_idade = media_idade / cont;
  printf("A media das idades e: %f.\n", media_idade);

  int cont_spotify = 0, cont_YTmusic = 0, cont_apple = 0, cont_pandora = 0, cont_other = 0, cont_DontUse = 0;
  for (int i = 0; i < 735; i++){
    if(strcmp("Spotify", dados[i]->streaming_service) == 0){
      cont_spotify ++;
    }
    if(strcmp("YouTube Music", dados[i]->streaming_service) == 0){
      cont_YTmusic ++;
    }
    else if(strcmp("Apple Music", dados[i]->streaming_service) == 0){
      cont_apple ++;
    }
    else if(strcmp("Pandora", dados[i]->streaming_service) == 0){
      cont_pandora ++;
    }
    else if(strcmp("Other streaming service", dados[i]->streaming_service) == 0){
      cont_other ++;
    }
    else if(strcmp("I do not use a streaming service.", dados[i]->streaming_service) == 0){
      cont_DontUse ++;
    }
  }
  printf("\n");
  printf("Contagem do uso dos Streamings\n");
  printf("Spotify: %d\n", cont_spotify);
  printf("Youtube Music: %d\n", cont_YTmusic);
  printf("Apple Music: %d\n", cont_apple);
  printf("Pandora: %d\n", cont_pandora);
  printf("Other streaming service: %d\n", cont_other);
  printf("Dont use streaming service: %d\n", cont_DontUse);
  
  for (int i = 0; i < numLinhas; i++) {
    free(dados[i]);
  }
 
  float leve = 0, mediano = 0, muito_tempo = 0;
    int cont_leve = 0, cont_mediano = 0, cont_muito_tempo = 0;

    for (int i = 0; i < numLinhas; i++) {
        if (dados[i]->hours_per_day > 0) {
            if (dados[i]->hours_per_day <= 2) {
                leve += dados[i]->hours_per_day;
                cont_leve++;
            } else if (dados[i]->hours_per_day <= 5) {
                mediano += dados[i]->hours_per_day;
                cont_mediano++;
            } else {
                muito_tempo += dados[i]->hours_per_day;
                cont_muito_tempo++;
            }
        }
    }
    
float media_insonia_leve = 0, media_insonia_mediano = 0, media_insonia_muito_tempo = 0;
    float media_depressao_leve = 0, media_depressao_mediano = 0, media_depressao_muito_tempo = 0;
    float media_ansiedade_leve = 0, media_ansiedade_mediano = 0, media_ansiedade_muito_tempo = 0;
    int cont_insonia_leve = 0, cont_insonia_mediano = 0, cont_insonia_muito_tempo = 0;
    int cont_depressao_leve = 0, cont_depressao_mediano = 0, cont_depressao_muito_tempo = 0;
    int cont_ansiedade_leve = 0, cont_ansiedade_mediano = 0, cont_ansiedade_muito_tempo = 0;

    for (int i = 0; i < numLinhas; i++) {
        if (dados[i]->hours_per_day > 0) {
            if (dados[i]->hours_per_day <= 2) {
                media_insonia_leve += dados[i]->insomnia;
                media_depressao_leve += dados[i]->depression;
                media_ansiedade_leve += dados[i]->anxiety;
                cont_insonia_leve++;
                cont_depressao_leve++;
                cont_ansiedade_leve++;
            } else if (dados[i]->hours_per_day <= 5) {
                media_insonia_mediano += dados[i]->insomnia;
                media_depressao_mediano += dados[i]->depression;
                media_ansiedade_mediano += dados[i]->anxiety;
                cont_insonia_mediano++;
                cont_depressao_mediano++;
                cont_ansiedade_mediano++;
            } else {
                media_insonia_muito_tempo += dados[i]->insomnia;
                media_depressao_muito_tempo += dados[i]->depression;
                media_ansiedade_muito_tempo += dados[i]->anxiety;
                cont_insonia_muito_tempo++;
                cont_depressao_muito_tempo++;
                cont_ansiedade_muito_tempo++;
            }
        }
    }

    if (cont_insonia_leve > 0) {
        media_insonia_leve /= cont_insonia_leve;
        media_depressao_leve /= cont_depressao_leve;
        media_ansiedade_leve /= cont_ansiedade_leve;
    }
    if (cont_insonia_mediano > 0) {
        media_insonia_mediano /= cont_insonia_mediano;
        media_depressao_mediano /= cont_depressao_mediano;
        media_ansiedade_mediano /= cont_ansiedade_mediano;
    }
    if (cont_insonia_muito_tempo > 0) {
        media_insonia_muito_tempo /= cont_insonia_muito_tempo;
        media_depressao_muito_tempo /= cont_depressao_muito_tempo;
        media_ansiedade_muito_tempo /= cont_ansiedade_muito_tempo;
    }

    printf("\nMédia da insônia, depressão e ansiedade para cada classificação de tempo:\n");
    printf("Tempo leve (até 2 horas por dia):\n");
      printf("- Média de insônia: %.2f\n", media_insonia_leve);
    printf("- Média de depressão: %.2f\n", media_depressao_leve);
    printf("- Média de ansiedade: %.2f\n", media_ansiedade_leve);

    printf("Tempo mediano (mais de 2 horas e até 5 horas por dia):\n");
    printf("- Média de insônia: %.2f\n", media_insonia_mediano);
    printf("- Média de depressão: %.2f\n", media_depressao_mediano);
    printf("- Média de ansiedade: %.2f\n", media_ansiedade_mediano);

    printf("Tempo muito tempo (mais de 5 horas por dia):\n");
    printf("- Média de insônia: %.2f\n", media_insonia_muito_tempo);
    printf("- Média de depressão: %.2f\n", media_depressao_muito_tempo);
    printf("- Média de ansiedade: %.2f\n", media_ansiedade_muito_tempo);
  return 0;
}
