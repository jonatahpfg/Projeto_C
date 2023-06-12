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
   
  /*1)ANALISE RELAÇÃO TEMPO POR SAÚDE MENTAL*/
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
    if (dados[i]->anxiety >  6) {
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
    if (dados[i]->insomnia >  6) {
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
  /*4)A IDADE PODE INFLUENCIAR NOS GOSTOS MUSICAIS*/

int rock_idade_media = 0;
int latin_idade_media = 0;
int vgm_idade_media = 0;
int jazz_idade_media = 0;
int kpop_idade_media = 0;
int country_idade_media = 0;
int hiphop_idade_media = 0;
int rap_idade_media = 0;
int classical_idade_media = 0;
int pop_idade_media = 0;
int gospel_idade_media = 0;
int edm_idade_media = 0;
int metal_idade_media = 0;
int rb_idade_media = 0;
int folk_idade_media = 0;
int lofi_idade_media = 0;

  
int rock_count = 0;
int latin_count = 0;
int vgm_count = 0;
int jazz_count = 0;
int kpop_count = 0;
int country_count = 0;
int hiphop_count = 0;
int rap_count = 0;
int classical_count = 0;
int pop_count = 0;
int gospel_count = 0;
int edm_count =0;
int metal_count = 0;
int rb_count =0; 
int folk_count = 0;
int lofi_count = 0;
  
  
  for (int i = 0; i < numLinhas; i++) {
    if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
      rock_idade_media += dados[i]->age;
      rock_count++;
      }
      else if (strcmp(dados[i]->fav_genre, "Lofi") == 0) {
      lofi_idade_media += dados[i]->age;
      lofi_count++;
      }
        else if (strcmp(dados[i]->fav_genre, "R&B") == 0) {
      rb_idade_media += dados[i]->age;
      rb_count++;
      }
      else if (strcmp(dados[i]->fav_genre, "Metal") == 0) {
      metal_idade_media += dados[i]->age;
      metal_count++;
      }
        else if (strcmp(dados[i]->fav_genre, "Folk") == 0) {
      folk_idade_media += dados[i]->age;
      folk_count++;
      }
          else if (strcmp(dados[i]->fav_genre, "EDM") == 0) {
      edm_idade_media += dados[i]->age;
      edm_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
      latin_idade_media += dados[i]->age;
      latin_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
      vgm_idade_media += dados[i]->age;
      vgm_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
      jazz_idade_media += dados[i]->age;
      jazz_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
      kpop_idade_media += dados[i]->age;
      kpop_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
      country_idade_media += dados[i]->age;
      country_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
      hiphop_idade_media += dados[i]->age;
      hiphop_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
      rap_idade_media += dados[i]->age;
      rap_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
      classical_idade_media += dados[i]->age;
      classical_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
      pop_idade_media += dados[i]->age;
      pop_count++;
      }
    else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
      gospel_idade_media += dados[i]->age;
      gospel_count++;
      }
  }
    lofi_idade_media/= lofi_count;
    edm_idade_media/= edm_count;
   metal_idade_media/= metal_count;
  folk_idade_media/=folk_count;
  rb_idade_media/= rb_count;
    rock_idade_media /= rock_count;
    latin_idade_media /= latin_count;
    vgm_idade_media /= vgm_count;
    jazz_idade_media /= jazz_count;
    kpop_idade_media /= kpop_count;
    country_idade_media /= country_count;
    hiphop_idade_media /= hiphop_count;
    rap_idade_media /= rap_count;
    classical_idade_media /= classical_count;
    pop_idade_media /= pop_count;
    gospel_idade_media /= gospel_count;

printf("\n");
printf("Quantidade por gênero:\n");
printf("Rock: %d\n", rock_count);
printf("Latin: %d\n", latin_count);
printf("Video game music: %d\n", vgm_count);
printf("Jazz: %d\n", jazz_count);
printf("K pop: %d\n", kpop_count);
printf("Country: %d\n", country_count);
printf("Hip hop: %d\n", hiphop_count);
printf("Rap: %d\n", rap_count);
printf("Classical: %d\n", classical_count);
printf("Pop: %d\n", pop_count);
printf("Gospel: %d\n", gospel_count);
printf("Metal: %d\n", metal_count);
printf("Lofi: %d\n", lofi_count);
printf("Folk: %d\n", folk_count);
printf("R&B: %d\n", rb_count);
printf("EDM: %d\n", edm_count);
printf("\n");

