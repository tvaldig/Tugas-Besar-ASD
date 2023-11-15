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
void printCurrent(){
    char judullagu[100], namaalbum[100], namapenyanyi[100];
    printf("%d\n", current.lagu);
    Word NamaPenyanyi = GetNamaPenyanyi(ArrayPenyanyi, current.penyanyi);
    Word NamaAlbum = GetNamaAlbum(ArrayPenyanyi, current.penyanyi, current.album, mapAlbum);
    Word JudulLaguW = GetJudulLagu(SetLagu, NamaAlbum, current.lagu+1, current.penyanyi);
    
    ConvertWordToString(&NamaPenyanyi,namapenyanyi);
    ConvertWordToString(&NamaAlbum, namaalbum);
    ConvertWordToString(&JudulLaguW, judullagu);

    printf("Now Playing...\n");
    printf("%s--%s by %s\n", namaalbum, judullagu, namapenyanyi);
}
