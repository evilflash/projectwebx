#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseJSON.h"

int parseJSON(){
	printf("\nparseJSON\n");
	int saut = 0;
    int sizeofmain = 0;
    int i = 0;
    FILE* WeatherJSON = fopen("weather.json", "r");
	if(WeatherJSON == NULL)
    {
        fprintf(stderr,"\nERROR, cannot open the weather file");
        return -1;
    }
    char* description = NULL;
    char weather[4] = "", temp_now[7] = "", pressure[5] = "", humidity[3] = "", temp_min[7] = "", temp_max[7] = "",
        visibility[6] = "", wind_speed[4] = "", wind_degree[4] = "", sun_sunrise[11] = "", sun_sunset[11] = "", lecture[100];

    fseek(WeatherJSON, 0, SEEK_SET);

    fseek(WeatherJSON, 51, SEEK_CUR);
    fread(weather, 3, 1, WeatherJSON);
    fseek(WeatherJSON, 1, SEEK_CUR);
    char char_actuel = "";


    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    	char_actuel = fgetc(WeatherJSON);

    fseek(WeatherJSON, 16, SEEK_CUR);
    while(char_actuel != '"')
    {
    	sizeofmain++;
	char_actuel = fgetc(WeatherJSON);
    }
	printf("l38");
    description = malloc (sizeof(char) * (sizeofmain + 1));
    fseek(WeatherJSON, -(sizeofmain + 1), SEEK_CUR);

    fread(description, sizeofmain, 1, WeatherJSON);
    description[sizeofmain] = '\0';

    printf("%s",description);

    while(saut < 3){
        char_actuel = fgetc(WeatherJSON);
        if(char_actuel == ','){
            saut++;
        }
    }
    saut = 0;
    while(saut < 2){
        char_actuel = fgetc(WeatherJSON);
         if(char_actuel == ':'){
            saut++;
        }
    }

    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        temp_now[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

    while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }

    i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        pressure[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }
    // printf("\n\n resbis : %s", pressure);
    while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }
     i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        humidity[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

     while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }
     i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        temp_min[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

    while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }
     i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != '}')
    {
        temp_max[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

    while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }
    i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        visibility[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

    saut = 0;
    while(saut < 2){
        char_actuel = fgetc(WeatherJSON);
         if(char_actuel == ':'){
            saut++;
        }
    }
    i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        wind_speed[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

    while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }
    i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != '}')
    {
        wind_degree[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }

    saut = 0;
    while(saut < 9){
        char_actuel = fgetc(WeatherJSON);
         if(char_actuel == ':'){
            saut++;
        }
    }
    i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != ',')
    {
        sun_sunrise[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }
    //printf("\n\n resbis : %s", sun_sunrise);
    while(char_actuel != ':'){
        char_actuel = fgetc((WeatherJSON));
    }
    i = 0;
    char_actuel = fgetc(WeatherJSON);
    while(char_actuel != '}')
    {
        sun_sunset[i] = char_actuel;
        char_actuel = fgetc(WeatherJSON);
        i++;
    }
    fclose(WeatherJSON);
    MYSQL sql;
    mysql_init(&sql);
    mysql_options(&sql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&sql,"127.0.0.1","root","aenprojectx","aen",0,NULL,0))
    {
    	  mysql_query(&sql, "SET NAMES 'utf8'");
          char marequete[600] = "";
          //On stock la requete dans notre tableau de char
          sprintf(marequete, "UPDATE meteo SET  iDMeteo, weather = %s, description = %s, tempnow = %s, pressure = %s, humidity = %s, tempsmin = %s, tempsmax = %s, visibility = %s, windspeed = %s, winddegree = %s, sunrise = %s, sunset = %s"
                  ,weather,description,temp_now,pressure,humidity,temp_min,temp_max,visibility,wind_speed,wind_degree,sun_sunrise,sun_sunset);
          //On execute la requete
          mysql_query(&sql, marequete);
          mysql_close(&sql);
    }
    else
    {
        printf("Une erreur � eu lieu lors de la connection sur la base de donn�e.");
    }
    free(description);
}