printf("\n");
printf("Média de idades por gênero:\n");
printf("Rock: %d\n", rock_idade_media);
printf("Latin: %d\n", latin_idade_media);
printf("Video game music: %d\n", vgm_idade_media);
printf("Jazz: %d\n", jazz_idade_media);
printf("K pop: %d\n", kpop_idade_media);
printf("Country: %d\n", country_idade_media);
printf("Hip hop: %d\n", hiphop_idade_media);
printf("Rap: %d\n", rap_idade_media);
printf("Classical: %d\n", classical_idade_media);
printf("Pop: %d\n", pop_idade_media);
printf("Gospel: %d\n", gospel_idade_media);
printf("Metal: %d\n", metal_idade_media);
printf("Lofi: %d\n", lofi_idade_media);
printf("Folk: %d\n", folk_idade_media);
printf("R&B: %d\n", rb_idade_media);
printf("EDM: %d\n", edm_idade_media);
printf("\n");


/*Parte 5, relações de BPM a insônia e ansiedade*/
int cont_insomnia_menor_3 = 0, cont_insomnia_menor_7 = 0, cont_insomnia_menor_10 = 0;
float  media_bpm_menor_3 = 0, media_bpm_menor_7 = 0, media_bpm_menor_10 = 0;
  
for (int i = 0; i < numLinhas; i++){
  if(dados[i]->bpm >=20 && dados[i]->bpm < 300){
    if(dados[i]->insomnia>= 0){
      if(dados[i]->insomnia <= 3){
        media_bpm_menor_3 += dados[i]->bpm;
        cont_insomnia_menor_3 ++;
      }
      else if(dados[i]->insomnia <= 7){
        media_bpm_menor_7 += dados[i]->bpm;
        cont_insomnia_menor_7 ++;
      }
      else if(dados[i]->insomnia <= 10){
        media_bpm_menor_10 += dados[i]->bpm;
        cont_insomnia_menor_10 ++;
      }
    }
  }
}
if (cont_insomnia_menor_3 > 0) {
  media_bpm_menor_3 = media_bpm_menor_3 / cont_insomnia_menor_3;
}

if (cont_insomnia_menor_7 > 0) {
  media_bpm_menor_7 = media_bpm_menor_7 / cont_insomnia_menor_7;
}

if (cont_insomnia_menor_10 > 0) {
  media_bpm_menor_10 = media_bpm_menor_10 / cont_insomnia_menor_10;
}

printf("\n");
printf("Media do BPM para niveis de insonia ate 3: %.2f\n", media_bpm_menor_3);
printf("Media do BPM para niveis de insonia de 4 a 7: %.2f\n", media_bpm_menor_7);
printf("Media do BPM para niveis de insonia de 8 a 10: %.2f\n", media_bpm_menor_10);

float media_rock_insomnia = 0, media_latin_insomnia = 0, media_vgm_insomnia = 0, media_jazz_insomnia = 0;
float media_rb_insomnia = 0, media_kpop_insomnia = 0, media_country_insomnia = 0, media_edm_insomnia = 0;
float media_hiphop_insomnia = 0, media_rap_insomnia = 0, media_pop_insomnia = 0, media_classical_insomnia = 0;
float media_metal_insomnia = 0, media_folk_insomnia = 0, media_lofi_insomnia = 0, media_gospel_insomnia = 0;

