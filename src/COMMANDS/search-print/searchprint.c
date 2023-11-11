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

