#include "save.h"

void SAVE(){
    STARTCOMMAND(false);

    if(!IsCommandWithSemicolon(currentCommand)){
        unknownCommand();
        return;
    }

    handleSemicolon(currentCommand);

    Word direktori = {"../save/",8};

    NEWFILE(ConcatString(direktori, currentCommand).TabWord);

    WRITEINT(ArrayPenyanyi.Neff);

    WRITEENTER();

    for(int i = 0; i < ArrayPenyanyi.Neff; i++){
        WRITEINT(ArrayPenyanyi.penyanyi[i].jumlahalbum);
        WRITEBLANK();
        WRITESTRING(ArrayPenyanyi.penyanyi[i].namapenyanyi.TabWord);
        WRITEENTER();

        for(int j = ArrayPenyanyi.penyanyi[i].IdAlbumPertama; j < ArrayPenyanyi.penyanyi[i].jumlahalbum + i; j++){
            WRITEINT(SetLagu[Value(mapAlbum, j)].Count);
            WRITEBLANK();
            WRITESTRING(mapAlbum.Elements[j].AlbumName.TabWord);
            WRITEENTER();

            for(int k = 0; k < SetLagu[Value(mapAlbum, j)].Count; k++){
                WRITESTRING(SetLagu[Value(mapAlbum, j)].AlbumLagu[k].JudulLagu.TabWord);
                WRITEENTER();
            }
        }
    }

    WRITEFINISH();
}