int rock_countt = 0;
int latin_countt = 0;
int vgm_countt = 0;
int jazz_countt = 0;
int kpop_countt = 0;
int country_countt = 0;
int hiphop_countt = 0;
int rap_countt = 0;
int classical_countt = 0;
int pop_countt = 0;
int gospel_countt = 0;
int  folk_countt = 0;
int  rb_countt = 0;
int edm_countt = 0;
int metal_countt = 0;
int lofi_countt = 0;

  
for (int i = 0; i < numLinhas; i++) {
  if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
    media_rock_insomnia += dados[i]->insomnia;
    rock_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
    media_latin_insomnia += dados[i]->insomnia;
    latin_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
    media_vgm_insomnia += dados[i]->insomnia;
    vgm_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
    media_jazz_insomnia += dados[i]->insomnia;
    jazz_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "R&B") == 0) {
    media_rb_insomnia += dados[i]->insomnia;
    rb_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
    media_kpop_insomnia += dados[i]->insomnia;
    kpop_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
    media_country_insomnia += dados[i]->insomnia;
    country_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "EDM") == 0) {
    media_edm_insomnia += dados[i]->insomnia;
    edm_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
    media_hiphop_insomnia += dados[i]->insomnia;
    hiphop_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
    media_pop_insomnia += dados[i]->insomnia;
    pop_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
    media_rap_insomnia += dados[i]->insomnia;
    rap_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
    media_classical_insomnia += dados[i]->insomnia;
    classical_countt ++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Metal") == 0) {
    media_metal_insomnia += dados[i]->insomnia;
    metal_countt ++;
  }
  else if (strcmp(dados[i]->fav_genre, "Folk") == 0) {
    media_folk_insomnia += dados[i]->insomnia;
    folk_countt ++;
  }
  else if (strcmp(dados[i]->fav_genre, "Lofi") == 0) {
    media_lofi_insomnia += dados[i]->insomnia;
    lofi_countt ++;
  }
  else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
    media_gospel_insomnia += dados[i]->insomnia;
    gospel_countt ++;
  }
}
printf("\n");
if (rock_countt > 0) {
    media_rock_insomnia /= rock_countt;
    printf("Média de insônia para o gênero Rock: %.2f\n", media_rock_insomnia);
}

if (latin_countt > 0) {
    media_latin_insomnia /= latin_countt;
    printf("Média de insônia para o gênero Latin: %.2f\n", media_latin_insomnia);
}

if (vgm_countt > 0) {
    media_vgm_insomnia /= vgm_countt;
    printf("Média de insônia para o gênero Video game music: %.2f\n", media_vgm_insomnia);
}

if (jazz_countt > 0) {
    media_jazz_insomnia /= jazz_countt;
    printf("Média de insônia para o gênero Jazz: %.2f\n", media_jazz_insomnia);
}

if (rb_countt > 0) {
    media_rb_insomnia /= rb_countt;
    printf("Média de insônia para o gênero R&B: %.2f\n", media_rb_insomnia);
}

if (kpop_countt > 0) {
    media_kpop_insomnia /= kpop_countt;
    printf("Média de insônia para o gênero K pop: %.2f\n", media_kpop_insomnia);
}

if (country_countt > 0) {
    media_country_insomnia /= country_countt;
    printf("Média de insônia para o gênero Country: %.2f\n", media_country_insomnia);
}

if (edm_countt > 0) {
    media_edm_insomnia /= edm_countt;
    printf("Média de insônia para o gênero EDM: %.2f\n", media_edm_insomnia);
}

if (hiphop_countt > 0) {
    media_hiphop_insomnia /= hiphop_countt;
    printf("Média de insônia para o gênero Hip hop: %.2f\n", media_hiphop_insomnia);
}

if (pop_countt > 0) {
    media_pop_insomnia /= pop_countt;
    printf("Média de insônia para o gênero Pop: %.2f\n", media_pop_insomnia);
}

if (rap_countt > 0) {
    media_rap_insomnia /= rap_countt;
    printf("Média de insônia para o gênero Rap: %.2f\n", media_rap_insomnia);
}

if (classical_countt > 0) {
    media_classical_insomnia /= classical_countt;
    printf("Média de insônia para o gênero Classical: %.2f\n", media_classical_insomnia);
}

if (metal_countt > 0) {
    media_metal_insomnia /= metal_countt;
    printf("Média de insônia para o gênero Metal: %.2f\n", media_metal_insomnia);
}

if (folk_countt > 0) {
    media_folk_insomnia /= folk_countt;
    printf("Média de insônia para o gênero Folk: %.2f\n", media_folk_insomnia);
}

if (lofi_countt > 0) {
    media_lofi_insomnia /= lofi_countt;
    printf("Média de insônia para o gênero Lofi: %.2f\n", media_lofi_insomnia);
}

if (gospel_countt > 0) {
    media_gospel_insomnia /= gospel_countt;
    printf("Média de insônia para o gênero Gospel: %.2f\n", media_gospel_insomnia);
}


