#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Verifichiamo se l'utente ha inserito il nome del file
    // argc deve essere almeno 2 (argv[0] è il programma, argv[1] è il file)
    if (argc < 2) {
        printf("Uso corretto: %s <nome_file>\n", argv[0]);
        return 1;
    }
    // Il nome del file passato da riga di comando si trova in argv[1]
    char *nome_file = argv[1];
    printf("Hai scelto di aprire il file: %s\n", nome_file);

    // Qui puoi procedere con l'apertura del file usando nome_file...

    return 0;
}
