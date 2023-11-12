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

    char temp = INTtoChar(ArrayPenyanyi.Neff);

    WRITE(&temp);

    WRITEENTER();

    for(int i = 0; i < ArrayPenyanyi.Neff; i++){
        char temp = INTtoChar(ArrayPenyanyi.penyanyi[i].jumlahalbum);
        WRITE(&temp);
        WRITEBLANK();
        WRITE(ArrayPenyanyi.penyanyi[i].namapenyanyi.TabWord);
        WRITEENTER();

        for(int j = i; j < ArrayPenyanyi.penyanyi[i].jumlahalbum + i; j++){
            char temp = INTtoChar(SetLagu[Value(mapAlbum, j)].Count);
            WRITE(&temp);
            WRITEBLANK();
            WRITE(mapAlbum.Elements[j].AlbumName.TabWord);
        }
    }

    WRITEFINISH();
}