float somaClassical = 0, somaCountry = 0, somaEDM = 0, somaFolk = 0, somaGospel = 0, somaHipHop = 0;
  float somaJazz = 0, somaKpop = 0, somaLatin = 0, somaLofi = 0, somaMetal = 0, somaPop = 0;
  float somaRB = 0, somaRap = 0, somaRock = 0, somaVGM = 0;
  int countClassical = 0, countCountry = 0, countEDM = 0, countFolk = 0, countGospel = 0, countHipHop = 0;
  int countJazz = 0, countKpop = 0, countLatin = 0, countLofi = 0, countMetal = 0, countPop = 0;
  int countRB = 0, countRap = 0, countRock = 0, countVGM = 0;

  for (int i = 0; i < numLinhas; i++) {
    if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
     if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300) { somaClassical += dados[i]->bpm;
      countClassical++;}
    } else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaCountry += dados[i]->bpm;
      countCountry++;}
    } else if (strcmp(dados[i]->fav_genre, "EDM") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaEDM += dados[i]->bpm;
      countEDM++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaRock += dados[i]->bpm;
      countRock++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Folk") == 0) {
     if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){ somaFolk += dados[i]->bpm;
      countFolk++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){ somaGospel += dados[i]->bpm;
      countGospel++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaHipHop += dados[i]->bpm;
      countHipHop++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){ somaCountry += dados[i]->bpm;
      countCountry++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaJazz += dados[i]->bpm;
      countJazz++;}
    }
     else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaKpop += dados[i]->bpm;
      countKpop++;}
    }
    else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
     if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300) {somaLatin += dados[i]->bpm;
      countLatin++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Lofi") == 0) {
     if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300) {somaLofi += dados[i]->bpm;
      countLofi++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Metal") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaMetal += dados[i]->bpm;
      countMetal++;}
    }
     else if (strcmp(dados[i]->fav_genre, "R&B") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaRB += dados[i]->bpm;
      countRB++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){somaPop += dados[i]->bpm;
      countPop++;}  
    }
     else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
      if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300){ somaRap += dados[i]->bpm;
      countRap++;}
    }
     else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
    if (dados[i]->bpm >= 20 && dados[i]->bpm <= 300) {
      somaVGM += dados[i]->bpm;
      countVGM++;
    }
    }
  }

  
  float mediaClassical = somaClassical / countClassical;
  float mediaCountry = somaCountry / countCountry;
  float mediaEDM = somaEDM / countEDM;
  float mediaFolk = somaFolk / countFolk;
  float mediaGospel = somaGospel / countGospel;
  float mediaHipHop = somaHipHop / countHipHop;
  float mediaJazz = somaJazz / countJazz;
  float mediaKpop = somaKpop / countKpop;
  float mediaLatin = somaLatin / countLatin;
  float mediaLofi = somaLofi / countLofi;
  float mediaMetal = somaMetal / countMetal;
  float mediaPop = somaPop / countPop;
  float mediaRB = somaRB / countRB;
  float mediaRap = somaRap / countRap;
  float mediaRock = somaRock / countRock;
  float mediaVGM = somaVGM / countVGM;

  printf("\n");
  printf("Média de BPM para cada estilo musical:\n");
  printf("Classical: %.2f\n", mediaClassical);
  printf("Country: %.2f\n", mediaCountry);
  printf("EDM: %.2f\n", mediaEDM);
  printf("Folk: %.2f\n", mediaFolk);
  printf("Gospel: %.2f\n", mediaGospel);
  printf("Hip Hop: %.2f\n", mediaHipHop);
  printf("Jazz: %.2f\n", mediaJazz);
  printf("K-pop: %.2f\n", mediaKpop);
  printf("Latin: %.2f\n", mediaLatin);
  printf("Lo-fi: %.2f\n", mediaLofi);
  printf("Metal: %.2f\n", mediaMetal);
  printf("Pop: %.2f\n", mediaPop);
  printf("R&B: %.2f\n", mediaRB);
  printf("Rap: %.2f\n", mediaRap);
  printf("Rock: %.2f\n", mediaRock);
  printf("Video Game Music: %.2f\n", mediaVGM);




 int numExplorers = 0; 
  int sumExplorerAge = 0; 

  int numNonExplorers = 0; 
  int sumNonExplorerAge = 0; 

  for (int i = 0; i < numLinhas; i++) {
    if (strcmp(dados[i]->exploratory, "Yes") == 0) {
      numExplorers++;
      sumExplorerAge += dados[i]->age;
    } else {
      numNonExplorers++;
      sumNonExplorerAge += dados[i]->age;
    }
  }

  float avgExplorerAge = sumExplorerAge / numExplorers;
  float avgNonExplorerAge = sumNonExplorerAge / numNonExplorers;

  printf("\nMédia de idade dos grupos que exploram e não exploram novos artistas e géneros");
  printf("\nMédia de idade dos que exploram: %.2f\n", avgExplorerAge);
  printf("Média de idade dos que não exploram: %.2f\n", avgNonExplorerAge);


 int countExplorers = 0; 
  int countNonExplorers = 0; 

  for (int i = 0; i < numLinhas; i++) {
    if (strcmp(dados[i]->exploratory, "Yes") == 0) {
      countExplorers++;
    } else if (strcmp(dados[i]->exploratory, "No") == 0){
      countNonExplorers++;
    }
  }

  printf("Número de pessoas que exploram: %d\n", countExplorers);
  printf("Número de pessoas que não exploram: %d\n", countNonExplorers);

  float mediaExplorer = ((float)countExplorers / numLinhas)*100;
  float mediaNonExplorer = ((float)countNonExplorers / numLinhas)*100;

  printf("Média de quantidade de pessoas do grupo que explora: %.2f\n", mediaExplorer);
  printf("Média de quantidade de pessoas do grupo que não explora: %.2f\n", mediaNonExplorer);

