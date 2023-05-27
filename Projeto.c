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
  
  
    /*2)ANÁLISE ESTILOS MUSICAIS MAIS RECORRENTES*/
  
int rock_depressao = 0;
int latin_depressao = 0;
int vgm_depressao = 0;
int jazz_depressao = 0;
int kpop_depressao = 0;
int country_depressao = 0;
int hiphop_depressao = 0;
int rap_depressao = 0;
int classical_depressao = 0;
int pop_depressao = 0;
int gospel_depressao = 0;

for (int i = 0; i < numLinhas; i++) {
    if (dados[i]->depression > 6) {
        if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
            rock_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
            latin_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
            vgm_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
            jazz_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
            kpop_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
            country_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
            hiphop_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
            rap_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
            classical_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
            pop_depressao++;
        }
        else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
            gospel_depressao++;
        }
    }
}

int rock_ansiedade = 0;
int latin_ansiedade = 0;
int vgm_ansiedade = 0;
int jazz_ansiedade = 0;
int kpop_ansiedade = 0;
int country_ansiedade = 0;
int hiphop_ansiedade = 0;
int rap_ansiedade = 0;
int classical_ansiedade = 0;
int pop_ansiedade = 0;
int gospel_ansiedade = 0;

for (int i = 0; i < numLinhas; i++) {
    if (dados[i]->anxiety > 6) {
        if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
            rock_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
            latin_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
            vgm_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
            jazz_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
            kpop_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
            country_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
            hiphop_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
            rap_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
            classical_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
            pop_ansiedade++;
        }
        else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
            gospel_ansiedade++;
        }
    }
}
  
int rock_insonia = 0;
int latin_insonia = 0;
int vgm_insonia = 0;
int jazz_insonia = 0;
int kpop_insonia = 0;
int country_insonia = 0;
int hiphop_insonia = 0;
int rap_insonia = 0;
int classical_insonia = 0;
int pop_insonia = 0;
int gospel_insonia = 0;

for (int i = 0; i < numLinhas; i++) {
    if (dados[i]->insomnia > 6) {
        if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
            rock_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
            latin_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
            vgm_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
            jazz_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
            kpop_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
            country_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
            hiphop_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
            rap_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
            classical_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
            pop_insonia++;
        }
        else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
            gospel_insonia++;
        }
    }
}
printf("\n");
printf("Depressão por gênero musical:\n");
printf("Rock: %d\n", rock_depressao);
printf("Latin: %d\n", latin_depressao);
printf("Video game music: %d\n", vgm_depressao);
printf("Jazz: %d\n", jazz_depressao);
printf("K pop: %d\n", kpop_depressao);
printf("Country: %d\n", country_depressao);
printf("Hip hop: %d\n", hiphop_depressao);
printf("Rap: %d\n", rap_depressao);
printf("Classical: %d\n", classical_depressao);
printf("Pop: %d\n", pop_depressao);
printf("Gospel: %d\n", gospel_depressao);
printf("\n");
printf("Insônia por gênero musical:\n");
printf("Rock: %d\n", rock_insonia);
printf("Latin: %d\n", latin_insonia);
printf("Video game music: %d\n", vgm_insonia);
printf("Jazz: %d\n", jazz_insonia);
printf("K pop: %d\n", kpop_insonia);
printf("Country: %d\n", country_insonia);
printf("Hip hop: %d\n", hiphop_insonia);
printf("Rap: %d\n", rap_insonia);
printf("Classical: %d\n", classical_insonia);
printf("Pop: %d\n", pop_insonia);
printf("Gospel: %d\n", gospel_insonia);
printf("\n");
printf("Ansiedade por gênero musical:\n");
printf("Rock: %d\n", rock_ansiedade);
printf("Latin: %d\n", latin_ansiedade);
printf("Video game music: %d\n", vgm_ansiedade);
printf("Jazz: %d\n", jazz_ansiedade);
printf("K pop: %d\n", kpop_ansiedade);
printf("Country: %d\n", country_ansiedade);
printf("Hip hop: %d\n", hiphop_ansiedade);
printf("Rap: %d\n", rap_ansiedade);
printf("Classical: %d\n", classical_ansiedade);
printf("Pop: %d\n", pop_ansiedade);
printf("Gospel: %d\n", gospel_ansiedade);
  
/*3)ANÁLISE relação da música na saúde mental*/

