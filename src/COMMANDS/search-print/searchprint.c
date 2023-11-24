#include "searchprint.h"

int searchidpenyanyi(TabInt p, Word input)
{ // Mencari key id penyanyi berdasarkan inputan user
    int i = 0;
    while (i < p.Neff)
    {
        if (p.penyanyi[i].namapenyanyi.Length == input.Length)
        {
            if (IsStringEqual(p.penyanyi[i].namapenyanyi.TabWord, input.TabWord))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int searchidalbum(TabInt p, int idpenyanyi, Word input, MapAlbum map)
{
    int i = p.penyanyi[idpenyanyi].IdAlbumPertama;
    int maks = p.penyanyi[idpenyanyi].jumlahalbum + i;
    while (i < maks)
    {
        if (map.Elements[i].AlbumName.Length == input.Length)
        {
            if (IsStringEqual(map.Elements[i].AlbumName.TabWord, input.TabWord))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}


int searchidlagu(Set *s, MapAlbum map, int idalbum, Word input)
{
    int idxset = Value(map, idalbum);

    for(int i = 0; i < s[idxset].Count; i++){
        if (s[idxset].AlbumLagu[i].JudulLagu.Length == input.Length)
            {
                if (IsStringEqual(s[idxset].AlbumLagu[i].JudulLagu.TabWord, input.TabWord))
                {
                    return i;
                }
            }
    }
    return -1;
}
Word GetNamaAlbum(TabInt p, int idpenyanyi, int idalbum, MapAlbum map)
{
    int i = p.penyanyi[idpenyanyi].IdAlbumPertama;
    int maks = p.penyanyi[idpenyanyi].jumlahalbum + i;
    Word NotFound = {"NOTFOUND", 8};
    while (i < maks)
    {
            if (i == idalbum)
            {
               return(map.Elements[i].AlbumName);
            }
            i++;
    }
    return NotFound;
}

Word GetJudulLagu(Set SetLagu[], Word namaalbum, int idlagu, int idpenyanyi)
{
    boolean found = false;
    Word NotFound = {"NOTFOUND", 8};
    int idAlbum = searchidalbum(ArrayPenyanyi, idpenyanyi, namaalbum, mapAlbum);
    int i = 0, index;
    Set S = SetLagu[Value(mapAlbum, idAlbum)];
    idlagu = idlagu - 1;

    while (i < S.Count && !found)
    {
            if (i == idlagu)
            {
                return S.AlbumLagu[i].JudulLagu;
            }
            i++;
    }
    return NotFound;
}

Word GetNamaPlaylist(ArrayDin Playlists, int idplaylist){
    boolean found = false;
    Word NotFound = {"NOTFOUND", 8};
    int i = 0;
    
    while(i < Playlists.Neff && !found){
        if(i == idplaylist){
            return Playlists.A[i].namaplaylist;
        }
        i++;
    }
    return NotFound;
}
void printCurrent(){
    char judullagu[100], namaalbum[100], namapenyanyi[100];
    Word NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);
    Word NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
    Word JudulLaguW = GetJudulLagu(SetLagu, NamaAlbum, current.lagu+1, current.penyanyi);
    
    ConvertWordToString(&NamaPenyanyi,namapenyanyi);
    ConvertWordToString(&NamaAlbum, namaalbum);
    ConvertWordToString(&JudulLaguW, judullagu);

    printf("%s - %s - %s.\n", namapenyanyi, judullagu, namaalbum);
}

void displayPlaylist(ArrayDin playlists, int idplaylist){
    playlist ply = playlists.A[idplaylist];
    if(!IsEmptyLinkedList(ply)){
        addressnode P = First(ply);
        printf("-----------------------\n");
        printf("| %s\n", ply.namaplaylist.TabWord);
        printf("-----------------------\n");
        printf("PENYANYI | ALBUM | LAGU\n");
        printf("-----------------------\n");
        do
        {
            printf("%s | %s | %s\n", ArrayPenyanyi.penyanyi[PENYANYI(P)].namapenyanyi.TabWord, mapAlbum.Elements[ALBUM(P)].AlbumName.TabWord, SetLagu[Value(mapAlbum, ALBUM(P))].AlbumLagu[LAGU(P)].JudulLagu.TabWord);
            P = Next(P);

        } while (P != null);
    } else {
        printf("Playlist kosong.\n");
    }
    
}

void displayAll(Set *s, MapAlbum m){
    printf("DAFTAR SELURUH LAGU DALAM SESI INI : \n");
    int idx = 0, idset;
    for(int i = 0; i < m.Count; i++){
        idset = Value(m, i);
        printf("%s : \n", m.Elements[i].AlbumName.TabWord);
        for(int j = 0; j < s[Value(m, i)].Count; j++){
            printf(" %d. %s\n", idx + 1, s[idset].AlbumLagu[j].JudulLagu.TabWord);
            idx++;
        }
    }
    
}