int group_Explorers = 0;
int frequenciaClassical = 0;
int frequenciaCountry = 0;
int frequenciaEDM = 0;
int frequenciaFolk = 0;
int frequenciaGospel = 0;
int frequenciaHipHop = 0;
int frequenciaJazz = 0;
int frequenciaKpop = 0;
int frequenciaLatin = 0;
int frequenciaLofi = 0;
int frequenciaMetal = 0;
int frequenciaPop = 0;
int frequenciaRB = 0;
int frequenciaRock = 0;
int frequenciaVideoGameMusic = 0;

for (int i = 0; i < numLinhas; i++) {
  if (strcmp(dados[i]->exploratory, "Yes") == 0) {
    group_Explorers++;

    if (strcmp(dados[i]->frequency_classical, "Very frequently") == 0 || strcmp(dados[i]->frequency_classical, "Sometimes") == 0) {
      frequenciaClassical++;
    }

    if (strcmp(dados[i]->frequency_country, "Very frequently") == 0 || strcmp(dados[i]->frequency_country, "Sometimes") == 0) {
      frequenciaCountry++;
    }

    if (strcmp(dados[i]->frequency_edm, "Very frequently") == 0 || strcmp(dados[i]->frequency_edm, "Sometimes") == 0) {
      frequenciaEDM++;
    }

    if (strcmp(dados[i]->frequency_folk, "Very frequently") == 0 || strcmp(dados[i]->frequency_folk, "Sometimes") == 0) {
      frequenciaFolk++;
    }

    if (strcmp(dados[i]->frequency_gospel, "Very frequently") == 0 || strcmp(dados[i]->frequency_gospel, "Sometimes") == 0) {
      frequenciaGospel++;
    }

    if (strcmp(dados[i]->frequency_hip_hop, "Very frequently") == 0 || strcmp(dados[i]->frequency_hip_hop, "Sometimes") == 0) {
      frequenciaHipHop++;
    }

    if (strcmp(dados[i]->frequency_jazz, "Very frequently") == 0 || strcmp(dados[i]->frequency_jazz, "Sometimes") == 0) {
      frequenciaJazz++;
    }

    if (strcmp(dados[i]->frequency_kpop, "Very frequently") == 0 || strcmp(dados[i]->frequency_kpop, "Sometimes") == 0) {
      frequenciaKpop++;
    }

    if (strcmp(dados[i]->frequency_latin, "Very frequently") == 0 || strcmp(dados[i]->frequency_latin, "Sometimes") == 0) {
      frequenciaLatin++;
    }

    if (strcmp(dados[i]->frequency_lofi, "Very frequently") == 0 || strcmp(dados[i]->frequency_lofi, "Sometimes") == 0) {
      frequenciaLofi++;
    }

    if (strcmp(dados[i]->frequency_metal, "Very frequently") == 0 || strcmp(dados[i]->frequency_metal, "Sometimes") == 0) {
      frequenciaMetal++;
    }

    if (strcmp(dados[i]->frequency_pop, "Very frequently") == 0 || strcmp(dados[i]->frequency_pop, "Sometimes") ==0) {
      frequenciaPop++;
    }

    if (strcmp(dados[i]->frequency_rb, "Very frequently") == 0 || strcmp(dados[i]->frequency_rb, "Sometimes") == 0) {
      frequenciaRB++;
    }

    if (strcmp(dados[i]->frequency_rock, "Very frequently") == 0 || strcmp(dados[i]->frequency_rock, "Sometimes") == 0) {
      frequenciaRock++;
    }

    if (strcmp(dados[i]->frequency_video_game_music, "Very frequently") == 0 || strcmp(dados[i]->frequency_video_game_music, "Sometimes") == 0) {
      frequenciaVideoGameMusic++;
    }
  }
}

  
double porcentclassical = (float)frequenciaClassical / group_Explorers;
double porcentcountry = (float)frequenciaCountry / group_Explorers;
double porcentedm = (float)frequenciaEDM / group_Explorers;
double porcentfolk = (float)frequenciaFolk / group_Explorers;
double porcentgospel =  (float)frequenciaGospel / group_Explorers;
double porcenthiphop = (float) frequenciaHipHop / group_Explorers;
double porcentjazz = (float)frequenciaJazz / group_Explorers;
double porcentkpop = (float)frequenciaKpop / group_Explorers;
double porcentlatin = (float)frequenciaLatin / group_Explorers;
double porcentlofi = (float)frequenciaLofi / group_Explorers;
double porcentmetal = (float)frequenciaMetal / group_Explorers;
double porcentpop = (float)frequenciaPop / group_Explorers;
double porcentrb = (float)frequenciaRB / group_Explorers;
double porcentrock = (float)frequenciaRock / group_Explorers;
double porcentvideogamemusic = (float)frequenciaVideoGameMusic / group_Explorers;
      