float media_ansiedade_no_effect = 0, media_ansiedade_improve = 0, media_ansiedade_worsen = 0;
float media_depressao_no_effect = 0, media_depressao_improve = 0, media_depressao_worsen = 0;
float media_insonia_no_effect = 0, media_insonia_improve = 0, media_insonia_worsen = 0;
int cont_no_effect = 0, cont_improve = 0, cont_worsen = 0;

for (int i = 0; i < numLinhas; i++) {
  if (strcmp("No effect", dados[i]->music_effects) == 0) {
    media_ansiedade_no_effect += dados[i]->anxiety;
    media_depressao_no_effect += dados[i]->depression;
    media_insonia_no_effect += dados[i]->insomnia;
    cont_no_effect++;
  } else if (strcmp("Improve", dados[i]->music_effects) == 0) {
    media_ansiedade_improve += dados[i]->anxiety;
    media_depressao_improve += dados[i]->depression;
    media_insonia_improve += dados[i]->insomnia;
    cont_improve++;
  } else if (strcmp("Worsen", dados[i]->music_effects) == 0) {
    media_ansiedade_worsen += dados[i]->anxiety;
    media_depressao_worsen += dados[i]->depression;
    media_insonia_worsen += dados[i]->insomnia;
    cont_worsen++;
  }
}

if (cont_no_effect > 0) {
  media_ansiedade_no_effect /= cont_no_effect;
  media_depressao_no_effect /= cont_no_effect;
  media_insonia_no_effect /= cont_no_effect;
}

if (cont_improve > 0) {
  media_ansiedade_improve /= cont_improve;
  media_depressao_improve /= cont_improve;
  media_insonia_improve /= cont_improve;
}

if (cont_worsen > 0) {
  media_ansiedade_worsen /= cont_worsen;
  media_depressao_worsen /= cont_worsen;
  media_insonia_worsen /= cont_worsen;
}

printf("\nMédia da ansiedade, depressão e insônia para cada classificação de efeito musical:\n");
printf("No effect:\n");
printf("- Média de ansiedade: %.2f\n", media_ansiedade_no_effect);
printf("- Média de depressão: %.2f\n", media_depressao_no_effect);
printf("- Média de insônia: %.2f\n", media_insonia_no_effect);

printf("Improve:\n");
printf("- Média de ansiedade: %.2f\n", media_ansiedade_improve);
printf("- Média de depressão: %.2f\n", media_depressao_improve);
printf("- Média de insônia: %.2f\n", media_insonia_improve);

printf("Worsen:\n");
printf("- Média de ansiedade: %.2f\n", media_ansiedade_worsen);
printf("- Média de depressão: %.2f\n", media_depressao_worsen);
printf("- Média de insônia: %.2f\n", media_insonia_worsen);

float media_tempo_no_effect=0, media_tempo_improve = 0, media_tempo_worsen = 0;
float cont_tempo_no_effect = 0, cont_tempo_improve= 0, cont_tempo_worsen = 0;

for (int i = 0; i < numLinhas; i++) {
  if (strcmp("No effect", dados[i]->music_effects) == 0) {
    media_tempo_no_effect += dados[i]->hours_per_day;
    cont_tempo_no_effect++;}
  else if (strcmp("Improve", dados[i]->music_effects) == 0) {
    media_tempo_improve += dados[i]->hours_per_day;
    cont_tempo_improve++;}
  else if (strcmp("Worsen", dados[i]->music_effects)== 0){
    media_tempo_worsen += dados[i]-> hours_per_day;
    cont_tempo_worsen++;
  }  
}
  
printf("\nMédia de tempo para cada grupo(Os que acreditam que faz efeito, os acreditam que piora e os que acreditam que não tem efeito.\n");
 if (cont_tempo_no_effect > 0) {
    media_tempo_no_effect /= cont_tempo_no_effect;
    int horas = (int)media_tempo_no_effect;
    int minutos = (int)((media_tempo_no_effect - horas) * 60);
    printf("\nSem efeito:\n- Média de tempo: %d h %02d min\n", horas, minutos);
  }

  if (cont_tempo_improve > 0) {
    media_tempo_improve /= cont_tempo_improve;
    int horas = (int)media_tempo_improve;
    int minutos = (int)((media_tempo_improve - horas) * 60);
    printf("Efeito Positivo:\n- Média de tempo: %d h %02d min\n", horas, minutos);
  }

  if (cont_tempo_worsen > 0) {
    media_tempo_worsen /= cont_tempo_worsen;
    int horas = (int)media_tempo_worsen;
    int minutos = (int)((media_tempo_worsen - horas) * 60);
    printf("Efeito Negativo:\n- Média de tempo: %d h %02d min\n", horas, minutos);
  }


 return 0;
}
