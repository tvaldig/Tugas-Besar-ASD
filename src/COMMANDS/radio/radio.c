#include "radio.h"


Word temp[RMAX];
int CountLagu(Set *s, MapAlbum m)
{
    int count = 0;
    for (int i = 0; i < m.Count; i++)
    {
        for (int j = 0; j < s[Value(m, i)].Count; j++)
        {
            count++;
        }
    }
    return count;
}

void TempLagu(Set *s, MapAlbum m)
{
    int id = 0, idset;
     for (int i = 0; i < m.Count; i++)
    {
        idset = Value(m, i);
        for (int j = 0; j < s[Value(m, i)].Count; j++)
        {
            temp[id] = s[idset].AlbumLagu[j].JudulLagu;
            id++;
        }
    }
}

void CreateEmptyRadio(Radio *r){
    r->RNeff = 0;
}

boolean SearchRadio(Radio *r, int id, int max){
    boolean found = false;
    int i = 0;
    while(i < max && !found){
        if(id == r->El[i]){
            found = true;
        }
        i++;
    }
    return 0;
}
int getSetLaguFromTemp(int id){
    for (int i = 0; i < mapAlbum.Count; i++)
    {
        for (int j = 0; j < mapAlbum.Count+1; j++)
        {
            if(IsStringEqual(temp[id].TabWord, SetLagu[Value(mapAlbum,i)].AlbumLagu[j].JudulLagu.TabWord)){
                return SetLagu[Value(mapAlbum,i)].idSet;
            }
        }
    }
    return -999;
}

int getIDPenyanyiFromAlbum(int idalbum){
    int check = 0;
    for(int i = 0; i < ArrayPenyanyi.Neff; i++){
        for (int j = ArrayPenyanyi.penyanyi->IdAlbumPertama; j < ArrayPenyanyi.penyanyi->IdAlbumPertama + ArrayPenyanyi.penyanyi->jumlahalbum;j++){
            if(check == idalbum){
                return i;
            }
            check++;
        }
    }
    return -999;
}
void playRadio(Radio *r){
    CreateQueue(&antrian);
    CreateEmptyStack(&riwayat);
    int idalbum, album, lagu, penyanyi;
    for(int i = 0; i < r->RNeff; i++){
        album = getSetLaguFromTemp(r->El[i])-1;
        lagu = searchidlagu(SetLagu, mapAlbum, album, temp[r->El[i]]);
        penyanyi = getIDPenyanyiFromAlbum(album);
        enqueue(&antrian, penyanyi, album, lagu);
        if(i != r->RNeff-1){
            Push(&riwayat, penyanyi, album, lagu);
        }
    }
    Reversestack(&riwayat);

    // Mengambil lagu pertama dari antrian menjadi current song; antrian sekarang dimulai dari lagu kedua
    dequeue(&antrian, &(&current)->penyanyi, &(&current)->album, &(&current)->lagu);
}
void radioFunction(){
    int MAX = CountLagu(SetLagu, mapAlbum);
    int n, a = 1, lengthlagu;
    TempLagu(SetLagu, mapAlbum);
    printf("\n");
    displayAll(SetLagu, mapAlbum);
    Radio rsong;
    Graph g;
    BMatrix MAdj;
    CreateEmptyRadio(&rsong);
    printf("\nSilahkan masukan ID lagu yang ingin ditampilkan sebagai radio :");
    STARTCOMMAND(false);
    if(IsCommandWithSemicolon(currentCommand)){
        handleSemicolon(currentCommand);
        n = ConvertWordToInt(currentCommand);
        n--;
        lengthlagu = temp[n].Length;
        rsong.El[0] = n;
        rsong.RNeff++;
        while(a < lengthlagu+1 && a < MAX){
            if ((lengthlagu + a) % MAX == rsong.El[0])
            {
                a++;
            }
            else
            {
                rsong.El[a] = (lengthlagu + a) % MAX;
                rsong.RNeff++;
                a++;
            }
        }

        CreateGraph(&g);
        MakeMatrix(rsong.RNeff, rsong.RNeff, &g.adjacencyMatrix);
        printf("\nRadio dari lagu  \"%s\" :\n", temp[rsong.El[0]].TabWord);
        for(int i = 0; i < ADJMaxtrix(g).NBrsEff; i++){
           addVerticesToAll(&g, i);
           if (isDirectlyConnected(g, 0, i))
           {
               printf("%d. %s\n", i, temp[rsong.El[i]].TabWord);
           }
        }

        printf("\nApakah anda ingin play radio ini? (Y/N) ");
        STARTCOMMAND(false);

        while (!(IsStringEqual(currentCommand.TabWord, "N;") || IsStringEqual(currentCommand.TabWord, "Y;")))
        {
            unknownCommand();
            printf("Apakah anda ingin play radio ini? (Y/N) ");
            STARTCOMMAND(false);
        }

        if(IsStringEqual(currentCommand.TabWord, "N;")){
            printf("\nAnda keluar dari radio tanpa memutar lagu!\n\n");
        } else {
            playRadio(&rsong);
            printf("\nBerhasil memutar radio!\n\n");
        }

        CreateEmptyRadio(&rsong);
    }else{
        printf("\nkurang semicolon!\n\n");
    }

}