printf("Média de pessoas que ouvem com frequência o estilo musical, em evidência o grupo que explora novos estilos e artistas:\n");
printf("Porcentagem Classical: %.2f\n", porcentclassical);
printf("Porcentagem Country: %.2f\n", porcentcountry);
printf("Porcentagem EDM: %.2f\n", porcentedm);
printf("Porcentagem Folk: %.2f\n", porcentfolk);
printf("Porcentagem Gospel: %.2f\n", porcentgospel);
printf("Porcentagem Hip Hop: %.2f\n", porcenthiphop);
printf("Porcentagem Jazz: %.2f\n", porcentjazz);
printf("Porcentagem Kpop: %.2f\n", porcentkpop);
printf("Porcentagem Latin: %.2f\n", porcentlatin);
printf("Porcentagem Lofi: %.2f\n", porcentlofi);
printf("Porcentagem Metal: %.2f\n", porcentmetal);
printf("Porcentagem Pop: %.2f\n", porcentpop);
printf("Porcentagem R&B: %.2f\n", porcentrb);
printf("Porcentagem Rock: %.2f\n", porcentrock);
printf("Porcentagem Video Game Music: %.2f\n", porcentvideogamemusic);



float media_rock_anxiety = 0, media_latin_anxiety = 0, media_vgm_anxiety = 0, media_jazz_anxiety = 0;
float media_rb_anxiety = 0, media_kpop_anxiety = 0, media_country_anxiety = 0, media_edm_anxiety = 0;
float media_hiphop_anxiety = 0, media_rap_anxiety = 0, media_pop_anxiety = 0, media_classical_anxiety = 0;
float media_metal_anxiety = 0, media_folk_anxiety = 0, media_lofi_anxiety = 0, media_gospel_anxiety = 0;

int rock_counttt = 0;
int latin_counttt = 0;
int vgm_counttt = 0;
int jazz_counttt = 0;
int kpop_counttt = 0;
int country_counttt = 0;
int hiphop_counttt = 0;
int rap_counttt = 0;
int classical_counttt = 0;
int pop_counttt = 0;
int gospel_counttt = 0;
int  folk_counttt = 0;
int  rb_counttt = 0;
int edm_counttt = 0;
int metal_counttt = 0;
int lofi_counttt = 0;

for (int i = 0; i < numLinhas; i++) {
  if (strcmp(dados[i]->fav_genre, "Rock") == 0) {
    media_rock_anxiety += dados[i]->anxiety;
    rock_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Latin") == 0) {
    media_latin_anxiety += dados[i]->anxiety;
    latin_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Video game music") == 0) {
    media_vgm_anxiety += dados[i]->anxiety;
    vgm_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Jazz") == 0) {
    media_jazz_anxiety += dados[i]->anxiety;
    jazz_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "R&B") == 0) {
    media_rb_anxiety += dados[i]->anxiety;
    rb_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "K pop") == 0) {
    media_kpop_anxiety += dados[i]->anxiety;
    kpop_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Country") == 0) {
    media_country_anxiety += dados[i]->anxiety;
    country_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "EDM") == 0) {
    media_edm_anxiety += dados[i]->anxiety;
    edm_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Hip hop") == 0) {
    media_hiphop_anxiety += dados[i]->anxiety;
    hiphop_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Pop") == 0) {
    media_pop_anxiety += dados[i]->anxiety;
    pop_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Rap") == 0) {
  media_rap_anxiety += dados[i]->anxiety;
    rap_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Classical") == 0) {
    media_classical_anxiety += dados[i]->anxiety;
    classical_counttt++;
  } 
  else if (strcmp(dados[i]->fav_genre, "Metal") == 0) {
    media_metal_anxiety += dados[i]->anxiety;
    metal_counttt++;
  }
  else if (strcmp(dados[i]->fav_genre, "Folk") == 0) {
    media_folk_anxiety += dados[i]->anxiety;
    folk_counttt++;
  }
  else if (strcmp(dados[i]->fav_genre, "Lofi") == 0) {
    media_lofi_anxiety += dados[i]->anxiety;
    lofi_counttt++;
  }
  else if (strcmp(dados[i]->fav_genre, "Gospel") == 0) {
    media_gospel_anxiety += dados[i]->anxiety;
    gospel_counttt++;
  }
}

// Calcular as médias
if (rock_countt > 0)
  media_rock_anxiety /= rock_counttt;
if (latin_countt > 0)
  media_latin_anxiety /= latin_counttt;
if (vgm_countt > 0)
  media_vgm_anxiety /= vgm_counttt;
if (jazz_countt > 0)
  media_jazz_anxiety /= jazz_counttt;
if (rb_countt > 0)
  media_rb_anxiety /= rb_counttt;
if (kpop_countt > 0)
  media_kpop_anxiety /= kpop_counttt;
if (country_countt > 0)
  media_country_anxiety /= country_counttt;
if (edm_countt > 0)
  media_edm_anxiety /= edm_counttt;
if (hiphop_countt > 0)
  media_hiphop_anxiety /= hiphop_counttt;
if (pop_countt > 0)
  media_pop_anxiety /= pop_counttt;
if (rap_countt > 0)
  media_rap_anxiety /= rap_counttt;
if (classical_countt > 0)
  media_classical_anxiety /= classical_countt;
if (metal_countt > 0)
  media_metal_anxiety /= metal_counttt;
if (folk_countt > 0)
  media_folk_anxiety /= folk_counttt;
if (lofi_countt > 0)
  media_lofi_anxiety /= lofi_counttt;
if (gospel_countt > 0)
  media_gospel_anxiety /= gospel_counttt;

printf("\nMédias de ansiedade por estilo de música:\n");
printf("Rock: %.2f\n", media_rock_anxiety);
printf("Latin: %.2f\n", media_latin_anxiety);
printf("Video game music: %.2f\n", media_vgm_anxiety);
printf("Jazz: %.2f\n", media_jazz_anxiety);
printf("R&B: %.2f\n", media_rb_anxiety);
printf("K pop: %.2f\n", media_kpop_anxiety);
printf("Country: %.2f\n", media_country_anxiety);
printf("EDM: %.2f\n", media_edm_anxiety);
printf("Hip hop: %.2f\n", media_hiphop_anxiety);
printf("Pop: %.2f\n", media_pop_anxiety);
printf("Rap: %.2f\n", media_rap_anxiety);
printf("Classical: %.2f\n", media_classical_anxiety);
printf("Metal: %.2f\n", media_metal_anxiety);
printf("Folk: %.2f\n", media_folk_anxiety);
printf("Lofi: %.2f\n", media_lofi_anxiety);
printf("Gospel: %.2f\n", media_gospel_anxiety);

  return 0; 
}
